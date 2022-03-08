#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "MeshLoader.h"
#include "SceneObject.h"

#define REFRESHRATE 16
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800



class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void InitObjects()
	{
		camera = new Camera();
		camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
		camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
		camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

		Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");

		for (size_t i = 0; i < 50; i++)
		{
			object[i] = new Cube(cubeMesh, (rand() % 400 / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
		}

	}
	void InitGL(int argc, char* argv[])
	{
		GLUTCallbacks::Init(this);
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
		glutCreateWindow("Simple OpenGL Program");
		glutKeyboardFunc(GLUTCallbacks::Keyboard);
		glutDisplayFunc(GLUTCallbacks::Display);
		glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		gluPerspective(90, 1, 1, 1000);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		glCullFace(GL_BACK);
	}
private:
	Camera* camera;
	Cube* object[50];
};

