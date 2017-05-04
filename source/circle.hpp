#include <iostream>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

struct Circle
{
	Circle(float a, Vec2 const& b, Color const& c);
	float const getR();
	Vec2 const getMid();
	void draw(Window const& window);


	float r;
	Vec2 mid;
	Color color;
	
};


#endif