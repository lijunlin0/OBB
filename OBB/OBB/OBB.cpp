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
	//���½�Ϊ����ԭ�㣬X������Ϊ����Y������Ϊ��
	setaspectratio(1, -1);
	setorigin(0, HEIGHT);
	getchar();
	return 0;
}