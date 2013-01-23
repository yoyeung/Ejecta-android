#ifndef __EJ_BINDING_CANVAS_H__
#define __EJ_BINDING_CANVAS_H__

#include "EJBindingBase.h"
#include "EJCanvasContextTexture.h"
#include "EJCanvasContextScreen.h"
#include "EJTexture.h"
#include "EJBindingImage.h"

static const char * EJLineCapNames[] = {
	"butt",
	"round",
	"square"
};

static const char * EJLineJoinNames[] = {
	"miter",
	"bevel",
	"round"
};

static const char * EJTextBaselineNames[] = {
	"alphabetic",
	"middle",
	"top",
	"hanging",
	"bottom",
	"ideographic"
};

static const char * EJTextAlignNames[] = {
	"start",
	"end",
	"left",
	"center",
	"right"
};

static const char * EJCompositeOperationNames[] = {
	"source-over",
	"lighter",
	"darker",
	"destination-out",
	"destination-over",
	"source-atop",
	"xor"
};

static const char * EJScalingModeNames[] = {
	"none",
	"fit-width",
	"fit-height"
};

class EJBindingCanvas : public EJBindingBase{
private:
	EJCanvasContext * renderingContext;
	EJApp * ejectaInstance;
	short width, height;
	
	bool isScreenCanvas;
	bool useRetinaResolution;
	EJScalingMode scalingMode;
	
	bool msaaEnabled;
	int msaaSamples;

	static bool firstCanvasInstance;
public:
	EJBindingCanvas(JSContextRef ctx ,JSObjectRef obj, size_t argc, const JSValueRef argv[]);
	EJBindingCanvas();
	~EJBindingCanvas();
	REFECTION_CLASS_IMPLEMENT_DEFINE(EJBindingCanvas);

	virtual string superclass(){return EJBindingBase::toString();};

	EJTexture* m_texture;
	EJTexture* texture();

	virtual void init(JSContextRef ctx ,JSObjectRef obj, size_t argc, const JSValueRef argv[]);

	EJ_BIND_ENUM_DEFINE( globalCompositeOperation, EJCompositeOperation, renderingContext->globalCompositeOperation);
	EJ_BIND_ENUM_DEFINE( lineCap, EJLineCap, renderingContext->state->lineCap);
	EJ_BIND_ENUM_DEFINE( lineJoin, EJLineJoin, renderingContext->state->lineJoin);
	EJ_BIND_ENUM_DEFINE( textAlign, EJTextAlign, renderingContext->state->textAlign);
	EJ_BIND_ENUM_DEFINE( textBaseline, EJTextBaseline, renderingContext->state->textBaseline);
	EJ_BIND_ENUM_DEFINE( scalingMode, EJScalingMode, scalingMode);

	EJ_BIND_GET_DEFINE( fillStyle, ctx );
	EJ_BIND_SET_DEFINE( fillStyle, ctx, value);
	EJ_BIND_GET_DEFINE( strokeStyle, ctx );
	EJ_BIND_SET_DEFINE( strokeStyle, ctx, value);
	EJ_BIND_GET_DEFINE( globalAlpha, ctx );
	EJ_BIND_SET_DEFINE( globalAlpha, ctx, value);
	EJ_BIND_GET_DEFINE( lineWidth, ctx);
	EJ_BIND_SET_DEFINE( lineWidth, ctx, value);
	EJ_BIND_GET_DEFINE( miterLimit, ctx);
	EJ_BIND_SET_DEFINE( miterLimit, ctx, value);

	EJ_BIND_GET_DEFINE(offsetLeft, ctx);
	EJ_BIND_GET_DEFINE(offsetTop, ctx);
	EJ_BIND_SET_DEFINE(retinaResolutionEnabled, ctx, value);
	EJ_BIND_GET_DEFINE(retinaResolutionEnabled, ctx);
	EJ_BIND_SET_DEFINE(imageSmoothingEnabled, ctx, value);
	EJ_BIND_GET_DEFINE(imageSmoothingEnabled, ctx);
	EJ_BIND_GET_DEFINE(backingStorePixelRatio, ctx);
	EJ_BIND_SET_DEFINE(MSAAEnabled, ctx, value);
	EJ_BIND_GET_DEFINE(MSAAEnabled, ctx);
	EJ_BIND_SET_DEFINE(MSAASamples, ctx, value);
	EJ_BIND_GET_DEFINE(MSAASamples, ctx);

	EJ_BIND_FUNCTION_DEFINE( getContext, ctx, argc, argv);
	EJ_BIND_FUNCTION_DEFINE(drawImage, ctx, argc, argv);
};

#endif //__EJ_BINDING_CANVAS_H__