#include <graphics.h>
#include <conio.h>
#include<iostream>
#include<math.h>
using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 1000;

int main()
{
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	//左下角为坐标原点，X轴向右为正，Y轴向上为正
	setaspectratio(1, -1);
	setorigin(0, HEIGHT);
	getchar();
	return 0;
}