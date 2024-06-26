#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Shape.h"
#include "Light.h"
#include "Camera.h"

using namespace std;

class Scene {
public:
	vector<Shape*> shapes;
	vector<Light*> lights;

	shared_ptr<Hit> hit(const camray& ray);
};

#endif