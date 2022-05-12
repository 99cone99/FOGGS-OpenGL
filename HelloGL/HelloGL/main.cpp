#include "HelloGL.h"
#include <iostream>

HelloGL::HelloGL(int argc, char* argv[])
{
	HelloGL::InitGL(argc, argv);
	HelloGL::InitObjects();
	glutMainLoop();
	initLighting();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (size_t i = 0; i < 20; i++)
	{
		cube[i]->Draw();
	}
	//for (size_t i = 0; i < 20; i++)
	//{
	//	pyramid[i]->Draw();
	//}
	
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	for (size_t i = 0; i < 20; i++)
	{
		cube[i]->Update();
	}
	//for (size_t i = 0; i < 20; i++)
	//{
	//	pyramid[i]->Update();
	//}

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