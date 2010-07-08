#include "Spirograph.h"


void SpirographPoint::draw()
{
	for (list<Vec2f>::iterator pointIt = mPoints.begin(); pointIt != mPoints.end(); ++pointIt)
		gl::drawSolidCircle(*pointIt, 5.0f);
}
	
void SpirographPoint::addPoint(ci::Vec2f point)
{
	mPoints.push_back(point);
	
	if ((int)mPoints.size() > mMaxPoints)
		mPoints.erase(mPoints.begin());
}
