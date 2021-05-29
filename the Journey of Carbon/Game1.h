#pragma once
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include<stdio.h>
#define Check_Circle(px,py,x,y,r) ((((px)-(x))*((px)-(x))+((py)-(y))*((py)-(y)))<=(r)*(r)?1:0)

int RunGame1();