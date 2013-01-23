/*
	 File:	   CFNetwork/CFURLProtocolPriv.h
 
	 Contains:   CFType URL protocol private header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLPROTOCOLPRIV__
#define __CFURLPROTOCOLPRIV__

#ifndef __CFURLPROTOCOL__
#include <CFNetwork/CFURLProtocol.h>
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

#pragma pack(push, 2)

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif


/*
   Do not use!  This is being staged out; use CFURLProtocolCopySchedulingArray, below, instead.
   Once CFSchedulingSet is available in CoreFoundation, there will be a scheduling set variant instead.
*/
/*
 *  CFURLProtocolGetSchedulingArray()
 *  
 */
CFN_EXPORT CFArrayRef 
CFURLProtocolGetSchedulingArray(CFURLProtocolRef prot)		__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLProtocolCachedResponseIsValid()
 *  
 */
CFN_EXPORT Boolean 
_CFURLProtocolCachedResponseIsValid(CFURLProtocolRef prot)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Informs the protocol that it is a download and should use download I/O characteristics*/
/*
 *  _CFURLProtocolSetIsDownload()
 *  
 */
CFN_EXPORT void 
_CFURLProtocolSetIsDownload(
  CFURLProtocolRef   prot,
  Boolean			isDownload)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/* Used by CFHTTPProtocol, Foundation and WebCore to construct the correct headers*/
/*
 *  _CFNetworkCopyPreferredLanguageCode()
 *  
 */
CFN_EXPORT CFStringRef 
_CFNetworkCopyPreferredLanguageCode(void)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFURLPROTOCOLPRIV__ */

