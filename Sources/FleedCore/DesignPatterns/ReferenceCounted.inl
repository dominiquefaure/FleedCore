#include "ReferenceCounted.h"


namespace FleedCore
{
	//------------------------------------------------------------------------
	FORCE_INLINE ReferenceCounted::ReferenceCounted()
	{
		m_count												=	0;
	}
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	FORCE_INLINE ReferenceCounted::~ReferenceCounted()
	{
	}
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	FORCE_INLINE FUint32 ReferenceCounted::GetReferenceCount()const
	{
		return m_count;
	}
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	FORCE_INLINE void ReferenceCounted::IncreaseReferenceCount()
	{
		m_count ++;
	}
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	FORCE_INLINE void ReferenceCounted::DecreaseReferenceCount()
	{
		m_count --;

		if( m_count == 0 )
		{
			PerformDelete();
		}
	}
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	FORCE_INLINE void ReferenceCounted::PerformDelete()
	{
		delete this;
	}
	//------------------------------------------------------------------------

}