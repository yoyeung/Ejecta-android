#include "EJBindingCanvas.h"
#include "EJBindingImageData.h"
#include "EJCanvasContextScreen.h"

bool EJBindingCanvas::firstCanvasInstance = true;

EJBindingCanvas::EJBindingCanvas() : renderingContext(0) {
	
	ejectaInstance = EJApp::instance();
	scalingMode = kEJScalingModeFitWidth;
	useRetinaResolution = true;
	msaaEnabled = false;
	msaaSamples = 2;	

	if( firstCanvasInstance ) {
		isScreenCanvas = true;
	}

	width = EJApp::instance()->width;
	height = EJApp::instance()->height;
}

void EJBindingCanvas::init(JSContextRef ctx ,JSObjectRef obj, size_t argc, const JSValueRef argv[]) {
	EJBindingBase::init(ctx, obj, 0, NULL);
	ejectaInstance = EJApp::instance();
	scalingMode = kEJScalingModeFitWidth;
	useRetinaResolution = true;
	msaaEnabled = false;
	msaaSamples = 2;

	if( firstCanvasInstance ) {
		isScreenCanvas = true;
		NSLOG("firstCanvasInstance : %d", firstCanvasInstance);
		firstCanvasInstance = false;
		NSLOG("firstCanvasInstance : %d", firstCanvasInstance);
	}
	
	if( argc == 2 ) {
		width = JSValueToNumberFast(ctx, argv[0]);
		height = JSValueToNumberFast(ctx, argv[1]);
	}
	else {
		//CGSize screen = (EJApp::instance())->view->bounds->size;
		width = EJApp::instance()->width;
		height = EJApp::instance()->height;
	}
}

EJBindingCanvas::EJBindingCanvas(JSContextRef ctx ,JSObjectRef obj, size_t argc, const JSValueRef argv[]) : renderingContext(0) {
	
	ejectaInstance = EJApp::instance();
	scalingMode = kEJScalingModeFitWidth;
	useRetinaResolution = true;
	msaaEnabled = false;
	msaaSamples = 2;

	if( firstCanvasInstance ) {
		isScreenCanvas = true;
		NSLOG("firstCanvasInstance : %d", firstCanvasInstance);
		firstCanvasInstance = false;
		NSLOG("firstCanvasInstance : %d", firstCanvasInstance);
	}
	
	if( argc == 2 ) {
		width = JSValueToNumberFast(ctx, argv[0]);
		height = JSValueToNumberFast(ctx, argv[1]);
	}
	else {
		width = EJApp::instance()->width;
		height = EJApp::instance()->height;
	}
}

EJBindingCanvas::~EJBindingCanvas() {
	renderingContext->release();
}

EJTexture* EJBindingCanvas::texture() {
	if (renderingContext->getClassName() == "EJCanvasContextTexture") {
		return ((EJCanvasContextTexture *)renderingContext)->m_texture;
	}
	else {
		return NULL;
	}
}

EJ_BIND_ENUM( EJBindingCanvas, globalCompositeOperation, EJCompositeOperation, renderingContext->globalCompositeOperation);
EJ_BIND_ENUM( EJBindingCanvas, lineCap, EJLineCap, renderingContext->state->lineCap);
EJ_BIND_ENUM( EJBindingCanvas, lineJoin, EJLineJoin, renderingContext->state->lineJoin);
EJ_BIND_ENUM( EJBindingCanvas, textAlign, EJTextAlign, renderingContext->state->textAlign);
EJ_BIND_ENUM( EJBindingCanvas, textBaseline, EJTextBaseline, renderingContext->state->textBaseline);
EJ_BIND_ENUM( EJBindingCanvas, scalingMode, EJScalingMode, scalingMode);

EJ_BIND_GET( EJBindingCanvas, fillStyle, ctx ) {
	return ColorRGBAToJSValue(ctx, renderingContext->state->fillColor);
}

EJ_BIND_SET( EJBindingCanvas, fillStyle, ctx, value) {
	renderingContext->state->fillColor = JSValueToColorRGBA(ctx, value);
}

EJ_BIND_GET( EJBindingCanvas, strokeStyle, ctx ) {
	return ColorRGBAToJSValue(ctx, renderingContext->state->strokeColor);
}

EJ_BIND_SET( EJBindingCanvas, strokeStyle, ctx, value) {
	renderingContext->state->strokeColor = JSValueToColorRGBA(ctx, value);
}

EJ_BIND_GET( EJBindingCanvas, globalAlpha, ctx ) {
	return JSValueMakeNumber(ctx, renderingContext->state->globalAlpha );
}

EJ_BIND_SET( EJBindingCanvas, globalAlpha, ctx, value) {
	renderingContext->state->globalAlpha = MIN(1,MAX(JSValueToNumberFast(ctx, value),0));
}

EJ_BIND_GET( EJBindingCanvas, lineWidth, ctx) {
	return JSValueMakeNumber(ctx, renderingContext->state->lineWidth);
}

EJ_BIND_SET( EJBindingCanvas, lineWidth, ctx, value) {
	renderingContext->state->lineWidth = JSValueToNumberFast(ctx, value);
}

EJ_BIND_GET( EJBindingCanvas, miterLimit, ctx) {
	return JSValueMakeNumber(ctx, renderingContext->state->miterLimit);
}

EJ_BIND_SET( EJBindingCanvas, miterLimit, ctx, value) {
	renderingContext->state->miterLimit = JSValueToNumberFast(ctx, value);
}

//
EJ_BIND_GET(EJBindingCanvas, offsetLeft, ctx) {
	return JSValueMakeNumber(ctx, 0);
}

EJ_BIND_GET(EJBindingCanvas, offsetTop, ctx) {
	return JSValueMakeNumber(ctx, 0);
}

EJ_BIND_SET(EJBindingCanvas, retinaResolutionEnabled, ctx, value) {
	useRetinaResolution = JSValueToBoolean(ctx, value);
}

EJ_BIND_GET(EJBindingCanvas, retinaResolutionEnabled, ctx) {
	return JSValueMakeBoolean(ctx, useRetinaResolution);
}

EJ_BIND_SET(EJBindingCanvas, imageSmoothingEnabled, ctx, value) {
	ejectaInstance->currentRenderingContext = renderingContext;
	renderingContext->imageSmoothingEnabled = JSValueToBoolean(ctx, value);
}

EJ_BIND_GET(EJBindingCanvas, imageSmoothingEnabled, ctx) {
	return JSValueMakeBoolean(ctx, renderingContext->imageSmoothingEnabled);
}

EJ_BIND_GET(EJBindingCanvas, backingStorePixelRatio, ctx) {
	return JSValueMakeNumber(ctx, renderingContext->backingStoreRatio);
}

EJ_BIND_SET(EJBindingCanvas, MSAAEnabled, ctx, value) {
	msaaEnabled = JSValueToBoolean(ctx, value);
}

EJ_BIND_GET(EJBindingCanvas, MSAAEnabled, ctx) {
	return JSValueMakeBoolean(ctx, msaaEnabled);
}

EJ_BIND_SET(EJBindingCanvas, MSAASamples, ctx, value) {
	int samples = JSValueToNumberFast(ctx, value);
	if( samples == 2 || samples == 4 ) {
		msaaSamples	= samples;
	}
}

EJ_BIND_GET(EJBindingCanvas, MSAASamples, ctx) {
	return JSValueMakeNumber(ctx, msaaSamples);
}
//

EJ_BIND_FUNCTION( EJBindingCanvas, getContext, ctx, argc, argv) {

	NSLOG("Canvas.getContext('2d'), firstCanvasInstance %d, isScreenCanvas : %d", firstCanvasInstance, isScreenCanvas);

	if( argc < 1 || !JSValueToNSString(ctx, argv[0])->isEqual(NSStringMake("2d")) ) { 
		return NULL; 
	};
	
	if( renderingContext ) { return jsObject; }
	ejectaInstance->currentRenderingContext = NULL;
	if( isScreenCanvas ) {
		NSLOG("get Screen Canvas Context");
		EJCanvasContextScreen * sc = new EJCanvasContextScreen(width, height);
		sc->useRetinaResolution = useRetinaResolution;
		sc->scalingMode = scalingMode;
		
		ejectaInstance->screenRenderingContext = sc;		
		renderingContext = (EJCanvasContext*)sc;
	}
	else {
		NSLOG("get Texture Canvas Context");
		renderingContext = (EJCanvasContext*)(new EJCanvasContextTexture(width, height));
	}
	
	renderingContext->msaaEnabled = msaaEnabled;
	renderingContext->msaaSamples = msaaSamples;
	
	renderingContext->create();
	ejectaInstance->currentRenderingContext = renderingContext;

	// Context and canvas are one and the same object, so getContext just
	// returns itself
	return jsObject;
}

EJ_BIND_FUNCTION(EJBindingCanvas, drawImage, ctx, argc, argv) {
	if( argc < 3 || !JSValueIsObject(ctx, argv[0]) ) return NULL;
	
	EJBindingImage* drawable = (EJBindingImage*)JSObjectGetPrivate((JSObjectRef)argv[0]);
	// NSObject<EJDrawable> * drawable = (NSObject<EJDrawable> *)JSObjectGetPrivate((JSObjectRef)argv[0]);
	EJTexture * image = drawable->texture;
	float scale = image->contentScale;
	
	short sx = 0, sy = 0, sw = 0, sh = 0;
	float dx = 0, dy = 0, dw = sw, dh = sh;	
	
	if( argc == 3 ) {
		// drawImage(image, dx, dy)
		dx = JSValueToNumberFast(ctx, argv[1]);
		dy = JSValueToNumberFast(ctx, argv[2]);
		sw = image->width;
		sh = image->height;
		dw = sw / scale;
		dh = sh / scale;
	}
	else if( argc == 5 ) {
		// drawImage(image, dx, dy, dw, dh)
		dx = JSValueToNumberFast(ctx, argv[1]);
		dy = JSValueToNumberFast(ctx, argv[2]);
		dw = JSValueToNumberFast(ctx, argv[3]);
		dh = JSValueToNumberFast(ctx, argv[4]);
		sw = image->width;
		sh = image->height;
	}
	else if( argc >= 9 ) {
		// drawImage(image, sx, sy, sw, sh, dx, dy, dw, dh)
		sx = JSValueToNumberFast(ctx, argv[1]) * scale;
		sy = JSValueToNumberFast(ctx, argv[2]) * scale;
		sw = JSValueToNumberFast(ctx, argv[3]) * scale;
		sh = JSValueToNumberFast(ctx, argv[4]) * scale;
		
		dx = JSValueToNumberFast(ctx, argv[5]);
		dy = JSValueToNumberFast(ctx, argv[6]);
		dw = JSValueToNumberFast(ctx, argv[7]);
		dh = JSValueToNumberFast(ctx, argv[8]);
	}
	else {
		return NULL;
	}
	
	ejectaInstance->currentRenderingContext = renderingContext;
	renderingContext->drawImage(image, sx, sy, sw, sh, dx, dy, dw, dh);
	// [renderingContext drawImage:image sx:sx sy:sy sw:sw sh:sh dx:dx dy:dy dw:dw dh:dh];
	
	return NULL;
}


REFECTION_CLASS_IMPLEMENT(EJBindingCanvas);