#include <iostream>
#include "rectangle.hpp"
#include "vec2.hpp"

	Rectangle::Rectangle(Vec2 const& a, Vec2 const& b):
		min_{a}, max_{b}{}

		Vec2 const Rectangle::getMin()
		{
			return min_;
		}

		Vec2 const Rectangle::getMax()
		{
			return max_;
		}

		//rechter unterer Punkt
		Vec2 const Rectangle::getRightLow()
		{
			return Vec2(max_.x, min_.y);
		}

		//linker oberer Punkt
		Vec2 const Rectangle::getLeftHigh()
		{
			return Vec2(min_.x, max_.y);
		}

		//Umfang
		float const Rectangle::circumference()
		{
			float a = getRightLow().x - min_.x;
			float b = max_.y - getRightLow().y;
			float c = max_.x - getLeftHigh().x;
			float d = getLeftHigh().y - min_.y;

			return(a + b + c + d);
		}