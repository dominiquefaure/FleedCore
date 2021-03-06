#ifndef __FLEEDCORE__COMMON_COMMON_MACROS_H__
#define __FLEEDCORE__COMMON_COMMON_MACROS_H__


#ifdef _DEBUG
#define FORCE_INLINE
#else
#define FORCE_INLINE	__forceinline
#endif


#define SAFE_DELETE( X ) if( X != NULL )\
{\
	delete X;\
	X = NULL;\
}


#define SAFE_DELETE_ARRAY( X ) if( X != NULL )\
{\
	delete[] X;\
	X = NULL;\
}


#define SAFE_RELEASE( X ) if( X != NULL )\
{\
	X->Release();\
	X = NULL;\
}


#endif