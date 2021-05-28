#include "Game2.h"
IMAGE Game3img[40];
class Sole sole;
class Mine mine[MAX_MINE];
class Cannon cannon;
bool Mine::burning = false;
int Mine::sum = 15;
void GameInit()
{
	//创建窗口 init 初始化  graphics图形界面
	//initgraph(WIN_WIDTH, WIN_HEIGHT);
	//加载图片
	loadimage(&Game3img[i_bk], _T("./images/Game2/bk.png"), WIN_WIDTH, WIN_HEIGHT);
	loadimage(&Game3img[i_sole - 1], _T("./images/Game2/6.png"), 140, 120);
	loadimage(&Game3img[i_sole], _T("./images/Game2/7.png"), 140, 120);
	loadimage(&Game3img[i_cannon - 1], _T("./images/Game2/0.png"), BIG, cannon.len);
	loadimage(&Game3img[i_cannon], _T("./images/Game2/1.png"), BIG, cannon.len);

	loadimage(&Game3img[i_fire - 1], _T("./images/Game2/12.jpg"), 60, 40);
	loadimage(&Game3img[i_fire], _T("./images/Game2/13.jpg"), 60, 40);

	loadimage(&Game3img[i_goldSmall - 1], _T("./images/Game2/4.png"), SMALL, SMALL);
	loadimage(&Game3img[i_goldSmall], _T("./images/Game2/5.png"), SMALL, SMALL);
	loadimage(&Game3img[i_goldBig - 1], _T("./images/Game2/4.png"), BIG, BIG);
	loadimage(&Game3img[i_goldBig], _T("./images/Game2/5.png"), BIG, BIG);

	loadimage(&Game3img[i_stoneSmall - 1], _T("./images/Game2/2.png"), SMALL, SMALL);
	loadimage(&Game3img[i_stoneSmall], _T("./images/Game2/3.png"), SMALL, SMALL);
	loadimage(&Game3img[i_stoneBig - 1], _T("./images/Game2/2.png"), BIG, BIG);
	loadimage(&Game3img[i_stoneBig], _T("./images/Game2/3.png"), BIG, BIG);

	loadimage(&Game3img[i_bomb - 1], _T("./images/Game2/10.png"), SMALL, SMALL);
	loadimage(&Game3img[i_bomb], _T("./images/Game2/11.png"), SMALL, SMALL);

	loadimage(&Game3img[i_burnSmall], _T("./images/Game2/burn.jpg"), SMALL, SMALL);
	loadimage(&Game3img[i_burnBig], _T("./images/Game2/burn.jpg"), BIG, BIG);

	loadimage(&Game3img[i_smokeSmall], _T("./images/Game2/smoke.jpg"), SMALL, SMALL);
	loadimage(&Game3img[i_smokeBig], _T("./images/Game2/smoke.jpg"), BIG, BIG);

	loadimage(&Game3img[i_explode], _T("./images/Game2/explode.jpg"), BIG, BIG);

	//loadimage(&Game3img[], _T("./images/victory_1.png"), WIN_WIDTH, WIN_HEIGHT);
	//初始化角色信息

	sole.width = 140;
	sole.height = 120;
	sole.x = WIN_WIDTH / 2 - sole.width / 2;//x轴居中
	sole.y = 0;
	sole.credit = 500;

	//初始化物品信息

	for (int i = 0; i < MAX_MINE; i++)
	{
		mine[i].flag = true;
		//初始化种类
		if (i < CBIG) {
			mine[i].type = C_Big;
			mine[i].size = BIG;
			switch (i)
			{
			case 0:
				mine[i].x = 0;
				mine[i].y = 300;
				break;
			case 1:
				mine[i].x = 750;
				mine[i].y = 230;
				break;
			case 2:
				mine[i].x = 250;
				mine[i].y = 230;
				break;
			case 3:
				mine[i].x = 550;
				mine[i].y = 400;
				break;
			}
		}
		else if (i < CBIG + CSMALL) {
			mine[i].type = C_Small;
			mine[i].size = SMALL;
			switch (i)
			{
			case 4:
				mine[i].x = 75;
				mine[i].y = 250;
				break;
			case 5:
				mine[i].x = 200;
				mine[i].y = 170;
				break;
			case 6:
				mine[i].x = 450;
				mine[i].y = 350;
				break;
			case 7:
				mine[i].x = 700;
				mine[i].y = 500;
				break;
			case 8:
				mine[i].x = 850;
				mine[i].y = 450;
				break;
			}
		}
		else if (i < CBIG + CSMALL + CHBIG) {
			mine[i].type = CH_Big;
			mine[i].size = BIG;
			mine[9].x = 500;
			mine[9].y = 200;
		}
		else if (i < CBIG + CSMALL + CHBIG + CHSMALL) {
			mine[i].type = CH_Small;
			mine[i].size = SMALL;
			switch (i)
			{
			case 10:
				mine[i].x = 100;
				mine[i].y = 160;
				break;
			case 11:
				mine[i].x = 200;
				mine[i].y = 430;
				break;
			case 12:
				mine[i].x = 400;
				mine[i].y = 450;
				break;
			}
		}
		else {
			mine[i].type = CHO;
			mine[i].size = SMALL;
			switch (i)
			{
			case 13:
				mine[i].x = 150;
				mine[i].y = 250;
				break;
			case 14:
				mine[i].x = 500;
				mine[i].y = 500;
				break;
			case 15:
				mine[i].x = 800;
				mine[i].y = 370;
				break;
			}
		}

	}
	mine[9].flag = false;
	//初始化钩子

	cannon.x = sole.x + 70;
	cannon.y = sole.y + 140;
	cannon.len = 50;
	cannon.endx = cannon.x;
	cannon.endy = cannon.y + cannon.len;
	cannon.firex = cannon.endx;
	cannon.firey = cannon.endy;
	cannon.angle = 0;
	cannon.dir = RIGHT;
	cannon.vx = 0;
	cannon.vy = 0;
	cannon.cannonState = C_NORMAL;
	cannon.fireState = F_NO;
	cannon.index = -1;
	//初始化矿物
}

void GameDraw()
{
	cleardevice();
	//绘制背景
	putimage(0, 0, &Game3img[i_bk]);
	setfillcolor(BROWN);
	solidrectangle(0, 120, WIN_WIDTH, 140);
	//绘制角色
	putimage(sole.x, sole.y, &Game3img[i_sole - 1], SRCAND);
	putimage(sole.x, sole.y, &Game3img[i_sole], SRCPAINT);
	//绘制火炮
	cannon.index = -1;
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 20);
	line(cannon.midx1, cannon.midy1, cannon.endx, cannon.endy);

	int y = 30;
	for (int i = 10; i > 0; i--)
	{
		setcolor(RGB(y, y, y));
		setlinestyle(PS_SOLID, 30 * i / 10);
		line(cannon.midx1, cannon.midy1, cannon.x, cannon.y);
		y += 8;
	}

	y = 20;
	for (int i = 10; i > 0; i--)
	{
		setcolor(RGB(y, y, y));
		setlinestyle(PS_SOLID, 40 * i / 10);
		line(cannon.midx2, cannon.midy2, cannon.x, cannon.y);
		y += 8;
	}

	//绘制火焰
	if (cannon.fireState == F_YES) {
		//putimage(cannon.firex, cannon.firey, &Game3img[i_fire - 1], SRCAND);
		//putimage(cannon.firex, cannon.firey, &Game3img[i_fire], SRCPAINT);
		y = 0;
		for (int i = 10; i > 0; i--)
		{
			setfillcolor(RGB(255, y, 0));
			solidcircle(cannon.firex, cannon.firey, 15 * i / 10);
			y += 20;
		}



	}
	if (cannon.cannonState == C_NORMAL) {
		cannon.firex = cannon.endx;
		cannon.firey = cannon.endy;//归位
	}
	//绘制垃圾
	for (int i = 0; i < CBIG; i++) {
		if (mine[i].flag == true) {
			putimage(mine[i].x, mine[i].y, &Game3img[i_goldBig - 1], SRCAND);
			putimage(mine[i].x, mine[i].y, &Game3img[i_goldBig], SRCPAINT);
		}
	}
	for (int i = CBIG; i < CBIG + CSMALL; i++) {
		if (mine[i].flag == true) {
			putimage(mine[i].x, mine[i].y, &Game3img[i_goldSmall - 1], SRCAND);
			putimage(mine[i].x, mine[i].y, &Game3img[i_goldSmall], SRCPAINT);
		}
	}

	for (int i = CBIG + CSMALL; i < CBIG + CSMALL + CHBIG; i++) {
		if (mine[i].flag == true) {
			putimage(mine[i].x, mine[i].y, &Game3img[i_stoneBig - 1], SRCAND);
			putimage(mine[i].x, mine[i].y, &Game3img[i_stoneBig], SRCPAINT);
		}
	}
	for (int i = CBIG + CSMALL + CHBIG; i < CBIG + CSMALL + CHBIG + CHSMALL; i++) {
		if (mine[i].flag == true) {
			putimage(mine[i].x, mine[i].y, &Game3img[i_stoneSmall - 1], SRCAND);
			putimage(mine[i].x, mine[i].y, &Game3img[i_stoneSmall], SRCPAINT);
		}
	}

	for (int i = CBIG + CSMALL + CHBIG + CHSMALL; i < CBIG + CSMALL + CHBIG + CHSMALL + BOMB; i++) {
		if (mine[i].flag == true) {
			putimage(mine[i].x, mine[i].y, &Game3img[i_bomb - 1], SRCAND);
			putimage(mine[i].x, mine[i].y, &Game3img[i_bomb], SRCPAINT);
		}
	}
	scorePrint(sole.credit);
}
void HookRock()
{
	if (cannon.cannonState == C_NORMAL)
	{
		if (cannon.dir == RIGHT)
		{
			cannon.angle++;
		}
		else
		{
			cannon.angle--;
		}
		if (cannon.angle > MAX_ANGLE)
		{
			cannon.dir = LEFT;
		}
		else if (cannon.angle < -MAX_ANGLE)
		{
			cannon.dir = RIGHT;
		}
		//角度转弧度  360 2pai  180  PI

		cannon.endx = cannon.x + sin(PI / 180 * cannon.angle) * cannon.len;
		cannon.endy = cannon.y + cos(PI / 180 * cannon.angle) * cannon.len;
		cannon.midx1 = cannon.x + sin(PI / 180 * cannon.angle) * cannon.len * 0.8;
		cannon.midy1 = cannon.y + cos(PI / 180 * cannon.angle) * cannon.len * 0.8;
		cannon.midx2 = cannon.x + sin(PI / 180 * cannon.angle) * cannon.len * 0.2;
		cannon.midy2 = cannon.y + cos(PI / 180 * cannon.angle) * cannon.len * 0.2;
	}
}


//游戏控制
int GameControl(int speed)
{
	if (GetAsyncKeyState(VK_ESCAPE)) {
		char input = _getch();
		return 1;
	}
	if (GetAsyncKeyState(VK_SPACE) && cannon.cannonState == C_NORMAL && sole.credit >= ONESHOT)
	{
		//按键，求出速度分量
		mciSendString(TEXT("seek fire to start"), NULL, 0, NULL);

		mciSendString(TEXT("play fire"), NULL, 0, NULL);
		char input = _getch();
		cannon.vx = sin(PI / 180 * cannon.angle) * speed;
		cannon.vy = cos(PI / 180 * cannon.angle) * speed;
		cannon.fireState = F_YES;
		cannon.cannonState = C_AWAIT;
		sole.credit -= ONESHOT;
	}
	//碰到边界，火球消失
	if (cannon.firex<0 || cannon.firex>WIN_WIDTH || cannon.firey > WIN_HEIGHT)
	{
		cannon.fireState = F_NO;
		cannon.cannonState = C_NORMAL;
		cannon.firex = cannon.endx;
		cannon.firey = cannon.endy;
	}
	if (cannon.fireState == F_YES)
	{
		cannon.firex += cannon.vx;
		cannon.firey += cannon.vy;
	}
	return 0;
}

void burn(int r) {
	Mine::burning = true;
	mine[r].flag = false;
	Mine::sum = Mine::sum - 1;
	switch (mine[r].type)
	{
	case C_Big:
		putimage(mine[r].x, mine[r].y, &Game3img[i_burnBig]);
		sole.credit += 80;
		break;
	case C_Small:
		putimage(mine[r].x, mine[r].y, &Game3img[i_burnSmall]);
		sole.credit += 100;
		break;
	case CH_Big:
		putimage(mine[r].x, mine[r].y, &Game3img[i_smokeBig]);
		sole.credit += 150;
		break;
	case CH_Small:
		putimage(mine[r].x, mine[r].y, &Game3img[i_smokeSmall]);
		sole.credit += 200;
		break;
	case CHO: {
		sole.credit += 50;
		int t = (BIG - SMALL) / 2;
		putimage(mine[r].x - t, mine[r].y - t, &Game3img[i_explode]);
		if (r == 15) {
			if (mine[1].flag) {
				mine[1].flag = false;
				sole.credit += 80;
				Mine::sum = Mine::sum - 1;
			}
			if (mine[8].flag) {
				mine[8].flag = false;
				sole.credit += 100;
				Mine::sum = Mine::sum - 1;
			}
		}
		if (r == 14) {
			if (mine[3].flag) {
				mine[3].flag = false;
				sole.credit += 80;
				Mine::sum = Mine::sum - 1;
			}
			if (mine[12].flag) {
				mine[12].flag = false;
				sole.credit += 200;
				Mine::sum = Mine::sum - 1;
			}
		}
		if (r == 13) {
			if (mine[0].flag) {
				mine[0].flag = false;
				sole.credit += 80;
				Mine::sum = Mine::sum - 1;
			}
			if (mine[2].flag) {
				mine[2].flag = false;
				sole.credit += 80;
				Mine::sum = Mine::sum - 1;
			}
			if (mine[5].flag) {
				mine[5].flag = false;
				sole.credit += 100;
				Mine::sum = Mine::sum - 1;
			}
			if (mine[10].flag) {
				mine[10].flag = false;
				sole.credit += 200;
				Mine::sum = Mine::sum - 1;
			}
		}
		break;
	}
	}
	//Sleep(10);
}
void JudgeGrap()
{
	//判断抓到那个物品
	for (int i = 0; i < MAX_MINE; i++)
	{
		if (mine[i].flag == true &&
			cannon.firex > mine[i].x && cannon.firex<mine[i].x + mine[i].size &&
			cannon.firey > mine[i].y && cannon.firey < mine[i].y + mine[i].size)
		{
			cannon.index = i;
			break;
		}
	}
	//如果抓到了
	if (cannon.index != -1)
	{
		cannon.fireState = F_NO;//火球消失
		cannon.cannonState = C_NORMAL;
		cannon.firex = cannon.endx;
		cannon.firey = cannon.endy;
		burn(cannon.index);
	}
}
void G2Music() {

	mciSendString(TEXT("open Game2BGM.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);//打开报警音
	mciSendString(TEXT("open fire.mp3 alias fire"), NULL, 0, NULL);
}

int Start() {
	GameInit();
	G2Music();
	initiateNumber();
	BeginBatchDraw();
	while (1)
	{
		HookRock();
		GameDraw();
		if (GameControl(10)) { return 4; }//返回1则退出4
		JudgeGrap();
		FlushBatchDraw();

		if (Mine::burning) {
			Sleep(500);
			Mine::burning = false;
		}
		else Sleep(10);
		if (Mine::sum == 0) {
			return 1;
		}
		if (sole.credit < ONESHOT && cannon.cannonState == C_NORMAL)return 2;
	}
	//1 胜利 2 失败 3 重开 4 跳关

}


int RunGame2() {
RESTART:
	int result = Start();
	EndBatchDraw();
	mciSendString(TEXT("close bgm"), NULL, 0, NULL);//关闭bgm
	if (result == 1) {
		victory();
		system("pause");
		return 1;
	}
	else if (result == 2) {
		defeat();
		system("pause");
		if (GetAsyncKeyState(89)) {
			goto RESTART;
		}
		else return 1;
		
	}
	else if (result == 3) {
		goto RESTART;
	}
	else if (result == 4) {
		return 1;
	}
}