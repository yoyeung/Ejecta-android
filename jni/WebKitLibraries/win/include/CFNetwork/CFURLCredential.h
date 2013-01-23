/*
	 File:	   CFNetwork/CFURLCredential.h
 
	 Contains:   CFType URL credential header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCREDENTIAL__
#define __CFURLCREDENTIAL__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
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


/*
 *  CFURLCredentialRef
 *  
 *  Discussion:
 *	This is the type of a reference CFURLCredential. NOTE:
 *	CFURLCredential objects may cause Keychain Services' optional
 *	user interface to be displayed. The function
 *	SecKeychainSetUserInteractionAllowed() can be used to enable or
 *	disable the Keychain Services optional user interface.
 */
typedef const struct _CFURLCredential*		CFURLCredentialRef;

/*
 *  CFURLCredentialPersistence
 *  
 *  Discussion:
 *	The persistence setting for the CFURLCredential object.
 */
enum CFURLCredentialPersistence {

  /*
   * This credential won't be saved.
   */
  kCFURLCredentialPersistenceNone = 1,

  /*
   * This credential will only be stored for this session.
   */
  kCFURLCredentialPersistenceForSession = 2,

  /*
   * This credential will be stored permanently and shared with other
   * applications.
   */
  kCFURLCredentialPersistencePermanent = 3
};
typedef enum CFURLCredentialPersistence CFURLCredentialPersistence;


/*
 *  CFURLCredentialGetTypeID()
 *  
 *  Discussion:
 *	Returns the type identifier of all CFURLCredential instances.
 *  
 */
CFN_EXPORT CFTypeID 
CFURLCredentialGetTypeID(void)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLCredentialCreate()
 *  
 *  Discussion:
 *	Creates a new CFURLCredential object.
 *  
 *  Parameters:
 *	
 *	allocator:
 *	  The CFAllocator which should be used to allocate memory for the
 *	  CFURLCredential. If this reference is not a valid CFAllocator,
 *	  the behavior is undefined.
 *	
 *	username:
 *	  A CFString containing the username.
 *	
 *	password:
 *	  A CFString containing the password.
 *	
 *	accountDomain:
 *	  Ignored.
 *	
 *	persistence:
 *	  The persistence setting for the CFURLCredential:
 *	  kCFURLCredentialPersistenceNone,
 *	  kCFURLCredentialPersistenceForSession, or
 *	  kCFURLCredentialPersistencePermanent.
 *  
 *  Result:
 *	A valid CFURLCredentialRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLCredentialRef 
CFURLCredentialCreate(
  CFAllocatorRef			   allocator,
  CFStringRef				  username,
  CFStringRef				  password,
  CFStringRef				  accountDomain,	   /* ignored */
  CFURLCredentialPersistence   persistence)				   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

	
/*
 *  CFURLCredentialCreateCopy()
 *  
 *  Discussion:
 *	Creates a new copy of a CFURLCredential object.
 *  
 *  Parameters:
 *	
 *	allocator:
 *	  The CFAllocator which should be used to allocate memory for the
 *	  CFURLCredential. If this reference is not a valid CFAllocator,
 *	  the behavior is undefined.
 *	
 *	theCredential:
 *	  The CFURLCredential object to be copied.
 *  
 *  Result:
 *	A valid CFURLCredentialRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLCredentialRef 
CFURLCredentialCreateCopy(
  CFAllocatorRef	   allocator,
  CFURLCredentialRef   theCredential)						 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialGetUsername()
 *  
 *  Discussion:
 *	Gets the username from a CFURLCredential object.  May return NULL if this credential applies to a certificate credential.
 *  
 *  Parameters:
 *	
 *	credential:
 *	  The CFURLCredential object.
 *  
 *  Result:
 *	A CFStringRef containing the username, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFStringRef 
CFURLCredentialGetUsername(CFURLCredentialRef credential)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialCopyPassword()
 *  
 *  Discussion:
 *	Copies the password from a CFURLCredential object. This is a copy
 *	operation because a new copy of the password must be created if
 *	the password is stored in a SecKeychainItem.  Note that just because
 *	there a password does not guarantee the process can access it -- the keychain code
 *	may not allow access by the current process.
 *	May return NULL if this certificate applies to a certificate credential.
 *  
 *  Parameters:
 *	
 *	credential:
 *	  The CFURLCredential object.
 *  
 *  Result:
 *	A CFStringRef containing the password, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFStringRef 
CFURLCredentialCopyPassword(CFURLCredentialRef credential)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialContainsPassword()
 *  
 *  Discussion:
 *	Determines if a CFURLCredential object contains a password. Note that just because
 *	there a password does not guarantee the process can access it -- the keychain code
 *	may not allow access by the current process.
 *  
 *  Parameters:
 *	
 *	credential:
 *	  The CFURLCredential object.
 *  
 *  Result:
 *	TRUE if there is a password; otherwise, FALSE.
 *  
 */
CFN_EXPORT Boolean 
CFURLCredentialContainsPassword(CFURLCredentialRef credential) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLCredentialGetPersistence()
 *  
 *  Discussion:
 *	Gets the persistence setting of a CFURLCredential object.
 *  
 *  Parameters:
 *	
 *	credential:
 *	  The CFURLCredential object.
 *  
 *  Result:
 *	The persistence setting of a CFURLCredential object.
 *  
 */
CFN_EXPORT CFURLCredentialPersistence 
CFURLCredentialGetPersistence(CFURLCredentialRef credential)  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
	
/*
 * CFURLCredentialGetCertificateArray()
 *
 * Discussion:
 *	If this credential was created to hold a certificate array, that array is returned.
 *
 * Parameters:
 *	credential:
 *		the CFURLCRedential object.
 *
 * Result:
 *	The certificate array or NULL if this is a username/password credential.
 */
CFN_EXPORT CFArrayRef
CFURLCredentialGetCertificateArray(CFURLCredentialRef credential)   __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCREDENTIAL__ */

