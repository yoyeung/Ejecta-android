/*
	 File:	   CFNetwork/CFURLProtectionSpace.h
 
	 Contains:   CFType URL protection space header
 
	 Copyright:  Copyright (c) 2001-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLPROTECTIONSPACE__
#define __CFURLPROTECTIONSPACE__

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
 *  CFURLProtectionSpaceRef
 *  
 *  Discussion:
 *	This is the type of a reference CFURLProtectionSpace.
 */
typedef struct _CFURLProtectionSpace*   CFURLProtectionSpaceRef;

/*
 *  CFURLProtectionSpaceServerType
 *  
 *  Discussion:
 *	The different kinds of protection spaces that can be passed in to
 *	CFURLProtectionSpaceCreate()
 */
enum CFURLProtectionSpaceServerType {

  /*
   * This protection space is for an HTTP server.
   */
  kCFURLProtectionSpaceServerHTTP = 1,

  /*
   * This protection space is for an HTTPS server (HTTP server over a
   * secure connection).
   */
  kCFURLProtectionSpaceServerHTTPS = 2,

  /*
   * This protection space is for an FTP server.
   */
  kCFURLProtectionSpaceServerFTP = 3,

  /*
   * This protection space is for an FTPS server (FTP server over a
   * secure connection).
   */
  kCFURLProtectionSpaceServerFTPS = 4,

  /*
   * This protection space is for an HTTP proxy.
   */
  kCFURLProtectionSpaceProxyHTTP = 5,

  /*
   * This protection space is for an HTTPS proxy (HTTP proxy over a
   * secure connection) .
   */
  kCFURLProtectionSpaceProxyHTTPS = 6,

  /*
   * This protection space is for an FTP proxy.
   */
  kCFURLProtectionSpaceProxyFTP = 7,

  /*
   * This protection space is for an SOCKS proxy.
   */
  kCFURLProtectionSpaceProxySOCKS = 8
};
typedef enum CFURLProtectionSpaceServerType CFURLProtectionSpaceServerType;



/*
 *  CFURLProtectionSpaceAuthenticationScheme
 *  
 *  Discussion:
 *	The different kinds of authentication schmes that can be passed
 *	in to CFURLProtectionSpaceCreate()
 */
enum CFURLProtectionSpaceAuthenticationScheme {

  /*
   * Use the default authentication scheme for a protocol. For
   * protection spaces created using
   * kCFURLProtectionSpaceAuthenticationSchemeDefault, the
   * CFURLProtectionSpaceCopyAuthenticationScheme function will return
   * kCFURLProtectionSpaceAuthenticationSchemeDefault until the actual
   * authentication scheme is determined.
   */
  kCFURLProtectionSpaceAuthenticationSchemeDefault = 1,

  /*
   * Use the Basic HTTP authentication scheme.
   */
  kCFURLProtectionSpaceAuthenticationSchemeHTTPBasic = 2,

  /*
   * Use the Digest Access HTTP authentication scheme.
   */
  kCFURLProtectionSpaceAuthenticationSchemeHTTPDigest = 3,

  /*
   * Use HTML Forms authentication.
   */
  kCFURLProtectionSpaceAuthenticationSchemeHTMLForm = 4,

  /*
   * Use the NTLM authentication scheme.
   */
  kCFURLProtectionSpaceAuthenticationSchemeNTLM = 5,

  /*
   * Negotiate for the authentication scheme - Kerberos or NTLM.
   */
  kCFURLProtectionSpaceAuthenticationSchemeNegotiate = 6,
	
  /*
   * Use an SSL identity and client certificate array.
   */
  kCFURLProtectionSpaceAuthenticationSchemeClientCertificateRequested = 7,
	
  /*
   * The protection space represents the server SecTrustRef and must be evaluated by the delegate
   * in order to proceed.
   */
  kCFURLProtectionSpaceAuthenticationSchemeServerTrustEvaluationRequested = 8,
	
  /*
   * Use the X-MobileMe-AuthToken auth protocol.
   */
  kCFURLProtectionSpaceAuthenticationSchemeXMobileMeAuthToken = 9
};
typedef enum CFURLProtectionSpaceAuthenticationScheme CFURLProtectionSpaceAuthenticationScheme;


/*
 *  CFURLProtectionSpaceGetTypeID()
 *  
 *  Discussion:
 *	Returns the type identifier of all CFURLProtectionSpace instances.
 *  
 */
CFN_EXPORT CFTypeID 
CFURLProtectionSpaceGetTypeID(void)						   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceCreate()
 *  
 *  Discussion:
 *	Creates a new CFURLProtectionSpace object.
 *  
 *  Parameters:
 *	
 *	allocator:
 *	  The CFAllocator which should be used to allocate memory for the
 *	  CFURLProtectionSpace. If this reference is not a valid
 *	  CFAllocator, the behavior is undefined.
 *	
 *	host:
 *	  A CFString containing the host name for the protection space.
 *	
 *	port:
 *	  A SInt32 value containing the port number for the protection
 *	  space.
 *	
 *	serverType:
 *	  A CFURLProtectionSpaceServerType constant defining the server
 *	  type or proxy type for the protection space.
 *	
 *	realm:
 *	  A CFString containing realm string for the protection space, or
 *	  NULL if there is no realm. The realm parameter is always
 *	  ignored for proxy server types.
 *	
 *	authenticationScheme:
 *	  A CFURLProtectionSpaceAuthenticationScheme constant defining
 *	  the authentication scheme for the protection space.
 *  
 *  Result:
 *	A valid CFURLProtectionSpaceRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLProtectionSpaceRef 
CFURLProtectionSpaceCreate(
  CFAllocatorRef							 allocator,
  CFStringRef								host,
  SInt32									 port,
  CFURLProtectionSpaceServerType			 serverType,
  CFStringRef								realm,					  /* can be NULL */
  CFURLProtectionSpaceAuthenticationScheme   authenticationScheme) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceCreateCopy()
 *  
 *  Discussion:
 *	Creates a new copy of a CFURLProtectionSpace object.
 *  
 *  Parameters:
 *	
 *	allocator:
 *	  The CFAllocator which should be used to allocate memory for the
 *	  CFURLProtectionSpace. If this reference is not a valid
 *	  CFAllocator, the behavior is undefined.
 *	
 *	theProtectionSpace:
 *	  The CFURLProtectionSpace object to be copied.
 *  
 *  Result:
 *	A valid CFURLProtectionSpaceRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLProtectionSpaceRef 
CFURLProtectionSpaceCreateCopy(
  CFAllocatorRef			allocator,
  CFURLProtectionSpaceRef   theProtectionSpace)			   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceGetHost()
 *  
 *  Discussion:
 *	Gets the host name of a CFURLProtectionSpace object.
 *  
 *  Parameters:
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A CFString containing the host name, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFStringRef 
CFURLProtectionSpaceGetHost(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceGetPort()
 *  
 *  Discussion:
 *	Gets the port number of a CFURLProtectionSpace object.
 *  
 *  Parameters:
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A SInt32 containing the port number, or 0 if unsuccessful.
 *  
 */
CFN_EXPORT SInt32 
CFURLProtectionSpaceGetPort(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceGetServerType()
 *  
 *  Discussion:
 *	Gets the server or proxy type of a CFURLProtectionSpace object.
 *  
 *  Parameters:
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A CFURLProtectionSpaceServerType containing the server or proxy
 *	type, or 0 if unsuccessful.
 *  
 */
CFN_EXPORT CFURLProtectionSpaceServerType 
CFURLProtectionSpaceGetServerType(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceGetRealm()
 *  
 *  Discussion:
 *	Gets the realm of a CFURLProtectionSpace object.
 *  
 *  Parameters:
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A CFString containing the realm, or NULL if there is no realm.
 *  
 */
CFN_EXPORT CFStringRef 
CFURLProtectionSpaceGetRealm(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceGetAuthenticationScheme()
 *  
 *  Discussion:
 *	Gets the authentication scheme of a CFURLProtectionSpace object.
 *  
 *  Parameters:
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A CFURLProtectionSpaceAuthenticationScheme containing the
 *	authentication scheme, or 0 if unsuccessful.
 *  
 */
CFN_EXPORT CFURLProtectionSpaceAuthenticationScheme 
CFURLProtectionSpaceGetAuthenticationScheme(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceIsProxy()
 *  
 *  Discussion:
 *	Determine if this CFURLProtectionSpace is a proxy server.
 *  
 *  Parameters:
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	TRUE if this CFURLProtectionSpace is a proxy server; otherwise,
 *	FALSE.
 *  
 */
CFN_EXPORT Boolean 
CFURLProtectionSpaceIsProxy(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLProtectionSpaceReceivesCredentialSecurely()
 *  
 *  Discussion:
 *	Determine if the credentials for this CFURLProtectionSpace can be
 *	sent securely.
 *  
 *  Parameters:
 *	
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	TRUE if a secure authentication scheme or protocol will be used;
 *	otherwise, FALSE.
 *  
 */
CFN_EXPORT Boolean 
CFURLProtectionSpaceReceivesCredentialSecurely(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 * CFURLProtectionSpaceGetDistinguishedNames()
 *
 * Discussion:
 * Return an array of DER-encoded array of acceptable distinguished names for client certificate mutual authentication.
 *
 *	protectionSpace:
 *	  The CFURLProtectionSpace object.
 *  
 *  Result:
 *	A CFArray of CFData wrapped DER-encoded certificates.
 *  
 */
CFN_EXPORT CFArrayRef 
CFURLProtectionSpaceGetDistinguishedNames(CFURLProtectionSpaceRef protectionSpace) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);
						   
#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLPROTECTIONSPACE__ */

