#include "cinder/app/AppBasic.h"
#include <list>
using namespace ci;
using namespace ci::app;
using namespace std;


class SpirographApp : public AppBasic
{
	public:
};


void SpirographApp::draw()
{
	gl::clear( Color( 0.1f, 0.1f, 0.1f ) );

}

// Start!
CINDER_APP_BASIC(SpirographApp, RendererGl)
