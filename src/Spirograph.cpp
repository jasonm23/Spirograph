#include "Spirograph.h"


Vec2f Spirograph::update(const Vec2f &loc)
{
	mAngle += mIncAngle;
	mRadius += mIncRadius;
	
	return Vec2f(loc.x + mRadius * cos(mAngle), loc.y + mRadius * sin(mAngle));
}


//
void SpirographPoint::draw()
{
	for (list<Vec2f>::iterator pointIt = mPoints.begin(); pointIt != mPoints.end(); ++pointIt)
	{
		// Mix colors :p
		glColor4f(cos(pointIt->x), sin(pointIt->y), sin(app::getElapsedSeconds()) * 0.1f, Rand::randFloat());
		
		gl::drawSolidCircle(*pointIt, Rand::randFloat(abs(-(cos(pointIt->x) * Rand::randFloat(mRadius))) / 7.5f));
	}
}

void SpirographPoint::addPoint(ci::Vec2f point)
{
	mPoints.push_back(point);
	
	if (mPoints.size() > mMaxPoints)
		mPoints.erase(mPoints.begin());
}
