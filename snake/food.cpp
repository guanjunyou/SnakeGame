#include "food.h"
food::food()
{
	foodPos.x = rand() % 80 * 10;//放止食物吃不到
	foodPos.y = rand() % 60 * 10;
	foodFlag = 1;//食物存在
}
void food::drawfood()
{
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(foodPos.x, foodPos.y,foodPos.x + 10, foodPos.y + 10);
}
void food::setFoodPos()
{
	//食物可能出现在蛇身上
	foodPos.x = rand() % 60 * 10;//放止食物吃不到
	foodPos.y = rand() % 59 * 10;
	foodFlag =1;//食物存在
}
int& food::getFlag()
{
	return foodFlag;
	//改变标记所以用引用
}
myPoint food::getFoodPos()
{
	return foodPos;
}