#include "Transform.h"

Transform::Transform()
{
	_modelMatrix = glm::mat4(1.0f);
	_position = glm::vec3(0.0, 0.0, 0.0);
	_rotation = glm::quat(glm::radians(glm::vec3(0.0f, 0.0f, 0.0f)));
	_scale = glm::vec3(1.0, 1.0, 1.0);
}

glm::mat4 Transform::GetModelMatrix()
{
	return _modelMatrix;
}

glm::vec3 Transform::GetPosition()
{
	return _position;
}

glm::quat Transform::GetRotation()
{
	return _rotation;
}

glm::vec3 Transform::GetScale()
{
	return _scale;
}

void Transform::SetPosition(float x, float y, float z)
{
	_position = glm::vec3(x, y, z);
	UpdateModelMatrix();
}

void Transform::SetRotation(float x, float y, float z)
{
	_rotation = glm::vec3(glm::radians(glm::vec3(x, y, z)));
	UpdateModelMatrix();
}

void Transform::SetScale(float x, float y, float z)
{
	_scale = glm::vec3(x, y, z);
	UpdateModelMatrix();
}

void Transform::UpdateModelMatrix()
{
	//rotacion
	_modelMatrix = glm::mat4_cast(_rotation);
	//escala
	_modelMatrix[0] = _modelMatrix[0] * _scale[0];
	_modelMatrix[1] = _modelMatrix[1] * _scale[1];
	_modelMatrix[2] = _modelMatrix[2] * _scale[2];
	//Transladar
	_modelMatrix[3][0] = _position[0];
	_modelMatrix[3][1] = _position[1];
	_modelMatrix[3][2] = _position[2];
}