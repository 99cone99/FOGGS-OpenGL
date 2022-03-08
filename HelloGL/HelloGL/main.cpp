#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	HelloGL::InitObjects();
	HelloGL::InitGL(argc, argv);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (size_t i = 0; i < 50; i++)
	{
		object[i]->Draw();
	}
	
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();

	for (size_t i = 0; i < 50; i++)
	{
		object[i]->Update();
	}

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
		camera->eye.z -= 0.1f;
	else if (key == 's')
		camera->eye.z += 0.1f;
	else if (key == 'd')
		camera->eye.x += 0.1f;
	else if (key == 'a')
		camera->eye.x -= 0.1f;
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

int main(int argc, char* argv[])
{
	HelloGL* game = new HelloGL(argc, argv);

	return 0;
}