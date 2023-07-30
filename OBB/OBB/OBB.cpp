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
	if (is_min == true)
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
	float maxT1 = -minT1;
	float minT2 = minT1;
	float maxT2 = -minT1;

	for (int i = 0; i < a.get_vertexs().size(); i++)
	{
		float Dot = 0;
	    //矩形a投影
		Dot = dot(a.get_vertexs()[i], axis);
		minT1 = minmax(minT1, Dot,true);
		maxT1 = minmax(maxT1, Dot,false);
		//矩形b投影
		Dot = dot(b.get_vertexs()[i], axis);
		minT2 = minmax(minT2, Dot,true);
		maxT2 = minmax(maxT2, Dot,false);
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
		setfillcolor(LIGHTRED);
	}
	else
	{
		setfillcolor(WHITE);
	}

}
void init(int x,int y,float angle1,float angle2)
{
	//矩形初始化
	Mrectangle a(x, y, angle1, 400, 200);
	Mrectangle b(500, 500, angle2, 400,200);


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
		angle1 += 0.05;
		angle2 += 0.1;
		BeginBatchDraw();

		clearrectangle(0, HEIGHT, WIDTH, 0);

		init(x,y, angle1,angle2);

		EndBatchDraw();
	}
	getchar();
	return 0;
}