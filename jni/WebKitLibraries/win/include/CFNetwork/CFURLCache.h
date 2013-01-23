/*
	 File:	   CFNetwork/CFURLCache.h
 
	 Contains:   CFType URL Cache header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCACHE__
#define __CFURLCACHE__

#ifndef __CFNETWORKCORETYPES__
#include <CFNetwork/CFNetworkCoreTypes.h>
#endif

#ifndef __CFURLREQUEST__
#include <CFNetwork/CFURLRequest.h>
#endif

#ifndef __CFURLRESPONSE__
#include <CFNetwork/CFURLResponse.h>
#endif



#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif


/*
 *  CFURLCachePriv
 *  
 *  Discussion:
 *	CFURLCache is a CFType that represents a cache of URLs.
 */
typedef const struct _CFCachedURLResponse*  CFCachedURLResponseRef;
	
/*
 *  CFURLCacheGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFURLCacheGetTypeID(void)									 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFCachedURLResponseGetTypeID(void)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseCreateWithData()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFCachedURLResponseCreateWithData(
  CFAllocatorRef	 alloc,
  CFURLResponseRef   response,
  CFDataRef		  data)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseCreateWithUserInfo()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFCachedURLResponseCreateWithUserInfo(
  CFAllocatorRef			alloc,
  CFURLResponseRef		  response,
  CFDataRef				 data,
  CFPropertyListRef		 userInfo,
  CFURLCacheStoragePolicy   storagePolicy)					__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseCreateWithDataArray()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFCachedURLResponseCreateWithDataArray(
  CFAllocatorRef alloc,
  CFURLResponseRef response,
  CFArrayRef dataArray,
  CFPropertyListRef userInfo,
  CFURLCacheStoragePolicy storagePolicy)					__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);
  
/*
 *  CFCachedURLResponseGetWrappedResponse()
 *  
 */
CFN_EXPORT CFURLResponseRef 
CFCachedURLResponseGetWrappedResponse(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetReceiverData()
 *		use CFCachedURLResponseCopyReceiverDataArray instead
 */
CFN_EXPORT CFDataRef 
CFCachedURLResponseGetReceiverData(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_7, __IPHONE_2_0, __IPHONE_5_0);

/*
 *  CFCachedURLResponseCopyReceiverDataArray()
 *  
 */
CFN_EXPORT CFArrayRef
CFCachedURLResponseCopyReceiverDataArray(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);

/*
 *  CFCachedURLResponseGetUserInfo()
 *  
 */
CFN_EXPORT CFPropertyListRef 
CFCachedURLResponseGetUserInfo(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetStoragePolicy()
 *  
 */
CFN_EXPORT CFURLCacheStoragePolicy 
CFCachedURLResponseGetStoragePolicy(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseSetStoragePolicy()
 *  
 */
CFN_EXPORT void 
CFCachedURLResponseSetStoragePolicy(
  CFCachedURLResponseRef	cachedResponse,
  CFURLCacheStoragePolicy   storagePolicy)					__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseGetNSCachedURLResponse()
 *  
 */
CFN_EXPORT CFTypeRef 
CFCachedURLResponseGetNSCachedURLResponse(CFCachedURLResponseRef cachedResponse) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFCachedURLResponseSetNSCachedURLResponse()
 *  
 */
CFN_EXPORT void 
CFCachedURLResponseSetNSCachedURLResponse(
  CFCachedURLResponseRef   cachedResponse,
  CFTypeRef				nsCachedURLResponse)			   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

#define CFURLCacheCopySharedURLCachePresent 1
/*
 *  CFURLCacheCopySharedURLCache()
 *  
 */
CFN_EXPORT CFURLCacheRef 
CFURLCacheCopySharedURLCache(void)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_3_0);
	
/*
 *  CFURLCacheSetSharedURLCache()
 *  
 */
CFN_EXPORT void 
CFURLCacheSetSharedURLCache(CFURLCacheRef cache)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCreate()
 *  
 */
CFN_EXPORT CFURLCacheRef 
CFURLCacheCreate(
  CFAllocatorRef   alloc,
  CFIndex		  memoryCapacity,
  CFIndex		  diskCapacity,
  CFStringRef	  path)									  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCopyResponseForRequest()
 *  
 */
CFN_EXPORT CFCachedURLResponseRef 
CFURLCacheCopyResponseForRequest(
  CFURLCacheRef	 cacheRef,
  CFURLRequestRef   request)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheAddCachedResponseForRequest()
 *  
 */
CFN_EXPORT void 
CFURLCacheAddCachedResponseForRequest(
  CFURLCacheRef			cacheRef,
  CFCachedURLResponseRef   cachedResponse,
  CFURLRequestRef		  request,
  CFTypeRef				nsCachedURLResponse)			   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheRemoveCachedResponseForRequest()
 *  
 */
CFN_EXPORT void 
CFURLCacheRemoveCachedResponseForRequest(
  CFURLCacheRef	 cacheRef,
  CFURLRequestRef   request)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheRemoveAllCachedResponses()
 *  
 */
CFN_EXPORT void 
CFURLCacheRemoveAllCachedResponses(CFURLCacheRef cacheRef)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheMemoryCapacity()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheMemoryCapacity(CFURLCacheRef cacheRef)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheDiskCapacity()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheDiskCapacity(CFURLCacheRef cacheRef)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheSetMemoryCapacity()
 *  
 */
CFN_EXPORT void 
CFURLCacheSetMemoryCapacity(
  CFURLCacheRef   cacheRef,
  CFIndex		 memoryCapacity)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  CFURLCacheSetMemoryLimit()
 *  
 */
CFN_EXPORT void 
_CFURLCacheSetMemoryLimit(
							CFURLCacheRef   cacheRef,
							CFIndex		 memoryCapacity,
							CFIndex		 requestCapacity)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_4_0);
	
	
	
/*
 *  CFURLCacheSetDiskCapacity()
 *  
 */
CFN_EXPORT void 
CFURLCacheSetDiskCapacity(
  CFURLCacheRef   cacheRef,
  CFIndex		 diskCapacity)							   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCurrentMemoryUsage()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheCurrentMemoryUsage(CFURLCacheRef cacheRef)		  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCacheCurrentDiskUsage()
 *  
 */
CFN_EXPORT CFIndex 
CFURLCacheCurrentDiskUsage(CFURLCacheRef cacheRef)			__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

	
#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCACHE__ */

