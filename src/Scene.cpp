#include "Scene.h"

shared_ptr<Hit> Scene::hit(const camray& ray) {
	float min_t = 100000000.0;
	//int min_ind = -1;

	shared_ptr<Hit> rtn = nullptr;

	for (int i = 0; i < shapes.size(); i++) {
		auto h = shapes.at(i)->intersect(ray.p, ray.v);
		if (h != nullptr && h->t < min_t) {
			min_t = h->t;
			rtn = h;
			/*struct camray ref { h-> };*/
		}
	}

	return rtn;
}