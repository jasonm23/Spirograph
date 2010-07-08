#include "cinder/app/AppBasic.h"

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
}

void SpirographApp::update()
{
	mSpirograph->mAngle += 0.02f;
	
	mLoc.x = mSpirograph->mLoc.x + mSpirograph->mRadius * cos(mSpirograph->mAngle);
	mLoc.y = mSpirograph->mLoc.y + mSpirograph->mRadius * sin(mSpirograph->mAngle); // Bottom
	
	// (mSpirograph->mRadius * sin(mSpirograph->mAngle)) * -1; // Top
}

void SpirographApp::draw()
{
	gl::clear(Color(0, 0, 0), true);
	
	
	mSpirograph->addPoint(mLoc);
	mSpirograph->draw();
}


// Start!
CINDER_APP_BASIC(SpirographApp, RendererGl)
