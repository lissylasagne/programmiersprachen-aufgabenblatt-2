#include <iostream>
#include "vec2.hpp"
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

struct Circle
{
	Circle(float a, Vec2 const& b);
	float const getR();
	Vec2 const getMid();
	

	float r;
	Vec2 mid;
	
};


#endif