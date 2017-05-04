#include <iostream>
#include "circle.hpp"
#include "vec2.hpp"

	Circle::Circle(float a, Vec2 const& b):
		r{a}, mid{b}{}

		float const Circle::getR()
		{
			return r;
		}

		Vec2 const Circle::getMid()
		{
			return mid;
		}

		