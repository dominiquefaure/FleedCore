#ifndef __FLEEDCORE_MATH_COLOR_H__
#define __FLEEDCORE_MATH_COLOR_H__


#include "../Common/Includes.h"

namespace FleedCore
{

	struct Color
	{
	public:

		/*
		* Default constructor , init to White
		*/
		FORCE_INLINE Color();

		/*
		* Copy constructor
		*/
		FORCE_INLINE Color( const Color& _color );

		/*
		* Create a color from the given parameters
		*/
		FORCE_INLINE Color( FFloat32 a_r , FFloat32 a_g , FFloat32 a_b , FFloat32 a_alpha = 1.0f );

		/*
		* Set the Color components
		*/
		FORCE_INLINE void Set( FFloat32 a_r , FFloat32 a_g , FFloat32 a_b , FFloat32 a_alpha = 1.0f );



	// Fields
	public:

		FFloat32 r;
		FFloat32 g;
		FFloat32 b;
		FFloat32 a;

	};


	// The inline is included in the Header only if not in debug mode
	#ifndef _DEBUG
	#include "Color.inl"
	#endif


}


#endif