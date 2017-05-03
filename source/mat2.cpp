#include <iostream>
#include "mat2.hpp"

	Mat2::Mat2():
		w{1.0}, x{0}, y{0}, z{1.0}{}

	Mat2::Mat2(float a, float b, float c, float d):
		w{a}, x{b}, y{c}, z{d}{}

	Mat2& Mat2::operator*=(Mat2 const& m)
	{
		float w1 = w * m.w + x * m.y;
		float x1 = w * m.x + x * m.z;
		float y1 = y * m.w + z * m.y;
		float z1 = y * m.x + z * m.z;
		w = w1;
		x = x1;
		y = y1;
		z = z1;
		return *this;
	}

	Mat2 const operator* (Mat2 const& m1, Mat2 const& m2)
	{
		return Mat2(m1) *= m2;
	}