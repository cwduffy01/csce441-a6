#include "helpers.h"

struct camray {
	glm::vec3 p;
	glm::vec3 v;
};

ostream& operator<< (ostream& os, const glm::vec3& v) {
	os << "( " << v.x << " " << v.y << " " << v.z << " )";
	return os;
}