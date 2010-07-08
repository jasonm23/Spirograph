#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;


//
class Spirograph
{
	public:
	
	Spirograph(float angle, float radius)
		: mAngle(angle), mRadius(radius), mLoc(Vec2f(getWindowWidth()/2, getWindowHeight()/2)) {}	
	
	float mAngle, mRadius;
	
	// Initial Spirograph location
	Vec2f mLoc;
};


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
	
	Spirograph *mSpirograph;
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
	
	mSpirograph = new Spirograph(0.0f, 60.0f);
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
	
	gl::drawSolidCircle(mLoc, 5.0f);
}

// Start!
CINDER_APP_BASIC(SpirographApp, RendererGl)
