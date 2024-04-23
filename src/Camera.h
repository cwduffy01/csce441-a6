#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <vector>

using namespace std;

struct camray {
	glm::vec3 p;
	glm::vec3 v;
};

class Camera {
public:
	glm::vec3 eye;
	glm::vec3 lookat;
	glm::vec3 up;
	float fovy;
	float focal_dist;
	int width;
	int height;

	vector<camray> rays;
};

#endif