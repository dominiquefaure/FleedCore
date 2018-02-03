#ifndef __FLEEDCORE_MATH_MATHS_H__
#define __FLEEDCORE_MATH_MATHS_H__


#include "../Common/Includes.h"

#include <math.h>

namespace FleedCore
{

	struct Maths
	{
		/*
		* return the Abs value of a float number
		*/
		FORCE_INLINE static FFloat32 Abs( FFloat32 a_value );

		/*
		* Get the Cosinus
		*/
		FORCE_INLINE static FFloat32 Cos( FFloat32 a_angle );

		/*
		* Get the Sinu
		*/
		FORCE_INLINE static FFloat32 Sin( FFloat32 a_angle );

		/*
		* Get the Tangent
		*/
		FORCE_INLINE static FFloat32 Tan( FFloat32 a_angle );

	};
}


// The inline is included in the Header only if not in debug mode
#ifndef _DEBUG
#include "Maths.inl"
#endif


#endif