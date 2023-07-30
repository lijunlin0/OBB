#pragma once
#pragma once
#include<utility>
using namespace std;
class Line
{
private:
	//坐标
	float X;
	float Y;
	//角度
	float angle;
	//长度
	float size;
public:
	Line(float x, float y, float angle, float size);
	void draw();
	static std::pair<float, float> get_point(float x, float y, float angle, float size);
	float get_angle() { return angle; }
	pair<float, float> get_end_point();
};
