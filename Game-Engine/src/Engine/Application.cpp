#include <gepch.h>
#include "Application.h"
#include "Engine/Event/Event.h"

#include <GLFW/glfw3.h>
namespace ge {

#define BIND_EVENT_FUNCTION(x) std::bind(&x,this,std::placeholders::_1)

	Application::Application()
	{
		window = std::unique_ptr<Window> (Window::Create());
		window->SetEventCallback(BIND_EVENT_FUNCTION(Application::onEvent));
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
		EventDispatcher dispacth(e);
		dispacth.Dispatch<WindowClosedEvent>(BIND_EVENT_FUNCTION(Application::onWindowClose));
		GE_CORE_TRACE("{0}", e);
	}
	bool Application::onWindowClose(WindowClosedEvent& e)
	{
		running = false;
		return true;
	}
}
