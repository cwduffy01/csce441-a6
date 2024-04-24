#include "Plane.h"

shared_ptr<Hit> Plane::intersect(const glm::vec3& p, const glm::vec3& v) {
	glm::vec3 n(0.0f, 1.0f, 0.0f);

	if (glm::dot(n, v) < 0) {
		float t = glm::dot(n, position - p) / glm::dot(n, v);
		glm::vec3 x = p + t * v;
		auto h = make_shared<Hit>(x, n, t);

		h->ambient = this->ambient;
		h->diffuse = this->diffuse;
		h->specular = this->specular;
		h->exponent = this->exponent;

		return h;
	}
	return nullptr;
}