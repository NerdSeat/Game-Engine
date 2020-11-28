#pragma once
#include <gepch.h>
#include "Engine/core.h"
#include "Engine/Event/Event.h"

namespace ge {

	struct WindowProperties
	{
		std::string title;
		unsigned int height;
		unsigned int width;
		WindowProperties(const std::string& t = "Game Engine",unsigned int h=1080,unsigned int w = 1920)
			:title(t),height(h),width(w){}

	};

	//interface for the window system
	class GAMEENGINE_API Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;
		virtual ~Window(){}
		virtual void onUpdate() = 0;
		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual unsigned int getWidth()const = 0;
		virtual unsigned int getHeight()const = 0;
		//Attributes
		virtual void setSync(bool enabled) = 0;
		virtual bool isSync()const = 0;
		//Factory pattern for creating the required window in the platform the engine is running on
		static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}