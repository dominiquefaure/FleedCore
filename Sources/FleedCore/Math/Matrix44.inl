
#include "Matrix44.h"
#include "MathMacros.h"

namespace FleedCore
{
	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44::Matrix44()
	{
		M[ 0 ][ 0 ]											=	0.0f;
		M[ 0 ][ 1 ]											=	0.0f;
		M[ 0 ][ 2 ]											=	0.0f;
		M[ 0 ][ 3 ]											=	0.0f;

		M[ 1 ][ 0 ]											=	0.0f;
		M[ 1 ][ 1 ]											=	0.0f;
		M[ 1 ][ 2 ]											=	0.0f;
		M[ 1 ][ 3 ]											=	0.0f;

		M[ 2 ][ 0 ]											=	0.0f;
		M[ 2 ][ 1 ]											=	0.0f;
		M[ 2 ][ 2 ]											=	0.0f;
		M[ 2 ][ 3 ]											=	0.0f;

		M[ 3 ][ 0 ]											=	0.0f;
		M[ 3 ][ 1 ]											=	0.0f;
		M[ 3 ][ 2 ]											=	0.0f;
		M[ 3 ][ 3 ]											=	0.0f;

	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44::Matrix44( const Matrix44& a_other )
	{

		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				M[ j ][ i ]									=	a_other.M[ j ][ i ];	
			}
		}
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44::Matrix44(	FFloat32 m00 , FFloat32 m01 , FFloat32 m02 ,FFloat32 m03 ,
										FFloat32 m10 , FFloat32 m11 , FFloat32 m12 ,FFloat32 m13 ,
										FFloat32 m20 , FFloat32 m21 , FFloat32 m22 ,FFloat32 m23 ,
										FFloat32 m30 , FFloat32 m31 , FFloat32 m32 ,FFloat32 m33 )
	{
		M[ 0 ][ 0 ]											=	m00;
		M[ 0 ][ 1 ]											=	m01;
		M[ 0 ][ 2 ]											=	m02;
		M[ 0 ][ 3 ]											=	m03;

		M[ 1 ][ 0 ]											=	m10;
		M[ 1 ][ 1 ]											=	m11;
		M[ 1 ][ 2 ]											=	m12;
		M[ 1 ][ 3 ]											=	m13;

		M[ 2 ][ 0 ]											=	m20;
		M[ 2 ][ 1 ]											=	m21;
		M[ 2 ][ 2 ]											=	m22;
		M[ 2 ][ 3 ]											=	m23;

		M[ 3 ][ 0 ]											=	m30;
		M[ 3 ][ 1 ]											=	m31;
		M[ 3 ][ 2 ]											=	m32;
		M[ 3 ][ 3 ]											=	m33;

	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetIdentity()
	{
		M[ 0 ][ 0 ]											=	1.0f;
		M[ 0 ][ 1 ]											=	0.0f;
		M[ 0 ][ 2 ]											=	0.0f;
		M[ 0 ][ 3 ]											=	0.0f;

		M[ 1 ][ 0 ]											=	0.0f;
		M[ 1 ][ 1 ]											=	1.0f;
		M[ 1 ][ 2 ]											=	0.0f;
		M[ 1 ][ 3 ]											=	0.0f;

		M[ 2 ][ 0 ]											=	0.0f;
		M[ 2 ][ 1 ]											=	0.0f;
		M[ 2 ][ 2 ]											=	1.0f;
		M[ 2 ][ 3 ]											=	0.0f;

		M[ 3 ][ 0 ]											=	0.0f;
		M[ 3 ][ 1 ]											=	0.0f;
		M[ 3 ][ 2 ]											=	0.0f;
		M[ 3 ][ 3 ]											=	1.0f;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE FFloat32 Matrix44::GetDeterminant()const
	{
		FFloat32 t00										=	( M[ 2 ][ 2 ] * M[ 3 ][ 3 ] ) - ( M[ 2 ][ 3 ] * M[ 3 ][ 2 ] );
		FFloat32 t01										=	( M[ 2 ][ 3 ] * M[ 3 ][ 1 ] ) - ( M[ 2 ][ 1 ] * M[ 3 ][ 3 ] );
		FFloat32 t02										=	( M[ 2 ][ 1 ] * M[ 3 ][ 2 ] ) - ( M[ 2 ][ 2 ] * M[ 3 ][ 1 ] );

		FFloat32 t10										=	t00;
		FFloat32 t11										=	( M[ 2 ][ 3 ] * M[ 3 ][ 0 ] ) - ( M[ 2 ][ 0 ] * M[ 3 ][ 3 ] );
		FFloat32 t12										=	( M[ 2 ][ 0 ] * M[ 3 ][ 2 ] ) - ( M[ 2 ][ 2 ] * M[ 3 ][ 0 ] );

		FFloat32 t20										=	( M[ 2 ][ 1 ] * M[ 3 ][ 3 ] ) - ( M[ 2 ][ 3 ] * M[ 3 ][ 1 ] );
		FFloat32 t21										=	t11;
		FFloat32 t22										=	( M[ 2 ][ 0 ] * M[ 3 ][ 1 ] ) - ( M[ 2 ][ 1 ] * M[ 3 ][ 0 ] );

		FFloat32 t30										=	t02;
		FFloat32 t31										=	( M[ 2 ][ 2 ] * M[ 3 ][ 0 ] ) - ( M[ 2 ][ 0 ] * M[ 3 ][ 2 ] );
		FFloat32 t32										=	t22;

		FFloat32 t0											=	( M[ 1 ][ 1 ] * t00 ) + ( M[ 1 ][ 2 ] * t01 ) + ( M[ 1 ][ 3 ] * t02 );
		FFloat32 t1											=	( M[ 1 ][ 0 ] * t10 ) + ( M[ 1 ][ 2 ] * t11 ) + ( M[ 1 ][ 3 ] * t12 );
		FFloat32 t2											=	( M[ 1 ][ 0 ] * t20 ) + ( M[ 1 ][ 1 ] * t21 ) + ( M[ 1 ][ 3 ] * t22 );
		FFloat32 t3											=	( M[ 1 ][ 0 ] * t30 ) + ( M[ 1 ][ 1 ] * t31 ) + ( M[ 1 ][ 2 ] * t32 );

		return ( ( M[ 0 ][ 0 ] * t0 ) - ( M[ 0 ][ 1 ] * t1 ) + ( M[ 0 ][ 2 ] * t2 ) - ( M[ 0 ][ 3 ] * t3 ) );
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::Inverse()
	{
		// if determinant i 0, reset the matrix as identity
		if( GetDeterminant() == 0.0f )
		{
			SetIdentity();
		}
		else
		{
			Matrix44 t_temp;

			// copy the different cross product components
			FFloat32 t_1201									=	( M[ 1 ][ 0 ] * M[ 2 ][ 1 ] ) - ( M[ 1 ][ 1 ] * M[ 2 ][ 0 ] );
			FFloat32 t_1202									=	( M[ 1 ][ 0 ] * M[ 2 ][ 2 ] ) - ( M[ 1 ][ 2 ] * M[ 2 ][ 0 ] );
			FFloat32 t_1203									=	( M[ 1 ][ 0 ] * M[ 2 ][ 3 ] ) - ( M[ 1 ][ 3 ] * M[ 2 ][ 0 ] );

			FFloat32 t_1212									=	( M[ 1 ][ 1 ] * M[ 2 ][ 2 ] ) - ( M[ 1 ][ 2 ] * M[ 2 ][ 1 ] );
			FFloat32 t_1213									=	( M[ 1 ][ 1 ] * M[ 2 ][ 3 ] ) - ( M[ 1 ][ 3 ] * M[ 2 ][ 1 ] );
			FFloat32 t_1223									=	( M[ 1 ][ 2 ] * M[ 2 ][ 3 ] ) - ( M[ 1 ][ 3 ] * M[ 2 ][ 2 ] );

			FFloat32 t_1301									=	( M[ 1 ][ 0 ] * M[ 3 ][ 1 ] ) - ( M[ 1 ][ 1 ] * M[ 3 ][ 0 ] );
			FFloat32 t_1302									=	( M[ 1 ][ 0 ] * M[ 3 ][ 2 ] ) - ( M[ 1 ][ 2 ] * M[ 3 ][ 0 ] );
			FFloat32 t_1303									=	( M[ 1 ][ 0 ] * M[ 3 ][ 3 ] ) - ( M[ 1 ][ 3 ] * M[ 3 ][ 0 ] );

			FFloat32 t_1312									=	( M[ 1 ][ 1 ] * M[ 3 ][ 2 ] ) - ( M[ 1 ][ 2 ] * M[ 3 ][ 1 ] );
			FFloat32 t_1313									=	( M[ 1 ][ 1 ] * M[ 3 ][ 3 ] ) - ( M[ 1 ][ 3 ] * M[ 3 ][ 1 ] );
			FFloat32 t_1323									=	( M[ 1 ][ 2 ] * M[ 3 ][ 3 ] ) - ( M[ 1 ][ 3 ] * M[ 3 ][ 2 ] );

			FFloat32 t_2301									=	( M[ 2 ][ 0 ] * M[ 3 ][ 1 ] ) - ( M[ 2 ][ 1 ] * M[ 3 ][ 0 ] );
			FFloat32 t_2302									=	( M[ 2 ][ 0 ] * M[ 3 ][ 2 ] ) - ( M[ 2 ][ 2 ] * M[ 3 ][ 0 ] );
			FFloat32 t_2303									=	( M[ 2 ][ 0 ] * M[ 3 ][ 3 ] ) - ( M[ 2 ][ 3 ] * M[ 3 ][ 0 ] );

			FFloat32 t_2312									=	( M[ 2 ][ 1 ] * M[ 3 ][ 2 ] ) - ( M[ 2 ][ 2 ] * M[ 3 ][ 1 ] );
			FFloat32 t_2313									=	( M[ 2 ][ 1 ] * M[ 3 ][ 3 ] ) - ( M[ 2 ][ 3 ] * M[ 3 ][ 1 ] );
			FFloat32 t_2323									=	( M[ 2 ][ 2 ] * M[ 3 ][ 3 ] ) - ( M[ 2 ][ 3 ] * M[ 3 ][ 2 ] );

			// Set the Temp Matrix value
			t_temp.M[ 0 ][ 0 ]								=	( M[ 1 ] [ 1 ] * t_2323 ) - ( M[ 1 ] [ 2 ] * t_2313 ) + ( M[ 1 ][ 3 ] * t_2312 );
			t_temp.M[ 1 ][ 0 ]								=	( M[ 1 ] [ 2 ] * t_2303 ) - ( M[ 1 ] [ 0 ] * t_2323 ) - ( M[ 1 ][ 3 ] * t_2302 );
			t_temp.M[ 2 ][ 0 ]								=	( M[ 1 ] [ 0 ] * t_2313 ) - ( M[ 1 ] [ 1 ] * t_2303 ) + ( M[ 1 ][ 3 ] * t_2301 );
			t_temp.M[ 3 ][ 0 ]								=	( M[ 1 ] [ 1 ] * t_2302 ) - ( M[ 1 ] [ 0 ] * t_2312 ) - ( M[ 1 ][ 2 ] * t_2301 );

			t_temp.M[ 0 ][ 1 ]								=	( M[ 0 ] [ 2 ] * t_2313 ) - ( M[ 0 ] [ 1 ] * t_2323 ) - ( M[ 0 ][ 3 ] * t_2312 );
			t_temp.M[ 1 ][ 1 ]								=	( M[ 0 ] [ 0 ] * t_2323 ) - ( M[ 0 ] [ 2 ] * t_2303 ) + ( M[ 0 ][ 3 ] * t_2302 );
			t_temp.M[ 2 ][ 1 ]								=	( M[ 0 ] [ 1 ] * t_2303 ) - ( M[ 0 ] [ 0 ] * t_2313 ) - ( M[ 0 ][ 3 ] * t_2301 );
			t_temp.M[ 3 ][ 1 ]								=	( M[ 0 ] [ 0 ] * t_2312 ) - ( M[ 0 ] [ 1 ] * t_2302 ) + ( M[ 0 ][ 2 ] * t_2301 );

			t_temp.M[ 0 ][ 2 ]								=	( M[ 0 ] [ 1 ] * t_1323 ) - ( M[ 0 ] [ 2 ] * t_1313 ) + ( M[ 0 ][ 3 ] * t_1312 );
			t_temp.M[ 1 ][ 2 ]								=	( M[ 0 ] [ 2 ] * t_1303 ) - ( M[ 0 ] [ 0 ] * t_1323 ) - ( M[ 0 ][ 3 ] * t_1302 );
			t_temp.M[ 2 ][ 2 ]								=	( M[ 0 ] [ 0 ] * t_1313 ) - ( M[ 0 ] [ 1 ] * t_1303 ) + ( M[ 0 ][ 3 ] * t_1301 );
			t_temp.M[ 3 ][ 2 ]								=	( M[ 0 ] [ 1 ] * t_1302 ) - ( M[ 0 ] [ 0 ] * t_1312 ) - ( M[ 0 ][ 2 ] * t_1301 );

			t_temp.M[ 0 ][ 3 ]								=	( M[ 0 ] [ 2 ] * t_1213 ) - ( M[ 0 ] [ 1 ] * t_1223 ) - ( M[ 0 ][ 3 ] * t_1212 );
			t_temp.M[ 1 ][ 3 ]								=	( M[ 0 ] [ 0 ] * t_1223 ) - ( M[ 0 ] [ 2 ] * t_1203 ) + ( M[ 0 ][ 3 ] * t_1202 );
			t_temp.M[ 2 ][ 3 ]								=	( M[ 0 ] [ 1 ] * t_1203 ) - ( M[ 0 ] [ 0 ] * t_1213 ) - ( M[ 0 ][ 3 ] * t_1201 );
			t_temp.M[ 3 ][ 3 ]								=	( M[ 0 ] [ 0 ] * t_1212 ) - ( M[ 0 ] [ 1 ] * t_1202 ) + ( M[ 0 ][ 2 ] * t_1201 );

			//compute the determinant
			FFloat32 t_determinant							=	( M[ 0 ][ 0 ] * t_temp.M[ 0 ][ 0 ] ) +( M[ 1 ][ 0 ] * t_temp.M[ 0 ][ 1 ] ) + ( M[ 0 ][ 2 ] * t_temp.M[ 3 ][ 0 ] ) + ( M[ 3 ][ 0 ] * t_temp.M[ 0 ][ 3 ] );

			// if big enough
			if( t_determinant > 1.0e-16f )
			{
				FFloat32 t_scale							=	1.0f / t_determinant;

				*this										=	t_temp * t_scale;
			}
			else
			{
				//reet to identity 
				SetIdentity();
			}
		}

	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44 Matrix44::GetInverse()const
	{
		Matrix44 t_result(*this);

		t_result.Inverse();

		return t_result;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::Transpose()
	{
		Matrix44 t_temp										=	*this;

		M[ 0 ][ 0 ]											=	t_temp.M[ 0 ][ 0 ];
		M[ 0 ][ 1 ]											=	t_temp.M[ 1 ][ 0 ];
		M[ 0 ][ 2 ]											=	t_temp.M[ 2 ][ 0 ];
		M[ 0 ][ 3 ]											=	t_temp.M[ 3 ][ 0 ];

		M[ 1 ][ 0 ]											=	t_temp.M[ 0 ][ 1 ];
		M[ 1 ][ 1 ]											=	t_temp.M[ 1 ][ 1 ];
		M[ 1 ][ 2 ]											=	t_temp.M[ 2 ][ 1 ];
		M[ 1 ][ 3 ]											=	t_temp.M[ 3 ][ 1 ];

		M[ 2 ][ 0 ]											=	t_temp.M[ 0 ][ 2 ];
		M[ 2 ][ 1 ]											=	t_temp.M[ 1 ][ 2 ];
		M[ 2 ][ 2 ]											=	t_temp.M[ 2 ][ 2 ];
		M[ 2 ][ 3 ]											=	t_temp.M[ 3 ][ 2 ];

		M[ 3 ][ 0 ]											=	t_temp.M[ 0 ][ 3 ];
		M[ 3 ][ 1 ]											=	t_temp.M[ 1 ][ 3 ];
		M[ 3 ][ 2 ]											=	t_temp.M[ 2 ][ 3 ];
		M[ 3 ][ 3 ]											=	t_temp.M[ 3 ][ 3 ];

	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44 Matrix44::GetTranspose()const
	{
		Matrix44 t_result;

		t_result.M[ 0 ][ 0 ]								=	M[ 0 ][ 0 ];
		t_result.M[ 0 ][ 1 ]								=	M[ 1 ][ 0 ];
		t_result.M[ 0 ][ 2 ]								=	M[ 2 ][ 0 ];
		t_result.M[ 0 ][ 3 ]								=	M[ 3 ][ 0 ];

		t_result.M[ 1 ][ 0 ]								=	M[ 0 ][ 1 ];
		t_result.M[ 1 ][ 1 ]								=	M[ 1 ][ 1 ];
		t_result.M[ 1 ][ 2 ]								=	M[ 2 ][ 1 ];
		t_result.M[ 1 ][ 3 ]								=	M[ 3 ][ 1 ];

		t_result.M[ 2 ][ 0 ]								=	M[ 0 ][ 2 ];
		t_result.M[ 2 ][ 1 ]								=	M[ 1 ][ 2 ];
		t_result.M[ 2 ][ 2 ]								=	M[ 2 ][ 2 ];
		t_result.M[ 2 ][ 3 ]								=	M[ 3 ][ 2 ];

		t_result.M[ 3 ][ 0 ]								=	M[ 0 ][ 3 ];
		t_result.M[ 3 ][ 1 ]								=	M[ 1 ][ 3 ];
		t_result.M[ 3 ][ 2 ]								=	M[ 2 ][ 3 ];
		t_result.M[ 3 ][ 3 ]								=	M[ 3 ][ 3 ];

		return t_result;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE FBool Matrix44::IsEqual( const Matrix44& a_other , FFloat32 a_tolerance )
	{
		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				if( Maths::Abs( M[ j ][ i ] - a_other.M[ j ][ i ] ) > a_tolerance )
				{
					return false;
				}
			}
		}

		return true;
	}
	//-----------------------------------------------------------------------------------------



	////////////
	// Translation Methods
	/////////////

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetTranslate( const Vector3F& a_translation )
	{
		//reset the Matrix to identity
		SetIdentity();

		_m30												=	a_translation.x;
		_m31												=	a_translation.y;
		_m32												=	a_translation.z;
	}
	//-----------------------------------------------------------------------------------------

	//	FORCE_INLINE void Translate( const Vector3F& a_translation );

	//	FORCE_INLINE void PostTranslate( const Vector3F& a_translation );


	////////////
	// Scale Methods
	/////////////

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetScale( const Vector3F& a_scale )
	{
		//reset the Matrix to identity
		SetIdentity();

		_m00												=	a_scale.x;
		_m11												=	a_scale.y;
		_m22												=	a_scale.z;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetScale( FFloat32 a_scale )
	{
		//reset the Matrix to identity
		SetIdentity();

		_m00												=	a_scale;
		_m11												=	a_scale;
		_m22												=	a_scale;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetScale( FFloat32 a_scaleX , FFloat32 a_scaleY , FFloat32 a_scaleZ )
	{
		//reset the Matrix to identity
		SetIdentity();

		_m00												=	a_scaleX;
		_m11												=	a_scaleY;
		_m22												=	a_scaleZ;
	}
	//-----------------------------------------------------------------------------------------


	////////////
	// Rotate Methods
	/////////////


	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetRotateX( FFloat32 a_angle )
	{
		// compute cos and sin
		FFloat32 t_cos										=	Maths::Cos( a_angle );
		FFloat32 t_sin										=	Maths::Sin( a_angle );

		// reset the Matrix to Identity
		SetIdentity();

		_m11												=	t_cos;
		_m12												=	-t_sin;
		_m21												=	t_sin;
		_m22												=	t_cos;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetRotateY( FFloat32 a_angle )
	{
		// compute cos and sin
		FFloat32 t_cos										=	Maths::Cos( a_angle );
		FFloat32 t_sin										=	Maths::Sin( a_angle );

		// reset the Matrix to Identity
		SetIdentity();

		_m00												=	t_cos;
		_m02												=	t_sin;
		_m20												=	-t_sin;
		_m22												=	t_cos;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetRotateZ( FFloat32 a_angle )
	{
		// compute cos and sin
		FFloat32 t_cos										=	Maths::Cos( a_angle );
		FFloat32 t_sin										=	Maths::Sin( a_angle );

		// reset the Matrix to Identity
		SetIdentity();

		_m00												=	t_cos;
		_m01												=	-t_sin;
		_m10												=	t_sin;
		_m11												=	t_cos;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetRotate( FFloat32 a_pitch , FFloat32 a_yaw , FFloat32 a_roll )
	{
		// compute Sin and cos for the 3 angles

		FFloat32 t_cosYaw									=	Maths::Cos( a_yaw );
		FFloat32 t_sinYaw									=	Maths::Sin( a_yaw );
		FFloat32 t_cosRoll									=	Maths::Cos( a_roll );
		FFloat32 t_sinRoll									=	Maths::Sin( a_roll );
		FFloat32 t_cosPitch									=	Maths::Cos( a_pitch );
		FFloat32 t_sinPitch									=	Maths::Sin( a_pitch );

		_m00												=	t_cosYaw * t_cosRoll;
		_m01												=	t_cosYaw * t_sinRoll;
		_m02												=	t_sinYaw;
		_m03												=	0.f;

		_m10												=	t_sinPitch * t_sinYaw * t_cosRoll - t_cosPitch * t_sinRoll;
		_m11												=	t_sinPitch * t_sinYaw * t_sinRoll + t_cosPitch * t_cosRoll;
		_m12												=	-t_sinPitch * t_cosYaw;
		_m13												= 0.f;

		_m20												=	-( t_cosPitch * t_sinYaw * t_cosRoll + t_sinPitch * t_sinRoll );
		_m21												=	t_cosRoll * t_sinPitch - t_cosPitch * t_sinYaw * t_sinRoll;
		_m22												=	t_cosPitch * t_cosYaw;
		_m23												=	0.f;

		_m30												=	0.0f;
		_m31												=	0.0f;
		_m32												=	0.0f;
		_m33												=	1.0f;

	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetRotate( const Vector3F& a_rotation )
	{
		SetRotate( a_rotation.x , a_rotation.y , a_rotation.z );
	}
	//-----------------------------------------------------------------------------------------



	//	FORCE_INLINE void SetRotate( const Vector3F&a_axi , float a_angle );


	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetTransScaleRot( Vector3F a_translation , Vector3F a_scale , Vector3F a_rot )
	{
		Matrix44 t_translation;
		Matrix44 t_scale;
		Matrix44 t_rot;

		// Set the different intermediates Matrix
		t_translation.SetTranslate( a_translation );
		t_scale.SetScale( a_scale );
		t_rot.SetRotate( a_rot );

		*this												=	t_translation * t_scale * t_rot;
	}
	//-----------------------------------------------------------------------------------------

	///////////////////////////
	// Projection Matrix
	//////////////////////////

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetOrthoProjection( FFloat32 a_left , FFloat32 a_right , FFloat32 a_top , FFloat32 a_bottom , FFloat32 a_zNear , FFloat32 a_zFar )
	{
		FFloat32 sx											=	1.0f / ( a_right - a_left );
		FFloat32 sy											=	1.0f / ( a_top - a_bottom );
		FFloat32 sz											=	1.0f / ( a_zFar - a_zNear );

		_m00												=	2.0f * sx;
		_m01												=	0.0f;
		_m02												=	0.0f;
		_m03												=	0.0f;

		_m10												=	0.0f;
		_m11												=	2.0f * sy;
		_m12												=	0.0f;
		_m13												=	0.0f;

		_m20												=	0.0f;
		_m21												=	0.0f;
		_m22												=	sz;
		_m23												=	0.0f;


		_m30												=	( a_right + a_left ) / ( a_left - a_right );
		_m31												=	( a_top + a_bottom ) / ( a_bottom - a_top );
		_m32												=	a_zNear / ( a_zNear - a_zFar );
		_m33												=	1.0f;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetPerpectiveProjection( FFloat32 a_fov , FFloat32 a_aspectRatio , FFloat32 a_zNear , FFloat32 a_zFar )
	{
		//todo add asserts

		FFloat32 t_yScale									=	1.0f / Maths::Tan( a_fov * 0.5f );
		FFloat32 t_xScale									=	t_yScale / a_aspectRatio;

		_m00												=	t_xScale;
		_m01												=	0.0f;
		_m02												=	0.0f;
		_m03												=	0.0f;

		_m10												=	0.0f;
		_m11												=	t_yScale;
		_m12												=	0.0f;
		_m13												=	0.0f;

		_m20												=	0.0f;
		_m21												=	0.0f;
		_m22												=	a_zFar / ( a_zFar - a_zNear );
		_m23												=	1.0f;

		_m30												=	0;
		_m31												=	0;
		_m32												=	-( a_zNear * a_zFar ) / ( a_zFar - a_zNear );
		_m33												=	0.0f;


	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE void Matrix44::SetLookAt( const Vector3F& a_position , const Vector3F& a_target , const Vector3F& a_up )
	{
		//Get normalized up vector
		Vector3F t_up										=	a_up.GetNormalized();

		Vector3F t_zAxis									=	a_target - a_position;
		t_zAxis.Normalize();

		Vector3F t_xAxis									=	Vector3F::Cross( t_up , t_zAxis );
		t_xAxis.Normalize();

		Vector3F t_yAxis									=	Vector3F::Cross( t_zAxis , t_xAxis );
		t_yAxis.Normalize();

		_m00												=	t_xAxis.x;
		_m01												=	t_yAxis.x;
		_m02												=	t_zAxis.x;
		_m03												=	0.0f;

		_m10												=	t_xAxis.y;
		_m11												=	t_yAxis.y;
		_m12												=	t_zAxis.y;
		_m13												=	0.0f;

		_m20												=	t_xAxis.z;
		_m21												=	t_yAxis.z;
		_m22												=	t_zAxis.z;
		_m23												=	0.0f;

		_m30												=	-t_xAxis.Dot( a_position );
		_m31												=	-t_yAxis.Dot( a_position );
		_m32												=	-t_zAxis.Dot( a_position );
		_m33												=	1.0f;
	}
	//-----------------------------------------------------------------------------------------


	////////////
	// Operators Methods
	/////////////


	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44 Matrix44::operator+( const Matrix44& a_other )const
	{
		// Create a Copy of this Matrix
		Matrix44 t_result( *this );

		// perform the Addition
		t_result											+=	a_other;

		//return the result
		return t_result;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44 Matrix44::operator-( const Matrix44& a_other )const
	{
		// Create a Copy of this Matrix
		Matrix44 t_result( *this );

		// perform the Substraction
		t_result											-=	a_other;

		//return the result
		return t_result;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44 Matrix44::operator*( const Matrix44& a_other )const
	{
	
	#if ( PLATFORM_CONFIG_MATRIX_ORDER == MATRIX_ORDER_ROW_MAJOR )
		const Matrix44& Mat1								=	a_other;
		const Matrix44& Mat2								=	*this;
	#else
		const Matrix44& Mat1								=	*this;
		const Matrix44& Mat2								=	a_other;
	#endif

		Matrix44 t_result;

		t_result.M[ 0 ][ 0 ]								=	( Mat1.M[0][0] * Mat2.M[0][0] ) + ( Mat1.M[0][1] * Mat2.M[1][0] ) + ( Mat1.M[0][2] * Mat2.M[2][0] ) + ( Mat1.M[0][3] * Mat2.M[3][0] );
		t_result.M[ 0 ][ 1 ]								=	( Mat1.M[0][0] * Mat2.M[0][1] ) + ( Mat1.M[0][1] * Mat2.M[1][1] ) + ( Mat1.M[0][2] * Mat2.M[2][1] ) + ( Mat1.M[0][3] * Mat2.M[3][1] );
		t_result.M[ 0 ][ 2 ]								=	( Mat1.M[0][0] * Mat2.M[0][2] ) + ( Mat1.M[0][1] * Mat2.M[1][2] ) + ( Mat1.M[0][2] * Mat2.M[2][2] ) + ( Mat1.M[0][3] * Mat2.M[3][2] );
		t_result.M[ 0 ][ 3 ]								=	( Mat1.M[0][0] * Mat2.M[0][3] ) + ( Mat1.M[0][1] * Mat2.M[1][3] ) + ( Mat1.M[0][2] * Mat2.M[2][3] ) + ( Mat1.M[0][3] * Mat2.M[3][3] );

		t_result.M[ 1 ][ 0 ]								=	( Mat1.M[1][0] * Mat2.M[0][0] ) + ( Mat1.M[1][1] * Mat2.M[1][0] ) + ( Mat1.M[1][2] * Mat2.M[2][0] ) + ( Mat1.M[1][3] * Mat2.M[3][0] );
		t_result.M[ 1 ][ 1 ]								=	( Mat1.M[1][0] * Mat2.M[0][1] ) + ( Mat1.M[1][1] * Mat2.M[1][1] ) + ( Mat1.M[1][2] * Mat2.M[2][1] ) + ( Mat1.M[1][3] * Mat2.M[3][1] );
		t_result.M[ 1 ][ 2 ]								=	( Mat1.M[1][0] * Mat2.M[0][2] ) + ( Mat1.M[1][1] * Mat2.M[1][2] ) + ( Mat1.M[1][2] * Mat2.M[2][2] ) + ( Mat1.M[1][3] * Mat2.M[3][2] );
		t_result.M[ 1 ][ 3 ]								=	( Mat1.M[1][0] * Mat2.M[0][3] ) + ( Mat1.M[1][1] * Mat2.M[1][3] ) + ( Mat1.M[1][2] * Mat2.M[2][3] ) + ( Mat1.M[1][3] * Mat2.M[3][3] );

		t_result.M[ 2 ][ 0 ]								=	( Mat1.M[2][0] * Mat2.M[0][0] ) + ( Mat1.M[2][1] * Mat2.M[1][0] ) + ( Mat1.M[2][2] * Mat2.M[2][0] ) + ( Mat1.M[2][3] * Mat2.M[3][0] );
		t_result.M[ 2 ][ 1 ]								=	( Mat1.M[2][0] * Mat2.M[0][1] ) + ( Mat1.M[2][1] * Mat2.M[1][1] ) + ( Mat1.M[2][2] * Mat2.M[2][1] ) + ( Mat1.M[2][3] * Mat2.M[3][1] );
		t_result.M[ 2 ][ 2 ]								=	( Mat1.M[2][0] * Mat2.M[0][2] ) + ( Mat1.M[2][1] * Mat2.M[1][2] ) + ( Mat1.M[2][2] * Mat2.M[2][2] ) + ( Mat1.M[2][3] * Mat2.M[3][2] );
		t_result.M[ 2 ][ 3 ]								=	( Mat1.M[2][0] * Mat2.M[0][3] ) + ( Mat1.M[2][1] * Mat2.M[1][3] ) + ( Mat1.M[2][2] * Mat2.M[2][3] ) + ( Mat1.M[2][3] * Mat2.M[3][3] );

		t_result.M[ 3 ][ 0 ]								=	( Mat1.M[3][0] * Mat2.M[0][0] ) + ( Mat1.M[3][1] * Mat2.M[1][0] ) + ( Mat1.M[3][2] * Mat2.M[2][0] ) + ( Mat1.M[3][3] * Mat2.M[3][0] );
		t_result.M[ 3 ][ 1 ]								=	( Mat1.M[3][0] * Mat2.M[0][1] ) + ( Mat1.M[3][1] * Mat2.M[1][1] ) + ( Mat1.M[3][2] * Mat2.M[2][1] ) + ( Mat1.M[3][3] * Mat2.M[3][1] );
		t_result.M[ 3 ][ 2 ]								=	( Mat1.M[3][0] * Mat2.M[0][2] ) + ( Mat1.M[3][1] * Mat2.M[1][2] ) + ( Mat1.M[3][2] * Mat2.M[2][2] ) + ( Mat1.M[3][3] * Mat2.M[3][2] );
		t_result.M[ 3 ][ 3 ]								=	( Mat1.M[3][0] * Mat2.M[0][3] ) + ( Mat1.M[3][1] * Mat2.M[1][3] ) + ( Mat1.M[3][2] * Mat2.M[2][3] ) + ( Mat1.M[3][3] * Mat2.M[3][3] );

		return t_result;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44 Matrix44::operator*( FFloat32 a_scale )const
	{
		// Create a Copy of this Matrix
		Matrix44 t_result( *this );

		// perform the multiplication
		t_result											*=	a_scale;

		//return the result
		return t_result;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44 Matrix44::operator/( FFloat32 a_divider )const
	{
		// Create a Copy of this Matrix
		Matrix44 t_result( *this );

		// perform the Division
		t_result											/=	a_divider;

		//return the result
		return t_result;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44& Matrix44::operator=( const Matrix44& a_other )
	{
		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				M[ j ][ i ]									=	a_other.M[ j ][ i ];
			}
		}

		return *this;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44& Matrix44::operator+=( const Matrix44& a_other )
	{

		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				M[ j ][ i ]									+=	a_other.M[ j ][ i ];
			}
		}

		return *this;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44& Matrix44::operator-=( const Matrix44& a_other )
	{
		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				M[ j ][ i ]									-=	a_other.M[ j ][ i ];
			}
		}

		return *this;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44& Matrix44::operator*=( const Matrix44& a_other )
	{
		*this												=	( *this ) * a_other;

		return *this;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44& Matrix44::operator*=( FFloat32 a_scale )
	{
		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				M[ j ][ i ]									*=	a_scale;
			}
		}
		return *this;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE Matrix44& Matrix44::operator/=( FFloat32 a_divider )
	{
		FFloat32 t_scale									=	1.0f / a_divider;

		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				M[ j ][ i ]									*=	t_scale;
			}
		}

		return *this;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE FBool Matrix44::operator==(const Matrix44& a_other)const
	{
		for( FUint32 j = 0 ; j < 4 ; j ++ )
		{
			for( FUint32 i = 0 ; i < 4 ; i ++ )
			{
				if( M[ j ][ i ] != a_other.M[ j ][ i ] )
				{
					return false;
				}
			}
		}

		return true;
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	FORCE_INLINE FBool Matrix44::operator!=(const Matrix44& a_other)const
	{
		return !(*this == a_other);
	}
	//-----------------------------------------------------------------------------------------

}