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
	
	
	//
	Vec2f mLoc;
	
	SpirographPoint *mSpirograph;
	
	// Params
	params::InterfaceGl mParams;
	
	float mAngle, mRadius;
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
	
	// Spirograph default parameters
	mAngle = mSpirograph->mAngle;
	mRadius = mSpirograph->mRadius;
	
	
	// Setup the parameters
	mParams = params::InterfaceGl("Spirograph Parameters", Vec2i(200, 400));
	
	mParams.addParam("Angle", &mAngle);
	mParams.addParam("Radius", &mRadius);
}

void SpirographApp::update()
{
	/*
		mSpirograph->mAngle += 0.02f;
	
		mLoc.x = mSpirograph->mLoc.x + mSpirograph->mRadius * cos(mSpirograph->mAngle);
		mLoc.y = mSpirograph->mLoc.y + mSpirograph->mRadius * sin(mSpirograph->mAngle); // Bottom
		
		// (mSpirograph->mRadius * sin(mSpirograph->mAngle)) * -1; // Top
	*/
	
	mAngle += 0.02;
	
	mLoc.x = mSpirograph->mLoc.x + mRadius * cos(mAngle);
	mLoc.y = mSpirograph->mLoc.y + mRadius * sin(mAngle);
	
	
	mSpirograph->addPoint(mLoc);
}

void SpirographApp::draw()
{
	gl::clear(Color(0, 0, 0), true);
	
	
	mSpirograph->draw();
	
	
	// Draw the interface
	params::InterfaceGl::draw();
}


// Start!
CINDER_APP_BASIC(SpirographApp, RendererGl)
