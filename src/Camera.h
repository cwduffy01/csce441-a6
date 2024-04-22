#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
	glm::vec3 position;
	glm::vec3 direction;
	float fov;
	float aspect;
	float plane_dist;


};

#endif