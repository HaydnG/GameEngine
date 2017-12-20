#include <Graphics/window.h>

namespace HayEngine { namespace Graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *_title, int _width, int _height) {
		title = _title;
		width = _width;
		height = _height;
		if (!Init()) {
			glfwTerminate();
		}
	}

	bool Window::Init() {

		if (!glfwInit()) {
			Print("Error: GLFW not initialised");
			return false;
		}


		screen = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!screen) {		
			Print("Failed to create window");
			return false;
		}
		glfwMakeContextCurrent(screen);
		glfwSetWindowSizeCallback(screen, windowResize);
		return true;
	}

	void Window::Clear() const{
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Window::Update() {
		glfwPollEvents();
		//glfwGetFramebufferSize(screen, &width, &height);
		glfwSwapBuffers(screen);
	}

	bool Window::IsClosed() const {
		return glfwWindowShouldClose(screen);
	}

	Window::~Window() {
		glfwTerminate();
	}

	void windowResize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

}}