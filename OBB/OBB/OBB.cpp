#include <graphics.h>
#include <conio.h>
#include<iostream>
#include<cmath>
#include"Line.h"
#include<vector>
#include "Mrectangle.h"
using namespace std;

const double PI = 3.1415926;
const int WIDTH = 1000;
const int HEIGHT = 1000;


float dot(pair<float, float> p1, pair<float, float> p2)
{
	return (p1.first * p2.first) + (p1.second * p2.second);
}
float minmax(float a,float b,bool is_min)
{
	if (is_min = true)
	{
		return a < b ? a : b;
	}
	else
	{
		return a > b ? a : b;
	}
}
bool intersect(Mrectangle a, Mrectangle b, pair<float,float> axis)
{
	float minT1 = 99999999;
	float maxT1 = 0;
	float minT2 = 99999999;
	float maxT2 = 0;

	for (int i = 0; i < a.get_vertexs().size(); i++)
	{
		float Dot = 0;
	    //矩形a投影
		Dot = dot(a.get_vertexs()[i], axis);
		minT1 = min(minT1, Dot);
		maxT1 = max(maxT1, Dot);

		//矩形b投影
		Dot = dot(b.get_vertexs()[i], axis);
		minT2 = min(minT2, Dot);
		maxT2 = max(maxT2, Dot);
	}
	if (maxT1 < minT2 || maxT2 < minT1)
	{
		return false;
	}
	return true;
}
void OBB(Mrectangle a,Mrectangle b)
{
	bool one = intersect(a, b, a.get_axis().first);
	bool two = intersect(a, b, a.get_axis().second);
	bool three = intersect(a, b, b.get_axis().first);
	bool four = intersect(a, b, b.get_axis().second);
	if (one && two && three && four)
	{
		
		setfillcolor(RED);
	}
	else
	{
		setfillcolor(WHITE);
	}

}
void init(int x,int y,float angle1,float angle2)
{
	//矩形初始化
	Mrectangle a(x, y-200, angle1, 400, 200);
	Mrectangle b(200, 200, angle2, 400,200);
	
	POINT pts1[] = { {a.get_vertexs()[0].first, a.get_vertexs()[0].second},  {a.get_vertexs()[1].first, a.get_vertexs()[1].second},  {a.get_vertexs()[2].first, a.get_vertexs()[2].second}, {a.get_vertexs()[3].first, a.get_vertexs()[3].second} };
	solidpolygon(pts1, 4);
	POINT pts2[] = { {b.get_vertexs()[0].first, b.get_vertexs()[0].second},  {b.get_vertexs()[1].first, b.get_vertexs()[1].second},  {b.get_vertexs()[2].first, b.get_vertexs()[2].second}, {b.get_vertexs()[3].first, b.get_vertexs()[3].second} };
	solidpolygon(pts2, 4);


	OBB(a, b);
}
int main()
{

	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	setorigin(0, HEIGHT);
	setaspectratio(1, -1);
	//左下角为坐标原点，X轴向右为正，Y轴向上为正
	float angle1 = 0;
	float angle2 = 0;
	ExMessage msg;
	while (true)
	{
		bool b = peekmessage(&msg, EX_MOUSE);
		int x = msg.x;
		int y = HEIGHT-msg.y;
		BeginBatchDraw();

		clearrectangle(0, HEIGHT, WIDTH, 0);

		init(x,y,30,-45);

		EndBatchDraw();
	}
	getchar();
	return 0;
}