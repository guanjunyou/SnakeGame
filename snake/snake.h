//专门做蛇要做的事情#pragma once
#ifndef _SNAKE_H_
#define _SNAKE_H_
#include<graphics.h>//图形化编程
#include<conio.h>//按键处理
#include "myPoint.h"//点的坐标

class snake
{
public:
	snake();//构造函数
	void drawSnake();//画蛇
	void moveSnake();//移动蛇
	void keyDown();//按键控制蛇
	//类的封装性
	int & getSnakeSize();//修改蛇长度的接口
	myPoint getSnakePos(int Pos);//获取蛇的pos节的坐标
	bool GetOver();//撞墙函数
	void ReInit();//重置蛇
	void SetSnakeSpeed(int sp);
	int & getSnakeSpeed();

protected:
	//属性特点
	int SnakeSpeed;
	myPoint snakePos[100];//蛇最多100节 存储每一节坐标
	int snakeSize;//当前节数
	char position;//蛇方向
	//把方向枚举出来
	enum direction { right, left, down, up };
	
};
#endif // !_SNAKE_H_
