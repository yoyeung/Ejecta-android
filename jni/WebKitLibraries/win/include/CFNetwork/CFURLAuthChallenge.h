/*
	 File:	   CFNetwork/CFURLAuthChallenge.h
 
	 Contains:   CFType URL auth challenge header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLAUTHCHALLENGE__
#define __CFURLAUTHCHALLENGE__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFNETWORKCORETYPES__
#include <CFNetwork/CFNetworkCoreTypes.h>
#endif

#ifndef __CFURLCREDENTIAL__
#include <CFNetwork/CFURLCredential.h>
#endif

#ifndef __CFURLPROTECTIONSPACE__
#include <CFNetwork/CFURLProtectionSpace.h>
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
 *  CFURLAuthChallengeRef
 *  
 *  Discussion:
 *	This is the type of a reference CFURLAuthChallenge.
 */
typedef struct _CFURLAuthChallenge*	 CFURLAuthChallengeRef;
typedef CFURLAuthChallengeRef		   CFURLAuthenticationChallengeRef;
/*
 *  CFURLAuthChallengeGetTypeID()
 *  
 *  Discussion:
 *	Returns the type identifier of all CFURLAuthChallenge instances.
 *  
 */
CFN_EXPORT CFTypeID 
CFURLAuthChallengeGetTypeID(void)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLAuthChallengeCreate()
 *  
 *  Discussion:
 *	Creates a new CFURLAuthChallenge object.
 *  
 *  Parameters:
 *	
 *	allocator:
 *	  The CFAllocator which should be used to allocate memory for the
 *	  CFURLAuthChallenge. If this reference is not a valid
 *	  CFAllocator, the behavior is undefined.
 *	
 *	protectionSpace:
 *	  The protection space for the CFURLAuthChallenge object.
 *	
 *	proposedCredential:
 *	  The proposed creadential for the CFURLAuthChallenge object, or
 *	  NULL if there is no proposed creadential.
 *	
 *	previousFailureCount:
 *	  The count of the receiver's failed authentication attempts.
 *	
 *	failureResponse:
 *	  The CFURLResponse representing the last authentication failure.
 *	
 *	error:
 *	  The last authentication failure.
 *  
 *  Result:
 *	A valid CFURLAuthChallengeRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLAuthChallengeRef 
CFURLAuthChallengeCreate(
  CFAllocatorRef			allocator,
  CFURLProtectionSpaceRef   protectionSpace,
  CFURLCredentialRef		proposedCredential,
  CFIndex				   previousFailureCount,
  CFURLResponseRef		  failureResponse,
  CFErrorRef				error)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLAuthChallengeGetProtectionSpace()
 *  
 *  Discussion:
 *	Returns the receiver's protection space.
 *  
 *  Parameters:
 *	
 *	authChallenge:
 *	  The CFURLAuthChallenge.
 *  
 *  Result:
 *	A valid CFURLProtectionSpaceRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLProtectionSpaceRef 
CFURLAuthChallengeGetProtectionSpace(CFURLAuthChallengeRef authChallenge) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLAuthChallengeGetProposedCredential()
 *  
 *  Discussion:
 *	Returns the proposed credential for this challenge.
 *  
 *  Parameters:
 *	
 *	authChallenge:
 *	  The CFURLAuthChallenge.
 *  
 *  Result:
 *	A valid CFURLCredentialRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLCredentialRef 
CFURLAuthChallengeGetProposedCredential(CFURLAuthChallengeRef authChallenge) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLAuthChallengeGetPreviousFailureCount()
 *  
 *  Discussion:
 *	Returns the receiver's count of failed authentication attempts.
 *  
 *  Parameters:
 *	
 *	authChallenge:
 *	  The CFURLAuthChallenge.
 *  
 *  Result:
 *	The count of failed authentication attempts, or -1 if
 *	unsuccessful.
 *  
 */
CFN_EXPORT CFIndex 
CFURLAuthChallengeGetPreviousFailureCount(CFURLAuthChallengeRef authChallenge) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLAuthChallengeGetError()
 *  
 *  Discussion:
 *	Returns the CFError representing the last authentication failure.
 *  
 *  Parameters:
 *	
 *	authChallenge:
 *	  The CFURLAuthChallenge.
 *  
 *  Result:
 *	The CFError representing the last authentication failure.
 *  
 */
CFN_EXPORT CFErrorRef 
CFURLAuthChallengeGetError(CFURLAuthChallengeRef authChallenge) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLAuthChallengeGetFailureResponse()
 *  
 *  Discussion:
 *	Returns the response representing the last authentication failure.
 *  
 *  Parameters:
 *	
 *	authChallenge:
 *	  The CFURLAuthChallenge.
 *  
 *  Result:
 *	The response representing the last authentication failure, or
 *	NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFTypeRef 
CFURLAuthChallengeGetFailureResponse(CFURLAuthChallengeRef authChallenge) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLAUTHCHALLENGEPRIV__ */

