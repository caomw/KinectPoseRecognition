#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ip/Resize.h"

//#define kinectInUse
//#define   recording		true

#define debug		


class Params
{
	public:	

		static float	boxMaxErrorX;//50
		static float	boxMaxErrorY;
		static float	maxErrorBetweenJoints;//1000
		static float	percentForMatching;
		static bool		recording;

		static float	comeBackHomeTime;
};