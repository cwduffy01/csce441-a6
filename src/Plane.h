#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
public:
	shared_ptr<Hit> Plane::intersect(const glm::vec3& p, const glm::vec3& v);

	glm::vec3 normal = glm::vec3(0.0f, 1.0f, 0.0f);
};

#endif