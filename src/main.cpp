#define GLM_ENABLE_EXPERIMENTAL 0

#include <iostream>
#include <string>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#include "Image.h"
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <cmath>
#define M_PI	3.14159265358979323846

// This allows you to skip the `std::` in front of C++ standard library
// functions. You can also say `using std::cout` to be more selective.
// You should never do this in a header file.
using namespace std;

double RANDOM_COLORS[7][3] = {
	{0.0000,    0.4470,    0.7410},
	{0.8500,    0.3250,    0.0980},
	{0.9290,    0.6940,    0.1250},
	{0.4940,    0.1840,    0.5560},
	{0.4660,    0.6740,    0.1880},
	{0.3010,    0.7450,    0.9330},
	{0.6350,    0.0780,    0.1840},
};

glm::vec3 compute_ray_color(const camray& ray, shared_ptr<Scene> scene) {
	Shape* hit = scene->hit(ray);
	glm::vec3 color(0.0f, 0.0f, 0.0f);
	if (hit != nullptr) {
		color = hit->diffuse;
		//for (Light* light : scene->lights) {
		//	glm::vec3 l = 
		//	
		//}
	}
	return color;
}

int main(int argc, char **argv)
{
	int scene_num = stoi(argv[1]);
	string filename = string(argv[4]);

	auto scene = make_shared<Scene>();

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





	
	Camera cam;

	cam.eye = glm::vec3(0.0f, 0.0f, 5.0f);
	cam.lookat = glm::vec3(0.0f, 0.0f, -1.0f);
	cam.fovy = M_PI/ 4;

	cam.focal_dist = 1.0;

	cam.width = stoi(argv[2]);
	cam.height = stoi(argv[3]);

	float world_height = 2 * cam.focal_dist * tan(cam.fovy / 2);
	float pixel_size = world_height / cam.height;

	auto img = make_shared<Image>(cam.width, cam.height);


	for (int j = 0; j < cam.height; j++) {
		for (int i = 0; i < cam.width; i++) {
			float x = - cam.width / 2.0 + (i + 0.5);
			float y = - cam.height / 2.0 + (j + 0.5);
			
			glm::vec3 v = normalize(glm::vec3(pixel_size * x, pixel_size * y, -1.0));

			camray r = { cam.eye, v };
			
			//cam.rays.push_back(r);
			glm::vec3 color = 255.0f * compute_ray_color(r, scene);
			img->setPixel(i, j, (int)color.r, (int)color.g, (int)color.b);
		}
	}

	//camray r = { glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, -1.0f) };

	//sph.intersect(r.p, r.v);

	img->setPixel(0, 0, 255, 255, 255);

	img->writeToFile(filename);
	
	return 0;
}
