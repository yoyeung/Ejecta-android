/*
	 File:	   CFNetwork/CFURLConnectionPriv.h
 
	 Contains:   CFType URL Connection private header 
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCONNECTIONPRIV__
#define __CFURLCONNECTIONPRIV__

#ifndef __CFURLCONNECTION__
#include <CFNetwork/CFURLConnection.h>
#endif

#include <Availability.h>

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
 * CFURLConnectionInvalidateConnectionCache()
 *  invalidates the entire connection cache, all existing connections will persist until their work is done, new connections will be un aware of them.
 */
CFN_EXPORT void
CFURLConnectionInvalidateConnectionCache()				    __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_1);
	
CFN_EXPORT void
CFURLConnectionSetShouldPipelineByDefault(Boolean shouldPipeline) __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_0);

CFN_EXPORT const CFStringRef _kCFURLConnectionPropertyShouldSniff		__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
CFN_EXPORT const CFStringRef _kCFURLConnectionPropertyRespectConnectionClose __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCONNECTIONPRIV__ */

