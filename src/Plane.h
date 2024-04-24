#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
public:
	shared_ptr<Hit> Plane::intersect(const glm::vec3& p, const glm::vec3& v);
};

#endif