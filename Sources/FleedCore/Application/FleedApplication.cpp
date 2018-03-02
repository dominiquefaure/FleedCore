#include "FleedApplication.h"



namespace FleedCore
{

	//---------------------------------------------------------------------------------------------
	FleedApplication::FleedApplication()
	{
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	FleedApplication::~FleedApplication()
	{
	
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void FleedApplication::SetWindowConfig( WinAppConfig& a_config )
	{
		// Set Default values
		a_config.m_className								=	L"VTSRenderSampleClass";
		a_config.m_captionText								=	L"DefaultApplication";
		a_config.m_dwStyle									=	WS_OVERLAPPEDWINDOW;
		a_config.m_dwXPos									=	CW_USEDEFAULT;
		a_config.m_dwYPos									=	0;
		a_config.m_dwWidth									=	CW_USEDEFAULT;
		a_config.m_dwHeight									=	0;


		a_config.m_smallIconResID							=	0;
		a_config.m_iconResID								=	0;

		// Allow custom configuration
		OnSetWindowConfig( a_config );
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void FleedApplication::Init( HWND a_handle )
	{
		// perform custom inits
		OnInit( );
	}
	//---------------------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------------------
	void FleedApplication::OnFrame()
	{
		PerformUpdates();
		PerformDraw();
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void FleedApplication::PerformUpdates()
	{
		// Custom Updates	
		OnUpdate();
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void FleedApplication::PerformDraw()
	{
		OnDraw();
	}
	//---------------------------------------------------------------------------------------------

}