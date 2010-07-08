#include "cinder/app/AppBasic.h"

#include "cinder/Rand.h"

#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;


// Spirograph data structure
class Spirograph
{
	public:
	
	Spirograph()
		: mAngle(0.0f), mRadius(60.0f), mLoc(Vec2f(getWindowWidth()/2, getWindowHeight()/2)) {}
	
	float mAngle, mRadius;
	
	// Initial Spirograph location
	Vec2f mLoc;
};


// This will maintain a list of points which we will Spirograph line
class SpirographPoint : public Spirograph
{
	public:
	
	SpirographPoint()
		: mMaxPoints(Rand::randInt(250, 500)) {}
	
	void draw();
	
	void addPoint(ci::Vec2f point);
	
	
	//
	int mMaxPoints;
	
	list<Vec2f> mPoints;
};
