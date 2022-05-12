#include "Pyramid.h"
#include <fstream>
#include <iostream>

void Pyramid::Update()
{
	_rotation += 0.5f;
	if (_rotation >= 360.0f)
		_rotation = 0.0f;
}

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_rotation = 0.0f;
	_position.x = x;
	std::cout << _position.x << std::endl;
	_position.y = y;
	_position.z = z;
}


Pyramid::~Pyramid()
{

}

void Pyramid::Draw()
{
	/*if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 0.0f, 1.0f, -1.0f);
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}*/
}