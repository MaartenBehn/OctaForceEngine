#pragma once

#ifdef OC_PLATFORM_WINDOWS

extern OctaForce::Application* OctaForce::CreateApplication();

	int main()
	{
		OctaForce::Log::Init();
		OC_CORE_INFO("Engine Startup...");

		auto app = OctaForce::CreateApplication();
		app->Run();
		delete app;
	}

#endif