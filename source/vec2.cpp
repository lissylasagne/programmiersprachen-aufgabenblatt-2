#include <iostream>
#include "vec2.hpp"

	Vec2::Vec2():
		x{0}, y{0}{}

	Vec2::Vec2(float a, float b):
		x{a}, y{b}{}


	Vec2& Vec2::operator+=(Vec2 const& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vec2& Vec2::operator-=(Vec2 const& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		return *this;
	}

	Vec2& Vec2::operator*=(float s)
	{
		this->x *= s;
		this->y *= s;
		return *this;
	}

	Vec2& Vec2::operator/=(float s)
	{
		this->x /= s;
		this->y /= s;
		return *this;
	}

	Vec2 const operator+(Vec2 const& u, Vec2 const& v)
	{
		return Vec2(u) += v;
	}

	Vec2 const operator-(Vec2 const& u, Vec2 const& v)
	{
		return Vec2(u) -= v;
	}

	Vec2 const operator*(Vec2 const& v, float s)
	{
		return Vec2(v) *= s;
	}

	Vec2 const operator/(Vec2 const& v, float s)
	{
		return Vec2(v) /= s;
	}

	Vec2 const operator*(float s, Vec2 const& v)
	{
		return Vec2(v) *= s;
	}


