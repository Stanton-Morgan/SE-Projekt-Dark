//������������Ŀ/����/�߼�/ʹ�ö��ֽ��ַ���
#include "Game3.h"
#include <string.h>
int flag, t;
int gif = 0;//��������Ϲ�����
TCHAR enemy[10];//�������
IMAGE mainmenu/*���˵�*/, victory, victory_2, lose, lose_2;
int enemynum = 0;
int musicon = 1;
//����ƽ�

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
//��������
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
//���������
class TOWER
{
public:
	IMAGE image;//���ͼƬ
	int value, price, num, lev, attacking,tag;//�������
	float ATK, radius, ATKS;//����������
	float x, y;//����
	WEAPON weapon;
	// ��������������������˵����
	IMAGE menucircle, towerUI[2], guide;
	int menuopen, guideshow[8];//�жϱ���
	char imagename[50], guidename[50], filename[50];//�ļ���
	void Update()//�����������䶯ʱ���ã����·���������
	{
		sprintf(filename, "./images/Game3/towerdata_%d_%d.txt", num, lev);
		FILE* ftower = fopen(filename, "r");
		fscanf(ftower, "%d %d %f %f %f %d", &price, &value, &ATK, &radius, &ATKS, &tag);
		fclose(ftower);
	}
	void Draw()//���Ʒ�����
	{
		if (lev != 0)
			sprintf(imagename, "./images/Game3/tower_%d_%d.png", num, lev);//��ʽת��
		else
			sprintf(imagename, "./images/Game3/notower.png");
		loadimage(&image, imagename);//����ͼƬ
		putimage(x - 21, y - 37, &image);//������ͼƬ
	}
	void Menu()//���Ʋ˵�
	{
		if (menuopen == 1)//�жϷ������˵��Ƿ�Ӧ��
		{
			putimage(x - 50, y - 50, &menucircle);
			if (lev == 0)
			{
				for (int i = 1; i <= 3; i++)
				{//����ͼ����
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
//�������
class ENEMY
{
public:
	IMAGE image,image_2, hp;
	int tag = 1;
	int num, attacted, value, aim = 1;//�������
	float x, y;//��������
	float HP, Hp, ATK, DEF, speed;//��������
	float w, h;//ͼƬ����
	char imagename[50],imagename_2[50];//ͼƬ��
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
//�ؿ���ͼ
class MAP
{
public:
	IMAGE image;//����						
	int lev, money, heart, kill;
	float spot_x[3][100] , spot_y[3][100];//��ͼ�ؼ��㣬�����ƶ�·��
	char ht[2], my[4], ew[10];//����������
	TOWER tower[towernum];//����������
	ENEMY enemy[60];//����
	char imagename[50], mapname[50], spotname[50];//�ļ���
	void Start()
	{
		sprintf(imagename, "./images/Game3/level_%d.png", lev);
		sprintf(mapname, "./images/Game3/level_%d.txt", lev);//��ʽת��ʵ����������
		loadimage(&image, imagename);
		money = 300;
		heart = 5;
		kill = 0;
		enemynum = 0;//��������
		FILE* fmap = fopen(mapname, "r");//���ļ��ж�ȡ����������
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
			fscanf(fmap, "%f %f ", &tower[i].x, &tower[i].y);//��ȡ����
			tower[i].weapon.x = tower[i].x;
			tower[i].weapon.y = tower[i].y;
		}
		for (int i = 0; i < 60; i++)
		{
			enemy[i].aim = 1;
			enemy[i].x = spot_x[0][1];
			enemy[i].y = spot_y[0][1];
		}
		fclose(fmap);//�ر��ļ�
		BeginBatchDraw();
	}	//���Ƶ�ͼ����
	void Draw()//���Ƶ�ͼ//��Ҫ���ƺ���
	{
		cleardevice();//����
		putimage(0, 0, &image);//����
		for (int i = 0; i < towernum; i++)
			tower[i].Draw();//���Ʒ�����
		for (int i = 0; i < towernum; i++)
			if (tower[i].attacking == 1 && tower[i].lev > 0)
				tower[i].weapon.Draw();
		for (int i = 0; i < enemynum; i++)
			if (enemy[i].HP > 0)
				enemy[i].Draw();//���ƹ���	

		for (int i = 0; i < towernum; i++)
			tower[i].Menu();//���Ʒ������˵�
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
			enemy[enemynum].Update();//���볡�Ĺ��ﲢ�������
		}
		for (int i = 0; i < enemynum; i++)
		{
			if (enemy[i].HP > 0)//���ڹ����������½���
			{
				Approach(&enemy[i].x, &enemy[i].y, &spot_x[i % 3][enemy[i].aim], &spot_y[i % 3][enemy[i].aim], &enemy[i].speed);
				if (fabs(enemy[i].x - spot_x[i % 3][enemy[i].aim]) < 1 && fabs(enemy[i].y - spot_y[i % 3][enemy[i].aim]) < 1)
					enemy[i].aim++;
				if (fabs(enemy[i].x - spot_x[i % 3][7]) <1 && fabs(enemy[i].y - spot_y[i % 3][7])<1)
					heart--;
			
			}
		}
		for (int i = 0; i < towernum; i++)
		{//�Է������͹�����б���
			for (int j = 0; j < enemynum; j++)
			{
				float x = enemy[j].x, y = enemy[j].y;
				if (tower[i].lev == 0)
					tower[i].attacking = 0;
				if (tower[i].lev > 0 && enemy[j].HP > 0)
				{
					enemy[j].attacted = 1;
					if (sqrt((tower[i].x - x) * (tower[i].x - x) + (tower[i].y - y) * (tower[i].y - y)) < tower[i].radius)
					{//��������빥����Χʱ
						tower[i].attacking = 1;
					}

					if (tower[i].attacking == 1 && enemy[j].attacted == 1
						&& sqrt((tower[i].x - x) * (tower[i].x - x) + (tower[i].y - y) * (tower[i].y - y)) < tower[i].radius)//���������ڹ����ҹ������ܵ�����ʱ
						Approach(&tower[i].weapon.x, &tower[i].weapon.y, &x, &y, &tower[i].ATKS);

					if (sqrt((tower[i].x - x) * (tower[i].x - x) + (tower[i].y - y) * (tower[i].y - y)) > tower[i].radius)
					{
						enemy[j].attacted = 0;
						enemy[j + 1].attacted = 1;
					}

					if (fabs(tower[i].weapon.x - x) <= 35 && fabs(tower[i].weapon.y - y) <= 35)
					{//���������Ĺ�������﷢����Ч��ײʱ
						tower[i].weapon.x = tower[i].x - 5;
						tower[i].weapon.y = tower[i].y - 16;
						enemy[j].HP -= tower[i].ATK - enemy[j].DEF;
						//������
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
//��ʼ����������Դ
void StartGame3()
{
	//ȫ����Դ����
	loadimage(&mainmenu, "./images/Game3/mainmenu.png");
	loadimage(&victory, "./images/Game3/victory.png", 874, 420);
	loadimage(&victory_2, "./images/Game3/victory_2.png", 874, 420);
	loadimage(&lose, "./images/Game3/lose.png", 874, 420);
	loadimage(&lose_2, "./images/Game3/lose_2.png", 874, 420);
	initgraph(width, height);
	setbkmode(TRANSPARENT);//�������ֵ�͸�����
	BeginBatchDraw();//��ʼ��������
}
//�������޹صĸ���
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
//�������йصĸ���
void UpdateWithInput()
{//����������Ӧ�ж������ĸı�
	
	if (MouseHit())
	{
		MOUSEMSG m = GetMouseMsg();//��ȡ�����Ϣ
		for (int i = 0; i < towernum; i++)
		{
			if (map.tower[i].menuopen == 0)//�������˵�δ��ʱ
			{
				if (fabs(m.x - map.tower[i].x) <= 36 && fabs(m.y - map.tower[i].y) <= 21
					&& fabs(m.x - 0) >= 36 && fabs(m.y - 0) >= 21 && m.uMsg == WM_LBUTTONDOWN)
				{
					//�ر������˵������򿪴˲˵�
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
								map.tower[i].weapon.num = map.tower[i].num = j;//ȷ�����������
								map.tower[i].lev++;//��������ȡ�۸�
								map.tower[i].Update();
								if (map.money >= map.tower[i].price)
									map.money -= map.tower[i].price;//�����Ǯ����۳�
								else
									map.tower[i].lev--;//ûǮ�ȼ�����
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
						{//�����ͣ��ʾ���ֽ���
							sprintf(map.tower[i].guidename, "./images/Game3/guide_%d_%d.png", map.tower[i].num, map.tower[i].lev + 1);
							loadimage(&map.tower[i].guide, map.tower[i].guidename, 230, 166);
							map.tower[i].guideshow[5] = 1;
						}
					}
					else if (fabs(m.x - map.tower[i].x) < 13 && fabs(m.y - map.tower[i].y - 50) < 13 && m.uMsg == WM_LBUTTONDOWN)
					{//���������
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

//ʤ������
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
//ʧ�ܽ���
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



//���˵�//ѡ�ؽ���
void Mainmenu()
{
	while (1)//ͨ������ѭ��ʵ��ѡ��
	{
		putimage(0, 0, &mainmenu);//ѡ�ؽ���
		FlushBatchDraw();//��������
		if (MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();//��ȡ�����Ϣ
			if (m.uMsg == WM_LBUTTONDOWN)//�������ʱ
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
//��Ϸ��//�������¿�ʼ����
void Restart()
{
	map.Start();//ÿһ�س�ʼ����������Դ
	map.Draw();
	gif = 0;
	while (1)
	{
		UpdateWithInput();//�������йصĸ���
		UpdateWithoutInput();//�������޹صĸ���	
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
//��Ϸ����//����return����ѡ��

void Quit()
{
	while (1)
	{
		if (flag == 1) {
			return;
		}
		Mainmenu();//���˵�����
		
		Restart();
	}
}


//������
int RunGame3()
{
	StartGame3();//��ʼ����������Դ
	Quit();
	EndBatchDraw();
	return 0;
}