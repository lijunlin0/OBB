#pragma once
#pragma once
#include<utility>
using namespace std;
class Line
{
private:
	//����
	float X;
	float Y;
	//�Ƕ�
	float angle;
	//����
	float size;
public:
	Line(float x, float y, float angle, float size);
	void draw();
	static std::pair<float, float> get_point(float x, float y, float angle, float size);
	float get_angle() { return angle; }
	pair<float, float> get_end_point();
};
