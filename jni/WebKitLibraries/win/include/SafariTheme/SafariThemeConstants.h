/*
 * Copyright (c) 2008 Apple Inc.
 * All rights reserved.
 *
 */

#ifndef SafariThemeConstants_h
#define SafariThemeConstants_h

#define SAFARI_THEME_VERSION 4

#ifdef DEBUG_ALL
#define SAFARITHEMEDLL L"SafariTheme_debug.dll"
#else
#define SAFARITHEMEDLL L"SafariTheme.dll"
#endif

typedef struct CGContext* CGContextRef;
typedef struct CGColor* CGColorRef;
struct CGRect;
struct CGSize;

namespace SafariTheme {
enum ThemePart {
    TextFieldPart = 0,
    TextAreaPart = 1,
    PushButtonPart = 2,
    SquareButtonPart = 3,
    PlasticButtonPart = 4,
    SearchFieldPart = 5,
    SearchFieldCancelButtonPart = 6,
    SearchFieldResultsDecorationPart = 7,
    SearchFieldResultsButtonPart = 8,
    ScrollUpArrowPart = 9,
    ScrollDownArrowPart = 10,
    ScrollLeftArrowPart = 11,
    ScrollRightArrowPart = 12,
    VScrollThumbPart = 13,
    HScrollThumbPart = 14,
    VScrollTrackPart = 15,
    HScrollTrackPart = 16,
    SliderThumbPart = 17,
    PopUpButtonPart = 18,
    DropDownButtonPart = 19,
    CheckboxPart = 20,
    RadioButtonPart = 21,
    ListHeaderPart = 22,
    MinimizeWindowButtonPart = 23,
    MaximizeWindowButtonPart = 24,
    RestoreWindowButtonPart = 25,
    CloseWindowButtonPart = 26,
    HelpButtonPart = 27,
    ScopeButtonPart = 28,
    ScopeBarBackgroundPart = 29,
    ChevronPart = 30,
    BookmarksIconPart = 31,
    ToolbarItemWellPart = 32,
    MenuItemPart = 33,
    DividerSplitterPart = 34,
    SideBarSelectionPart = 35,
    CapsLockPart = 36,
    HDividerSeparatorPart = 37,
    PopUpButtonArrowsPart = 38,
    MediaFullscreenButtonPart = 39,
    MediaMuteButtonPart = 40,
    MediaPauseButtonPart = 41,
    MediaPlayButtonPart = 42,
    MediaSeekBackButtonPart = 43,
    MediaSeekForwardButtonPart = 44,
    MediaSliderThumbPart = 45,
    MediaUnMuteButtonPart = 46,
    LocationFieldWithButtonPart = 47,
    LocationFieldPart = 48,
    MediaShowClosedCaptionsButtonPart = 49,
    MediaHideClosedCaptionsButtonPart = 50,
    ThemePartSentinel
};

typedef unsigned ThemeControlState;

enum ThemeControlStateMask {
    ActiveState = 1,
    PressedState = 1 << 1,
    EnabledState = 1 << 2,
    DefaultState = 1 << 3,
    CheckedState = 1 << 4,
    IndeterminateCheckedState = 1 << 5,
    FocusedState = 1 << 6,
    HoveredState = 1 << 7,
    DraggedState = 1 << 8,
    SelectedState = 1 << 9,
};

enum ThemeControlSubType {
    RegularControl = 0,
    DropDownControl = 1,
};

enum ThemeControlSize {
    RegularControlSize = 0,
    SmallControlSize = 1,
    MiniControlSize = 2,
    LargeControlSize = 3,
};

enum ScrollBarPiece {
    NoScrollPiece = 0,
    BackButtonPiece = 1 << 0,
    BackTrackPiece = 1 << 1,
    ThumbPiece = 1 << 2,
    ForwardTrackPiece = 1 << 3,
    ForwardButtonPiece = 1 << 4,
    AllPieces = 0xffffffff,
};

typedef unsigned ScrollBarPieceMask;

enum ThemeColor {
    EtchedTextTopColor = 0,
    EtchedTextBottomColor = 1,
    BoldEtchedTextTopColor = 2,
    BoldEtchedTextBottomColor = 3,
    FocusRingColor = 4,
};

enum ProgressIndicatorType {
    NormalBarType = 0,
    IndeterminateBarType = 1,
    SpinnerType = 2,
    MediaType = 3,
};

enum SegmentedControlType {
    InsetType = 0,
    TexturedType = 1,
};

enum ThemeImageNeedsShadow {
    DoesNotNeedShadow = 0,
    NeedsShadow = 1,
};

enum ThemeImageType {
    NoImageType = 0,
    NamedImageType = 1,
    PathImageType = 2,
};

enum ThemeImageName {
    AddBookmarkImage = 1,
    AddImage = 2,
    AutoFillImage = 3,
    BackImage = 4,
    ForwardImage = 5,
    HomeImage = 6,
    MakeTextBiggerImage = 7,
    MakeTextSmallerImage = 8,
    PrintImage = 9,
    ReloadImage = 10,
    ReportBugImage = 11,
    StopImage = 12,
    ToolsImage = 13,
};

// type specifies the type of image. If the type is NamedImageType, the name
// field must be filled. If the type is PathImageType, the utf8Path field must
// be filled. If the type is NoImageType, no other fields must be filled.
// utf8Path is a null-terminated filesystem path to the image encoded in UTF-8.
// Its memory is owned by the caller.
// needsShadow indicates that the image does not have a built-in shadow
// underneath and needs one in order to fit in with the engraved look.
struct ThemeImage {
    ThemeImageType type;
    ThemeImageName name;
    const char* utf8Path;
    ThemeImageNeedsShadow needsShadow;
};

// These declarations are deprecated. Clients should be using ThemeControlSize instead.
typedef ThemeControlSize NSControlSize;
#define NSRegularControlSize RegularControlSize
#define NSSmallControlSize SmallControlSize
#define NSMiniControlSize MiniControlSize

// This declaration is deprecated. Clients should be using STPaintThemePart instead.
typedef void (__stdcall*paintThemePartPtr)(ThemePart, CGContextRef, const CGRect&, NSControlSize, ThemeControlState);
}

#endif
