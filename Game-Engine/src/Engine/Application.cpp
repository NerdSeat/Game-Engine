#include <gepch.h>
#include "Application.h"
#include "Engine/Event/Event.h"
#include"Engine/Event/ApplicationEvent.h"
#include "Engine/Log.h"
namespace ge {


	Application::Application()
	{
	}
	Application::~Application()
	{

	}
	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		GE_TRACE(e);
		while (true);
	}
}
