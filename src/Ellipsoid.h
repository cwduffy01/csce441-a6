#ifndef ELLIPSOID_H
#define ELLIPSOID_H

#include "Shape.h"

class Ellipsoid : public Shape {
public:
	shared_ptr<Hit> Ellipsoid::intersect(const glm::vec3& p, const glm::vec3& v);
	void set_E();

	glm::mat4 E;
	glm::mat4 E_inv;
	glm::mat4 E_inv_tr;
};

#endif