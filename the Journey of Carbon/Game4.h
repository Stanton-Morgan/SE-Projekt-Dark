#pragma once
#include <graphics.h>  
#include <conio.h>
#include <stdio.h>
#include"FrameWork.h"
#define B_SIZE 40 // �����С
#define B_H 15 
#define B_L 24// ���������һ��15*24������


struct Player // �ṹ�壬���ڼ�¼���λ��
{
	int i;
	int j;
};


enum Element // ����ö�����ͣ�С�������еĿ��ܵ�����
{
	wall, target, box, empty, achieved, role
};

// ���ڴ洢��ͼ���ݣ���ö������ʵ��

int RunGame4();