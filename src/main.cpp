#include "ofMain.h"
#include "testApp.h"
#include "ofGLProgrammableRenderer.h"

//========================================================================
int main( ){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
	ofSetupOpenGL(640, 480, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp( new testApp());

}
