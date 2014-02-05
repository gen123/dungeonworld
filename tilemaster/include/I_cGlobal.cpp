#include "I_cGlobal.h"
#include  <math.h>
#include <SDL_Image.h>


I_cGlobal *gData;





I_cGlobal::I_cGlobal()
{
 showDebugText_ = false;
}

I_cGlobal::~I_cGlobal()
{
}




void I_cGlobal::SetCurrentDir(string dir)
{
 currentDir_ = dir;
}




int I_cGlobal::nextpoweroftwo(int x)
{
	double logbase2 = log((double)x) / log((double)2);
	return round(pow((double)2,ceil(logbase2)));
	

}




int I_cGlobal::round(double x)
{
	return (int)(x + 0.5);
}



