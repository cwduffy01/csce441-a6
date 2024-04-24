#include "Sphere.h"

shared_ptr<Hit> Sphere::intersect(const glm::vec3& p, const glm::vec3& v) {
	glm::vec3 pc = p - position;
	float a = glm::dot(v, v);
	float b = 2 * glm::dot(v, pc);
	float c = glm::dot(pc, pc) - pow(scale.x, 2);
	float d = pow(b, 2) - 4 * a * c;

	float t = -1.0;

	if (d > 0) {
		float t0 = (-b + sqrt(d)) / (2 * a);
		float t1 = (-b - sqrt(d)) / (2 * a);

		float t = fmin(t0, t1);
		glm::vec3 x = p + t * v;
		glm::vec3 n = glm::normalize((x - position) / scale.x);
		auto h = make_shared<Hit>(x, n, t);

		h->ambient = this->ambient;
		h->diffuse = this->diffuse;
		h->specular = this->specular;
		h->exponent = this->exponent;
		h->reflective = this->reflective;

		return h;
	}
	return nullptr;
}