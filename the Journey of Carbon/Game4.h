#pragma once
#include <graphics.h>  
#include <conio.h>
#include <stdio.h>
#include"FrameWork.h"
#define B_SIZE 40 // 方块大小
#define B_H 15 
#define B_L 24// 方块个数，一共15*24个方块


struct Player // 结构体，用于记录玩家位置
{
	int i;
	int j;
};


enum Element // 定义枚举类型，小方块所有的可能的种类
{
	wall, target, box, empty, achieved, role
};

// 用于存储地图数据，用枚举类型实现

int RunGame4();