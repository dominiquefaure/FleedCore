#ifndef __FLEEDCORE_DESIGN_PATTERNS_REFERENCE_COUNTED_H__
#define __FLEEDCORE_DESIGN_PATTERNS_REFERENCE_COUNTED_H__

#include "../Common/Includes.h"

namespace FleedCore
{

	class ReferenceCounted
	{
	public:

		FORCE_INLINE ReferenceCounted();

		FORCE_INLINE virtual ~ReferenceCounted();

		/*
		* Get the number of times this object is reference
		*/
		FORCE_INLINE FUint32 GetReferenceCount()const;

		/*
		* Increase the Object reference count by 1
		*/
		FORCE_INLINE void IncreaseReferenceCount();

		/*
		* Decrease the Object Reference Count by 1.
		* If the counter reach 0, the Object will be deleted
		*/
		FORCE_INLINE void DecreaseReferenceCount();


	protected:

		/*
		* Delete this Object
		*/
		virtual FORCE_INLINE void PerformDelete();

	private:

		FUint32		m_count;
	};

	
}

// The inline is included in the Header only if not in debug mode
#ifndef _DEBUG
#include "ReferenceCounted.inl"
#endif

#endif