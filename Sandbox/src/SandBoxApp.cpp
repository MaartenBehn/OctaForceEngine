#include "OctaForce.h"

class Sandbox : public OctaForce::Application 
{

public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

OctaForce::Application* OctaForce::CreateApplication()
{
	return new Sandbox();
}