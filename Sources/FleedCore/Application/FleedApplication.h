#ifndef __FLEEDCORE_FLEED_APPLICATION_H__
#define __FLEEDCORE_FLEED_APPLICATION_H__

#include<Windows.h>

#include "WindowsAppConfig.h"

namespace FleedCore
{

	class WinMainLauncher;

	class FleedApplication
	{
		friend class WinMainLauncher;

	public:

		FleedApplication();
		virtual ~FleedApplication();

		/*
		* Initialize the Game
		*/
		void Init( HWND a_handle );

		/*
		 * Called every ticks by the main loop perform all the frame operations
 		 */
		void OnFrame();

	// pure Virtual methods to be overrided
	protected:

		/*
		 * Called at Application initialization, allow to start loading custom data
		 */
		virtual void OnInit(){}

		/*
		 * Called at Application initialization, allow to start loading custom data
		 */
		virtual void OnClose(){}

		/*
		 * Called every ticks to perform the update operations
		 */
		virtual void OnUpdate(){}

		/*
		 *  called every ticks to perform the custom draw operations
		 */
		virtual void OnDraw(){}

		/*
		 * Allow custom config of the Windows creation
		 */
		virtual void OnSetWindowConfig( WinAppConfig& a_config ){}

	// Methodss
	private:

		/*
		 * Configure the Windows Dialog
		 */
		void SetWindowConfig( WinAppConfig& a_config );

		/*
		 * Perform all the Frame Updates
		 */
		void PerformUpdates();

		/*
		 * PErform all the Draw Operations
		 *
		 */
		void PerformDraw();


	protected:

	};


}
#endif