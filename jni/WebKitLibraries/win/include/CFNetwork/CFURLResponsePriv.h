/*
	 File:	   CFNetwork/CFURLResponsePriv.h
 
	 Contains:   CFType URL Response private header
  
	 Copyright:   Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLRESPONSEPRIV__
#define __CFURLRESPONSEPRIV__

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




/* Mutation - hopefully these do not need to become public?*/
/*
 *  CFURLResponseSetExpectedContentLength()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetExpectedContentLength(
  CFURLResponseRef   response,
  SInt64			 length)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseSetMIMEType()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetMIMEType(
  CFURLResponseRef   response,
  CFStringRef		mimeType)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseSetExpiration()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetExpiration(
  CFURLResponseRef   response,
  CFAbsoluteTime	 expiration)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseSetRecommendedCachePolicy()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetRecommendedCachePolicy(
  CFURLResponseRef		  response,
  CFURLCacheStoragePolicy   policy)						   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLResponseSetCreationTime()
 *  
 */
CFN_EXPORT void 
_CFURLResponseSetCreationTime(
  CFURLResponseRef   response,
  CFAbsoluteTime	 creationTime)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLRESPONSEPRIV__ */

