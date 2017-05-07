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
			draw(window, color);

		}

		void Circle::draw(Window const& window, Color const& c)
		{
			Mat2 matA = rot(0.2617994);
			Vec2 vecA(r, 0.0);
			

			for (int i = 1; i <= 24; i++){
				Vec2 vecB = matA.vecmat(vecA);
				window.draw_line(mid.x + vecA.x, mid.y + vecA.y, mid.x + vecB.x, mid.y + vecB.y, c.r, c.g, c.b);
				vecA = (matA.vecmat(vecA)); 
			}

		}

		bool Circle::is_inside(Vec2 const& v)
		{
			if(((v.x - mid.x) * (v.x - mid.x) + (v.y - mid.y) * (v.y - mid.y)) > (r * r)) {
				return false;
			} else {
				return true;
			}
		}

		void Circle::setColor(Color const& c)
		{
			color.setColor(c.r, c.g, c.b);
		}




