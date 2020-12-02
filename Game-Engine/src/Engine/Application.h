#pragma once
#include "core.h"
#include "Event/Event.h"
#include "Window.h"
#include"Engine/Event/ApplicationEvent.h"
namespace ge {

	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void onEvent(Event& e);

	private:
		bool onWindowClose(WindowClosedEvent& e);
		std::unique_ptr<Window> window;
		bool running = true;
	};
	Application* CreateApplication();
}

