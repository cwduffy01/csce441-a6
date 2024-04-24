#define GLM_ENABLE_EXPERIMENTAL 0

#include <iostream>
#include <string>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#include "Image.h"
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
#include "Ellipsoid.h"
#include "Plane.h"

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

glm::vec3 compute_ray_color(const camray& ray, shared_ptr<Scene> scene, Camera& cam) {
	shared_ptr<Hit> hit = scene->hit(ray);
	glm::vec3 color(0.0f, 0.0f, 0.0f);
	if (hit != nullptr) {
		color = hit->ambient;
		glm::vec3 e = glm::normalize(cam.eye - hit->x);
		for (Light* light : scene->lights) {
			glm::vec3 l = normalize(light->position - hit->x);
			glm::vec3 h = glm::normalize(e + l);

			camray light_ray = { hit->x, l };
			bool pass = false;
			for (int i = 0; i < scene->shapes.size(); i++) {
				auto h = scene->shapes.at(i)->intersect(light_ray.p, light_ray.v);
				if (h != nullptr && h->t > 1e-4) {
					//return color;
					pass = true;
					break;
				}
			}

			if (!pass) {
				glm::vec3 cd = hit->diffuse * max(0.0f, glm::dot(hit->n, l));
				glm::vec3 cs = hit->specular * pow(max(0.0f, glm::dot(hit->n, h)), hit->exponent);

				color += light->intensity * (cd + cs);
			}
			color = 0.5f * hit->n + glm::vec3(0.5f, 0.5f, 0.5f);
		}
	}

	if (color.r > 1) { color.r = 1.0f; }
	if (color.g > 1) { color.g = 1.0f; }
	if (color.b > 1) { color.b = 1.0f; }

	return color;
}

int main(int argc, char **argv)
{
	int scene_num = stoi(argv[1]);
	string filename = string(argv[4]);

	auto scene = make_shared<Scene>();

	if (scene_num == 1 || scene_num == 2) {
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
	}
	else if (scene_num == 3) {
		Plane p;
		p.position = glm::vec3(0.0f, -1.0f, 0.0f);
		p.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
		p.specular = glm::vec3(0.0f, 0.0f, 0.0f);
		p.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
		p.exponent = 0.0;

		Sphere sph1;
		sph1.position = glm::vec3(-0.5f, 0.0f, -0.5f);
		sph1.diffuse = glm::vec3(0.0f, 1.0f, 0.0f);
		sph1.specular = glm::vec3(1.0f, 1.0f, 0.5f);
		sph1.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
		sph1.exponent = 100.0;

		Ellipsoid ell1;
		ell1.position = glm::vec3(0.5f, 0.0f, 0.5f);
		ell1.scale = glm::vec3(0.5f, 0.6f, 0.2f);
		ell1.diffuse = glm::vec3(1.0f, 0.0f, 0.0f);
		ell1.specular = glm::vec3(1.0f, 1.0f, 0.5f);
		ell1.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
		ell1.exponent = 100.0;
		ell1.set_E();

		Light l1;
		l1.position = glm::vec3(1.0f, 2.0f, 2.0f);
		l1.intensity = 0.5;

		Light l2;
		l2.position = glm::vec3(-1.0f, 2.0f, -1.0f);
		l2.intensity = 0.5;

		scene->shapes.insert(scene->shapes.end(), { &p, &sph1, &ell1 });
		scene->lights.insert(scene->lights.end(), { &l1, &l2 });
	}
	

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
			glm::vec3 color = 255.0f * compute_ray_color(r, scene, cam);
			img->setPixel(i, j, (int)color.r, (int)color.g, (int)color.b);
		}
	}

	img->writeToFile(filename);
	
	return 0;
}
