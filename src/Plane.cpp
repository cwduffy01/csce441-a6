#include "Plane.h"

shared_ptr<Hit> Plane::intersect(const glm::vec3& p, const glm::vec3& v) {
	float t = glm::dot(normal, position - p) / glm::dot(normal, v);
	if (t > 0) {
		glm::vec3 x = p + t * v;
		auto h = make_shared<Hit>(x, normal, t);

		h->ambient = this->ambient;
		h->diffuse = this->diffuse;
		h->specular = this->specular;
		h->exponent = this->exponent;
		h->reflective = this->reflective;

		return h;
	}

	//if (glm::dot(normal, v) != 0) {
	//	
	//}
	return nullptr;
}