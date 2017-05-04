#include <iostream>
#include "circle.hpp"
#include <cmath>

	Circle::Circle(float a, Vec2 const& b, Color const& c):
		r{a}, mid{b}, color{c}{}

		float const Circle::getR()
		{
			return r;
		}

		Vec2 const Circle::getMid()
		{
			return mid;
		}



		void Circle::draw(Window const& window)
		{
			//middle
			//window.draw_point(mid.x, mid.y, color.r, color.g, color.b);
			
			float degree45 = sqrt((r*r)/2);
			//lines
			window.draw_line(mid.x + r, mid.y, mid.x + degree45, mid.y - degree45, color.r, color.g, color.b);
			window.draw_line(mid.x + degree45, mid.y - degree45, mid.x, mid.y - r, color.r, color.g, color.b);
			window.draw_line(mid.x, mid.y - r, mid.x - degree45, mid.y - degree45, color.r, color.g, color.b);
			window.draw_line(mid.x - degree45, mid.y - degree45, mid.x - r, mid.y, color.r, color.g, color.b);
			window.draw_line(mid.x - r, mid.y, mid.x - degree45, mid.y + degree45, color.r, color.g, color.b);
			window.draw_line(mid.x - degree45, mid.y + degree45, mid.x, mid.y + r, color.r, color.g, color.b);
			window.draw_line(mid.x, mid.y + r, mid.x + degree45, mid.y + degree45, color.r, color.g, color.b);
			window.draw_line(mid.x + degree45, mid.y + degree45, mid.x + r, mid.y, color.r, color.g, color.b);
		}