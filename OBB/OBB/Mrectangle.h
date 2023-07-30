#pragma once
#include<vector>
#include"Line.h"
using namespace std;
class Mrectangle
{
private:
	pair<float, float> center;
	vector<pair<float, float>> vertexs;
	float angle;
	float width;
	float height;
	pair<pair<float, float>, pair<float, float>> axis;
	pair<float, float>axisY;
public:
	Mrectangle(float x,float y,float angle,float width,float height);
	pair<float, float> get_center();
	vector<pair<float, float>> get_vertexs() { return vertexs; }
	pair<pair<float, float>, pair<float, float>> get_axis();
};
