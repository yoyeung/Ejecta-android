/*
 *  WKCACFView.h
 *  WebKitQuartzCoreAdditions
 *
 *  Created by Adam Roben on 1/5/11.
 *  Copyright 2011 Apple Inc. All rights reserved.
 *
 */

#ifndef WKCACFView_h
#define WKCACFView_h

#include <QuartzCore/CoreAnimationCF.h>
#include <WebKitQuartzCoreAdditions/WebKitQuartzCoreAdditionsBase.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WKQCA_DEFINED_WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>

#ifdef WKQCA_DEFINED_WIN32_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Returns the type identifier of all WKCACFView instances. */
WKQCA_EXPORT CFTypeID WKCACFViewGetTypeID(void);

enum WKCACFViewDrawingDestination {
    /* Drawing is done directly into the window passed to WKCACFViewUpdate. Drawing occurs
     * automatically and asynchronously after WKCACFViewFlushContext is called. Synchronous drawing
     * can be achieved by calling WKCACFViewDraw. */
    kWKCACFViewDrawingDestinationWindow = 0,

    /* Drawing is done to an image in system memory. Drawing is manually driven by the caller via
     * the WKCACFViewCopyDrawnImage API. The window passed to WKCACFViewUpdate is still used by
     * Direct3D for message processing, but is not drawn into. */
    kWKCACFViewDrawingDestinationImage,
};
typedef enum WKCACFViewDrawingDestination WKCACFViewDrawingDestination;

/* Creates a new view object. */
WKQCA_EXPORT WKCACFViewRef WKCACFViewCreate(WKCACFViewDrawingDestination destination);

/* Sets the root layer being displayed by the view. */
WKQCA_EXPORT void WKCACFViewSetLayer(WKCACFViewRef view, CACFLayerRef layer);

/* Sets the window associated with the view. The passed-in bounds
 * should match the window's client rect. */
WKQCA_EXPORT void WKCACFViewUpdate(WKCACFViewRef view, HWND window, const CGRect* bounds);

/* Commit all changes made to view and the layer tree it references to
 * the render tree (i.e. to the screen). This function must be called
 * after modifying any layer properties or adding any animations to
 * have their effect be seen. */
WKQCA_EXPORT void WKCACFViewFlushContext(WKCACFViewRef view);

/* Invalidates a region of the view, i.e. causes it to be redrawn the next
 * time the view redraws anything. */
WKQCA_EXPORT void WKCACFViewInvalidateRects(WKCACFViewRef view, const CGRect rects[], size_t count);

/* Returns true if it is possible for this view to draw into the window
 * at this time. This can return false if, e.g., the system does not
 * meet CoreAnimation's hardware requirements. */
WKQCA_EXPORT bool WKCACFViewCanDraw(WKCACFViewRef view);

/* Renders the current region needing updating into the view's window. May only be called when the
 * view was created with kWKCACFViewDrawingDestinationWindow. */
WKQCA_EXPORT void WKCACFViewDraw(WKCACFViewRef view);

/* Renders the current region needing updating and returns it as an image. imageOrigin specifies
 * the location within the view to which the image corresponds, relative to the bottom-left. May
 * only be called when the view was created with kWKCACFViewDrawingDestinationImage. */
WKQCA_EXPORT WKCACFImageRef WKCACFViewCopyDrawnImage(WKCACFViewRef view, CGPoint* imageOrigin, CFTimeInterval* nextDrawTime);

/* Renders the entire view into the device context. */
WKQCA_EXPORT void WKCACFViewDrawIntoDC(WKCACFViewRef view, HDC dc);

/* Sets a function to be called whenever the view's root layer has changed and needs to be redrawn. */
typedef void (*WKCACFViewContextDidChangeCallback)(WKCACFViewRef view, void* info);
WKQCA_EXPORT void WKCACFViewSetContextDidChangeCallback(WKCACFViewRef view, WKCACFViewContextDidChangeCallback callback, void* info);

/* Returns the default beginTime of animations added as part of the
 * previous transaction (i.e. the previous call to WKCACFViewFlushContext). */
WKQCA_EXPORT CFTimeInterval WKCACFViewGetLastCommitTime(WKCACFViewRef view);

/* Allows for an arbitrary pointer to be associated with the view's context. */
WKQCA_EXPORT void WKCACFViewSetContextUserData(WKCACFViewRef view, void* userData);

#ifdef __cplusplus
}
#endif

#endif // WKCAView_h
