#include <sys/time.h>
#include "EJTimer.h"

EJTimerCollection::EJTimerCollection()
{
	timers = NSDictionary::create();
}

EJTimerCollection::~EJTimerCollection()
{
	timers->release();
}

int EJTimerCollection::scheduleCallback(JSObjectRef callback, float interval, BOOL repeat)
{
	lastId++;
	
	EJTimer * timer = new EJTimer(callback, interval, repeat);
	timers->setObject(timer, lastId);
	timer->release();
	return lastId;
}

void EJTimerCollection::cancelId(int timerId)
{
	timers->removeObjectForKey(timerId);
}

void EJTimerCollection::update()
{
	NSDictElement* pElement = NULL;
	NSObject* pObject = NULL;
	NSDICT_FOREACH(timers, pElement)
	{
		pObject = pElement->getObject();
	    EJTimer* timer = (EJTimer*)pObject;
        timer->check();
        if( !timer->active ) {
			timers->removeObjectForKey(pElement->getIntKey());
		}	
	}
}


EJTimer::EJTimer()
{

}

EJTimer::EJTimer(JSObjectRef callbackp, float intervalp, BOOL repeatp)
{
	active = true;
	interval = intervalp;
	repeat = repeatp;

	struct timeval time;
    //struct timezone tz;
    gettimeofday(&time, NULL);
    target = time.tv_sec + time.tv_usec / 1000000.0  + interval;

	callback = callbackp;
	JSValueProtect(EJApp::instance()->jsGlobalContext, callback);
}

EJTimer::~EJTimer()
{
	JSValueUnprotect(EJApp::instance()->jsGlobalContext, callback);
}

void EJTimer::check()
{
	struct timeval time;
	time.tv_sec = 0;
	time.tv_usec = 0;
    //struct timezone tz;
    gettimeofday(&time, NULL);
	double currentTime = time.tv_sec + time.tv_usec / 1000000.0  + interval;

	if( active && target <= currentTime) {
		EJApp::instance()->invokeCallback(callback, NULL, 0, NULL);
		
		if( repeat ) {
			target = currentTime + interval;
		}
		else {
			active = false;
		}
	}
}