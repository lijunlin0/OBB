#include "Mrectangle.h"
#include <graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
const double PI = 3.1415926;
Mrectangle::Mrectangle(float x, float y, float angle, float width, float height)
{
	center.first = x;
	center.second = y;
	this->angle = angle;
	this->width = width;
	this->height = height;
	float size = sqrt(width * width + height + height) / 2;
	float center_angle = atan(height / width) * 180 / PI;

	Line l1(x, y, -center_angle + angle, size);
	Line l2(x, y, center_angle + angle, size);
	Line l3(x, y, 180 - center_angle + angle, size);
	Line l4(x, y, -(180 - center_angle) + angle, size);

	vertexs.push_back(l1.get_end_point());
	vertexs.push_back(l2.get_end_point());
	vertexs.push_back(l3.get_end_point());
	vertexs.push_back(l4.get_end_point());
	POINT pts[] = { {vertexs[0].first, vertexs[0].second},  {vertexs[1].first,vertexs[1].second}, {vertexs[2].first, vertexs[2].second }, { vertexs[3].first,vertexs[3].second } };
	solidpolygon(pts, 4);
}
pair<float, float> Mrectangle::get_center()
{
	return center;
}

pair<pair<float, float>, pair<float, float>> Mrectangle::get_axis()
{
	float x1 = vertexs[1].first - vertexs[0].first;
	float y1 = vertexs[1].second - vertexs[0].second;
	float l1 = sqrt(x1 * x1 + y1 * y1);
	pair<float, float> axisX(x1/l1, y1/l1);
	x1 = vertexs[2].first - vertexs[1].first;
	y1 = vertexs[2].second - vertexs[1].second;
	l1= sqrt(x1 * x1 + y1 * y1);
	pair<float, float> axisY(x1 / l1, y1 / l1);
	return pair<pair<float, float>, pair<float, float>>(axisX,axisY);
}
