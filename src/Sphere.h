#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
	Hit* intersect(const glm::vec3& p, const glm::vec3& v);
};

#endif