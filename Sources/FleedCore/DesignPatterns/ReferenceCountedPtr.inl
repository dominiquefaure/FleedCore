
#include "ReferenceCountedPtr.h"

namespace FleedCore
{
	//------------------------------------------------------------------------------------
	template<class T>
	inline ReferenceCountedPtr<T>::ReferenceCountedPtr()
	{
		m_pointer												=	NULL;
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T>
	inline ReferenceCountedPtr<T>::ReferenceCountedPtr( T* a_object )
	{
		// save pointer to the Object
		m_pointer												=	a_object;

		// if the pointer is not NULL, increase it' refernce count ( Need to be a ReferenceCounted objectg ! )
		if( m_pointer )
		{
			m_pointer->IncreaseReferenceCount();
		}

	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T>
	inline ReferenceCountedPtr<T>::ReferenceCountedPtr( const ReferenceCountedPtr& a_ptr )
	{
		m_pointer												=	a_ptr.m_pointer;

		// if the pointer is not NULL, increase it' refernce count ( Need to be a ReferenceCounted objectg ! )
		if( m_pointer )
		{
			m_pointer->IncreaseReferenceCount();
		}
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T>
	inline ReferenceCountedPtr<T>::~ReferenceCountedPtr(  )
	{
		// if the pointer is not NULL, decrease it' refernce count ( Need to be a ReferenceCounted objectg ! )
		if( m_pointer )
		{
			m_pointer->DecreaseReferenceCount();
		}
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T> 
	inline ReferenceCountedPtr<T>& ReferenceCountedPtr<T>::operator=( const ReferenceCountedPtr& a_ptr )
	{
		//if we want to assign the same pointer, just return this one
		if( m_pointer == a_ptr.m_pointer )
		{
			return *this;
		}

		// decrease reference count of the current object pointed, as we don't refernce it anymore
		if( m_pointer != NULL )
		{
			m_pointer->DecreaseReferenceCount();
		}

		// update the pointer
		m_pointer												=	a_ptr.m_pointer;

		// Increase the counter for the new object pointed
		if( m_pointer != NULL )
		{
			m_pointer->IncreaseReferenceCount();
		}

		return *this;
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T> 
	inline T& ReferenceCountedPtr<T>::operator* (void)
	{
		return *m_pointer;
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T> 
	inline const T& ReferenceCountedPtr<T>::operator* (void) const
	{
		return *m_pointer;
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T> 
	inline T* ReferenceCountedPtr<T>::operator-> (void)
	{
		return m_pointer;
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T> 
	inline const T* ReferenceCountedPtr<T>::operator-> (void)const
	{
		return m_pointer;
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T>
	inline FBool ReferenceCountedPtr<T>::operator!()const
	{
		return ( m_pointer == NULL );
	}
	//------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------
	template<class T>
	FBool ReferenceCountedPtr<T>::operator == ( const ReferenceCountedPtr& a_ptr )const
	{
		return ( m_pointer == a_ptr.m_pointer );
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T>
	FBool ReferenceCountedPtr<T>::operator == ( const T* a_ptr )const
	{
		return ( m_pointer == a_ptr );
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T>
	FBool ReferenceCountedPtr<T>::operator != ( const ReferenceCountedPtr& a_ptr )const
	{
		return ( m_pointer != a_ptr.m_pointer );
	}
	//------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------
	template<class T>
	FBool ReferenceCountedPtr<T>::operator != ( const T* a_ptr )const
	{
		return ( m_pointer != a_ptr );
	}
	//------------------------------------------------------------------------------------


	//------------------------------------------------------------------------------------
	template<class T>
	inline FBool ReferenceCountedPtr<T>::IsValid()const
	{
		return ( m_pointer != NULL );
	}
	//------------------------------------------------------------------------------------

}

