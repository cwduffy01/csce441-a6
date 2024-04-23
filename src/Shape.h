#ifndef SHAPE_H
#define SHAPE_H

#include "Hit.h"
#include "helpers.h"
#include <glm/glm.hpp>

class Shape {
public:
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	glm::vec3 diffuse;
	glm::vec3 ambient;
	glm::vec3 specular;
	float exponent;

	bool reflective = false;

	Shape();

	virtual Hit* intersect(const glm::vec3& p, const glm::vec3& v) = 0;
};

#endif