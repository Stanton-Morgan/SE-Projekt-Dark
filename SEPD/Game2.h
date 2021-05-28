#pragma once
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include <conio.h>
#include"FrameWork.h"
#define MAX_MINE 16//��������
#define MAX_ANGLE 80 //���Ƕ�
#define PI 3.1415926535898
#define SMALL 50
#define BIG 120
#define CBIG 4
#define CSMALL 5
#define CHBIG 1
#define CHSMALL 3
#define BOMB 3
#define ONESHOT 80

int RunGame2();
enum MINE //ö��ͼƬ�����±�
{
	i_cannon = 1,
	i_sole = 7,
	i_fire = 9,
	i_bk = 10,
	i_goldSmall = 13,
	i_goldBig = 15,
	i_stoneSmall = 17,
	i_stoneBig = 19,
	i_bomb = 21,
	i_burnSmall = 23,
	i_burnBig = 25,
	i_smokeSmall = 27,
	i_smokeBig = 29,
	i_explode = 31,
};
enum TYPE 
{	//��Ʒ����ö��
	C_Big,
	C_Small,
	CH_Big,
	CH_Small,
	CHO,
	//����
	LEFT,
	RIGHT,
	//����״̬������/��ȴ
	C_NORMAL,
	C_AWAIT,
	//�����Ƿ���ʾ
	F_YES,
	F_NO
};
class Sole //��ɫ��Ϣ
{
public:
	int x;//��ͼλ��
	int y;
	int width;//ͼƬ���
	int height;
	int credit;//����
};
class Mine //��Ʒ
{
public:
	int x;
	int y;
	int size; //�߽��ж�
	bool flag;//�Ƿ����
	int type;//��Ʒ����
	int gold;//��Ʒ��ֵ
	static bool burning;
	static int sum;
};//goldBig[4], goldSmall[5], stoneBig[1], stoneSmall[3], bomb[3]

class Cannon //�ڹ�
{
public:
	int x;
	int y;
	int endx;//����
	int endy;
	int midx1;
	int midy1;
	int midx2;
	int midy2;
	int firex;//����
	int firey;
	int len;//����
	int angle;//�Ƕ�
	int dir;//�ڶ�����
	int vx;//�ٶȷ���
	int vy;
	int cannonState;//����״̬
	int fireState;//����״̬
	int index;//��¼���е���Ʒ�±�
};