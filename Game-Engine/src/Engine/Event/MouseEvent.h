#pragma once
#include "Event.h"
#include <sstream>

namespace ge {

	class GAMEENGINE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) :mouseX(x), mouseY(y) {}
		inline float getX()const { return mouseX; }
		inline float getY()const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return stream.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CAT(EventCatMouse|EventCatInput)
	private:
		float mouseX, mouseY;
	};

	class GAMEENGINE_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float x,float y)
			:xOffset(x),yOffset(y){}
		inline float getXOffset()const { return xOffset; }
		inline float getYOffset()const { return yOffset; }
		std::string ToString()const override
		{
			std::stringstream stream;
			stream << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
			return stream.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CAT(EventCatMouse|EventCatInput)
	private:
		float xOffset, yOffset;
	};

	class GAMEENGINE_API MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton()const { return mouseButton; }

		EVENT_CLASS_CAT(EventCatMouse|EventCatMouseButton)
	protected:
		MouseButtonEvent(int button)
			:mouseButton(button) {}
		int mouseButton;
	};
	class GAMEENGINE_API MouseButtonPressedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button){}
		std::string ToString()const override
		{
			std::stringstream stream;
			stream << "MouseButtonPressed: " << mouseButton;
			return stream.str();
		}
		EVENT_CLASS_TYPE(MousePressed)
	};

	class GAMEENGINE_API MouseButtonReleasedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}
		std::string ToString()const override
		{
			std::stringstream stream;
			stream << "MouseButtonReleased: " << mouseButton;
			return stream.str();
		}
		EVENT_CLASS_TYPE(MouseReleased)
	};
}
