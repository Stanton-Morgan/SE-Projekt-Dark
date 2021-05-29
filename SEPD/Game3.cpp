//运行条件：项目/属性/高级/使用多字节字符集
#include "Game3.h"
#include <string.h>
int flag, t;
int gif = 0;//这个变量老管用了
TCHAR enemy[10];//文字输出
IMAGE mainmenu/*主菜单*/, victory, victory_2, lose, lose_2;
int enemynum = 0;
int musicon = 1;
//两点逼近

void Restart(), Victory(), Lose();
void Quit();

void Approach(float* x1, float* y1, float* x2, float* y2, float* speed)
{
	float speedx = *speed, speedy = *speed, dis, disy = *y2 - *y1, disx = *x2 - *x1;
	if (disx != 0 && disy != 0)
	{
		dis = sqrt(disy * disy + disx * disx);
		speedy = fabs(disy * *speed / dis);
		speedx = fabs(disx * *speed / dis);
	}
	if (speedx == 0)
		speedx = *speed;
	if (speedy == 0)
		speedy = *speed;
	if (disx > 0)
		*x1 += speedx;
	else
		*x1 -= speedx;
	if (disy > 0)
		*y1 += speedy;
	else
		*y1 -= speedy;
}
//攻击动画
class WEAPON
{
public:
	IMAGE image,image_2;
	float x, y;
	char imagename[50],imagename_2[50];
	int num;
	void Draw()
	{
		sprintf(imagename, "./images/Game3/weapon_%d.png", num);
		sprintf(imagename_2, "./images/Game3/weapon_%d.png(2)", num);
		loadimage(&image, imagename);
		loadimage(&image_2, imagename_2);
		putimage(x, y, &image,SRCPAINT);
		putimage(x, y, &image_2, SRCAND);
	}
};
//防御塔相关
class TOWER
{
public:
	IMAGE image;//相关图片
	int value, price, num, lev, attacking,tag;//相关数据
	float ATK, radius, ATKS;//防御塔属性
	float x, y;//坐标
	WEAPON weapon;
	// 防御塔附属物——防御塔菜单相关
	IMAGE menucircle, towerUI[2], guide;
	int menuopen, guideshow[8];//判断变量
	char imagename[50], guidename[50], filename[50];//文件名
	void Update()//防御塔发生变动时调用，更新防御塔属性
	{
		sprintf(filename, "./images/Game3/towerdata_%d_%d.txt", num, lev);
		FILE* ftower = fopen(filename, "r");
		fscanf(ftower, "%d %d %f %f %f %d", &price, &value, &ATK, &radius, &ATKS, &tag);
		fclose(ftower);
	}
	void Draw()//绘制防御塔
	{
		if (lev != 0)
			sprintf(imagename, "./images/Game3/tower_%d_%d.png", num, lev);//格式转换
		else
			sprintf(imagename, "./images/Game3/notower.png");
		loadimage(&image, imagename);//导入图片
		putimage(x - 21, y - 37, &image);//防御塔图片
	}
	void Menu()//绘制菜单
	{
		if (menuopen == 1)//判断防御塔菜单是否应打开
		{
			putimage(x - 50, y - 50, &menucircle);
			if (lev == 0)
			{
				for (int i = 1; i <= 3; i++)
				{//掩码图绘制
					putimage(x - 22 + 38 * pow(-1, i), y - 22 + 38 * pow(-1, (i + 1) / 2), 46, 41, &towerUI[0], 46 * (i - 1), 0, SRCAND);
					putimage(x - 22 + 38 * pow(-1, i), y - 22 + 38 * pow(-1, (i + 1) / 2), 46, 41, &towerUI[1], 46 * (i - 1), 0, SRCPAINT);
				}
			}
			else if (lev < 3)
			{
				putimage(x - 23, y - 68, 46, 41, &towerUI[0], 46 * 4, 0, SRCAND);
				putimage(x - 23, y - 68, 46, 41, &towerUI[1], 46 * 4, 0, SRCPAINT);
				putimage(x - 21, y + 27, 46, 41, &towerUI[0], 46 * 6, 0, SRCAND);
				putimage(x - 21, y + 27, 46, 41, &towerUI[1], 46 * 6, 0, SRCPAINT);
			}
			else
			{
				putimage(x - 23, y - 68, 46, 41, &towerUI[0], 46 * 5, 0, SRCAND);
				putimage(x - 23, y - 68, 46, 41, &towerUI[1], 46 * 5, 0, SRCPAINT);
				putimage(x - 21, y + 27, 46, 41, &towerUI[0], 46 * 6, 0, SRCAND);
				putimage(x - 21, y + 27, 46, 41, &towerUI[1], 46 * 6, 0, SRCPAINT);
			}
		}
	}
};
//怪物相关
class ENEMY
{
public:
	IMAGE image,image_2, hp;
	int tag = 1;
	int num, attacted, value, aim = 1;//相关数据
	float x, y;//怪物坐标
	float HP, Hp, ATK, DEF, speed;//怪物属性
	float w, h;//图片长宽
	char imagename[50],imagename_2[50];//图片名
	void Update()
	{
		char filename[50];
		sprintf(filename, "./images/Game3/enemydata_%d.txt", num);
		FILE* fenemy = fopen(filename, "r");
		fscanf(fenemy, "%d %f %f %f %f %f", &value, &Hp, &HP, &ATK, &DEF, &speed);
		fclose(fenemy);
	}
	void Draw()
	{
		if (tag == 1) {
			loadimage(&hp, "./images/Game3/HP.png", Hp, 3);
			sprintf(imagename, "./images/Game3/enemy_%d_%d.png", num, gif / 100 % 2);
			sprintf(imagename_2, "./images/Game3/enemy_%d_%d(2).png", num, gif / 100 % 2);
			loadimage(&image, imagename);
			loadimage(&image_2, imagename_2);

			w = image.getwidth();
			h = image.getheight();
			putimage(x - w / 2, y - h, &image_2,SRCAND);
			putimage(x - w / 2, y - h, &image,SRCPAINT);

			putimage(x - Hp / 4, y - h - 10, Hp / 2, 3, &hp, (Hp - HP) / 2, 0);
		}
	}
};
//关卡地图
class MAP
{
public:
	IMAGE image;//背景						
	int lev, money, heart, kill;
	float spot_x[3][100] , spot_y[3][100];//地图关键点，怪物移动路线
	char ht[2], my[4], ew[10];//文字输出相关
	TOWER tower[towernum];//防御塔数量
	ENEMY enemy[60];//敌人
	char imagename[50], mapname[50], spotname[50];//文件名
	void Start()
	{
		sprintf(imagename, "./images/Game3/level_%d.png", lev);
		sprintf(mapname, "./images/Game3/level_%d.txt", lev);//格式转换实现批量导入
		loadimage(&image, imagename);
		money = 300;
		heart = 5;
		kill = 0;
		enemynum = 0;//数据重置
		FILE* fmap = fopen(mapname, "r");//从文件中读取防御塔坐标
		for (int i = 0; i < 3; i++)
		{
			sprintf(spotname, "./images/Game3/aim_%d_%d.txt", lev, i % 3);
			FILE* faim = fopen(spotname, "r");
			for (int j = 0; j < 9; j++)
			{
				fscanf(faim, "%f %f ", &spot_x[i][j], &spot_y[i][j]);
			}
			fclose(faim);
		}
		for (int i = 0; i < towernum; i++)
		{
			loadimage(&tower[i].menucircle, "./images/Game3/menucircle.png", 100, 100);
			loadimage(&tower[i].towerUI[0], "./images/Game3/towerUIy.png", 322, 41);
			loadimage(&tower[i].towerUI[1], "./images/Game3/towerUI.png", 322, 41);
			tower[i].lev = 0;
			fscanf(fmap, "%f %f ", &tower[i].x, &tower[i].y);//读取坐标
			tower[i].weapon.x = tower[i].x;
			tower[i].weapon.y = tower[i].y;
		}
		for (int i = 0; i < 60; i++)
		{
			enemy[i].aim = 1;
			enemy[i].x = spot_x[0][1];
			enemy[i].y = spot_y[0][1];
		}
		fclose(fmap);//关闭文件
		BeginBatchDraw();
	}	//绘制地图函数
	void Draw()//绘制地图//主要绘制函数
	{
		cleardevice();//清屏
		putimage(0, 0, &image);//背景
		for (int i = 0; i < towernum; i++)
			tower[i].Draw();//绘制防御塔
		for (int i = 0; i < towernum; i++)
			if (tower[i].attacking == 1 && tower[i].lev > 0)
				tower[i].weapon.Draw();
		for (int i = 0; i < enemynum; i++)
			if (enemy[i].HP > 0)
				enemy[i].Draw();//绘制怪物	

		for (int i = 0; i < towernum; i++)
			tower[i].Menu();//绘制防御塔菜单
	}
	void Update()
	{
		if (gif % (1000 - enemynum * 10) == 0 && enemynum < 60)
		{
			enemynum++;
			enemy[enemynum].num = 1;
			if (enemynum >= 20 && enemynum < 40)
				enemy[enemynum].num = 2;
			if (enemynum >= 40)
				enemy[enemynum].num = 3;
			enemy[enemynum].Update();//新入场的怪物并对其更新
		}
		for (int i = 0; i < enemynum; i++)
		{
			if (enemy[i].HP > 0)//仅在怪物存活的情况下进行
			{
				Approach(&enemy[i].x, &enemy[i].y, &spot_x[i % 3][enemy[i].aim], &spot_y[i % 3][enemy[i].aim], &enemy[i].speed);
				if (fabs(enemy[i].x - spot_x[i % 3][enemy[i].aim]) < 1 && fabs(enemy[i].y - spot_y[i % 3][enemy[i].aim]) < 1)
					enemy[i].aim++;
				if (fabs(enemy[i].x - spot_x[i % 3][7]) <1 && fabs(enemy[i].y - spot_y[i % 3][7])<1)
					heart--;
			
			}
		}
		for (int i = 0; i < towernum; i++)
		{//对防御塔和怪物进行遍历
			for (int j = 0; j < enemynum; j++)
			{
				float x = enemy[j].x, y = enemy[j].y;
				if (tower[i].lev == 0)
					tower[i].attacking = 0;
				if (tower[i].lev > 0 && enemy[j].HP > 0)
				{
					enemy[j].attacted = 1;
					if (sqrt((tower[i].x - x) * (tower[i].x - x) + (tower[i].y - y) * (tower[i].y - y)) < tower[i].radius)
					{//当怪物进入攻击范围时
						tower[i].attacking = 1;
					}

					if (tower[i].attacking == 1 && enemy[j].attacted == 1
						&& sqrt((tower[i].x - x) * (tower[i].x - x) + (tower[i].y - y) * (tower[i].y - y)) < tower[i].radius)//当防御塔在攻击且怪物正受到攻击时
						Approach(&tower[i].weapon.x, &tower[i].weapon.y, &x, &y, &tower[i].ATKS);

					if (sqrt((tower[i].x - x) * (tower[i].x - x) + (tower[i].y - y) * (tower[i].y - y)) > tower[i].radius)
					{
						enemy[j].attacted = 0;
						enemy[j + 1].attacted = 1;
					}

					if (fabs(tower[i].weapon.x - x) <= 35 && fabs(tower[i].weapon.y - y) <= 35)
					{//当防御塔的攻击与怪物发生有效碰撞时
						tower[i].weapon.x = tower[i].x - 5;
						tower[i].weapon.y = tower[i].y - 16;
						enemy[j].HP -= tower[i].ATK - enemy[j].DEF;
						//减速塔
						if (tower[i].tag == 1) {
							enemy[j].speed = 0.1;
						}
					}
					if (tower[i].attacking == 0)
					{
						tower[i].weapon.x = tower[i].x - 5;
						tower[i].weapon.y = tower[i].y - 16;
					}
					if (enemy[j].HP <= 0)
					{
						kill++;
						money += enemy[j].value;
						enemy[j].attacted = 0;
					}
				}
			}
		}
	}
} map;
//初始化、导入资源
void StartGame3()
{
	//全局资源导入
	loadimage(&mainmenu, "./images/Game3/mainmenu.png");
	loadimage(&victory, "./images/Game3/victory.png", 874, 420);
	loadimage(&victory_2, "./images/Game3/victory_2.png", 874, 420);
	loadimage(&lose, "./images/Game3/lose.png", 874, 420);
	loadimage(&lose_2, "./images/Game3/lose_2.png", 874, 420);
	initgraph(width, height);
	setbkmode(TRANSPARENT);//所有文字的透明输出
	BeginBatchDraw();//开始批量绘制
}
//与输入无关的更新
void UpdateWithoutInput()
{
	map.Update();
	map.Draw();
	settextstyle(40, 0, _T("Impact"));
	sprintf(map.ht, _T("%d"),map.heart);
	outtextxy(40, 0, map.ht);
	sprintf(map.my, _T("%d"), map.money);
	outtextxy(900, 0, map.my);
	outtextxy(60, 40, map.ew);
	if (map.kill == 59 && map.heart > 0)
		Victory();
	if (map.heart <= 0)
		Lose();
}
//与输入有关的更新
void UpdateWithInput()
{//鼠标操作及对应判定变量的改变
	
	if (MouseHit())
	{
		MOUSEMSG m = GetMouseMsg();//获取鼠标信息
		for (int i = 0; i < towernum; i++)
		{
			if (map.tower[i].menuopen == 0)//防御塔菜单未打开时
			{
				if (fabs(m.x - map.tower[i].x) <= 36 && fabs(m.y - map.tower[i].y) <= 21
					&& fabs(m.x - 0) >= 36 && fabs(m.y - 0) >= 21 && m.uMsg == WM_LBUTTONDOWN)
				{
					//关闭其他菜单，仅打开此菜单
					for (int j = 0; j < towernum; j++)
					{
						if (j == i)
							map.tower[j].menuopen = 1;
						else
							map.tower[j].menuopen = 0;
					}
				}
			}
			else
			{
				if (map.tower[i].lev == 0)
				{
					for (int j = 1; j <= 3; j++)
						if (fabs(m.x - map.tower[i].x - 40 * pow(-1, j)) < 20 && fabs(m.y - map.tower[i].y - 40 * pow(-1, (j + 1) / 2)) < 20)
						{
							if (map.tower[i].guideshow[j] == 1 && m.uMsg == WM_LBUTTONDOWN)
							{
								map.tower[i].weapon.num = map.tower[i].num = j;//确定防御塔编号
								map.tower[i].lev++;//假升级获取价格
								map.tower[i].Update();
								if (map.money >= map.tower[i].price)
									map.money -= map.tower[i].price;//如果有钱，则扣除
								else
									map.tower[i].lev--;//没钱等级回退
							}
							else
							{
								sprintf(map.tower[i].guidename, "./images/Game3/guide_%d_1.png", j);
								loadimage(&map.tower[i].guide, map.tower[i].guidename, 230, 166);
								for (int k = 1; k <= 4; k++)
									if (k == j)
										map.tower[i].guideshow[k] = 1;
									else
										map.tower[i].guideshow[k] = 0;
							}
						}
						else
							map.tower[i].guideshow[j] = 0;
				}
				else
				{
					if (fabs(m.x - map.tower[i].x) < 20 && fabs(m.y - map.tower[i].y + 50) < 20 && map.tower[i].lev < 3)
					{
						if (map.tower[i].guideshow[5] == 1 && m.uMsg == WM_LBUTTONDOWN)
						{
							map.tower[i].lev++;
							map.tower[i].Update();
							if (map.money >= map.tower[i].price)
								map.money -= map.tower[i].price;
							else
							{
								map.tower[i].lev--;
								map.tower[i].Update();
							}
						}
						else
						{//鼠标悬停显示文字介绍
							sprintf(map.tower[i].guidename, "./images/Game3/guide_%d_%d.png", map.tower[i].num, map.tower[i].lev + 1);
							loadimage(&map.tower[i].guide, map.tower[i].guidename, 230, 166);
							map.tower[i].guideshow[5] = 1;
						}
					}
					else if (fabs(m.x - map.tower[i].x) < 13 && fabs(m.y - map.tower[i].y - 50) < 13 && m.uMsg == WM_LBUTTONDOWN)
					{//拆除防御塔
						map.money += map.tower[i].value;
						map.tower[i].lev = 0;
					}
					else
						map.tower[i].guideshow[5] = 0;
				}
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					map.tower[i].menuopen = 0;
					for (int j = 0; j < 8; j++)
						map.tower[i].guideshow[j] = 0;
				}
			}
		}
	}
	
}

//胜利界面
void Victory()
{
	while (1)
	{
		putimage(0, 0, &victory_2,SRCAND);
		putimage(0, 0, &victory, SRCPAINT);
		if (flag == 1) {
			break;
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			//_getch();
			flag = 1;
			break;
		}
		FlushBatchDraw();
	}
}
//失败界面
void Lose()
{
	while (1)
	{
		putimage(0, 0, &lose_2, SRCAND);
		putimage(0, 0, &lose, SRCPAINT);
		if (flag == 1) {
			break;
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			//_getch();
			flag = 1;
			break;
		}
		FlushBatchDraw();
	}
}



//主菜单//选关界面
void Mainmenu()
{
	while (1)//通过跳出循环实现选关
	{
		putimage(0, 0, &mainmenu);//选关界面
		FlushBatchDraw();//批量绘制
		if (MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();//获取鼠标信息
			if (m.uMsg == WM_LBUTTONDOWN)//左键按下时
			{
				if (fabs(m.x - 454) <= 20 && fabs(m.y - 387) <= 20) {
					map.lev = 1;
					break;
				}
				else
					continue;
			}
		}
	}
}
//游戏中//用于重新开始本关
void Restart()
{
	map.Start();//每一关初始化、载入资源
	map.Draw();
	gif = 0;
	while (1)
	{
		UpdateWithInput();//与输入有关的更新
		UpdateWithoutInput();//与输入无关的更新	
		if (flag == 1) {
			break;
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			//_getch();
			flag = 1;
			break;
		}
		FlushBatchDraw();
		gif++;
	}
}
//游戏主体//用于return重新选关

void Quit()
{
	while (1)
	{
		if (flag == 1) {
			return;
		}
		Mainmenu();//主菜单界面
		
		Restart();
	}
}


//主函数
int RunGame3()
{
	StartGame3();//初始化、载入资源
	Quit();
	EndBatchDraw();
	return 0;
}