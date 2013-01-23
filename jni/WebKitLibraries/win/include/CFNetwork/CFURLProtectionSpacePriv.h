/*
	 File:	   CFNetwork/CFURLProtectionSpacePriv.h
 
	 Contains:   CFType URL protection space header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLPROTECTIONSPACEPRIV__
#define __CFURLPROTECTIONSPACEPRIV__

#ifndef __CFURLPROTECTIONSPACE__
#include <CFNetwork/CFURLProtectionSpace.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
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

CFN_EXPORT CFDictionaryRef CFURLProtectionSpaceCopyProperties(CFAllocatorRef allocator, CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);

CFN_EXPORT CFURLProtectionSpaceRef CFURLProtectionSpaceCreateWithProperties(CFAllocatorRef allocator, CFDictionaryRef properties) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);
					   
#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLPROTECTIONSPACEPRIV__ */

