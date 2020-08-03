#include "OctaForce.h"

class ExampleLayer : public OctaForce::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		OC_INFO("ExampleLayer::Update");
	}

	void OnEvent(OctaForce::Event& event) override
	{
		OC_TRACE("{0}", event);
	}

};


class Sandbox : public OctaForce::Application 
{

public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}
};

OctaForce::Application* OctaForce::CreateApplication()
{
	return new Sandbox();
}