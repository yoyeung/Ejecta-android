#include <GLES/gl.h>
#include <GLES/glext.h>
#include "EJCanvasContextTexture.h"

void EJCanvasContextTexture::create() 
{
	NSLOG("EJCanvasContextTexture create");
	m_texture = new EJTexture(width, height);

	bufferWidth = m_texture->realWidth;
	bufferHeight = m_texture->realHeight;

	EJCanvasContext::create();
	glFramebufferTexture2DOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, m_texture->textureId, 0);
	prepare();

	glClearColor(0.0f, 0.0f, 1.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);
}

EJCanvasContextTexture::EJCanvasContextTexture() 
{

}

EJCanvasContextTexture::EJCanvasContextTexture(short widthp, short heightp) : EJCanvasContext( widthp, heightp)
{

}

EJCanvasContextTexture::~EJCanvasContextTexture() 
{
	m_texture->release();
}

const char* EJCanvasContextTexture::getClassName() 
{
	return "EJCanvasContextTexture";
}

EJTexture* EJCanvasContextTexture::texture() 
{
	if( msaaNeedsResolving ) {	
		GLint boundFrameBuffer;
		glGetIntegerv( GL_FRAMEBUFFER_BINDING_OES, &boundFrameBuffer );
		
		/*
			Android上不支持多重采样
		**/

		//Bind the MSAA and View frameBuffers and resolve
		// glBindFramebufferOES(GL_FRAMEBUFFER_OES, msaaFrameBuffer);
		// glBindFramebufferOES(GL_DRAW_FRAMEBUFFER_APPLE, viewFrameBuffer);
		// glResolveMultisampleFramebufferAPPLE();
		
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, boundFrameBuffer);
		
		msaaNeedsResolving = false;
	}
	
	return m_texture;
}

void EJCanvasContextTexture::prepare() {

	NSLOG("EJCanvasContextTexture prepare");
	
	EJCanvasContext::prepare();
	msaaNeedsResolving = msaaEnabled;
}