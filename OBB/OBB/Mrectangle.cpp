#include "Mrectangle.h"
#include <graphics.h>
#include<iostream>
using namespace std;
Mrectangle::Mrectangle(float x, float y, float angle, float width, float height)
{
	this->angle = angle;
	this->width = width;
	this->height = height;
	int size;
	pair<float, float> p(x, y);
	int temp = angle;
	for (int i = 0; i < 4; i++,temp+=90)
	{
		vertexs.push_back(p);
		if (i % 2 == 0)
		{
			size = height;
		}
		else
		{
			size = width;
		}
		Line l(p.first, p.second, temp, size);
		p = l.get_end_point();
	}	
}
pair<float, float> Mrectangle::get_center()
{
	Line l(vertexs[0].first, vertexs[0].second, angle, height/2);
	pair<float, float> center_(l.get_end_point());
	Line temp1(center_.first, center_.second, l.get_angle() + 90, width/2);
	return temp1.get_end_point();
}

pair<pair<float, float>, pair<float, float>> Mrectangle::get_axis()
{
	pair<float, float> axisX(vertexs[1].first - vertexs[0].first, vertexs[1].second - vertexs[0].second);
	pair<float, float> axisY(vertexs[2].first - vertexs[1].first, vertexs[2].second - vertexs[1].second);
	return pair<pair<float, float>, pair<float, float>>(axisX,axisY);
}
