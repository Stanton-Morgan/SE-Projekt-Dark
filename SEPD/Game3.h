#pragma warning(disable:4996)//防止vs2019报错，使程序顺利运行
#pragma comment(lib,"Winmm.lib")
#pragma once
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <mmsystem.h>
#define width 960
#define height 600//游戏画面尺寸
#define towernum 20//防御塔数量



//声明函数


int RunGame3();