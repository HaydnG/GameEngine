#pragma once

#include <GLFW/glfw3.h>
#include <Log/Log.h>

namespace HayEngine { namespace Graphics {

	class Window {

	private:
		const char *title;
		int width, height;
		GLFWwindow *screen;
		bool Closed;
	public:
		Window(const char *name, int width, int height);
		~Window();
		bool IsClosed() const;
		void Clear() const;
		void Update();
		
		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }

	private:
		bool Init();


	};


}}