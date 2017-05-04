#include <iostream>
#include "color.hpp"

Color::Color(float d):
	r{d}, g{d}, b{d}{}

Color::Color(float a, float b, float c):
	r{a}, g{b}, b{c}{}

void Color::setColor(float r, float g, float b){
	this -> r = r;
	this -> g = g;
	this -> b = b;
}

