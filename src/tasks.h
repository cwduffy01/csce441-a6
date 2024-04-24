#include "Scene.h"
#include "Sphere.h"

shared_ptr<Scene> scene1() {
	shared_ptr<Scene> scene = make_shared<Scene>();

	Sphere sph1;
	sph1.position = glm::vec3(-0.5f, -1.0f, 1.0f);
	sph1.diffuse = glm::vec3(1.0f, 0.0f, 0.0f);
	sph1.specular = glm::vec3(1.0f, 1.0f, 0.5f);
	sph1.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
	sph1.exponent = 100.0;

	Sphere sph2;
	sph2.position = glm::vec3(0.5f, -1.0f, -1.0f);
	sph2.diffuse = glm::vec3(0.0f, 1.0f, 0.0f);
	sph2.specular = glm::vec3(1.0f, 1.0f, 0.5f);
	sph2.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
	sph2.exponent = 100.0;

	Sphere sph3;
	sph3.position = glm::vec3(0.0f, 1.0f, 0.0f);
	sph3.diffuse = glm::vec3(0.0f, 0.0f, 1.0f);
	sph3.specular = glm::vec3(1.0f, 1.0f, 0.5f);
	sph3.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
	sph3.exponent = 100.0;

	Light l1;
	l1.position = glm::vec3(-2.0f, 1.0f, 1.0f);

	scene->shapes.insert(scene->shapes.end(), { &sph1, &sph2, &sph3 });
	scene->lights.push_back(&l1);

	return scene;
}