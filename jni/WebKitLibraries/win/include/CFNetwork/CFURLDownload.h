/*
	 File:	   CFNetwork/CFURLDownload.h
 
	 Contains:   CFType URL Download header
 
	 Copyright:  Copyright (c) 2006-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLDOWNLOAD__
#define __CFURLDOWNLOAD__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFURLCONNECTION__
#include <CFNetwork/CFURLConnection.h>
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
 *  CFURLDownload
 *  
 *  Discussion:
 *	CFURLDownload is a CFType that represents a download attempt of a
 *	CFURLRequest and saving the downloaded data to a file.  The
 *	progress of the download is reported to the client object.  Note:
 *	The word "download" is used to refer to the process of loading
 *	data off a network, decoding the data if necessary and saving the
 *	data to a file.
 */
typedef struct _CFURLDownload*		  CFURLDownloadRef;

/*
 *  CFURLDownloadDidStartCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download starts.  This
 *	callback is sort of redundant in the standard case where
 *	CFURLDownloadStart is called but is provided to support the
 *	CFURLDownloadCreateWithLoadingConnection case.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDidStartCallback )(CFURLDownloadRef download, const void *clientInfo);

/*
 *  CFURLDownloadWillSendRequestCallback
 *  
 *  Discussion:
 *	Callback function which is called when the download object
 *	determines that is must change URLs in order to continue the
 *	download.  If the client is sataified with the proposed
 *	redirected request then the callback should return the passed in
 *	request after calling CFRetain on it (the download will take
 *	ownership of the returned request).  The client can return NULL
 *	and the redirect will be canceled (or the client can cancel the
 *	entire operation by calling CFURLDownloadCancel).
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	request:
 *	  The proposed redirected request.
 *	
 *	redirectionResponse:
 *	  The URL response that caused the redirect.  May be NULL.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 *  
 *  Result:
 *	The actual URL request to use in light of the redirectionResponse.
 */
typedef CALLBACK_API_C( CFURLRequestRef , CFURLDownloadWillSendRequestCallback )(CFURLDownloadRef download, CFURLRequestRef request, CFURLResponseRef redirectionResponse, const void *clientInfo);

/*
 *  CFURLDownloadDidReceiveAuthenticationChallengeCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download must
 *	authenticate a challenge in order to continue.  This callback
 *	provides the client the opportunity to determine the couuse of
 *	action to take for the challange.  The client can provide
 *	credentials, continue without credentials or cancel the download.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	challenge:
 *	  The URL authentication challenge that must by authenticated in
 *	  order to download the request.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDidReceiveAuthenticationChallengeCallback )(CFURLDownloadRef download, CFURLAuthChallengeRef challenge, const void *clientInfo);

/*
 *  CFURLDownloadDidReceiveResponseCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download has received
 *	sufficient load data to construct the CFURLResponse object for
 *	the download. In some rare cases multiple responses may be
 *	received for a single download.  Should this occur the client
 *	should assume that each new response resets the download progress
 *	to 0 and should check the new response for the expected content
 *	length.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	response:
 *	  The CFURLResponse object received as part of the download.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDidReceiveResponseCallback )(CFURLDownloadRef download, CFURLResponseRef response, const void *clientInfo);

/*
 *  CFURLDownloadWillResumeWithResponseCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download has receieved a
 *	response from the server after attempting to resume a download.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	response:
 *	  The CFURLResponse object received as part of the download.
 *	
 *	startingByte:
 *	  the location of the start of the resumed data (in bytes)
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadWillResumeWithResponseCallback )(CFURLDownloadRef download, CFURLResponseRef response, UInt64 startingByte, const void *clientInfo);

/*
 *  CFURLDownloadDidReceiveDataCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download receives data
 *	incrementally.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	length:
 *	  The amount of data received in this increment, measured in
 *	  bytes.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDidReceiveDataCallback )(CFURLDownloadRef download, CFIndex length, const void *clientInfo);

/*
 *  CFURLDownloadShouldDecodeDataOfMIMETypeCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download determines that
 *	a downloaded object is encoded to inquire if the file should be
 *	automatically decoded. Return true to automatically decode the
 *	file, false to leave it encoded.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	encodingType:
 *	  The type of the encoding used by the downloaded object.  The
 *	  supported encoding formats are gzip ("application/gzip"),
 *	  Binhex ("application/mac-binhex40") and MacBinary
 *	  ("application/macbinary").
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 *  
 *  Result:
 *	true to decode, false to leave encoded
 */
typedef CALLBACK_API_C( Boolean , CFURLDownloadShouldDecodeDataOfMIMETypeCallback )(CFURLDownloadRef download, CFStringRef encodingType, const void *clientInfo);

/*
 *  CFURLDownloadDecideDestinationWithSuggestedObjectNameCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download has determined
 *	a suggested name for the downloaded object.  The client can
 *	modify the path by calling CFURLDownloadSetDestination.  This
 *	callback will not be received if CFURLDownloadSetDestination has
 *	already been called on the download.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	objectName:
 *	  The proposed name for the downloaded object.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDecideDestinationWithSuggestedObjectNameCallback )(CFURLDownloadRef download, CFStringRef objectName, const void *clientInfo);

/*
 *  CFURLDownloadDidCreateDestinationCallback
 *  
 *  Discussion:
 *	Callback function which is called when the download has created
 *	the destination object.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	path:
 *	  CFURL file system path of created object.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDidCreateDestinationCallback )(CFURLDownloadRef download, CFURLRef path, const void *clientInfo);

/*
 *  CFURLDownloadDidFinishCallback
 *  
 *  Discussion:
 *	Callback function which is called when a download is complete.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDidFinishCallback )(CFURLDownloadRef download, const void *clientInfo);

/*
 *  CFURLDownloadDidFailCallback
 *  
 *  Discussion:
 *	Callback function which is called if a download fails.
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	error:
 *	  The reason the download failed.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 */
typedef CALLBACK_API_C( void , CFURLDownloadDidFailCallback )(CFURLDownloadRef download, CFErrorRef error, const void *clientInfo);

/*
 *  CFURLDownloadShouldUseCredentialStorageCallback
 *  
 *  Discussion:
 *	Callback function which allows the client to prevent CFNetwork from consulting
 *	the credential storage for credentials before a CFURLDownloadDidReceiveAuthenticationChallengeCallback.
 *	The default behavior for a download it to apply the default credentials from the credential storage
 *	before informing the client of the challenge (by way of CFURLDownloadDidReceiveAuthenticationChallengeCallback).
 *	
 *	Return false to prevent CFNetwork from using the credential storage automatically (the client can still apply
 *	any default credentials from within a CFURLDownloadDidReceiveAuthenticationChallengeCallback).
 *
 *	Returning true is the same as not implementing this callback.  In those cases CFNetwork will apply
 *	the default credentials from the credential storage as appropriate for a given challenge before
 *	consulting the client.
 *
 *  Parameters:
 *	
 *	download:
 *	  The download object receiving the callback.
 *	
 *	clientInfo:
 *	  The clientInfo pointer passed in by the client when the
 *	  download was created.
 * 
 *  Result:
 *	false to not consult the credential store automatically, true to apply default credentials automatically (default behavior)
 */
typedef CALLBACK_API_C( Boolean , CFURLDownloadShouldUseCredentialStorageCallback )(CFURLDownloadRef download, const void *clientInfo);

typedef CALLBACK_API_C( Boolean, CFURLDownloadCanRespondToProtectionSpace ) (CFURLDownloadRef download, CFURLProtectionSpaceRef protectionSpace, const void* clientInfo);

/* This structure is passed to the various download create calls.  It specifies a pointer value that
	will be provided to all client callbacks along with the callbacks themselves.  The data will be 
	copied from the passed in structure (and the download object will retain the clientInfo if a retain
	callback is provided). */
struct CFURLDownloadClient_V0 {
  CFIndex			 version;				/* set to 0 */
  const void *		clientInfo;			 /* this value will be passed in to client callbacks */

  CFAllocatorRetainCallBack  retain;		  /* A pointer to the function to call to retain the clientInfo object.  Pass in NULL if no retain is needed */
  CFAllocatorReleaseCallBack  release;		/* A pointer to the function to call to release the clientInfo object.  Pass in NULL if no release is needed */
  CFAllocatorCopyDescriptionCallBack  copyDescription;

  CFURLDownloadDidStartCallback  didStart;
  CFURLDownloadWillSendRequestCallback  willSendRequest; /* this callback uses the same ownership policy as the v1 CFURLConnection callback of the same name (i.e. this callback should return a reference to the returned object) */
  CFURLDownloadDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
  CFURLDownloadDidReceiveResponseCallback  didReceiveResponse;
  CFURLDownloadWillResumeWithResponseCallback  willResumeWithResponse;
  CFURLDownloadDidReceiveDataCallback  didReceiveData;
  CFURLDownloadShouldDecodeDataOfMIMETypeCallback  shouldDecodeDataOfMIMEType;
  CFURLDownloadDecideDestinationWithSuggestedObjectNameCallback  decideDestinationWithSuggestedObjectName;
  CFURLDownloadDidCreateDestinationCallback  didCreateDestination;
  CFURLDownloadDidFinishCallback  didFinish;
  CFURLDownloadDidFailCallback  didFail;
};

#define _CFURLDownloadClientV1Present 1
struct CFURLDownloadClient_V1 {
  CFIndex			 version;				/* set to 1 */
  const void *		clientInfo;			 /* this value will be passed in to client callbacks */

  CFAllocatorRetainCallBack  retain;		  /* A pointer to the function to call to retain the clientInfo object.  Pass in NULL if no retain is needed */
  CFAllocatorReleaseCallBack  release;		/* A pointer to the function to call to release the clientInfo object.  Pass in NULL if no release is needed */
  CFAllocatorCopyDescriptionCallBack  copyDescription;

  CFURLDownloadDidStartCallback  didStart;
  CFURLDownloadWillSendRequestCallback  willSendRequest; /* this callback uses the same ownership policy as the v1 CFURLConnection callback of the same name (i.e. this callback should return a reference to the returned object) */
  CFURLDownloadDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
  CFURLDownloadDidReceiveResponseCallback  didReceiveResponse;
  CFURLDownloadWillResumeWithResponseCallback  willResumeWithResponse;
  CFURLDownloadDidReceiveDataCallback  didReceiveData;
  CFURLDownloadShouldDecodeDataOfMIMETypeCallback  shouldDecodeDataOfMIMEType;
  CFURLDownloadDecideDestinationWithSuggestedObjectNameCallback  decideDestinationWithSuggestedObjectName;
  CFURLDownloadDidCreateDestinationCallback  didCreateDestination;
  CFURLDownloadDidFinishCallback  didFinish;
  CFURLDownloadDidFailCallback  didFail;
  CFURLDownloadShouldUseCredentialStorageCallback shouldUseCredentialStorage; /* new for v1 */
};

#define _CFURLDownloadClientV2Present 1
struct CFURLDownloadClient_V2 {
	CFIndex			 version;				/* set to 2 */
	const void *		clientInfo;			 /* this value will be passed in to client callbacks */
	
	CFAllocatorRetainCallBack  retain;		  /* A pointer to the function to call to retain the clientInfo object.  Pass in NULL if no retain is needed */
	CFAllocatorReleaseCallBack  release;		/* A pointer to the function to call to release the clientInfo object.  Pass in NULL if no release is needed */
	CFAllocatorCopyDescriptionCallBack  copyDescription;
	
	CFURLDownloadDidStartCallback  didStart;
	CFURLDownloadWillSendRequestCallback  willSendRequest; /* this callback uses the same ownership policy as the v1 CFURLConnection callback of the same name (i.e. this callback should return a reference to the returned object) */
	CFURLDownloadDidReceiveAuthenticationChallengeCallback  didReceiveAuthenticationChallenge;
	CFURLDownloadDidReceiveResponseCallback  didReceiveResponse;
	CFURLDownloadWillResumeWithResponseCallback  willResumeWithResponse;
	CFURLDownloadDidReceiveDataCallback  didReceiveData;
	CFURLDownloadShouldDecodeDataOfMIMETypeCallback  shouldDecodeDataOfMIMEType;
	CFURLDownloadDecideDestinationWithSuggestedObjectNameCallback  decideDestinationWithSuggestedObjectName;
	CFURLDownloadDidCreateDestinationCallback  didCreateDestination;
	CFURLDownloadDidFinishCallback  didFinish;
	CFURLDownloadDidFailCallback  didFail;
	CFURLDownloadShouldUseCredentialStorageCallback shouldUseCredentialStorage; /* new for v1 */
	CFURLDownloadCanRespondToProtectionSpace canRespondToProtectionSpace;	/* new for v2 */
};

	
typedef struct CFURLDownloadClient_V2	CFURLDownloadClient_V2;
typedef struct CFURLDownloadClient_V1	CFURLDownloadClient_V1;
typedef struct CFURLDownloadClient_V0	CFURLDownloadClient_V0;
typedef struct CFURLDownloadClient_V0	CFURLDownloadClient; // this is for source compatiblity with existing clients...

typedef CFURLDownloadClient_V2			CFURLDownloadClientCurrent;

/*
 *  CFURLDownloadGetTypeID()
 *  
 *  Discussion:
 *	This routine will return the CFTypeID for the CFURLDownload type.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Result:
 *	the CFTypeID for the CFURLDownload type.
 *  
 */
CFN_EXPORT CFTypeID 
CFURLDownloadGetTypeID(void)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCreate()
 *  
 *  Discussion:
 *	This routine will create a CFURLDownload using the provided
 *	CFURLRequest.  The download needs to scheduled using
 *	CFDownloadScheduleWithRunLoop and explicitly started using
 *	CFURLDownloadStart.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The CFAllocator to use.  Pass NULL for the default allocator.
 *	
 *	request:
 *	  A CFURLRequest specifying the source of the download.  This
 *	  request will be used to create a CFURLConnection to get the
 *	  data from.
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
CFURLDownloadCreate(
  CFAllocatorRef		 alloc,
  CFURLRequestRef		request,
  CFURLDownloadClient *  client)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCreateWithResumeData()
 *  
 *  Discussion:
 *	This routine will create a CFURLDownload using the provided
 *	resumeData.  The resume data should have been created from a
 *	previously stopped download using CFURLDownloadCopyResumeData. 
 *	The download needs to scheduled using
 *	CFDownloadScheduleWithRunLoop and explicitly started using
 *	CFURLDownloadStart.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The CFAllocator to use.  Pass NULL for the default allocator.
 *	
 *	resumeData:
 *	  The resumeData returned by an earlier call to
 *	  CFURLDownloadCopyResumeData
 *	
 *	path:
 *	  Path to partially downloaded object to use as the basis for the
 *	  resumed download.
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
CFURLDownloadCreateWithResumeData(
  CFAllocatorRef		 alloc,
  CFDataRef			  resumeData,
  CFURLRef			   path,
  CFURLDownloadClient *  client)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadScheduleWithRunLoop()
 *  
 *  Discussion:
 *	Schedule the given operation on the specified runloop and mode. A
 *	CFURLDownload can be scheduled on multiple runloop/mode
 *	combinations. An opertion must be scheduled on at least one
 *	runloop.  Callbacks will be made on one of the schedule
 *	runloop/modes.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The CFURLDownload to schedule.
 *	
 *	rl:
 *	  The runLoop on which to schedule the operation.  Must be
 *	  non-NULL.
 *	
 *	mode:
 *	  The mode on which to schedule the operation.  Must be non-NULL.
 *  
 */
CFN_EXPORT void 
CFURLDownloadScheduleWithRunLoop(
  CFURLDownloadRef   download,
  CFRunLoopRef	   rl,
  CFStringRef		mode)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadUnscheduleFromRunLoop()
 *  
 *  Discussion:
 *	Unschedule the given operation from the specified runloop and
 *	mode.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The CFURLDownload to unschedule.
 *	
 *	rl:
 *	  The runLoop from which to unschedule the operation.  Must be
 *	  non-NULL.
 *	
 *	mode:
 *	  The mode from which to unschedule the operation.  Must be
 *	  non-NULL.
 *  
 */
CFN_EXPORT void 
CFURLDownloadUnscheduleFromRunLoop(
  CFURLDownloadRef   download,
  CFRunLoopRef	   rl,
  CFStringRef		mode)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadStart()
 *  
 *  Discussion:
 *	Starts an already created and scheduled download operation.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download operation to start.  Must be scheduled on at least
 *	  one runloop.
 *  
 */
CFN_EXPORT void 
CFURLDownloadStart(CFURLDownloadRef download)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCancel()
 *  
 *  Discussion:
 *	Cancels a running download operation.  By default the destination
 *	file will be deleted. If you want to be able to resume the
 *	operation make sure to set deletesUponFailure to false using
 *	CFURLDownloadSetDeletesUponFailure before canceling the download.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download operation to cancel.
 *  
 */
CFN_EXPORT void 
CFURLDownloadCancel(CFURLDownloadRef download)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLDownloadSetDeletesUponFailure()
 *  
 *  Discussion:
 *	Sets a flag that determines if the partially downloaded object
 *	should be deleted if the download fails or is canceled.  The
 *	default value for a new download is true.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to set the value for.
 *	
 *	deletesUponFailure:
 *	  The value to set the flag.  If false then a partially
 *	  downloaded file will be left on disk, which is necessary for
 *	  the resume case.  If true the partially downloaded file will be
 *	  deleted.
 *  
 */
CFN_EXPORT void 
CFURLDownloadSetDeletesUponFailure(
  CFURLDownloadRef   download,
  Boolean			deletesUponFailure)					  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadDeletesUponFailure()
 *  
 *  Discussion:
 *	Returns the current value of the deletesUponFailure flag for the
 *	download.  The default value for a new download is true.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to get the value for.
 *  
 */
CFN_EXPORT Boolean 
CFURLDownloadDeletesUponFailure(CFURLDownloadRef download)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadUseCredential()
 *  
 *  Discussion:
 *	Used to provide credentials for an authentication challenge. 
 *	This is expected to be called from within a
 *	didReceiveAuthenticationChallenge callback.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download operation provide credentials for.
 *	
 *	creds:
 *	  The credentials to use.  Pass NULL to use no credentials.
 *	
 *	challenge:
 *	  The challenge to use the credentials on.
 *  
 */
CFN_EXPORT void 
CFURLDownloadUseCredential(
  CFURLDownloadRef		download,
  CFURLCredentialRef	  creds,		   /* can be NULL */
  CFURLAuthChallengeRef   challenge)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadSetDestination()
 *  
 *  Discussion:
 *	Sets the destination file for the download operation to the
 *	specified path.  The allowOverwrite flag determines if the
 *	operation should delete an object that exists at that path or
 *	fail if an object is already present.  Typically this call is
 *	made from withing the decideDestinationWithSuggestedObjectName
 *	callback, using the suggested object name.  Once a destination is
 *	set future calls on the same download will be ignored.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to set the path for.
 *	
 *	path:
 *	  A CFURL specifying the path for the destination object.  This
 *	  path includes the filename (i.e. is not a parent directory
 *	  path).
 *	
 *	allowOverwrite:
 *	  If true then the download will overwrite an existing object at
 *	  path, otherwise the download will fail if an existing object is
 *	  encountered.
 *  
 */
CFN_EXPORT void 
CFURLDownloadSetDestination(
  CFURLDownloadRef   download,
  CFURLRef		   path,
  Boolean			allowOverwrite)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCopyDestination()
 *  
 *  Discussion:
 *	Returns a CFURL containing the path of the destination object for
 *	the download.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to copy the destination from.
 *  
 *  Result:
 *	A CFURL containing the path of the destination object for this
 *	download.  If the destination has not been determined yet then
 *	NULL will be returned.
 *  
 */
CFN_EXPORT CFURLRef 
CFURLDownloadCopyDestination(CFURLDownloadRef download)	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCopyRequest()
 *  
 *  Discussion:
 *	Returns the CFURLRequest associated with the download.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to copy the request from.
 *  
 */
CFN_EXPORT CFURLRequestRef 
CFURLDownloadCopyRequest(CFURLDownloadRef download)		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCopyResumeData()
 *  
 *  Discussion:
 *	Returns the information necessary to resume a canceled download
 *	in a serialzed form suitable for writing out to persistent
 *	storage.  The resumeData can be used to resume the download by
 *	creating a new CFURLDownload using
 *	CFURLDownloadCreateWithResumeData.  This call should be made
 *	after canceling the download.  The download should have had
 *	deletesUponFailure set to false before the cancel occurs
 *	(otherwise the partially downloaded file will be deleted).
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to copy the resumeData from.
 *  
 */
CFN_EXPORT CFDataRef 
CFURLDownloadCopyResumeData(CFURLDownloadRef download)		__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCanResumeDownloadDecodedWithEncodingMIMEType()
 *  
 *  Discussion:
 *	This routine will return true if a download decoded for the
 *	passed in MIMEType can be resumed.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	MIMEType:
 *	  The MIMEType to check.  If decoding the provided MIMEType is
 *	  unsupported then false will be returned.
 *  
 *  Result:
 *	True if the download could be resumed if the download was decoded
 *	for this MIMEType, false otherwise.
 *  
 */
CFN_EXPORT Boolean 
CFURLDownloadCanResumeDownloadDecodedWithEncodingMIMEType(CFStringRef MIMEType) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  CFURLDownloadCreateWithResumeInformation()
 *  
 *  Discussion:
 *	This routine will create a CFURLDownload using the provided
 *	resumeInformation.  The resume information should have been
 *	created from a previously stopped download using
 *	CFURLDownloadCopyResumeInformation.  The download needs to
 *	scheduled using CFDownloadScheduleWithRunLoop and explicitly
 *	started using CFURLDownloadStart.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The CFAllocator to use.  Pass NULL for the default allocator.
 *	
 *	resumeInformation:
 *	  The resumeInformation returned by an earlier call to
 *	  CFURLDownloadCopyResumeInformation.
 *	
 *	path:
 *	  Path to partially downloaded object to use as the basis for the
 *	  resumed download.
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
CFURLDownloadCreateWithResumeInformation(
  CFAllocatorRef		 alloc,
  CFDictionaryRef		resumeInformation,
  CFURLRef			   path,
  CFURLDownloadClient *  client)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCopyResumeInformation()
 *  
 *  Discussion:
 *	Returns the information necessary to resume a canceled download
 *	in a CFDictionary.  The resumeInformation is not serialized as
 *	resumeData.  The resumeInformation can be used to resume the
 *	download by creating a new CFURLDownload using
 *	CFURLDownloadCreateWithResumeInformation.  This call should be
 *	made after canceling the download.  The download should have had
 *	deletesUponFailure set to false before the cancel occurs
 *	(otherwise the partially downloaded file will be deleted).  This
 *	function is provided for cases where the data does not need to
 *	serialized.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to copy the resumeInformation from.
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFURLDownloadCopyResumeInformation(CFURLDownloadRef download) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLDownloadSetDirectoryPath()
 *  
 *  Discussion:
 *	This sets the parent directory to use for the download
 *	destination file in the absence of an explicit destination (see
 *	CFURLDownloadSetDestination).  The download target will be this
 *	path plus the suggested object name.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to set the directory path for.
 *	
 *	directoryPath:
 *	  A CFURL representing the desired parent directory for the
 *	  download.
 *  
 */
CFN_EXPORT void 
CFURLDownloadSetDirectoryPath(
  CFURLDownloadRef   download,
  CFURLRef		   directoryPath)						   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCopyDirectoryPath()
 *  
 *  Discussion:
 *	Returns the directory path associated with the download or NULL
 *	if one has not been set.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to copy the directory path from.
 *  
 */
CFN_EXPORT CFURLRef 
CFURLDownloadCopyDirectoryPath(CFURLDownloadRef download)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadSetOriginatingURL()
 *  
 *  Discussion:
 *	This sets the originating URL for the download (which by default
 *	if the main document URL from the request associated with the
 *	download). This is the URL that will be set as the originating
 *	URL in the downloaded object's quarantine info (and will be the
 *	url displayed in GateKeeper II warnings).
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to set the directory path for.
 *	
 *	originatingURL:
 *	  A CFURL representing desired origin of the download (from the
 *	  user's perspective).
 *  
 */
CFN_EXPORT void 
CFURLDownloadSetOriginatingURL(
  CFURLDownloadRef   download,
  CFURLRef		   originatingURL)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCopyOriginatingURL()
 *  
 *  Discussion:
 *	Returns the originating URL associated with the download or NULL
 *	if one has not been set.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	download:
 *	  The download to copy the originating url from.
 *  
 */
CFN_EXPORT CFURLRef 
CFURLDownloadCopyOriginatingURL(CFURLDownloadRef download)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadCreateWithDirectoryPath()
 *  
 *  Discussion:
 *	This is equivalent to calling CFURLDownCreate followed by
 *	CFURLDownloadSetDirectoryPath.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT CFURLDownloadRef 
CFURLDownloadCreateWithDirectoryPath(
  CFAllocatorRef		 alloc,
  CFURLRequestRef		request,
  CFURLRef			   directoryPath,
  CFURLDownloadClient *  client)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
   If you want the actual download work to take on a thread other than where the download itself is scheduled, call these.  
   Otherwise, the download will take place wherever the connection itself has been scheduled.
*/
/*
 *  CFURLDownloadScheduleDownloadWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLDownloadScheduleDownloadWithRunLoop(
  CFURLDownloadRef   download,
  CFRunLoopRef	   rl,
  CFStringRef		mode)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLDownloadUnscheduleDownloadFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFURLDownloadUnscheduleDownloadFromRunLoop(
  CFURLDownloadRef   download,
  CFRunLoopRef	   rl,
  CFStringRef		mode)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#if defined(__WIN32__)
/*
 *  CFURLDownloadScheduleWithCurrentMessageQueue()
 *  
 */
CFN_EXPORT void 
CFURLDownloadScheduleWithCurrentMessageQueue(CFURLDownloadRef download) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


#endif

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFURLDOWNLOAD__ */

