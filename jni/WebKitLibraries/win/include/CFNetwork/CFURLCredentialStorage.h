/*
	 File:	   CFNetwork/CFURLCredentialStorage.h
 
	 Contains:   CFType URL credential storage header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCREDENTIALSTORAGE__
#define __CFURLCREDENTIALSTORAGE__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFURLCREDENTIAL__
#include <CFNetwork/CFURLCredential.h>
#endif

#ifndef __CFURLPROTECTIONSPACE__
#include <CFNetwork/CFURLProtectionSpace.h>
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
 *  CFURLCredentialStorageRef
 *  
 *  Discussion:
 *	This is the type of a reference CFURLCredentialStorage. NOTE:
 *	CFURLCredentialStorage objects may cause Keychain Services'
 *	optional user interface to be displayed. The function
 *	SecKeychainSetUserInteractionAllowed() can be used to enable or
 *	disable the Keychain Services optional user interface.
 */
typedef struct _CFURLCredentialStorage*  CFURLCredentialStorageRef;
/*
 *  kCFURLCredentialStorageChangedNotification
 *  
 *  Summary:
 *	This notification is sent on the main thread whenever the set of
 *	stored credentials changes.
 *  
 */
CFN_EXPORT const CFStringRef kCFURLCredentialStorageChangedNotification  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
/*
 *  CFURLCredentialStorageGetTypeID()
 *  
 *  Discussion:
 *	Returns the type identifier of all CFURLCredentialStorage
 *	instances.
 *  
 */
CFN_EXPORT CFTypeID 
CFURLCredentialStorageGetTypeID(void)						 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialStorageCreate()
 *  
 *  Discussion:
 *	Creates a new CFURLCredentialStorage object.
 *  
 *  Parameters:
 *	
 *	allocator:
 *	  The CFAllocator which should be used to allocate memory for the
 *	  CFURLCredentialStorage. If this reference is not a valid
 *	  CFAllocator, the behavior is undefined.
 *	
 *  Result:
 *	A valid CFURLCredentialStorageRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLCredentialStorageRef 
CFURLCredentialStorageCreate(
  CFAllocatorRef   allocator)					   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialStorageCopyCredentialsForProtectionSpace()
 *  
 *  Discussion:
 *	Copies the CFURLCredentials for the specified
 *	CFURLProtectionSpace and returns them in a CFDictionary.
 *  
 *  Parameters:
 *	
 *	credentialStorage:
 *	  The CFURLCredentialStorage object.
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A CFDictionaryRef the credentials for the specified protection
 *	space, or NULL if unsuccessful. The dictionary's keys are
 *	usernames as CFStringRefs and the corresponding values are
 *	CFURLCredentialRefs.
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFURLCredentialStorageCopyCredentialsForProtectionSpace(
  CFURLCredentialStorageRef   credentialStorage,
  CFURLProtectionSpaceRef	 protectionSpace)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialStorageCopyAllCredentials()
 *  
 *  Discussion:
 *	Copies the CFURLCredentials for all available
 *	CFURLProtectionSpaces and returns them in a CFDictionary.
 *  
 *  Result:
 *	A CFDictionary containing the credentials for all available
 *	protection spaces. The dictionary has keys corresponding to the
 *	CFURLProtectionSpace objects. The values for the
 *	CFURLProtectionSpace keys consist of CFDictionaries where the
 *	keys are usernames as CFStringRefs, and the corresponding values
 *	are CFURLCredentialRefs.
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFURLCredentialStorageCopyAllCredentials(CFURLCredentialStorageRef credentialStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialStorageSetCredentialForProtectionSpace()
 *  
 *  Discussion:
 *	Adds a CFURLCredential to the CFURLCredentialStorage for the
 *	specified CFURLProtectionSpace.
 *  
 *  Parameters:
 *	
 *	credentialStorage:
 *	  The CFURLCredentialStorage object.
 *	
 *	credential:
 *	  The CFURLCredential object.
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 */
CFN_EXPORT void 
CFURLCredentialStorageSetCredentialForProtectionSpace(
  CFURLCredentialStorageRef   credentialStorage,
  CFURLCredentialRef		  credential,
  CFURLProtectionSpaceRef	 protectionSpace)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialStorageRemoveCredentialForProtectionSpace()
 *  
 *  Discussion:
 *	Removes a CFURLCredential from the CFURLCredentialStorage for the
 *	specified CFURLProtectionSpace. If the credential has a
 *	CFURLCredentialPersistence of
 *	kCFURLCredentialPersistencePermanent, the credential is also
 *	removed from permanent storage.
 *  
 *  Parameters:
 *	
 *	credentialStorage:
 *	  The CFURLCredentialStorage object.
 *	
 *	credential:
 *	  The CFURLCredential object.
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 */
CFN_EXPORT void 
CFURLCredentialStorageRemoveCredentialForProtectionSpace(
  CFURLCredentialStorageRef   credentialStorage,
  CFURLCredentialRef		  credential,
  CFURLProtectionSpaceRef	 protectionSpace)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialStorageCopyDefaultCredentialForProtectionSpace()
 *  
 *  Discussion:
 *	Copies the default CFURLCredential from the
 *	CFURLCredentialStorage for the specified CFURLProtectionSpace.
 *  
 *  Parameters:
 *	
 *	credentialStorage:
 *	  The CFURLCredentialStorage object.
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A CFURLCredentialRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLCredentialRef 
CFURLCredentialStorageCopyDefaultCredentialForProtectionSpace(
  CFURLCredentialStorageRef   credentialStorage,
  CFURLProtectionSpaceRef	 protectionSpace)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialStorageSetDefaultCredentialForProtectionSpace()
 *  
 *  Discussion:
 *	Sets the default CFURLCredential in the CFURLCredentialStorage
 *	for the specified CFURLProtectionSpace.
 *  
 *  Parameters:
 *	
 *	credentialStorage:
 *	  The CFURLCredentialStorage object.
 *	
 *	credential:
 *	  The CFURLCredential object.
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 */
CFN_EXPORT void 
CFURLCredentialStorageSetDefaultCredentialForProtectionSpace(
  CFURLCredentialStorageRef   credentialStorage,
  CFURLCredentialRef		  credential,
  CFURLProtectionSpaceRef	 protectionSpace)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCREDENTIALSTORAGE__ */

