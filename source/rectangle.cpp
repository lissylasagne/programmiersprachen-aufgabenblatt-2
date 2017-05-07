#include <iostream>
#include "rectangle.hpp"

	Rectangle::Rectangle(Vec2 const& a, Vec2 const& b, Color const& c):
		min_{a}, max_{b}, color{c}{}

		Vec2 const Rectangle::getMin() const
		{
			return min_;
		}

		Vec2 const Rectangle::getMax() const
		{
			return max_;
		}

		//rechter unterer Punkt
		Vec2 const Rectangle::getRightLow() const
		{
			return Vec2(max_.x, min_.y);
		}

		//linker oberer Punkt
		Vec2 const Rectangle::getLeftHigh() const
		{
			return Vec2(min_.x, max_.y);
		}

		//Umfang
		float const Rectangle::circumference() const
		{
			float a = getRightLow().x - min_.x;
			float b = max_.y - getRightLow().y;
			float c = max_.x - getLeftHigh().x;
			float d = getLeftHigh().y - min_.y;

			return(a + b + c + d);
		}

		void Rectangle::draw(Window const& window) const
		{
			//draw 4 lines
			window.draw_line(min_.x, min_.y, max_.x, min_.y, color.r, color.g, color.b);
			window.draw_line(max_.x, min_.y, max_.x, max_.y, color.r, color.g, color.b);
			window.draw_line(max_.x, max_.y, min_.x, max_.y, color.r, color.g, color.b);
			window.draw_line(min_.x, max_.y, min_.x, min_.y, color.r, color.g, color.b);

		}

		void Rectangle::draw(Window const& window, Color const& c) const
		{
			//draw 4 lines
			window.draw_line(min_.x, min_.y, max_.x, min_.y, c.r, c.g, c.b);
			window.draw_line(max_.x, min_.y, max_.x, max_.y, c.r, c.g, c.b);
			window.draw_line(max_.x, max_.y, min_.x, max_.y, c.r, c.g, c.b);
			window.draw_line(min_.x, max_.y, min_.x, min_.y, c.r, c.g, c.b);

		}

		bool Rectangle::is_inside(Vec2 const& v) const
		{
			if(v.x > max_.x || v.x < min_.x || v.y > max_.y || v.y < min_.y) {
				return false;
			} else {
				return true;
			}

		}

		void Rectangle::setColor(Color const& c)
		{
			color.setColor(c.r, c.g, c.b);
		}




