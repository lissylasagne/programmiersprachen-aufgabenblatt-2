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

		void Circle::draw(Window const& window, Color const& c)
		{
			//middle
			//window.draw_point(mid.x, mid.y, color.r, color.g, color.b);
			
			float degree45 = sqrt((r*r)/2);
			//lines
			window.draw_line(mid.x + r, mid.y, mid.x + degree45, mid.y - degree45, c.r, c.g, c.b);
			window.draw_line(mid.x + degree45, mid.y - degree45, mid.x, mid.y - r, c.r, c.g, c.b);
			window.draw_line(mid.x, mid.y - r, mid.x - degree45, mid.y - degree45, c.r, c.g, c.b);
			window.draw_line(mid.x - degree45, mid.y - degree45, mid.x - r, mid.y, c.r, c.g, c.b);
			window.draw_line(mid.x - r, mid.y, mid.x - degree45, mid.y + degree45, c.r, c.g, c.b);
			window.draw_line(mid.x - degree45, mid.y + degree45, mid.x, mid.y + r, c.r, c.g, c.b);
			window.draw_line(mid.x, mid.y + r, mid.x + degree45, mid.y + degree45, c.r, c.g, c.b);
			window.draw_line(mid.x + degree45, mid.y + degree45, mid.x + r, mid.y, c.r, c.g, c.b);
		}

		bool Circle::is_inside(Vec2 const& v)
		{
			float degree45 = sqrt((r*r)/2);

			if (v.x > mid.x + r || v.x < mid.x - r || v.y > mid.y + r || v.y < mid.y - r) {
				return false;
			} else if (v.x > mid.x + degree45 && v.y > mid.y + degree45) {
				return false;
			} else if (v.x > mid.x + degree45 && v.y < mid.y - degree45) {
				return false;
			} else if (v.x < mid.x - degree45 && v.y > mid.y + degree45) {
				return false;
			} else if (v.x < mid.x - degree45 && v.y < mid.y - degree45) {
				return false;
			} else {
				return true;
			}
		}

		void Circle::setColor(Color const& c)
		{
			color.setColor(c.r, c.g, c.b);
		}




