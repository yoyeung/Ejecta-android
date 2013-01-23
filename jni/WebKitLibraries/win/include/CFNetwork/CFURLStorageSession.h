/*
 *  CFURLStorageSessionPriv.h
 *  CFNetwork
 *
 *  Copyright 2011 Apple Inc. All rights reserved.
 *
 */

#ifndef __CFURLSTORAGESESSION__
#define __CFURLSTORAGESESSION__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __CFNETWORK__
#include <CFNetwork/CFNetwork.h>
#endif

#ifndef __CFNETWORKCORETYPES__
#include <CFNetwork/CFNetworkCoreTypes.h>
#endif

#ifndef __CFHTTPCOOKIES__
#include <CFNetwork/CFHTTPCookies.h>
#endif

#ifndef __CFURLCREDENTIALSTORAGE__
#include <CFNetwork/CFURLCredentialStorage.h>
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
	
#pragma pack(push, 2)
	
	
	/*
	 *  _CFURLStorageSessionRef
	 *  
	 *  Discussion:
	 *	This type is a session object that allows control of different types of storage
	 */
//	typedef struct __CFURLStorageSession*			  CFURLStorageSessionRef;

	
	/*
	 *  _CFURLStorageSessionGetTypeID()
	 *  
	 *  Discussion:
	 *	Returns the type identifier of all _CFURLStorageSession instances.
	 *  
	 *  Mac OS X threading:
	 *	Not thread safe
	 *  
	 */
	CFN_EXPORT CFTypeID 
	_CFURLStorageSessionGetTypeID(void)									  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	

	// properties for storage creation
	CFN_EXPORT const CFStringRef	_kCFURLStorageSessionIsPrivate;										/* [R  ] CFBoolean */
	
	/*
	 * _CFURLStorageSessionCreate()
	 *  
	 *  Discussion:
	 *	Create a new instance of a storage session object.  This will allocate
	 *	only the underlying structures and set aside the resources.
	 *  
	 *  Mac OS X threading:
	 *	Not thread safe
	 *  
	 *  Parameters:
	 *	
	 *	alloc:
	 *	  Allocator to use for allocating.  NULL indicates the default
	 *	  allocator.
	 *	
	 *	sessionIdentifier:
	 *	  An optional string idenfiier that is useful for persistance and rendezvous.
	 *	
	 *	sessionProperties:
	 *	  A set of configuraton properties supporting storage behaviors
	 *  
	 */
	CFN_EXPORT CFURLStorageSessionRef 
	_CFURLStorageSessionCreate(	CFAllocatorRef	  alloc, CFStringRef   sessionIdentifier, CFDictionaryRef	sessionProperties)				__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

	
	/*
	 * _CFURLStorageSessionCreateData()
	 *  
	 *  Discussion:
	 *	Support for serialization. This call creates a data that can be
	 *	used to create a storage session via _CFURLStorageSessionCreateWithData().
	 *  
	 *  Mac OS X threading:
	 *	Not thread safe
	 *  
	 *  Parameters:
	 *	
	 *	alloc:
	 *	  Allocator to use for allocating.  NULL indicates the default
	 *	  allocator.
	 *	
	 *	session:
	 *	  The session to convert to data
	 *	
	 */
	CFN_EXPORT CFDataRef
	_CFURLStorageSessionCreateData(CFAllocatorRef alloc, CFURLStorageSessionRef session)									__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

	
	/*
	 * _CFURLStorageSessionCreateWithData()
	 *  
	 *  Discussion:
	 *	Create a new session from a data created by _CFURLStorageSessionCreateData().
	 *	Supports serialization.
	 *  
	 *  Mac OS X threading:
	 *	Not thread safe
	 *  
	 *  Parameters:
	 *	
	 *	alloc:
	 *	  Allocator to use for allocating.  NULL indicates the default
	 *	  allocator.
	 *	
	 *	data:
	 *	  An optional string idenfiier that is useful for persistance and rendezvous.
	 *  
	 */
	CFN_EXPORT
	CFURLStorageSessionRef _CFURLStorageSessionCreateWithData(CFAllocatorRef alloc, CFDataRef data)							__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);
	
	/*
	 * _CFURLStorageSessionCopyProcessDefault()
	 *  
	 *  Discussion:
	 *	Accessor for default session.
	 *  
	 *  Mac OS X threading:
	 *	Not thread safe
	 *  
	 *  Parameters:
	 *	
	 *	inAllocator:
	 *	  Allocator to use for allocating.  NULL indicates the default
	 *	  allocator.
	 *	
	 */
	CFN_EXPORT CFURLStorageSessionRef
	_CFURLStorageSessionCopyProcessDefault(CFAllocatorRef inAllocator)														__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

	/*
	 * _CFURLStorageSessionGetDefault()
	 *	
	 *  Discussion:
	 *	Use _CFURLStorageSessionCopyProcessDefault instead. Non-retaining accessor for default session.
	 *  If you have to use this, don't release the session returned.
	 *  
	 *  Mac OS X threading:
	 *	Not thread safe
	 *  
	 *  Parameters:
	 *	
	 *	inAllocator:
	 *	  Allocator that is ignored.
	 */
	
	 CFN_EXPORT CFURLStorageSessionRef
	_CFURLStorageSessionGetDefault(CFAllocatorRef inAllocator)																__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

	/*
	 * _CFURLStorageSessionCopyIdentifier()
	 */
	CFN_EXPORT CFStringRef
	_CFURLStorageSessionCopyIdentifier(CFAllocatorRef inAllocator, CFURLStorageSessionRef storageSession) 					__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

	/*
	 * _CFURLStorageSessionCopyCookieStorage()
	 */
	CFN_EXPORT CFHTTPCookieStorageRef
	_CFURLStorageSessionCopyCookieStorage(CFAllocatorRef inAllocator, CFURLStorageSessionRef storageSession) 				__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

	/*
	 * _CFURLStorageSessionCopyCredentialStorage()
	 */
	CFN_EXPORT CFURLCredentialStorageRef
	_CFURLStorageSessionCopyCredentialStorage(CFAllocatorRef inAllocator, CFURLStorageSessionRef storageSession) 			__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

	/*
	 * _CFURLStorageSessionCopyCache()
	 */
	CFN_EXPORT CFURLCacheRef
	_CFURLStorageSessionCopyCache(CFAllocatorRef inAllocator, CFURLStorageSessionRef storageSession)						__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_5_0);

#pragma pack(pop)
	
#ifdef __cplusplus
}
#endif

#endif /* __CFURLSTORAGESESSION__ */

