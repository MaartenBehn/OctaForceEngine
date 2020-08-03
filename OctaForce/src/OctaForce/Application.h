#pragma once

#include "OctaForce/Core.h"
#include "OctaForce/Events/Event.h"
#include "OctaForce/Events/ApplicationEvent.h"

#include "OctaForce/Window.h"
#include "OctaForce/LayerStack.h"
#include "OctaForce/Events/Event.h"
#include "OctaForce/Events/ApplicationEvent.h"



namespace OctaForce 
{

	class OC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		 
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}




