#include "cinder/app/AppBasic.h"

#include "cinder/params/Params.h"

#include "Spirograph.h"

using namespace ci;
using namespace ci::app;
using namespace std;


//
class SpirographApp : public AppBasic
{
	public:
	
	void prepareSettings(Settings *settings);
	
	void setup();
	void update();
	void draw();
	
	void keyDown(KeyEvent event);
	
	
	//
	Vec2f mLoc;
	
	SpirographPoint *mSpirograph;
	
	// Params
	params::InterfaceGl mParams;
	
	float mAngle, mRadius, mIncAngle;
};


//
void SpirographApp::prepareSettings(Settings *settings)
{
	settings->setWindowSize(800, 600);
	settings->setFrameRate(60.0f);
	
	settings->setTitle("SpirographApp");
}

void SpirographApp::setup()
{
	mLoc = Vec2f(getWindowWidth()/2, getWindowHeight()/2);
	
	mSpirograph = new SpirographPoint();
	
	// Base Spirograph parameters
	mAngle = 0.0f;
	mRadius = 65.0f;
	
	mIncAngle = 0.02f;
	
	
	// Setup the parameters
	mParams = params::InterfaceGl("Spirograph Parameters", Vec2i(200, 400));
	
	mParams.addParam("Angle", &mAngle);
	mParams.addParam("Increment Angle", &mIncAngle);
	mParams.addParam("Radius", &mRadius);
	mParams.addSeparator();
	mParams.addParam("Spirograph Angle", &mSpirograph->mAngle);
	mParams.addParam("Spirograph Radius", &mSpirograph->mRadius);
}

void SpirographApp::update()
{
	/*
		mSpirograph->mAngle += 0.02f;
	
		mLoc.x = mSpirograph->mLoc.x + mSpirograph->mRadius * cos(mSpirograph->mAngle);
		mLoc.y = mSpirograph->mLoc.y + mSpirograph->mRadius * sin(mSpirograph->mAngle); // Bottom
		
		// (mSpirograph->mRadius * sin(mSpirograph->mAngle)) * -1; // Top
	*/
	
	mAngle += mIncAngle;
	
	mLoc.x = mSpirograph->mLoc.x + mRadius * sin(mAngle);
	mLoc.y = mSpirograph->mLoc.y + mRadius * cos(mAngle);
	
	
	mSpirograph->addPoint(mSpirograph->update(mLoc));
}

void SpirographApp::draw()
{
	gl::clear(Color(0, 0, 0), true);
	
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	mSpirograph->draw();
	
	glDisable(GL_BLEND);
	
	
	// Draw the interface
	params::InterfaceGl::draw();
}


//
void SpirographApp::keyDown(KeyEvent event)
{
	if (event.getCode() == KeyEvent::KEY_ESCAPE)
		std::exit(0);
}


// Start!
CINDER_APP_BASIC(SpirographApp, RendererGl)
