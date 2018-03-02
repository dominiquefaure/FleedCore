#ifndef __FLEED_CORE_APPLICATION_WINDOWS_APP_CONFIG_H__
#define __FLEED_CORE_APPLICATION_WINDOWS_APP_CONFIG_H__
#include <string>

namespace FleedCore
{
	struct WinAppConfig
	{
		//	LPCWSTR	m_className;
		//	LPCWSTR	m_captionText;

		std::wstring	m_className;
		std::wstring	m_captionText;

		DWORD	m_dwStyle;
		DWORD	m_dwXPos;
		DWORD	m_dwYPos;
		DWORD	m_dwWidth;
		DWORD	m_dwHeight;

		int		m_iconResID;
		int		m_smallIconResID;

		int		m_menuID;
	};

}


#endif