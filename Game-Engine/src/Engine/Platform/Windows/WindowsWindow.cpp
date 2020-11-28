#include "gepch.h"
#include "WindowsWindow.h"

namespace ge {
	static bool GLFWInitialised = false;

	Window* Window::Create(const WindowProperties& properties)
	{
		return new WindowsWindow(properties);
	}
	
	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		init(properties);
	}
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	void WindowsWindow::setSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.sync = enabled;
	}
	bool WindowsWindow::isSync() const
	{
		return data.sync;
	}
	void WindowsWindow::init(const WindowProperties& properties)
	{
		data.title = properties.title;
		data.height = properties.height;
		data.width = properties.width;

		GE_CORE_INFO("Creating Window {0} ({1},{2})", properties.title, properties.width, properties.height);

		if (!GLFWInitialised)
		{
			int success = glfwInit();
			GE_CORE_ASSERT(success, "Could not initialise GLFW!");

			GLFWInitialised = true;
		}

		window = glfwCreateWindow((int)properties.width, (int)properties.height, data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		setSync(true);

	}
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}

}