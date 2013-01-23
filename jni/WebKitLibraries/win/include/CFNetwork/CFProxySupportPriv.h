/*
	 File:	   CFNetwork/CFProxySupportPriv.h
 
	 Contains:   Support for computing which proxy applies when
 
	 Copyright:  Copyright (c) 2006-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFPROXYSUPPORTPRIV__
#define __CFPROXYSUPPORTPRIV__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __CFARRAY__
#include <CoreFoundation/CFArray.h>
#endif

#ifndef __CFSTRING__
#include <CoreFoundation/CFString.h>
#endif

#ifndef __CFURL__
#include <CoreFoundation/CFURL.h>
#endif

#ifndef __CFERROR__
#include <CoreFoundation/CFError.h>
#endif

#ifndef __CFRUNLOOP__
#include <CoreFoundation/CFRunLoop.h>
#endif

#ifndef __CFSTREAM__
#include <CoreFoundation/CFStream.h>
#endif

#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  CFNetworkProxyAutoConfigurationSetAuthentication()
 *  
 *  Discussion:
 *	Invoke on the ticket given with ExecuteProxyAutoConfigurarion URL prior to scheduling to 
 *	supply authentication credentials to the PAC file fetch.
 *  
 *  Availability:
 *	Mac OS X:		 in version 10.5 and later in CoreServices.framework
 *	CarbonLib:		not available
 *	Non-Carbon CFM:   not available
 */
CFN_EXPORT void 
CFNetworkProxyAutoConfigurationSetAuthentication(
CFRunLoopSourceRef executionTicket, 
CFStringRef login, 
CFStringRef password) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

#ifdef __cplusplus
}
#endif

#endif /* __CFPROXYSUPPORTPRIV__ */

