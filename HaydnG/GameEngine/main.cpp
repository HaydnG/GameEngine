#include <GLFW/glfw3.h>
#include <iostream>
#include <Main/HayEngine.h>

int main() {

	using namespace Graphics;
	Print("hello");
	Window window("HayEngine!", 960, 540);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);//Set colour to blue (RGB)

	

	while (!window.IsClosed()) {
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		//Print(window.getWidth(),", ",window.getHeight());
		window.Clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
		window.Update();

	}

	

}