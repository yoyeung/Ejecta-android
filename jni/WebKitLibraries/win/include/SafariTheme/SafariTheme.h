/*
 * Copyright (c) 2007, 2008 Apple Inc.
 * All rights reserved.
 *
 */

#ifndef SafariTheme_h
#define SafariTheme_h

#include "SafariThemeConstants.h"

#ifdef SAFARITHEME_EXPORTS
#define ST_EXTERN extern "C" __declspec(dllexport)
#else
#define ST_EXTERN extern "C" __declspec(dllimport)
#endif

ST_EXTERN void APIENTRY STInitialize();
ST_EXTERN void APIENTRY STPaintThemePart(SafariTheme::ThemePart, CGContextRef, const CGRect&, SafariTheme::ThemeControlSize, SafariTheme::ThemeControlState);
ST_EXTERN void APIENTRY STPaintScrollBar(CGContextRef, const CGRect&, SafariTheme::ThemeControlSize, SafariTheme::ThemeControlState, SafariTheme::ScrollBarPiece pressedPiece, bool vertical, float value, float thumbProportion, SafariTheme::ScrollBarPieceMask piecesToPaint);
ST_EXTERN void APIENTRY STPaintWindowFrame(CGContextRef context, const CGRect& rect, SafariTheme::ThemeControlState state, int topBarHeight, int bottomBarHeight, bool topBarBorder, bool bottomBarBorder);
ST_EXTERN void APIENTRY STPaintProgressIndicator(SafariTheme::ProgressIndicatorType, CGContextRef, const CGRect&, SafariTheme::ThemeControlSize, SafariTheme::ThemeControlState, float value);
ST_EXTERN void APIENTRY STPaintSegmentedControl(SafariTheme::SegmentedControlType, CGContextRef, const CGRect&, SafariTheme::ThemeControlSize, unsigned segmentCount, const SafariTheme::ThemeControlState* states, const SafariTheme::ThemeControlSubType* subTypes, const SafariTheme::ThemeImage* images);
ST_EXTERN void APIENTRY STPaintSegmentedControlImage(SafariTheme::SegmentedControlType, CGContextRef, const CGRect&, SafariTheme::ThemeControlSize, unsigned segmentIndex, unsigned segmentCount, const SafariTheme::ThemeControlState, const SafariTheme::ThemeControlSubType, const SafariTheme::ThemeImage, CGColorRef);
ST_EXTERN CGColorRef APIENTRY STCopyThemeColor(SafariTheme::ThemeColor, SafariTheme::ThemeControlState);
ST_EXTERN void APIENTRY STGetPartDimensions(SafariTheme::ThemePart, const CGRect&, SafariTheme::ThemeControlSize, CGSize* outSize);

#endif
