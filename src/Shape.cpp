#include "Shape.h"

Shape::Shape() :
	position(0.0f, 0.0f, 0.0f),
	scale(1.0f, 1.0f, 1.0f),
	rotation(0.0f, 0.0f, 0.0f),
	diffuse(0.0f, 0.0f, 0.0f),
	ambient(0.0f, 0.0f, 0.0f),
	specular(0.0f, 0.0f, 0.0f),
	exponent(0.0f)
{};