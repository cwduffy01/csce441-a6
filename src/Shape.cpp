#include "Shape.h"

Shape::Shape() :
	position(0.0f, 0.0f, 0.0f),
	scale(1.0f, 1.0f, 1.0f),
	rotation(0.0f, 0.0f, 0.0f),
	diffuse(0.0f, 0.0f, 0.0f),
	ambient(0.0f, 0.0f, 0.0f),
	specular(0.0f, 0.0f, 0.0f),
	exponent(0.0f)
{};

Shape::Shape(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation, glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular, float exponent, bool reflective) {
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;
	this->diffuse = diffuse;
	this->ambient = ambient;
	this->specular = specular;
	this->exponent = exponent;
	this->reflective = reflective;
}