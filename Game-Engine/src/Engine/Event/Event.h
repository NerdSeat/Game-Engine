#pragma once

#include "Engine/core.h"

namespace ge {

	enum class EventType
	{
		None = 0,WindowClose,WindowResize,WindowFocus,
		WindowLostFocus,WindowMoved,AppTick,AppUpdate,
		AppRender,KeyPressed,KeyReleased,MousePressed,
		MouseReleased,MouseMoved,MouseScrolled
	};

	/*may need to filter some events according to category for logging
	
	Creating a bitfield to apply multiple categories to a single
	event type.
	*/
	enum EventCat
	{
		None=0,
		EventCatApplication = BIT(0),
		EventCatInput = BIT(1),
		EventCatKeyboard = BIT(2),
		EventCatMouse = BIT(3),
		EventCatMouseButton = BIT(4)

	};

#define EVENT_CLASS_TYPE(type)\
	static EventType GetStaticType(){return EventType::##type;}\
	virtual EventType GetEventType()const override {return GetStaticType();}\
	virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CAT(cat) virtual int GetCatFlags()const override{return cat;}

	//base class for events
	class GAMEENGINE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType()const = 0;
		virtual const char* GetName()const = 0;
		virtual int GetCatFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool isInCat(EventCat cat){return GetCatFlags() & cat;}
	protected:
		bool eventHandled = false;
	};
	
	class EventDispatcher
	{
		template<class T>
		using EventFunction = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e)
			:event(e){}

		template<class T>
		bool Dispatch(EventFunction<T> funct)
		{
			if(event.GetEventType()==T::GetStaticType())
			{
				event.eventHandled = funct(*(T*)&event);
				return true;
			}
		}

	private:
		Event& event;
	};
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
