#include <gepch.h>
#include "Application.h"
#include "Engine/Event/Event.h"
#include"Engine/Event/ApplicationEvent.h"
#include <GLFW/glfw3.h>
namespace ge {

#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application::Application()
	{
		window = std::unique_ptr<Window> (Window::Create());
		window->SetEventCallback(BIND_EVENT_FUNCTION(onEvent));
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
	void Application::onEvent(Event& e)
	{
		GE_CORE_INFO("{0}", e);
	}
}
