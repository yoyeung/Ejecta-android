/*
 *  CFHTTPAuthenticationPriv.h
 *  CFNetwork
 *
 *  Created by Mark Pauley on 7/3/08.
 *  Copyright 2008 Apple Inc. All rights reserved.
 *
 */

#ifndef __CFHTTPAUTHENTICATIONPRIV__
#define __CFHTTPAUTHENTICATIONPRIV__

#include <Availability.h>

#ifdef __cplusplus
extern "C" {
#endif
	
/*
 * _CFHTTPAuthenticationCopyProperties()
 *
 * Discussion:
 * Serializes a CFHTTPAuthentication object into a CFDictionary for archival.
 *
 * Mac OS X threading:
 * Thread safe
 *
 * Parameters:
 * 
 * alloc:
 *   A CFAllocator object with which to allocate resources for the resulting CFDictionaryRef, or NULL for the default allocator.
 * 
 * auth:
 *   A reference to the CFHTTPAuthentication object to serialize.
 *
 * Result:
 * A CFDictionaryRef containing all of the properties necessary to describe the given CFHTTPAuthentication object
 * and re-serialize it at a later time.  This function's result follows the Copy rule, the caller takes ownership and should release.
 * returns NULL in the event that the call failed to allocate a CFDictionary object.
 */
CFN_EXPORT CFDataRef
_CFHTTPAuthenticationCopySerializedData(CFAllocatorRef alloc, CFHTTPAuthenticationRef auth);


/*
 * _CFHTTPAuthenticationCreateWithProperties()
 *
 * Discussion:
 * Synthesizes a CFHTTPAuthentication object with a dictionary created earlier by CFHTTPAuthenticationCopyProperties.
 *
 * Mac OS X threading:
 * Thread safe
 *
 * Parameters:
 * 
 * alloc:
 *  A CFAllocator object with which to allocate resources for the resulting CFHTTPAuthenticationRef, or NULL for the default allocator.
 * 
 * properties:
 *  A CFDictionaryRef created via the _CFHTTPAuthenticationCopyProperties() api.
 * 
 * Result:
 * A CFHTTPAuthenticationRef with the properties given in properties.  Returns NULL on failure.
 */
CFN_EXPORT CFHTTPAuthenticationRef
_CFHTTPAuthenticationCreateWithData(CFAllocatorRef alloc, CFDataRef properties);


enum /*CFStreamErrorHTTPAuthentication*/ {
	// can happen if we were unable to instantiate an Authentication from a purported serialized data blob.
	kCFStreamErrorHTTPAuthenticationInvalidSerialization = -1003,
};
	
#ifdef __cplusplus
}
#endif

#endif
