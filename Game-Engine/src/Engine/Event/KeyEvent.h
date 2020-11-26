#pragma once

#include "Event.h"
#include <sstream>
#include <string>
namespace ge {

	class GAMEENGINE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode()const { return keyCode; }

		//Keyboard event is also an input
		EVENT_CLASS_CAT(EventCatKeyboard | EventCatInput)

	protected:
		KeyEvent(int keycode):keyCode(keycode){}
		int keyCode;
	};

	class GAMEENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode,int repeatkeycount)
			:KeyEvent(keycode),repeatKeyCount(repeatkeycount){}
		inline int GetRepeatKeyCount()const { return repeatKeyCount; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyPressedEvent: " << keyCode << "(" << repeatKeyCount << " repeats)";
			return stream.str();
		}

		static EventType GetStaticType() { return EventType::KeyPressed; }
		virtual EventType GetEventType()const override { return GetStaticType(); }
		virtual const char* GetName()const override { return "KeyPressed"; }

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatKeyCount;
	};

	class GAMEENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode){}

		std::string ToString()const override
		{
			std::stringstream stream;
			stream << "KeyReleasedEvent: " << keyCode;
			return stream.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};

}