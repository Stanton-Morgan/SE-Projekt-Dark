#pragma once
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include <conio.h>
#include"FrameWork.h"
#define MAX_MINE 16//垃圾数量
#define MAX_ANGLE 80 //最大角度
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
enum MINE //枚举图片数组下标
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
{	//物品类型枚举
	C_Big,
	C_Small,
	CH_Big,
	CH_Small,
	CHO,
	//方向
	LEFT,
	RIGHT,
	//火炮状态，正常/冷却
	C_NORMAL,
	C_AWAIT,
	//火焰是否显示
	F_YES,
	F_NO
};
class Sole //角色信息
{
public:
	int x;//贴图位置
	int y;
	int width;//图片宽高
	int height;
	int credit;//积分
};
class Mine //物品
{
public:
	int x;
	int y;
	int size; //边界判断
	bool flag;//是否存在
	int type;//物品类型
	int gold;//物品价值
	static bool burning;
	static int sum;
};//goldBig[4], goldSmall[5], stoneBig[1], stoneSmall[3], bomb[3]

class Cannon //炮管
{
public:
	int x;
	int y;
	int endx;//火炮
	int endy;
	int midx1;
	int midy1;
	int midx2;
	int midy2;
	int firex;//火球
	int firey;
	int len;//长度
	int angle;//角度
	int dir;//摆动方向
	int vx;//速度分量
	int vy;
	int cannonState;//火炮状态
	int fireState;//火球状态
	int index;//记录击中的物品下标
};