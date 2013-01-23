/*
	 File:	   CFNetwork/CFURLCachePriv.h
 
	 Contains:   CFType URL Cache header
 
	 Copyright:  Copyright (c) 2001-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCACHEPRIV__
#define __CFURLCACHEPRIV__

#ifndef __CFNETWORKCORETYPES__
#include <CFNetwork/CFNetworkCoreTypesPriv.h>
#endif

#ifndef __CFURLCACHE__
#include <CFNetwork/CFURLCache.h>
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

#endif /* __CFURLCACHEPRIV__ */

