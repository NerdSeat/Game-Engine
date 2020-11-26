#pragma once
#include "core.h"
namespace ge {

	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}

