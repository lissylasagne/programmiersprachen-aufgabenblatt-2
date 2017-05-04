#include <iostream>
#ifndef COLOR_HPP
#define COLOR_HPP

struct Color
{
	Color(float d);
	Color(float a, float b, float c);


	float r;
	float g;
	float b;
};

#endif