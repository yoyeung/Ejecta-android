/*
 *  WebKitQuartzCoreAdditionsBase.h
 *  WebKitQuartzCoreAdditions
 *
 *  Created by Adam Roben on 1/5/11.
 *  Copyright 2011 Apple Inc. All rights reserved.
 *
 */

#ifndef WebKitQuartzCoreAdditionsBase_h
#define WebKitQuartzCoreAdditionsBase_h

#ifndef WKQCA_EXPORT
#ifdef BUILDING_WKQCA
#define WKQCA_EXPORT __declspec(dllexport)
#else
#define WKQCA_EXPORT __declspec(dllimport)
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _WKCACFImage* WKCACFImageRef;
typedef struct _WKCACFView* WKCACFViewRef;

/* Releases internal resources. Useful in combination with the debug Direct3D runtime's "Break on
   Memory Leaks" feature. Must only be called after all WKCACFViews have been destroyed. */
WKQCA_EXPORT void WKCACFShutDown(void);

#ifdef __cplusplus
}
#endif

#endif // WebKitQuartzCoreAdditionsBase_h
