#include <iostream>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

struct Rectangle
{
	Rectangle(Vec2 const& a, Vec2 const& b, Color const& c);
	Vec2 const getMin();
	Vec2 const getMax();
	Vec2 const getRightLow();
	Vec2 const getLeftHigh();
	float const circumference();
	void draw(Window const& window);
	void draw(Window const& window, Color const& color);
	bool is_inside(Vec2 const& v);
	void setColor(Color const& c);

	Vec2 min_;
	Vec2 max_;
	Color color;
	
};


#endif