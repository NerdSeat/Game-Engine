#include "gepch.h"
#include "WindowsWindow.h"
#include "Engine/Event/ApplicationEvent.h"
#include "Engine/Event/KeyEvent.h"
#include "Engine/Event/MouseEvent.h"
namespace ge {
	static bool GLFWInitialised = false;
	
	static void GLFWErrorCallback(int error, const char* description)
	{
		GE_CORE_ERROR("GLFW Error({0}):{1}",error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFWInitialised = true;
		}

		window = glfwCreateWindow((int)properties.width, (int)properties.height, data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		setSync(true);

		//set glfw callback functions
		glfwSetWindowSizeCallback(window, [](GLFWwindow* win, int width, int height)
		{
			WindowData& new_data = *(WindowData*)glfwGetWindowUserPointer(win);
			new_data.width = width;
			new_data.height = height;
			WindowResizeEvent event(width, height);
			new_data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* win)
		{
			WindowData& new_data = *(WindowData*)glfwGetWindowUserPointer(win);
			WindowClosedEvent event;
			new_data.eventCallback(event);
		});

		glfwSetKeyCallback(window, [](GLFWwindow* win, int key, int scancode, int action, int mods)
		{
			WindowData& new_data = *(WindowData*)glfwGetWindowUserPointer(win);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					new_data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					new_data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					new_data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow * win, int button, int action, int mods)
		{
			WindowData& new_data = *(WindowData*)glfwGetWindowUserPointer(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					new_data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					new_data.eventCallback(event);
					break;
				}
			}

		});
		glfwSetScrollCallback(window, [](GLFWwindow* win, double xOffset, double yOffset)
		{
			WindowData& new_data = *(WindowData*)glfwGetWindowUserPointer(win);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			new_data.eventCallback(event);
		});
		glfwSetCursorPosCallback(window, [](GLFWwindow* win,double xPost,double yPost)
		{
			WindowData& new_data = *(WindowData*)glfwGetWindowUserPointer(win);
			MouseMovedEvent event((float)xPost, (float)yPost);
			new_data.eventCallback(event);
		});
	}
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}

}