#ifndef __FLEEDCORE_APPLICATION_WINMAIN_LAUNCHER_H__
#define __FLEEDCORE_APPLICATION_WINMAIN_LAUNCHER_H__

#include <Windows.h>

#include "WindowsAppConfig.h"
#include "FleedApplication.h"


namespace FleedCore
{


	class WinMainLauncher
	{
	public:
		WinMainLauncher();
		~WinMainLauncher();
	


		int Run( FleedApplication* a_application , HINSTANCE a_hInstance, int a_nCmdShow );

	// MEthods
	private:

		BOOL Init( FleedApplication* a_application , HINSTANCE a_hInstance, int a_nCmdShow );

		/*
		* Register the WNDCLASSEX Class
		*/
		BOOL RegisterWndClass( );


		BOOL CreateWindowDlg( int a_nCmdShow );

	//// Fields
	private:
		HINSTANCE     m_hInst;
		HWND          m_hWnd;


		TCHAR			m_strClass[MAX_PATH];
		TCHAR			m_strCaption[MAX_PATH];
		WNDCLASSEX		m_stWcex;


		WinAppConfig		m_config;

		FleedApplication*	m_application;
	};

}

#endif