#pragma once
#include "core.h"
#include "Event/Event.h"
#include "Window.h"
namespace ge {

	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	private:
		std::unique_ptr<Window> window;
		bool running = true;
	};
	Application* CreateApplication();
}

