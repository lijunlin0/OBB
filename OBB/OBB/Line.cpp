#include<graphics.h>
#include<math.h>
#include<iostream>
#include "Line.h"
const double PI = 3.1415926;

Line::Line(float x, float y, float angle, float size)
{
	X = x;
	Y = y;
	this->angle = angle;
	this->size = size;
}

void Line::draw()
{
	float radian = angle * PI / 180;
	float x = X + size * cos(radian);
	float y = Y + size * sin(radian);
	line(X, Y, x, y);
}

pair<float, float> Line::get_point(float x, float y, float angle, float size)
{
	float radian = angle * PI / 180;
	float x1 = x + size * cos(radian);
	float y1 = y + size * sin(radian);
	pair<float, float> p;
	p.first = x1;
	p.second = y1;
	return p;
}

pair<float, float> Line::get_end_point()
{
	return pair<float, float> (get_point(X, Y, angle, size));
}
