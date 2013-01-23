/*
	 File:	   CFNetwork/CFURLConnection.h
 
	 Contains:   CFType URL Connection header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCONNECTION__
#define __CFURLCONNECTION__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFNETWORKCORETYPES__
#include <CFNetwork/CFNetworkCoreTypesPriv.h>
#endif

#ifndef __CFURLREQUEST__
#include <CFNetwork/CFURLRequest.h>
#endif

#ifndef __CFURLRESPONSE__
#include <CFNetwork/CFURLResponse.h>
#endif

/* This is only needed for the stubs of CFURLAuthenticationChallenge and CFURLCachedResponse; it should be removed when those objects come available. */
#ifndef __CFURLPROTOCOL__
#include <CFNetwork/CFURLProtocol.h>
#endif

#ifndef __CFURLAUTHCHALLENGE__
#include <CFNetwork/CFURLAuthChallenge.h>
#endif

#ifndef __CFURLCREDENTIAL__
#include <CFNetwork/CFURLCredential.h>
#endif


/* Provide a compiler flag folks can check for to determine which version of the callbacks are the "default" */
#define ERRORS_AS_CFERRORS

#include <Availability.h>

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
 *  CFURLConnection
 *  
 *  Discussion:
 *	CFURLConnection is a CFType that represents a download attempt of
 *	a CFURLRequest.  CFURLConnection is inherently asynchronous,
 *	although a synchronous API does exist.  CFURLConnections are
 *	created from a request and a client.  The request describes the
 *	download to be attempted; the client is the object contacted as
 *	the download progresses. which It is used by CFURLConnection and
 *	CFURLDownload.
 */
typedef struct _CFURLConnection*		CFURLConnectionRef;
typedef CALLBACK_API_C( CFURLRequestRef , CFURLConnectionWillSendRequestCallback )(CFURLConnectionRef conn, CFURLRequestRef request, CFURLResponseRef redirectionResponse, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidReceiveResponseCallback )(CFURLConnectionRef conn, CFURLResponseRef response, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidReceiveDataCallback )(CFURLConnectionRef conn, CFDataRef data, CFIndex originalLength, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidStopBufferingDataCallback )(CFURLConnectionRef conn, CFDataRef bufferedData, CFIndex originalLength, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidFinishLoadingCallback )(CFURLConnectionRef conn, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidFailCallbackV0 )(CFURLConnectionRef conn, CFStreamError error, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidFailCallback )(CFURLConnectionRef conn, CFErrorRef error, const void *clientInfo);
typedef CALLBACK_API_C( CFCachedURLResponseRef , CFURLConnectionWillCacheResponseCallback )(CFURLConnectionRef conn, CFCachedURLResponseRef cachedResponse, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidReceiveAuthenticationChallengeCallback )(CFURLConnectionRef conn, CFURLAuthChallengeRef challenge, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidSendBodyDataCallback )(CFURLConnectionRef conn, CFIndex bytesWritten, CFIndex totalBytesWritten, CFIndex totalBytesExpectedToWrite, const void *clientInfo);
typedef CALLBACK_API_C( Boolean , CFURLConnectionShouldUseCredentialStorageCallback )(CFURLConnectionRef conn, const void *clientInfo);
typedef CALLBACK_API_C( CFReadStreamRef , CFURLConnectionNeedNewBodyStreamCallback )(CFURLConnectionRef conn, CFURLRequestRef request, const void *clientInfo);
typedef CALLBACK_API_C( Boolean, CFURLConnectionCanRespondToProtectionSpace ) (CFURLConnectionRef conn, CFURLProtectionSpaceRef protectionSpace, const void* clientInfo);
typedef CALLBACK_API_C( void, CFURLConnectionWillSendRequestForAuthenticationChallenge ) (CFURLConnectionRef conn, CFURLAuthChallengeRef challenge, const void *clientInfo);
typedef CALLBACK_API_C( void , CFURLConnectionDidReceiveDataArrayCallback )(CFURLConnectionRef conn, CFArrayRef dataArray, const void *clientInfo);

struct CFURLConnectionClient_V0 {
  CFIndex			 version;				/* 0*/
  const void *		clientInfo;

  CFAllocatorRetainCallBack  retain;
  CFAllocatorReleaseCallBack  release;
  CFAllocatorCopyDescriptionCallBack  copyDescription;

  CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request.  Clients of CFURLConnection MUST retain the CFURLRequest passed to willSendRequest. */
  CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
  CFURLConnectionDidReceiveDataCallback  didReceiveData;
  CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
  CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
  CFURLConnectionDidFailCallbackV0  didFail;
  CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
  CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
};
	
struct CFURLConnectionClient_V1 {
	CFIndex			 version;				/* 1 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
};

#define _CFURLConnectionClientV2Present 1
struct CFURLConnectionClient_V2 {
	CFIndex			 version;				/* 2 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLConnectionDidSendBodyDataCallback didSendBodyData;		/* new for v2 */
};

#define _CFURLConnectionClientV3Present 1
struct CFURLConnectionClient_V3 {
	CFIndex			 version;				/* 3 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLConnectionDidSendBodyDataCallback didSendBodyData;		/* new for v2 */
	CFURLConnectionShouldUseCredentialStorageCallback shouldUseCredentialStorage; /* new for v3 */
	CFURLConnectionNeedNewBodyStreamCallback needNewBodyStream; /* new for v3 */	
};
	
#define _CFURLConnectionClientV4Present 1
struct CFURLConnectionClient_V4 {
	CFIndex			 version;				/* 4 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;	/* DEPRECATED */
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLConnectionDidSendBodyDataCallback didSendBodyData;		/* new for v2 */
	CFURLConnectionShouldUseCredentialStorageCallback shouldUseCredentialStorage; /* new for v3 */
	CFURLConnectionNeedNewBodyStreamCallback needNewBodyStream; /* new for v3 */	
	
	CFURLConnectionCanRespondToProtectionSpace canRespondToProtectionSpace;	/* new for v4 */
};

#define _CFURLConnectionClientV5Present 1
struct CFURLConnectionClient_V5 {
	CFIndex			 version;				/* 5 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;	/* DEPRECATED */
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLConnectionDidSendBodyDataCallback didSendBodyData;		/* new for v2 */
	CFURLConnectionShouldUseCredentialStorageCallback shouldUseCredentialStorage; /* new for v3 */
	CFURLConnectionNeedNewBodyStreamCallback needNewBodyStream; /* new for v3 */	
	CFURLConnectionCanRespondToProtectionSpace canRespondToProtectionSpace;	/* new for v4 */	
	CFURLConnectionWillSendRequestForAuthenticationChallenge willSendRequestForAuthenticationChallenge;	/* new for v5 */
};	

#define _CFURLConnectionClientV6Present 1
struct CFURLConnectionClient_V6 {
	CFIndex			 version;				/* 6 */
	const void *		clientInfo;
	
	CFAllocatorRetainCallBack  retain;
	CFAllocatorReleaseCallBack  release;
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLConnectionWillSendRequestCallback  willSendRequest; /* starting with v1, CFURLConnection will take ownership of the returned request (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveResponseCallback  didReceiveResponse;
	CFURLConnectionDidReceiveDataCallback  didReceiveData;
	CFURLConnectionDidStopBufferingDataCallback  didStopBuffering;	/* DEPRECATED */
	CFURLConnectionDidFinishLoadingCallback  didFinishLoading;
	CFURLConnectionDidFailCallback  didFail;
	CFURLConnectionWillCacheResponseCallback  willCacheResponse; /* starting with v1, CFURLConnection will take ownership of the returned cached response (i.e. this callback should return a reference to the returned object)*/
	CFURLConnectionDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLConnectionDidSendBodyDataCallback didSendBodyData;		/* new for v2 */
	CFURLConnectionShouldUseCredentialStorageCallback shouldUseCredentialStorage; /* new for v3 */
	CFURLConnectionNeedNewBodyStreamCallback needNewBodyStream; /* new for v3 */	
	CFURLConnectionCanRespondToProtectionSpace canRespondToProtectionSpace;	/* new for v4 */	
	CFURLConnectionWillSendRequestForAuthenticationChallenge willSendRequestForAuthenticationChallenge;	/* new for v5 */
	CFURLConnectionDidReceiveDataArrayCallback didReceiveDataArray; /* new for v6 */
};	
typedef struct CFURLConnectionClient_V0 CFURLConnectionClient_V0;
typedef struct CFURLConnectionClient_V1 CFURLConnectionClient_V1;
typedef struct CFURLConnectionClient_V2 CFURLConnectionClient_V2;
typedef struct CFURLConnectionClient_V3 CFURLConnectionClient_V3;
typedef struct CFURLConnectionClient_V4 CFURLConnectionClient_V4;
typedef struct CFURLConnectionClient_V5 CFURLConnectionClient_V5;
typedef struct CFURLConnectionClient_V6 CFURLConnectionClient_V6;

#define _CFURLConnectionClientCurrentVersion	6
typedef struct CFURLConnectionClient_V6 CFURLConnectionClientCurrent;

typedef struct CFURLConnectionClient_V1	CFURLConnectionClient; // this is for source compatiblity with existing clients...

/*
 *  CFURLConnectionGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFURLConnectionGetTypeID(void)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionCreate()
 *  
 */
CFN_EXPORT CFURLConnectionRef 
CFURLConnectionCreate(
  CFAllocatorRef		   alloc,
  CFURLRequestRef		  request,
  CFURLConnectionClient *  client)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionCreateWithProperties()
 *  
 */
CFN_EXPORT CFURLConnectionRef 
CFURLConnectionCreateWithProperties(
  CFAllocatorRef		   alloc,
  CFURLRequestRef		  request,
  CFURLConnectionClient *  client,
  CFDictionaryRef properties)					__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
 
/* keys to be used in the properties dictionary passed to CFURLConnectionCreateWithProperties */

/* kCFURLConnectionSocketStreamProperties : value should be dictionary of socketstream level property key/value pairs */
CFN_EXPORT const CFStringRef kCFURLConnectionSocketStreamProperties __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/* kCFURLConnectionURLConnectionProperties : properties applied to the url connection layer itself */
CFN_EXPORT const CFStringRef kCFURLConnectionURLConnectionProperties __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/* Supported kCFURLConnectionURLConnectionProperties properties: */
/* kCFURLConnectionSuspensionThreshold : value is a CFNumber represeting number of bytes that the connection is willing to fall behind the client.  If the loader
	is buffering more than the threshold value it will suspend the connection until the client processes the bytes. */
CFN_EXPORT const CFStringRef kCFURLConnectionSuspensionThreshold	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
	
/* The presence of this property will prohibit CFNetwork from calling AOSKit UI when new credentials are needed. 
   The value of this key is a CFBoolenRef: TRUE=prohibit, FALSE=allow. If property is not present, the default is allow. */
CFN_EXPORT const CFStringRef kCFURLConnectionProhibitAuthChallengeUI	__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_3);	

/*
   Default buffer size of 0 sends bytes through to the client as quickly as they arrive.  
   If you set the buffer size to non-zero, CFURLConnection will not report bytes that have arrived until
   either maxSizeToBuffer bytes have arrived or another event has taken place (like an error or auth challenge arriving)
*/
/*
 *  CFURLConnectionSetMaximumBufferSize()
 *  
 */
CFN_EXPORT void 
CFURLConnectionSetMaximumBufferSize(
  CFURLConnectionRef   conn,
  CFIndex			  maxSizeToBuffer)					   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionGetMaximumBufferSize()
 *  
 */
CFN_EXPORT CFIndex 
CFURLConnectionGetMaximumBufferSize(CFURLConnectionRef conn)  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 * Delegate callbacks will be made to this dispatch queue
 */
CFN_EXPORT void CFURLConnectionSetDelegateDispatchQueue(CFURLConnectionRef conn, dispatch_queue_t q) __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);

/*
 *  CFURLConnectionScheduleWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionScheduleWithRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionUnscheduleFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionUnscheduleFromRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
   If you want the actual download work to take on a thread other than where the connection itself is scheduled, call these.  
   Otherwise, the download will take place wherever the connection itself has been scheduled
*/
/*
 *  CFURLConnectionScheduleDownloadWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionScheduleDownloadWithRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionUnscheduleDownloadFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLConnectionUnscheduleDownloadFromRunLoop(
  CFURLConnectionRef   conn,
  CFRunLoopRef		 rl,
  CFStringRef		  mode)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if defined(__WIN32__)
/*
 *  CFURLConnectionScheduleWithCurrentMessageQueue()
 *  
 */
CFN_EXPORT void 
CFURLConnectionScheduleWithCurrentMessageQueue(CFURLConnectionRef conn) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#endif
/*
 *  CFURLConnectionStart()
 *  
 */
CFN_EXPORT void 
CFURLConnectionStart(CFURLConnectionRef conn)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionCancel()
 *  
 */
CFN_EXPORT void 
CFURLConnectionCancel(CFURLConnectionRef conn)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionHalt()
 *  
 */
CFN_EXPORT void 
CFURLConnectionHalt(CFURLConnectionRef conn)				  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionResume()
 *  
 */
CFN_EXPORT void 
CFURLConnectionResume(CFURLConnectionRef conn)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLConnectionUseCredential()
 *  
 */
CFN_EXPORT void 
CFURLConnectionUseCredential(
  CFURLConnectionRef	  conn,
  CFURLCredentialRef	  creds,
  CFURLAuthChallengeRef   challenge)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
+ *  CFURLConnectionPerformDefaultHandlingForChallenge()
+ *  
+ */
CFN_EXPORT void 
CFURLConnectionPerformDefaultHandlingForChallenge(
	CFURLConnectionRef	  conn,
	CFURLAuthChallengeRef   challenge)						 __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);
	
/*
+ *  CFURLConnectionRejectChallenge()
+ *  
+ */
CFN_EXPORT void 
CFURLConnectionRejectChallenge(
	CFURLConnectionRef	  conn,
	CFURLAuthChallengeRef   challenge)						__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);

/*
   Synchronously sends the request and returns the data, plus the response and any error by-ref.  Caller must release the returned data, as well as 
   the response and error if they are requested.  No customization during the processing of the request is permitted.  
*/
/*
 *  CFURLConnectionSendSynchronousRequest()
 *  
 */
CFN_EXPORT CFDataRef 
CFURLConnectionSendSynchronousRequest(
  CFURLRequestRef	 request,
  CFURLResponseRef *  response,
  CFErrorRef *		err,
  CFTimeInterval	  timeout)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCONNECTION__ */

