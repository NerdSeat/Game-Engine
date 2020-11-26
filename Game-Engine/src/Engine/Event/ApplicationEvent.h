#pragma once
#include <sstream>
#include "Event.h"

namespace ge {

	class GAMEENGINE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int w,unsigned int h)
			:width(w),height(h){}
		inline unsigned int getWidth()const { return width; }
		inline unsigned int getHeight()const { return height; }
		std::string ToString()const override
		{
			std::stringstream stream;
			stream << "WindowResizeEvent: " << getWidth() << ", " << getHeight();
			return stream.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CAT(EventCatApplication)
	private:
		unsigned int width, height;
	};

	class GAMEENGINE_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent(){}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CAT(EventCatApplication)
	};

	class GAMEENGINE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CAT(EventCatApplication)
	};

	class GAMEENGINE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CAT(EventCatApplication)
	};

	class GAMEENGINE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CAT(EventCatApplication)
	};

}