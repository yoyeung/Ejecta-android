/*
	 File:	   CFNetwork/CFHTTPCookiesPriv.h
 
	 Contains:   CFType HTTPCookies private header
 
	 Copyright:  Copyright (c) 2006-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFHTTPCOOKIESPRIV__
#define __CFHTTPCOOKIESPRIV__


#ifndef __CFHTTPCOOKIES__
#include <CFNetwork/CFHTTPCookies.h>
#endif

#include <Availability.h>

/*
 * For building on SnowLeopard...
 * This should be removed once Availability.h revs for SL
 */
#if TARGET_OS_WIN32
#define _CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE		/* WHATEVER */
#elif __MAC_10_7
#define _CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE		__OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_7,__IPHONE_2_0, __IPHONE_3_0)
#else
#define _CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE		__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0)
#endif


#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 2)

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif

/*
 *  CFHTTPCookieGetName()
 *
 *  ** DEPRECATED: use CFHTTPCookieCopyName instead **
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetName(CFHTTPCookieRef inCookie)					_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;

/*
 *  CFHTTPCookieGetValue()
 *
 *  ** DEPRECATED: use CFHTTPCookieCopyValue instead **
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetValue(CFHTTPCookieRef inCookie)					_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;

/*
 *  CFHTTPCookieGetExpiratonDate()
 *
 *  ** DEPRECATED: use CFHTTPCookieGetExpirationTime instead **
 *  
 */
CFN_EXPORT CFDateRef 
CFHTTPCookieGetExpiratonDate(CFHTTPCookieRef inCookie)			_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;
	
/*
 *  CFHTTPCookieGetCreateDate()
 *
 *  ** DEPRECATED: use CFHTTPCookieGetCreationTime instead **
 *  
 */
CFN_EXPORT CFDateRef 
CFHTTPCookieGetCreateDate(CFHTTPCookieRef inCookie)				_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;

/*
 *  CFHTTPCookieGetDomain()
 *
 *  ** DEPRECATED: use CFHTTPCookieCopyDomain instead **
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetDomain(CFHTTPCookieRef inCookie)					_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;

/*
 *  CFHTTPCookieGetPath()
 *
 *  ** DEPRECATED: use CFHTTPCookieCopyPath instead **
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetPath(CFHTTPCookieRef inCookie)					_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;

/*
 *  CFHTTPCookieGetComment()
 *
 *  ** DEPRECATED: use CFHTTPCookieCopyComment instead **
 *  
 */
CFN_EXPORT CFStringRef 
CFHTTPCookieGetComment(CFHTTPCookieRef inCookie)				_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;

/*
 *  CFHTTPCookieGetCommentURL()
 *
 *  ** DEPRECATED: use CFHTTPCookieCopyCommentURL instead **
 *  
 */
CFN_EXPORT CFURLRef 
CFHTTPCookieGetCommentURL(CFHTTPCookieRef inCookie)				_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;

/*
 *  CFHTTPCookieGetPortArray()
 *
 *  ** DEPRECATED: use CFHTTPCookieCopyPortArray instead **
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieGetPortArray(CFHTTPCookieRef inCookie)				_CFNETWORK_COOKIES_DEPRECATED_ON_DESKTOP_AND_PHONE;


struct CFHTTPCookieStorageFilterContext {
  CFIndex			 version;
  void *			  info;
  CFAllocatorRetainCallBack  retain;
  CFAllocatorReleaseCallBack  release;
  CFAllocatorCopyDescriptionCallBack  copyDescription;
};
typedef struct CFHTTPCookieStorageFilterContext CFHTTPCookieStorageFilterContext;
typedef CALLBACK_API_C( Boolean , CFHTTPCookieStorageFilterProcPtr )(CFHTTPCookieStorageRef inStorage, CFHTTPCookieRef inTestCookie, void *inInfo);
/*
 *  _CFHTTPCookieStorageGetDefault()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
_CFHTTPCookieStorageGetDefault(CFAllocatorRef inAllocator)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  _CFHTTPCookieStorageCreateInMemory()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
_CFHTTPCookieStorageCreateInMemory(
  CFAllocatorRef					  inAllocator,
  CFHTTPCookieStorageRef			  baseStorage,
  CFHTTPCookieStorageFilterProcPtr	filterCallback,
  CFHTTPCookieStorageFilterContext *  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFHTTPCookieStorageCreateFromFile()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
_CFHTTPCookieStorageCreateFromFile(
  CFAllocatorRef					  inAllocator,
  CFURLRef							inStorageLocation,
  CFHTTPCookieStorageRef			  baseStorage,
  CFHTTPCookieStorageFilterProcPtr	filterCallback,
  CFHTTPCookieStorageFilterContext *  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 * CFHTTPCookie_domainMatches()
 * *very private, just for testing*
 */
CFN_EXPORT Boolean
CFHTTPCookie_domainMatches(
  CFHTTPCookieRef cookie, 
  CFURLRef inOriginURL)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


CFN_EXPORT Boolean 
CFHTTPCookie_looksLikeIPAddress(
  CFStringRef domainName)								__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);
	
	
/* _CFHTTPCookieStorageFlushCookieStores
 *
 * spi to _really_ flush all of the cookie storages to disk
 * and remove any in-memory cached cookie storages.
 * (for testing purposes mostly)
 */
CFN_EXPORT void
_CFHTTPCookieStorageFlushCookieStores()		__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_3_0);

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFHTTPCOOKIESPRIV__ */

