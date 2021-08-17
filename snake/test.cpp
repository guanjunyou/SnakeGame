#include<iostream>
#include "snake.h"
#include "food.h"
/*
未实现的需求：
1 多难度梯级切换  yes
2 多个食物同时出现 
3 实时显示蛇的长度 yes
4 撞墙结束 yes
5 音乐效果
6 AI模式

2021/8/17  关竣佑
*/ 
using namespace std;
//写在这里 交互处理

snake *pSnake = new snake;
food *pFood = new food;
int SnakeSpeed;

void SetSnakeInit()
{
	pSnake->ReInit();
}

bool GameOver = false;

void eatFood(snake* pSnake, food *pFood)
{
	//当坐标相等时吃
	//类外访问保护成员，提供了公有接口
	if (pSnake->getSnakePos(0).x == pFood->getFoodPos().x&&
		pSnake->getSnakePos(0).y == pFood->getFoodPos().y)
	{
		//游戏引擎
		pSnake->getSnakeSize()++;
		pFood->getFlag() = 0;
	}
}

bool GameLevel() //控制游戏难度
{   
	bool other = false;
	char userkey = 49;
	//userkey = _getch();
	while(1) {
		other = false;
		if (_kbhit())
		{

			userkey = _getch();//conio.h
			switch (userkey)
			{
			case 49:
				pSnake->SetSnakeSpeed(100);
				break;
			case 50:
				pSnake->SetSnakeSpeed(50);
				break;
			case 51:
				pSnake->SetSnakeSpeed(20);
				break;
			case 52:
				GameOver = true;
				break;
			default:
				other = true;
				break;
				
			}
			if(!other)
			return true;
		}
	}
	return false;
}


void GameOn()//绘制游戏运行时右侧的界面
{
	setfillcolor(RGB(220,20,60));//颜色
	fillrectangle(600, 0, 610, 600);
	setfillcolor(RGB(220, 20, 60));//颜色
	fillrectangle(0, 590, 600, 600);
	setfillcolor(RGB(0, 139, 139));//颜色
	fillrectangle(610, 150, 1000, 160);
	setfillcolor(RGB(0, 139, 139));//颜色
	fillrectangle(610, 300, 1000, 310);

	char str[32];
	char str2[64];
	char str3[64];
	char str4[64];
	char str5[64];
	char str6[64];
	int score = pSnake->getSnakeSize();
	settextcolor(0x40E0D0);
	//settextstyle(50, 0, "楷体");
	sprintf_s(str, "蛇长：%d\n", score);	//格式化数据转字符串
	settextstyle(40, 0, "楷体");
	outtextxy(700, 50, str);
	if(pSnake->getSnakeSpeed()==100) sprintf_s(str2, "难度级别：简单级别", score);
	else if(pSnake->getSnakeSpeed()==50) sprintf_s(str2, "难度级别：普通级别", score);
	else sprintf_s(str2, "难度级别：地狱级别", score);
	//格式化数据转字符串
	outtextxy(630, 200, str2);

	sprintf_s(str3, "向上按 W", score);
	outtextxy(630, 350, str3);

	sprintf_s(str4, "向下按 S", score);
	outtextxy(630, 510, str4);

	sprintf_s(str5, "向右按 D", score);
	outtextxy(800, 350, str5);

	sprintf_s(str6, "向左按 A", score);
	outtextxy(800, 510, str6);
}

 
void GameStart()
{
	cleardevice();
	char str[64];
	settextcolor(0x40E0D0);
	 settextstyle(40, 0, "楷体");
	sprintf_s(str,"贪吃蛇游戏(Made by GJY)");
	outtextxy(250, 150, str);
	
	setfillcolor(RGB(220, 20, 60));//颜色  横杠
	fillrectangle(100,300, 900, 305);

	setfillcolor(RGB(220, 20, 60));//颜色  横杠2
	fillrectangle(100, 500, 900, 505);

	setfillcolor(RGB(220, 20, 60));//颜色  竖杠1
	fillrectangle(300, 300, 305, 505);

	char str1[64];
	settextcolor(0x40E0D0);
	settextstyle(30, 0, "楷体");
	sprintf_s(str1, "简单模式按1");
	outtextxy(100, 400, str1);

	setfillcolor(RGB(220, 20, 60));//颜色  竖杠2
	fillrectangle(500, 300, 505, 505);

	char str2[64];
	settextcolor(0xFF00FF);
	settextstyle(30, 0, "楷体");
	sprintf_s(str2, "中等模式按2");
	outtextxy(320, 400, str2);

	setfillcolor(RGB(220, 20, 60));//颜色  竖杠3
	fillrectangle(700, 300, 705, 505);

	char str3[64];
	settextcolor(0x0000FF);
	settextstyle(30, 0, "楷体");
	sprintf_s(str3, "地狱模式按3");
	outtextxy(520, 400, str3);

	char str4[64];
	settextcolor(0xD4F2E7);
	settextstyle(30, 0, "楷体");
	sprintf_s(str4, "退出游戏按4");
	outtextxy(720, 400, str4);
	 
	while (1)
	{
		if (GameLevel())
			break;
	}
}

 

void SnakeMain()
{

	cleardevice();//刷新页面
	int cnt = 0;

	while (1)
	{
		cnt++;
		char strOver[50];
		int score = pSnake->getSnakeSize();
		//sprintf_s(str, "分数：%d", score);	//格式化数据转字符串
		//outtextxy(0, 0, str);	//最终输出 分数：100

		cleardevice();//刷新背景
		GameOn();

		if (pFood->getFlag() == 0||(pSnake->getSnakeSpeed()==30)&&cnt==5)
		{
			cnt = 0;
			pFood->setFoodPos();
		}

		pSnake->drawSnake();
		pSnake->moveSnake();
		eatFood(pSnake, pFood);
		pFood->drawfood();
		//只有当有按键时才处理 先做条件判断
		if (pSnake->GetOver())
		{
			settextcolor(0x0000FF);
			sprintf_s(strOver, "Game Over! 最大蛇长：%d  即将自动返回菜单", score);	//格式化数据转字符串
			outtextxy(20, 40, strOver);
			Sleep(2000);
			break;
		}
		if (_kbhit())
		{
			pSnake->keyDown();
		}
		Sleep(pSnake->getSnakeSpeed());
	}

}

int main()
{
	initgraph(1000, 600);//创建一个窗口
	setbkcolor(BLACK);//背景颜色
	while (!GameOver)
	{
		GameStart();
		if (GameOver) return 0;

		SnakeMain();
		SetSnakeInit();
	}
	_getch();
	closegraph();
	system("pause");
	return 0;
}