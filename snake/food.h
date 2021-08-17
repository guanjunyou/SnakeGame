#ifndef _FOOD_H_
#define _FOOD_H_
#include<graphics.h>
#include "myPoint.h"
class food
{
public:
	food();
	void drawfood();
	void setFoodPos();
	int& getFlag();
	myPoint getFoodPos();
protected:
	myPoint foodPos;
	int foodFlag;//食物存在标记
};
#endif // !_FOOD_H_
#pragma once
