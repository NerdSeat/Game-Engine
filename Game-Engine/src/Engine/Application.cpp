#include <gepch.h>
#include "Application.h"
#include "Engine/Event/Event.h"
#include"Engine/Event/ApplicationEvent.h"
#include <GLFW/glfw3.h>
namespace ge {


	Application::Application()
	{
		window = std::unique_ptr<Window> (Window::Create());
	}
	Application::~Application()
	{

	}
	void Application::Run()
	{
		while (running)
		{
			glClearColor(1,0,0,1);
			glClear(GL_COLOR_BUFFER_BIT);
			window->onUpdate();
		}
	}
}
