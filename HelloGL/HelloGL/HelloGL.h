#pragma once
#include <time.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Pyramid.h"
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
		srand(time(NULL));
		camera = new Camera();
		camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 5.0f;
		camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
		camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

		Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
		//Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

		Texture2D* texture = new Texture2D();
		texture->Load((char*)"penguins.raw", 512, 512);

		for (size_t i = 0; i < 20; i++)
		{
			cube[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 400) / 10.0f)- 20.0f, -((rand() % 1000) / 10.0f));

		}
		
		//for (size_t i = 0; i < 20; i++)
		//{
		//	pyramid[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 400) / 10.0f) - 20.0f, -((rand() % 1000) / 10.0f));
		//}

		

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
		gluPerspective(45, 1, 1, 1000);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glCullFace(GL_BACK);	
	}

	void initLighting()
	{
		_lightPosition = new Vector4();
		_lightPosition->x = 0.0;
		_lightPosition->y = 0.0;
		_lightPosition->z = 1.0;
		_lightPosition->w = 0.0;

		_lightData = new Lighting();
		_lightData->Ambient.x = 0.2;
		_lightData->Ambient.y = 0.2;
		_lightData->Ambient.z = 0.2;
		_lightData->Ambient.w = 1.0;
		_lightData->Diffuse.x = 0.8;
		_lightData->Diffuse.y = 0.8;
		_lightData->Diffuse.z = 0.8;
		_lightData->Diffuse.w = 1.0;
		_lightData->Specular.x = 0.2;
		_lightData->Specular.y = 0.2;
		_lightData->Specular.z = 0.2;
		_lightData->Specular.w = 1.0;
	}


private:
	Camera* camera;
	SceneObject* cube[50];
	Vector4* _lightPosition;
	Lighting* _lightData;
	//SceneObject* pyramid[50];
};

