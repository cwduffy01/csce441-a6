#include "Scene.h"

shared_ptr<Hit> Scene::hit(const camray& ray) {
	float min_t = -1.0;
	shared_ptr<Hit> rtn = nullptr;

	for (int i = 0; i < shapes.size(); i++) {
		auto h = shapes.at(i)->intersect(ray.p, ray.v);
		if (h != nullptr) {
			if (h->t > 1e-4 && (min_t < 0 || h->t < min_t)) {
				min_t = h->t;
				rtn = h;
			}
		}
		
	}

	return rtn;
}