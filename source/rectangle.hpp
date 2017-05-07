#include <iostream>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

struct Rectangle
{
	Rectangle(Vec2 const& a, Vec2 const& b, Color const& c);
	Vec2 const getMin() const;
	Vec2 const getMax() const;
	Vec2 const getRightLow() const;
	Vec2 const getLeftHigh() const;
	float const circumference() const;
	void draw(Window const& window) const;
	void draw(Window const& window, Color const& color) const;
	bool is_inside(Vec2 const& v) const;
	void setColor(Color const& c);

	Vec2 min_;
	Vec2 max_;
	Color color;
	
};


#endif