/*
	 File:	   CFNetwork/CFURLDownloadPriv.h
 
	 Contains:   CFType URL Download private header
 
	 Copyright:  Copyright (c) 2006-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLDOWNLOADPRIV__
#define __CFURLDOWNLOADPRIV__

#ifndef __CFURLDOWNLOAD__
#include <CFNetwork/CFURLDownload.h>
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
 *  CFURLDownloadCreateAndStartWithLoadingConnection()
 *  
 *  Discussion:
 *	This routine will create a CFURLDownload using an existing
 *	CFURLConnection.  The download will start automatically since the
 *	connection is live at the time this call is made.  This can only
 *	be made before any data has been received on the connection.  The
 *	expected use if from within the connection's didReceiveRespone
 *	callback.  The download callbacks will arrive on the runloop/mode
 *	combinations that the underlying connection is scheduled on. 
 *	There is no need to call CFURLDownloadStart on a download created
 *	with this function.  This function will return NULL if the
 *	connection is not in the proper state to be used with a download.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The CFAllocator to use.  Pass NULL for the default allocator.
 *	
 *	conn:
 *	  The connection to "convert" into a download.
 *	
 *	request:
 *	  The request associated with the connection object.
 *	
 *	response:
 *	  The response object to associate with the download (such as the
 *	  response provided to the connection's didReceiveRespone
 *	  callback).
 *	
 *	client:
 *	  A filled in CFURLDownloadClient struct.  The data will be
 *	  copied by the download.
 *  
 *  Result:
 *	A reference to the newly created object or NULL if the creation
 *	failed.
 *  
 */
CFN_EXPORT CFURLDownloadRef 
CFURLDownloadCreateAndStartWithLoadingConnection(
  CFAllocatorRef		 alloc,
  CFURLConnectionRef	 conn,
  CFURLRequestRef		request,
  CFURLResponseRef	   response,
  CFURLDownloadClient *  client)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* CFURLDownloadCreateWithLoadingConnection is on its way out, since the connClient parameter is unnecessary - use CFURLDownloadCreateAndStartWithLoadingConnection instead */
/*
 *  CFURLDownloadCreateWithLoadingConnection()
 *  
 *  Discussion:
 *	This now deprecated routine (use
 *	CFURLDownloadCreateAndStartWithLoadingConnection) will create a
 *	CFURLDownload using an existing CFURLConnection. The download
 *	will start automatically since the connection is live at the time
 *	this call is made.  This can only be made before any data has
 *	been received on the connection.  The expected use if from within
 *	the connection's didReceiveRespone callback.  The download
 *	callbacks will arrive on the runloop/mode combinations that the
 *	underlying connection is scheduled on.  There is no need to call
 *	CFURLDownloadStart on a download created with this function.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The CFAllocator to use.  Pass NULL for the default allocator.
 *	
 *	conn:
 *	  The connection to "convert" into a download.
 *	
 *	request:
 *	  The request associated with the connection object.
 *	
 *	response:
 *	  The response object to associate with the download (such as the
 *	  response provided to the connection's didReceiveRespone
 *	  callback).
 *	
 *	connClient:
 *	  << THIS IS NOT NECESSARY >>
 *	
 *	client:
 *	  A filled in CFURLDownloadClient struct.  The data will be
 *	  copied by the download.
 *  
 *  Result:
 *	A reference to the newly created object or NULL if the creation
 *	failed.
 *  
 */
CFN_EXPORT CFURLDownloadRef 
CFURLDownloadCreateWithLoadingConnection(
  CFAllocatorRef		   alloc,
  CFURLConnectionRef	   conn,
  CFURLRequestRef		  request,
  CFURLResponseRef		 response,
  CFURLConnectionClient *  connClient,	   /* can be NULL */
  CFURLDownloadClient *	client)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFURLDOWNLOADPRIV__ */

