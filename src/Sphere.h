#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
	shared_ptr<Hit> Sphere::intersect(const glm::vec3& p, const glm::vec3& v);
};

#endif