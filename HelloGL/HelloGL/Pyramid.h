#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"




class Pyramid : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;
public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	void Draw();
	void Update();

	//static bool Load(char* path);
};

