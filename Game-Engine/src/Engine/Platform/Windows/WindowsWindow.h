#pragma once
#include "Window.h"
#include <GLFW/glfw3.h>
namespace ge{

		class WindowsWindow : public Window
		{
		public:
			WindowsWindow(const WindowProperties& properties);
			virtual ~WindowsWindow();

			void onUpdate() override;
			inline unsigned int getWidth() const override { return data.width; }
			inline unsigned int getHeight() const override { return data.height; }
			
			//Attributes
			inline void SetEventCallback(const EventCallbackFunction& callback) override { data.eventCallback = callback; }
			void setSync(bool enabled)override;
			bool isSync()const override;

		private:
			virtual void init(const WindowProperties& properties);
			virtual void Shutdown();
		private:
			GLFWwindow* window;

			struct WindowData
			{
				std::string title;
				unsigned int width, height;
				bool sync;
				EventCallbackFunction eventCallback;

			};
			WindowData data;
		};
}

