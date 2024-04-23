#include "Scene.h"

Shape* Scene::hit(const camray& ray) {
	float min_t = 100000000.0;
	//int min_ind = -1;

	Shape* rtn = nullptr;

	for (int i = 0; i < shapes.size(); i++) {
		Hit* h = shapes.at(i)->intersect(ray.p, ray.v);
		if (h != nullptr && h->t < min_t) {
			min_t = h->t;
			rtn = shapes.at(i);
		}
	}

	return rtn;
}