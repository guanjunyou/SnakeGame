#include "snake.h"
snake::snake()//构造函数
{
	SnakeSpeed = 50;
	snakeSize = 3;
	//给蛇初始化
	for (int i = 0; i < snakeSize; i++)
	{
		snakePos[i].x = 10 * i;
		snakePos[i].y = 50;
	}//一节长10单位
	position = right;//起始方向朝右

}
void snake::drawSnake()//画蛇
{
	for (int i = 0; i < snakeSize; i++)
	{
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//颜色
		fillrectangle(snakePos[i].x, snakePos[i].y, snakePos[i].x + 10, snakePos[i].y + 10);
		//填充矩形

	}
}
void snake::moveSnake()//移动蛇
{
	//处理蛇头之外的东西
	for (int i = snakeSize - 1; i > 0; i--)
	{
		snakePos[i].x = snakePos[i - 1].x;
		snakePos[i].y = snakePos[i - 1].y;
	}
	//处理蛇头
	switch (position)
	{
	case right:
		snakePos[0].x += 10;
		break;
	case left:
		snakePos[0].x -= 10;
		break;
	case up:
		snakePos[0].y -= 10;
		break;
	case down:
		snakePos[0].y += 10;
		break;

	}
}
void snake::keyDown()//按键控制蛇
{
	//按键唯一改变蛇头的方向
	char userkey = 0;
	userkey = _getch();//conio.h
	switch (userkey)
	{//按键框架 数字是小键盘
	case 'w':
	case 'W':
	case 72: 
		if (position != down)
		{
			position = up;
		}
		break;

	case 's':
	case 'S':
	case 80:
		if (position != up)
		{
			position = down;
		}
		break;

	case 'a':
	case 'A':
	case 75:
		if (position != right)
		{
			position = left;
		}
		break;

	case 'd':
	case'D':
	case 77:
		if (position != left)
		{
			position = right;
		}
		break;

	}
}
//类的封装性
int & snake::getSnakeSize()//修改蛇长度的接口
{
	return snakeSize;
}
myPoint snake::getSnakePos(int pos)//获取蛇的pos节的坐标
{
	return snakePos[pos];
}
bool snake::GetOver()
{
	if (snakePos[0].x == 0 || snakePos[0].x == 600 || snakePos[0].y == 0 || snakePos[0].y == 590)
	{
		return true;
	}
	return false;
}

void snake::ReInit()
{
	SnakeSpeed = 50;
	snakeSize = 3;
	//给蛇初始化
	for (int i = 0; i < snakeSize; i++)
	{
		snakePos[i].x = 10 * i;
		snakePos[i].y = 50;
	}//一节长10单位
	position = right;//起始方向朝右
}

void snake::SetSnakeSpeed(int sp)
{
	SnakeSpeed = sp;
}

int & snake::getSnakeSpeed()
{
	return SnakeSpeed;
}