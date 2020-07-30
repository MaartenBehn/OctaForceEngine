#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace OctaForce 
{

	class OC_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}




