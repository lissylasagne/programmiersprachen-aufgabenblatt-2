#include <iostream>
#include "vec2.hpp"
#ifndef MAT2_HPP
#define MAT2_HPP

struct Mat2
{
	Mat2();
	Mat2(float a, float b, float c, float d);
	Vec2 vecmat (Vec2 const& v) const;
	float const det() const; 
	Mat2 const inv() const;
	Mat2 const tra()const;

	Mat2& operator*=(Mat2 const& m);

	float w;
	float x;
	float y;
	float z;
};

Mat2 const operator* (Mat2 const& m1, Mat2 const& m2);
Mat2 const rot(float b);

#endif