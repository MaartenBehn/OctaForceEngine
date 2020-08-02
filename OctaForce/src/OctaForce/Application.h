#pragma once

#include "Core.h"
#include "OctaForce/Events/Event.h"
#include "OctaForce/Events/ApplicationEvent.h"

#include "Window.h"

namespace OctaForce 
{

	class OC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		 
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}




