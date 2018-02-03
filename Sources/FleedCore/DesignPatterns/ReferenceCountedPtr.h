#ifndef __FLEEDCORE_DESIGN_PATTERNS_REFERENCE_COUNTED_PTR_H__
#define __FLEEDCORE_DESIGN_PATTERNS_REFERENCE_COUNTED_PTR_H__

#include "../Common/Includes.h"

namespace FleedCore
{


	/*
	* Smart pointer for Reference counted objects
	*/
	template<class T>
	class ReferenceCountedPtr
	{
	public:

		ReferenceCountedPtr( void );
		ReferenceCountedPtr( T* a_object );
		ReferenceCountedPtr( const ReferenceCountedPtr& a_ptr );

		~ReferenceCountedPtr();


		ReferenceCountedPtr& operator=( const ReferenceCountedPtr& a_ptr );

		/*
		* if the Object is not valid, force the game to crash
		*/
		T& operator* (void);

		/*
		* if the Object is not valid, force the game to crash
		*/
		const T& operator* (void) const;

		/*
		* Allow to use like a standard pointer
		* if the Object is not valid, force the game to crash
		*/
		T* operator-> (void);

		/*
		* Allow to use like a standard pointer
		* if the Object is not valid, force the game to crash
		*/
		const T* operator-> (void)const;


		FBool operator!()const;

		/*
		* Check if it's the same pointer
		*/
		FBool operator == ( const ReferenceCountedPtr& a_ptr )const;

		/*
		* Check if it's the same pointer
		*/
		FBool operator == ( const T* a_ptr )const;

		/*
		* Check if it's not the same pointer
		*/
		FBool operator != ( const ReferenceCountedPtr& a_ptr )const;

		/*
		* Check if it's not the same pointer
		*/
		FBool operator != ( const T* a_ptr )const;


		/*
		* return true if this object point to a valid pointer
		*/
		FBool IsValid()const;

	private:

		// pointer to the ReferenceCounted object
		T*	m_pointer;

	};


}

// The inline is included in the Header only if not in debug mode
#ifndef _DEBUG
#include "ReferenceCountedPtr.inl"
#endif
#endif