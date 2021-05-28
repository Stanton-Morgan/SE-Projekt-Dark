#include "Game1.h"
#include "FrameWork.h"

UINT g_BeginTime;
UINT n_BeginTime;
int in_ch1_hand = 0;
int in_ch2_hand = 0;//0啥也没有，1~7拿对应号的rub，8拿着空的垃圾袋,9拿着垃圾袋。
int width = 960;
int high = 600;
int shen_hou = 50;
int music_line = 0;
IMAGE BG;
IMAGE AC1, AC2;
IMAGE AC3, AC4;
IMAGE RUBBISH;
IMAGE BAg1;
IMAGE BAg2;
IMAGE bin1, bin2, bin3, bin4, bin11, bin21, bin31, bin41;
IMAGE rub1, rub2, rub3, rub4, rub5, rub6, rub7, rub8, rub9, rub10;
IMAGE rub11, rub21, rub31, rub41, rub51, rub61, rub71, rub81, rub91, rub101;
int p_run1[14];
//垃圾状态参数，初始化垃圾存在为0，一号捡到垃圾后为1不画,二号捡到则为2，假如为3则送进正确的垃圾箱，4错误垃圾箱.
int lajidai[2] = { 540,500 };//垃圾袋堆位置
int la_ji_xiang_de_wei_zhi[8] = { 0,0,50,0,100,0,150,0 };
int d_id;
int d_id2;
int rb_x = 100;
int rb_y = 600;
int id = 0;
int id1 = 0;
int clock = 0;
int clock2 = 0;
int size_of_rub = 30;
//人物坐标
int p_x = width - 100;
int p_y = high - 100;
int p2_x = width / 2;
int p2_y = high / 2;
void scoreprint(int score);
void;
//第二个人与第一个初始出生地不同
int time_sleep = 30;
IMAGE juan1, juan2, dui1, dui2;
int r[10] = { 0,0,0,0,0,0,0,0,0,0 };
int r_x[11] = { 0,800,880,700,690,600,700,300,999,0,0 };
int r_y[11] = { 0,450,430,500,360,400,300,400,466,0,0 };

int score_game_of_yxb = 0;
int score() {
	int sum = 0;
	for (int i = 1; i < 8; i++) {
		if (r[i] == 0 || r[i] == 1 || r[i] == 2) {
			sum += 0;
			continue;
		}
		if (r[i] == 3) {
			sum += 5;
			continue;

		}
		if (r[i] == 4) {
			sum += 10;
			continue;
		}
	}

	return sum;
}
int gameover() {

	return 0;
}
int is_lenth_ok(int a, int b, int c, int d) {
	if (abs(a - c) <= 55 && abs(b - d) <= 55) {
		return 1;
	}

	else {
		return 2;
	}
}
/*int score() {
	int sum = 0;
	for (int i = 1;i < 11;i++) {
		if (r[i] == 1) {
			sum +=3;
			continue;

		}
		if (r[i] == 2) {
			sum += 10;
			continue;

		}
		if (r[i] == 1) {
			sum += 5;
			continue;

		}

	}
	return sum;
}*/

void change_name_of_window() {
	HWND hnd = GetHWnd();

	SetWindowText(hnd, _T("嘿嘿"));
	int isok = MessageBox(hnd, _T("欢迎"), _T("你好"), MB_OKCANCEL);
	if (isok == IDOK) {
		HWND okk = GetHWnd();

		SetWindowText(okk, _T(""));
		int isokk = MessageBox(okk, _T("好耶"), _T("针不戳"), MB_OK);
	}
	else
	{
		HWND noo = GetHWnd();

		SetWindowText(noo, _T(""));
		int isokk = MessageBox(noo, _T("即使取消游戏还是要开始哦"), _T("？？？"), MB_OK);
	}
}
int min_length(int a, int b, int b1, int b2, int b3, int b4) {
	return 1;
}
int moodle_change() {
	HWND hnd = GetHWnd();
	SetWindowText(hnd, _T("选择模式"));
	int isok = MessageBox(hnd, _T("点击确定选择单人模式，点击取消选择双人模式"), _T("模式选择"), MB_OKCANCEL);
	if (isok == IDOK) {
		return 1;
	}
	else
		return 2;
}//单人？
int game_over(int a) {
	if (a < 2)
	{
		return 1;
	}
	else
	{
		//score();


	}
}//判定游戏结束
int RunGame1()
{

	change_name_of_window();
	//change_name_of_windowf();
	g_BeginTime = GetTickCount();
	//设置窗口大小
	initgraph(width, high);
	settextstyle(30, 0, _T("微软雅黑"));
	setlinecolor(RED);
	//加载背景图片
	loadimage(&BG, _T("./images/Game1/bg2.jpg"));
	loadimage(&RUBBISH, _T("./images/Game1/垃圾.png"), 100, 100);
	//垃圾
	mciSendString(TEXT("open Game4move.mp3 alias push"), NULL, 0, NULL);

	loadimage(&rub1, _T("./images/Game1/rub1.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub2, _T("./images/Game1/rub2.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub3, _T("./images/Game1/rub3.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub4, _T("./images/Game1/rub4.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub5, _T("./images/Game1/rub5.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub6, _T("./images/Game1/rub9.jpg"), size_of_rub + 20, size_of_rub + 20);
	loadimage(&rub7, _T("./images/Game1/垃圾7.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub11, _T("./images/Game1/rub12.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub21, _T("./images/Game1/rub21.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub31, _T("./images/Game1/rub31.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub41, _T("./images/Game1/rub41.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub51, _T("./images/Game1/rub51.jpg"), size_of_rub, size_of_rub);
	loadimage(&rub61, _T("./images/Game1/rub91.jpg"), size_of_rub + 20, size_of_rub + 20);
	loadimage(&rub71, _T("./images/Game1/垃圾71.jpg"), size_of_rub, size_of_rub);
	loadimage(&juan1, _T("./images/Game1/卷1.jpg"), 25, 25);
	loadimage(&juan2, _T("./images/Game1/卷2.jpg"), 25, 25);
	loadimage(&bin1, _T("./images/Game1/bins.jpg"), 200, 50);
	loadimage(&dui1, _T("./images/Game1/垃圾袋.jpg"), 50, 50);
	loadimage(&dui2, _T("./images/Game1/垃圾袋1.jpg"), 50, 50);
	loadimage(&bin11, _T("./images/Game1/bins1.jpg"), 200, 50);
	initiateNumber();
	//
	loadimage(&BAg1, _T("./images/Game1/垃圾袋-1.jpg"), 50, 50);
	loadimage(&BAg2, _T("./images/Game1/垃圾袋-2.jpg"), 50, 50);
	//绘制背景图片
	putimage(0, 0, &BG);//
	//putimage(400, 300,100,100, &RUBBISH,0,0);
	//drawAlpha(&RUBBISH, rb_x, rb_y);
	TCHAR timeStr[256];
	//加载人物图片
	loadimage(&AC1, _T("./images/Game1/actor1.jpg"));
	loadimage(&AC2, _T("./images/Game1/actor2.jpg"));
	loadimage(&AC3, _T("./images/Game1/girl1.jpg"));
	loadimage(&AC4, _T("./images/Game1/girl2.jpg"));
	//绘制人物图片
	if (moodle_change() == 1) {
		BeginBatchDraw();

		int actor_change = 0;
		int is_actor_has_rubbish = 0;
		while (1)
		{
			if (MouseHit())
			{
				//鼠标信息
				MOUSEMSG msg = GetMouseMsg();
				printf("(x,y)(%d,%d)\n", msg.x, msg.y);
				//消息分发
				switch (msg.uMsg) {
				case WM_LBUTTONDOWN:
					outtextxy(400, 400, _T("针不戳"));

					break;
				case WM_RBUTTONDOWN:
					outtextxy(400, 400, _T("住在山里"));
					break;

				}

			}
			TCHAR timeStr[256];
			int loseTime = GetTickCount() - g_BeginTime;
			_stprintf_s(timeStr, _T("time:%02d:%02d"), loseTime / 1000 / 60, loseTime / 1000 % 60);
			settextcolor(RGB(250, 180, 0));
			outtextxy((width - textwidth(timeStr)) / 2, 3, timeStr);
			if ((loseTime) / 1000 / 60 == 2) {

				score_game_of_yxb = score();
				scorePrint(score_game_of_yxb);

				break;

			}
			//game_over(loseTime / 1000 / 60);
			if (GetAsyncKeyState(VK_SHIFT))
			{
				actor_change++;

			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				if (actor_change % 2 == 0) {
					d_id = 1;
					p_x -= 8;
					if (p_x <= 0)
					{
						p_x = 0;
					}
					if (p_x <= width - 400)
					{
						p_x = width - 400;
					}

					id++;
					Sleep(time_sleep);
					if (id == 3)
					{
						id = 0;
					}
				}
				else
				{
					d_id2 = 1;
					p2_x -= 8;
					if (p2_x <= 0)
					{
						p2_x = 0;
					}
					if (p2_x >= width - 400)
					{
						p2_x = width - 400;
					}

					id1++;
					Sleep(time_sleep);
					if (id1 == 3)
					{
						id1 = 0;
					}

				}

			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{

				if (actor_change % 2 == 0) {
					p_x += 8;
					d_id = 2;
					if (p_x >= width - 50)
					{
						p_x = width - 50;
					}
					if (p_x <= width - 400)
					{
						p_x = width - 400;
					}
					id++;
					Sleep(time_sleep);
					if (id == 3)
					{
						id = 0;
					}
				}
				else {
					d_id2 = 2;
					p2_x += 8;
					if (p2_x >= width - 50)
					{
						p2_x = width - 50;
					}
					if (p2_x >= width - 450)
					{
						p2_x = width - 450;
					}
					id1++;
					Sleep(time_sleep);
					if (id1 == 3)
					{
						id1 = 0;
					}
				}

			}
			else if (GetAsyncKeyState(VK_UP))
			{
				if (actor_change % 2 == 0) {
					p_y -= 8;
					d_id = 3;
					if (p_y <= 0)
					{
						p_y = 0;
					}
					if (p_y <= high - 400)
					{
						p_y = high - 400;
					}

					id++;
					Sleep(time_sleep);
					if (id == 3)
					{
						id = 0;
					}
				}
				else {
					d_id2 = 3;
					p2_y -= 8;
					if (p2_y <= 0)
					{
						p2_y = 0;
					}
					id1++;
					Sleep(time_sleep);
					if (id1 == 3)
					{
						id1 = 0;
					}


				}

			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				if (actor_change % 2 == 0) {
					d_id = 0;
					p_y += 8;
					if (p_y >= high - 50)
					{
						p_y = high - 50;
					}
					if (p_y <= high - 400)
					{
						p_y = high - 400;
					}
					id++;
					Sleep(time_sleep);
					if (id == 3)
					{
						id = 0;
					}
				}
				else {
					d_id2 = 0;
					p2_y += 8;
					if (p2_y >= high - 50)
					{
						p2_y = high - 50;
					}
					id1++;

					Sleep(time_sleep);
					if (id1 == 3)
					{
						id1 = 0;
					}


				}
			}
			if (GetAsyncKeyState(VK_ESCAPE)) {
				score_game_of_yxb = score();
				scorePrint(score_game_of_yxb);


				break;
			}
			if (GetAsyncKeyState(VK_SPACE)) {

				//画一个饼状图。。。。。。。条状也行
				//
				if (actor_change % 2 == 0) {//玩家1
					if (in_ch1_hand == 9) {
						if (is_lenth_ok(p_x, p_y, r_x[1], r_y[1]) == 1) {
							in_ch1_hand = 1;
							r[1] = 1;
						}
						else if (is_lenth_ok(p_x, p_y, r_x[2], r_y[2]) == 1) {
							in_ch1_hand = 2;
							r[2] = 1;
						}
						else if (is_lenth_ok(p_x, p_y, r_x[3], r_y[3]) == 1) {
							in_ch1_hand = 3;
							r[3] = 1;
						}
						else if (is_lenth_ok(p_x, p_y, r_x[4], r_y[4]) == 1) {
							in_ch1_hand = 4;
							r[4] = 1;
						}
						else if (is_lenth_ok(p_x, p_y, r_x[5], r_y[5]) == 1) {
							in_ch1_hand = 5;
							r[5] = 1;
						}
						else if (is_lenth_ok(p_x, p_y, r_x[6], r_y[6]) == 1) {
							in_ch1_hand = 6;
							r[6] = 1;
						}

					}
					else if (in_ch1_hand == 0 && is_lenth_ok(p_x, p_y, lajidai[0], lajidai[1]) == 1) {
						in_ch1_hand = 9;
					}



					else if (in_ch1_hand != 0 && in_ch1_hand != 9) {//玩家一放东西
						if (in_ch1_hand == 1) {
							if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;

								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;
							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[1] = 3;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							//扔垃圾1
							in_ch1_hand = 0;
							r[1] = 0;
						}
						if (in_ch1_hand == 2) {
							if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;
							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[2] = 3;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}


							in_ch1_hand = 0;
							r[2] = 0;
						}
						if (in_ch1_hand == 3) {
							if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;
							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[3] = 3;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							in_ch1_hand = 0;
							r[3] = 0;
						}
						if (in_ch1_hand == 4) {
							if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;
							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[4] = 3;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							in_ch1_hand = 0;
							r[4] = 0;
						}
						if (in_ch1_hand == 5) {
							if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;
							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[5] = 3;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							in_ch1_hand = 0;
							r[5] = 0;
						}
						if (in_ch1_hand == 6) {
							if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;
							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							in_ch1_hand = 0;
							r[6] = 0;
						}
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);

						/*if (in_ch1_hand == 9) {
							in_ch1_hand = 0;
						}*/

					}

				}
				else if (actor_change % 2 == 1) {//玩家1空手时

					if (in_ch2_hand == 0 && is_lenth_ok(p2_x, p2_y, lajidai[0], lajidai[1]) == 1) {
						in_ch2_hand = 9;
					}


					if (in_ch2_hand == 9) {
						if (is_lenth_ok(p2_x, p2_y, r_x[1], r_y[1]) == 1) {
							in_ch2_hand = 1;
							r[1] = 1;
						}
						else if (is_lenth_ok(p2_x, p2_y, r_x[2], r_y[2]) == 1) {
							in_ch2_hand = 2;
							r[2] = 1;
						}
						else if (is_lenth_ok(p2_x, p2_y, r_x[3], r_y[3]) == 1) {
							in_ch2_hand = 3;
							r[3] = 1;
						}
						else if (is_lenth_ok(p2_x, p2_y, r_x[4], r_y[4]) == 1) {
							in_ch2_hand = 4;
							r[4] = 1;
						}
						else if (is_lenth_ok(p2_x, p2_y, r_x[5], r_y[5]) == 1) {
							in_ch2_hand = 5;
							r[5] = 1;
						}
						else if (is_lenth_ok(p2_x, p2_y, r_x[6], r_y[6]) == 1) {
							in_ch2_hand = 6;
							r[6] = 1;
						}

					}
					else if (in_ch2_hand != 0) {//玩家er放东西
						if (in_ch2_hand == 1) {
							if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;
							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[1] = 3;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							//扔垃圾1
							in_ch2_hand = 0;
							r[1] = 0;
						}
						if (in_ch2_hand == 2) {
							if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;
							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[2] = 3;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}


							in_ch2_hand = 0;
							r[2] = 0;
						}
						if (in_ch2_hand == 3) {
							if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;
							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[3] = 3;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							in_ch2_hand = 0;
							r[3] = 0;
						}
						if (in_ch2_hand == 4) {
							if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;
							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[4] = 3;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							in_ch2_hand = 0;
							r[4] = 0;
						}
						if (in_ch2_hand == 5) {
							if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;
							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[5] = 3;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							in_ch2_hand = 0;
							r[5] = 0;
						}
						if (in_ch2_hand == 6) {
							if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;
							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							in_ch2_hand = 0;
							r[6] = 0;
						}
						//if (in_ch2_hand == 9) {
							//in_ch2_hand = 0;
						//}
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
					}

				}
			}
			/*  -----------------------------------------------*/
			if (GetAsyncKeyState(0x4F) & 0x8000) {
				if (actor_change % 2 == 0) {
					if (in_ch1_hand == 9) {
						for (int i = 1; i < 7; i++) {
							if (is_lenth_ok(p_x, p_y, r_x[i], r_y[i]) == 1) {
								r[i] = 1;
								in_ch1_hand = i;
								mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

								mciSendString(TEXT("play push"), NULL, 0, NULL);
								break;

							}
						}
					}
					else if (in_ch1_hand == 0 && is_lenth_ok(p_x, p_y, lajidai[0], lajidai[1]) == 1) {
						in_ch1_hand = 9;
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
					}
				}
				else if (actor_change % 2 == 1) {
					//
					if (in_ch2_hand == 9) {
						for (int i = 1; i < 7; i++) {
							if (is_lenth_ok(p2_x, p2_y, r_x[i], r_y[i]) == 1) {
								r[i] = 2;
								in_ch2_hand = i;
								mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

								mciSendString(TEXT("play push"), NULL, 0, NULL);
								break;

							}
						}
					}
					else if (in_ch2_hand == 0 && is_lenth_ok(p2_x, p2_y, lajidai[0], lajidai[1]) == 1) {
						in_ch2_hand = 9;
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
					}

				}
			}
			if (GetAsyncKeyState(0x50) & 0x8000) {
				if (actor_change % 2 == 0) {
					if (d_id == 3) {

						// && (is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1 || is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1 || is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1 || is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1
						if (in_ch1_hand > 0 && in_ch1_hand < 8) {

							if (in_ch1_hand == 1) {
								if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1 && p_x > 0 && p_x <= 50) {
									in_ch1_hand = 0;
									r[1] = 4;
									r_x[1] = -1000;
									r_y[1] = -1000;
								}
								else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1 && p_x > 50 && p_x <= 100) {
									in_ch1_hand = 0;
									r[1] = 4;
									r_x[1] = -1000;
									r_y[1] = -1000;

								}
								else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1 && p_x > 100 && p_x <= 150) {
									in_ch1_hand = 0;
									r[1] = 3;
									r_x[1] = -1000;
									r_y[1] = -1000;

								}
								else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1 && p_x > 150 && p_x <= 200) {
									in_ch1_hand = 0;
									r[1] = 4;
									r_x[1] = -1000;
									r_y[1] = -1000;

								}
								//扔垃圾1
								in_ch1_hand = 0;
								r[1] = 0;
							}
							if (in_ch1_hand == 2) {
								if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
									in_ch1_hand = 0;
									r[2] = 4;
									r_x[2] = -1000;
									r_y[2] = -1000;
								}
								else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
									in_ch1_hand = 0;
									r[2] = 4;
									r_x[2] = -1000;
									r_y[2] = -1000;

								}
								else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
									in_ch1_hand = 0;
									r[2] = 3;
									r_x[2] = -1000;
									r_y[2] = -1000;

								}
								else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
									in_ch1_hand = 0;
									r[2] = 4;
									r_x[2] = -1000;
									r_y[2] = -1000;

								}


								in_ch1_hand = 0;
								r[2] = 0;
							}
							if (in_ch1_hand == 3) {
								if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
									in_ch1_hand = 0;
									r[3] = 4;
									r_x[3] = -1000;
									r_y[3] = -1000;
								}
								else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
									in_ch1_hand = 0;
									r[3] = 3;
									r_x[3] = -1000;
									r_y[3] = -1000;

								}
								else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
									in_ch1_hand = 0;
									r[3] = 4;
									r_x[3] = -1000;
									r_y[3] = -1000;

								}
								else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
									in_ch1_hand = 0;
									r[3] = 4;
									r_x[3] = -1000;
									r_y[3] = -1000;

								}
								in_ch1_hand = 0;
								r[3] = 0;
							}
							if (in_ch1_hand == 4) {
								if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
									in_ch1_hand = 0;
									r[4] = 4;
									r_x[4] = -1000;
									r_y[4] = -1000;
								}
								else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
									in_ch1_hand = 0;
									r[4] = 4;
									r_x[4] = -1000;
									r_y[4] = -1000;

								}
								else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
									in_ch1_hand = 0;
									r[4] = 4;
									r_x[4] = -1000;
									r_y[4] = -1000;

								}
								else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
									in_ch1_hand = 0;
									r[4] = 3;
									r_x[4] = -1000;
									r_y[4] = -1000;

								}
								in_ch1_hand = 0;
								r[4] = 0;
							}
							if (in_ch1_hand == 5) {
								if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
									in_ch1_hand = 0;
									r[5] = 4;
									r_x[5] = -1000;
									r_y[5] = -1000;
								}
								else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
									in_ch1_hand = 0;
									r[5] = 4;
									r_x[5] = -1000;
									r_y[5] = -1000;

								}
								else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
									in_ch1_hand = 0;
									r[5] = 4;
									r_x[5] = -1000;
									r_y[5] = -1000;

								}
								else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
									in_ch1_hand = 0;
									r[5] = 3;
									r_x[5] = -1000;
									r_y[5] = -1000;

								}
								in_ch1_hand = 0;
								r[5] = 0;
							}
							if (in_ch1_hand == 6) {
								if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
									in_ch1_hand = 0;
									r[6] = 4;
									r_x[6] = -1000;
									r_y[6] = -1000;
								}
								else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
									in_ch1_hand = 0;
									r[6] = 3;
									r_x[6] = -1000;
									r_y[6] = -1000;

								}
								else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
									in_ch1_hand = 0;
									r[6] = 4;
									r_x[6] = -1000;
									r_y[6] = -1000;

								}
								else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
									in_ch1_hand = 0;
									r[6] = 3;
									r_x[6] = -1000;
									r_y[6] = -1000;

								}
								in_ch1_hand = 0;
								r[6] = 0;
							}
							mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

							mciSendString(TEXT("play push"), NULL, 0, NULL);
						}
					}
					if (in_ch1_hand > 0 && in_ch1_hand < 8) {
						for (int i = 1; i < 7; i++) {
							if (r[i] == 1) {
								in_ch1_hand = 0;
								r[i] = 0;
								mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

								mciSendString(TEXT("play push"), NULL, 0, NULL);
								break;

							}

						}
					}
				}


				else if (actor_change % 2 == 1) {
					if (in_ch2_hand > 0 && in_ch2_hand < 8) {
						for (int i = 1; i < 7; i++) {
							if (r[i] == 2) {
								in_ch2_hand = 0;
								r[i] = 0;
								mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

								mciSendString(TEXT("play push"), NULL, 0, NULL);
								break;

							}

						}
					}
					if (in_ch2_hand > 0 && in_ch2_hand < 8 && (is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1 || is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1 || is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1 || is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1)) {//玩家er放东西
						if (in_ch2_hand == 1) {
							if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;
							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[1] = 3;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							//扔垃圾1
							in_ch2_hand = 0;
							r[1] = 0;
						}
						if (in_ch2_hand == 2) {
							if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;
							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[2] = 3;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}


							in_ch2_hand = 0;
							r[2] = 0;
						}
						if (in_ch2_hand == 3) {
							if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;
							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[3] = 3;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							in_ch2_hand = 0;
							r[3] = 0;
						}
						if (in_ch2_hand == 4) {
							if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;
							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[4] = 3;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							in_ch2_hand = 0;
							r[4] = 0;
						}
						if (in_ch2_hand == 5) {
							if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;
							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[5] = 3;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							in_ch2_hand = 0;
							r[5] = 0;
						}
						if (in_ch2_hand == 6) {
							if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch2_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;
							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch2_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch2_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch2_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							in_ch2_hand = 0;
							r[6] = 0;
						}
						//if (in_ch2_hand == 9) {
							//in_ch2_hand = 0;
						//}
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
					}

				}
			}
			if (in_ch1_hand > 0 && in_ch1_hand < 8) {
				for (int i = 1; i < 7; i++) {
					if (r[i] == 1) {
						r_x[i] = p_x;
						r_y[i] = p_y;
					}
				}
			}
			if (in_ch2_hand > 0 && in_ch2_hand < 8) {
				for (int i = 1; i < 7; i++) {
					if (r[i] == 1) {
						r_x[i] = p2_x;
						r_y[i] = p2_y;
					}
				}
			}
			if (true);
			if (r[1] == 1) {
				r_x[1] = p_x;
				r_y[1] = p_y;
			}
			if (r[2] == 1) {
				r_x[2] = p_x;
				r_y[2] = p_y;

			}
			if (r[3] == 1) {
				r_x[3] = p_x;
				r_y[3] = p_y;
			}
			if (r[4] == 1) {
				r_x[4] = p_x;
				r_y[4] = p_y;
			}
			if (r[5] == 1) {
				r_x[5] = p_x;
				r_y[5] = p_y;
			}
			if (r[6] == 1) {
				r_x[6] = p_x;
				r_y[6] = p_y;
			}
			if (r[1] == 2) {
				r_x[1] = p2_x;
				r_y[1] = p2_y;
			}
			if (r[2] == 2) {
				r_x[2] = p2_x;
				r_y[2] = p2_y;

			}
			if (r[3] == 2) {
				r_x[3] = p2_x;
				r_y[3] = p2_y;
			}
			if (r[4] == 2) {
				r_x[4] = p2_x;
				r_y[4] = p2_y;
			}
			if (r[5] == 2) {
				r_x[5] = p2_x;
				r_y[5] = p2_y;
			}
			if (r[6] == 2) {
				r_x[6] = p2_x;
				r_y[6] = p2_y;
			}
			clearrectangle(0, 0, width, high);
			//绘制背景图片
			putimage(0, 0, &BG);
			setlinestyle(PS_SOLID, 10);   //设置画线的大小
			line(width - 400, high - 400, width - 400, high);
			line(width - 400, high - 400, width, high - 400);


			if (r[1] == 0) {
				putimage(r_x[1], r_y[1], &rub11, NOTSRCERASE);
				putimage(r_x[1], r_y[1], &rub1, SRCINVERT);

			}
			if (r[2] == 0) {
				putimage(r_x[2], r_y[2], &rub21, NOTSRCERASE);
				putimage(r_x[2], r_y[2], &rub2, SRCINVERT);

			}
			if (r[3] == 0) {
				putimage(r_x[3], r_y[3], &rub31, NOTSRCERASE);
				putimage(r_x[3], r_y[3], &rub3, SRCINVERT);

			}
			if (r[4] == 0) {
				putimage(r_x[4], r_y[4], &rub41, NOTSRCERASE);
				putimage(r_x[4], r_y[4], &rub4, SRCINVERT);

			}
			if (r[5] == 0) {
				putimage(r_x[5], r_y[5], &rub51, NOTSRCERASE);
				putimage(r_x[5], r_y[5], &rub5, SRCINVERT);

			}
			if (r[6] == 0) {
				putimage(r_x[6], r_y[6], &rub61, NOTSRCERASE);
				putimage(r_x[6], r_y[6], &rub6, SRCINVERT);

			}//垃圾定位
			//垃圾定位系统
			putimage(la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1], &bin11, NOTSRCERASE);
			putimage(la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1], &bin1, SRCINVERT);
			putimage(lajidai[0], lajidai[1], &dui2, NOTSRCERASE);
			putimage(lajidai[0], lajidai[1], &dui1, SRCINVERT);//卷的位置
			putimage(p_x, p_y, 50, 50, &AC2, 50 * id, 50 * d_id, NOTSRCERASE);
			putimage(p_x, p_y, 50, 50, &AC1, 50 * id, 50 * d_id, SRCINVERT);
			putimage(p2_x, p2_y, 50, 50, &AC4, 50 * id1, 50 * d_id2, NOTSRCERASE);
			putimage(p2_x, p2_y, 50, 50, &AC3, 50 * id1, 50 * d_id2, SRCINVERT);

			if (in_ch1_hand > 0 && in_ch1_hand < 8) {
				if (d_id == 1) {
					putimage(p_x + 20, p_y, &BAg2, NOTSRCERASE);
					putimage(p_x + 20, p_y, &BAg1, SRCINVERT);
				}
				if (d_id == 2) {
					putimage(p_x - 20, p_y, &BAg2, NOTSRCERASE);
					putimage(p_x - 20, p_y, &BAg1, SRCINVERT);
				}
				if (d_id == 3) {
					putimage(p_x, p_y + 20, &BAg2, NOTSRCERASE);
					putimage(p_x, p_y + 20, &BAg1, SRCINVERT);
				}
				if (d_id == 0) {
					putimage(p_x, p_y - 20, &BAg2, NOTSRCERASE);
					putimage(p_x, p_y - 20, &BAg1, SRCINVERT);
				}

			}
			if (in_ch1_hand == 9) {
				if (d_id == 1) {
					putimage(p_x + 15, p_y, &juan2, NOTSRCERASE);
					putimage(p_x + 15, p_y, &juan1, SRCINVERT);
				}
				if (d_id == 2) {
					putimage(p_x - 15, p_y, &juan2, NOTSRCERASE);
					putimage(p_x - 15, p_y, &juan1, SRCINVERT);
				}
				if (d_id == 3) {
					putimage(p_x, p_y + 15, &juan2, NOTSRCERASE);
					putimage(p_x, p_y + 15, &juan1, SRCINVERT);
				}
				if (d_id == 0) {
					putimage(p_x, p_y - 15, &juan2, NOTSRCERASE);
					putimage(p_x, p_y - 15, &juan1, SRCINVERT);
				}

			}
			if (in_ch2_hand > 0 && in_ch2_hand < 8) {
				if (d_id2 == 1) {
					putimage(p2_x + 20, p2_y, &BAg2, NOTSRCERASE);
					putimage(p2_x + 20, p2_y, &BAg1, SRCINVERT);
				}
				if (d_id2 == 2) {
					putimage(p2_x - 20, p2_y, &BAg2, NOTSRCERASE);
					putimage(p2_x - 20, p2_y, &BAg1, SRCINVERT);
				}
				if (d_id2 == 3) {
					putimage(p2_x, p2_y + 20, &BAg2, NOTSRCERASE);
					putimage(p2_x, p2_y + 20, &BAg1, SRCINVERT);
				}
				if (d_id2 == 0) {
					putimage(p2_x, p2_y - 20, &BAg2, NOTSRCERASE);
					putimage(p2_x, p2_y - 20, &BAg1, SRCINVERT);
				}

			}

			else if (in_ch2_hand == 9) {
				if (d_id2 == 1) {
					putimage(p2_x + 20, p2_y, &juan2, NOTSRCERASE);
					putimage(p2_x + 20, p2_y, &juan1, SRCINVERT);
				}
				if (d_id2 == 2) {
					putimage(p2_x - 20, p2_y, &juan2, NOTSRCERASE);
					putimage(p2_x - 20, p2_y, &juan1, SRCINVERT);
				}
				if (d_id2 == 3) {
					putimage(p2_x, p2_y + 20, &juan2, NOTSRCERASE);
					putimage(p2_x, p2_y + 20, &juan1, SRCINVERT);
				}
				if (d_id2 == 0) {
					putimage(p2_x, p2_y - 20, &juan2, NOTSRCERASE);
					putimage(p2_x, p2_y - 20, &juan1, SRCINVERT);
				}

			}

			loseTime = GetTickCount() - g_BeginTime;
			_stprintf_s(timeStr, _T("time:%02d:%02d"), loseTime / 1000 / 60, loseTime / 1000 % 60);
			settextcolor(RGB(250, 180, 0));
			outtextxy((width - textwidth(timeStr)) / 2, 3, timeStr);

			//实现放和捡垃圾
			FlushBatchDraw();
		}
		EndBatchDraw();
		//关闭窗口
		//closegraph();
	}
	else {
		putimage(p_x, p_y, 50, 50, &AC2, 0, 0, NOTSRCERASE);
		putimage(p_x, p_y, 50, 50, &AC1, 0, 0, SRCINVERT);

		putimage(p2_x, p2_y, 50, 50, &AC4, 0, 0, NOTSRCERASE);
		putimage(p2_x, p2_y, 50, 50, &AC3, 0, 0, SRCINVERT);
		putimage(10, 100, 50, 100, &bin11, 0, 0, NOTSRCERASE);
		putimage(10, 100, 50, 100, &bin1, 0, 0, SRCINVERT);
		BeginBatchDraw();
		BeginBatchDraw();
		while (1)
		{
			if (MouseHit())
			{
				//鼠标信息
				MOUSEMSG msg = GetMouseMsg();
				printf("(x,y)(%d,%d)\n", msg.x, msg.y);
				//消息分发
				switch (msg.uMsg) {
				case WM_LBUTTONDOWN:
					outtextxy(400, 400, _T(""));

					break;
				case WM_RBUTTONDOWN:
					outtextxy(400, 400, _T(""));
					break;

				}

			}
			TCHAR timeStr[256];
			int loseTime = GetTickCount() - g_BeginTime;
			_stprintf_s(timeStr, _T("time:%02d:%02d"), loseTime / 1000 / 60, loseTime / 1000 % 60);
			settextcolor(RGB(106, 0, 95));
			outtextxy((width - textwidth(timeStr)) / 2, 3, timeStr);
			if ((loseTime) / 1000 / 60 == 2) {

				score_game_of_yxb = score();
				scorePrint(score_game_of_yxb);
				//change_name_of_windowf();
				break;

			}
			//game_over(loseTime / 1000 / 60);
			if (GetAsyncKeyState(0x41) & 0x8000)	//a
			{
				d_id = 1;
				p_x -= 8;
				if (p_x <= 0)
				{
					p_x = 0;
				}
				if (p_x <= width - 400)
				{
					p_x = width - 400;
				}
				id++;
				if (id == 3)
				{
					id = 0;
				}

			}
			else if (GetAsyncKeyState(0x44) & 0x8000)	//d
			{
				d_id = 2;
				p_x += 8;
				if (p_x >= width - 50)
				{
					p_x = width - 50;
				}
				id++;
				if (id == 3)
				{
					id = 0;
				}

			}
			else if (GetAsyncKeyState(0x57) & 0x8000)		//w
			{
				d_id = 3;
				p_y -= 8;
				if (p_y <= 0)
				{
					p_y = 0;
				}
				if (p_y <= high - 400)
				{
					p_y = high - 400;
				}

				id++;
				if (id == 3)
				{
					id = 0;
				}

			}
			else if (GetAsyncKeyState(0x53) & 0x8000)		//s
			{
				d_id = 0;
				p_y += 8;
				if (p_y >= high - 50)
				{
					p_y = high - 50;
				}
				id++;
				if (id == 3)
				{
					id = 0;
				}
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)		//左键
			{
				d_id2 = 1;
				p2_x -= 8;
				if (p2_x <= 0)
				{
					p2_x = 0;
				}
				id1++;

				if (id1 == 3)
				{
					id1 = 0;
				}
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)		//右键
			{
				d_id2 = 2;
				p2_x += 8;
				if (p2_x >= width - 50)
				{
					p2_x = width - 50;
				}
				if (p2_x >= width - 450)
				{
					p2_x = width - 450;
				}
				id1++;
				if (id1 == 3)
				{
					id1 = 0;
				}
			}
			else if (GetAsyncKeyState(VK_UP) & 0x8000)		//上键
			{
				d_id2 = 3;
				p2_y -= 8;
				if (p2_y <= 0)
				{
					p2_y = 0;
				}
				id1++;
				if (id1 == 3)
				{
					id1 = 0;
				}
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000)		//下键
			{
				d_id2 = 0;
				p2_y += 8;
				if (p2_y >= high - 50)
				{
					p2_y = high - 50;
				}
				id1++;
				if (id1 == 3)
				{
					id1 = 0;
				}
			}
			if (GetAsyncKeyState(VK_ESCAPE)) {
				score_game_of_yxb = score();
				scorePrint(score_game_of_yxb);
				//change_name_of_windowf();
				break;
			}
			if (GetAsyncKeyState(0x4F) & 0x8000) {

				if (in_ch1_hand == 9) {
					for (int i = 1; i < 7; i++) {
						if (is_lenth_ok(p_x, p_y, r_x[i], r_y[i]) == 1) {
							r[i] = 1;
							in_ch1_hand = i;
							mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

							mciSendString(TEXT("play push"), NULL, 0, NULL);

							break;

						}
					}
				}
				else if (in_ch1_hand == 0 && is_lenth_ok(p_x, p_y, lajidai[0], lajidai[1]) == 1) {
					in_ch1_hand = 9;
					mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

					mciSendString(TEXT("play push"), NULL, 0, NULL);
				}
			}
			if (GetAsyncKeyState(0x50) & 0x8000) {
				if (d_id == 3) {

					// && (is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1 || is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1 || is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1 || is_lenth_ok(p_x, p_y, la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1
					if (in_ch1_hand > 0 && in_ch1_hand < 8) {

						if (in_ch1_hand == 1) {
							if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1 && p_x > 0 && p_x <= 50) {
								in_ch1_hand = 0;

								r[1] = 4;
								r_x[1] = -1000;
								r_y[1] = -1000;
							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1 && p_x > 50 && p_x <= 100) {
								in_ch1_hand = 0;
								r[1] = 4;

								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1 && p_x > 100 && p_x <= 150) {
								in_ch1_hand = 0;
								r[1] = 3;

								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1 && p_x > 150 && p_x <= 200) {
								in_ch1_hand = 0;
								r[1] = 4;

								r_x[1] = -1000;
								r_y[1] = -1000;

							}
							//扔垃圾1
							in_ch1_hand = 0;
							r[1] = 0;
						}
						if (in_ch1_hand == 2) {
							if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;
							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[2] = 3;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}
							else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[2] = 4;
								r_x[2] = -1000;
								r_y[2] = -1000;

							}


							in_ch1_hand = 0;
							r[2] = 0;
						}
						if (in_ch1_hand == 3) {
							if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;
							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[3] = 3;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[3] = 4;
								r_x[3] = -1000;
								r_y[3] = -1000;

							}
							in_ch1_hand = 0;
							r[3] = 0;
						}
						if (in_ch1_hand == 4) {
							if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;
							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[4] = 4;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[4] = 3;
								r_x[4] = -1000;
								r_y[4] = -1000;

							}
							in_ch1_hand = 0;
							r[4] = 0;
						}
						if (in_ch1_hand == 5) {
							if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;
							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[5] = 4;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[5] = 3;
								r_x[5] = -1000;
								r_y[5] = -1000;

							}
							in_ch1_hand = 0;
							r[5] = 0;
						}
						if (in_ch1_hand == 6) {
							if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
								in_ch1_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;
							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
								in_ch1_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
								in_ch1_hand = 0;
								r[6] = 4;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
								in_ch1_hand = 0;
								r[6] = 3;
								r_x[6] = -1000;
								r_y[6] = -1000;

							}
							in_ch1_hand = 0;
							r[6] = 0;
						}
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
					}
				}
				if (in_ch1_hand > 0 && in_ch1_hand < 8) {
					for (int i = 1; i < 7; i++) {
						if (r[i] == 1) {
							in_ch1_hand = 0;
							r[i] = 0;
							mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

							mciSendString(TEXT("play push"), NULL, 0, NULL);
							break;

						}

					}
				}
			}
			if (in_ch1_hand > 0 && in_ch1_hand < 8) {
				for (int i = 1; i < 7; i++) {
					if (r[i] == 1) {
						r_x[i] = p_x;
						r_y[i] = p_y;
					}
				}
			}
			/*-------------------------------------------------------施工区*/

			if (GetAsyncKeyState(0x4D) & 0x8000) {

				if (in_ch2_hand == 9) {
					for (int i = 1; i < 7; i++) {
						if (is_lenth_ok(p2_x, p2_y, r_x[i], r_y[i]) == 1) {
							r[i] = 2;
							in_ch2_hand = i;
							mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

							mciSendString(TEXT("play push"), NULL, 0, NULL);
							break;

						}
					}
				}
				else if (in_ch2_hand == 0 && is_lenth_ok(p2_x, p2_y, lajidai[0], lajidai[1]) == 1) {
					in_ch2_hand = 9;
				}
			}
			if (GetAsyncKeyState(0x4E) & 0x8000) {
				if (in_ch2_hand > 0 && in_ch2_hand < 8 && (is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1 || is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1 || is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1 || is_lenth_ok(p2_x, p2_y, la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1)) {//玩家er放东西
					if (in_ch2_hand == 1) {
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
						if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
							in_ch2_hand = 0;
							r[1] = 4;
							r_x[1] = -1000;
							r_y[1] = -1000;
						}
						else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
							in_ch2_hand = 0;
							r[1] = 4;
							r_x[1] = -1000;
							r_y[1] = -1000;

						}
						else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
							in_ch2_hand = 0;
							r[1] = 3;
							r_x[1] = -1000;
							r_y[1] = -1000;

						}
						else if (is_lenth_ok(r_x[1], r_y[1], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
							in_ch2_hand = 0;
							r[1] = 4;
							r_x[1] = -1000;
							r_y[1] = -1000;

						}
						//扔垃圾1
						in_ch2_hand = 0;
						r[1] = 0;
					}
					if (in_ch2_hand == 2) {
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
						if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
							in_ch2_hand = 0;
							r[2] = 4;
							r_x[2] = -1000;
							r_y[2] = -1000;
						}
						else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
							in_ch2_hand = 0;
							r[2] = 4;
							r_x[2] = -1000;
							r_y[2] = -1000;

						}
						else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
							in_ch2_hand = 0;
							r[2] = 3;
							r_x[2] = -1000;
							r_y[2] = -1000;

						}
						else if (is_lenth_ok(r_x[2], r_y[2], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
							in_ch2_hand = 0;
							r[2] = 4;
							r_x[2] = -1000;
							r_y[2] = -1000;

						}


						in_ch2_hand = 0;
						r[2] = 0;
					}
					if (in_ch2_hand == 3) {
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
						if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
							in_ch2_hand = 0;
							r[3] = 4;
							r_x[3] = -1000;
							r_y[3] = -1000;
						}
						else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
							in_ch2_hand = 0;
							r[3] = 3;
							r_x[3] = -1000;
							r_y[3] = -1000;

						}
						else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
							in_ch2_hand = 0;
							r[3] = 4;
							r_x[3] = -1000;
							r_y[3] = -1000;

						}
						else if (is_lenth_ok(r_x[3], r_y[3], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
							in_ch2_hand = 0;
							r[3] = 4;
							r_x[3] = -1000;
							r_y[3] = -1000;

						}
						in_ch2_hand = 0;
						r[3] = 0;
					}
					if (in_ch2_hand == 4) {
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
						if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
							in_ch2_hand = 0;
							r[4] = 4;
							r_x[4] = -1000;
							r_y[4] = -1000;
						}
						else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
							in_ch2_hand = 0;
							r[4] = 4;
							r_x[4] = -1000;
							r_y[4] = -1000;

						}
						else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
							in_ch2_hand = 0;
							r[4] = 4;
							r_x[4] = -1000;
							r_y[4] = -1000;

						}
						else if (is_lenth_ok(r_x[4], r_y[4], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
							in_ch2_hand = 0;
							r[4] = 3;
							r_x[4] = -1000;
							r_y[4] = -1000;

						}
						in_ch2_hand = 0;
						r[4] = 0;
					}
					if (in_ch2_hand == 5) {
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
						if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
							in_ch2_hand = 0;
							r[5] = 4;
							r_x[5] = -1000;
							r_y[5] = -1000;
						}
						else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
							in_ch2_hand = 0;
							r[5] = 4;
							r_x[5] = -1000;
							r_y[5] = -1000;

						}
						else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
							in_ch2_hand = 0;
							r[5] = 4;
							r_x[5] = -1000;
							r_y[5] = -1000;

						}
						else if (is_lenth_ok(r_x[5], r_y[5], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
							in_ch2_hand = 0;
							r[5] = 3;
							r_x[5] = -1000;
							r_y[5] = -1000;

						}
						in_ch2_hand = 0;
						r[5] = 0;
					}
					if (in_ch2_hand == 6) {
						mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

						mciSendString(TEXT("play push"), NULL, 0, NULL);
						if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1]) == 1) {
							in_ch2_hand = 0;
							r[6] = 4;
							r_x[6] = -1000;
							r_y[6] = -1000;
						}
						else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[2], la_ji_xiang_de_wei_zhi[3]) == 1) {
							in_ch2_hand = 0;
							r[6] = 3;
							r_x[6] = -1000;
							r_y[6] = -1000;

						}
						else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[4], la_ji_xiang_de_wei_zhi[5]) == 1) {
							in_ch2_hand = 0;
							r[6] = 4;
							r_x[6] = -1000;
							r_y[6] = -1000;

						}
						else if (is_lenth_ok(r_x[6], r_y[6], la_ji_xiang_de_wei_zhi[6], la_ji_xiang_de_wei_zhi[7]) == 1) {
							in_ch2_hand = 0;
							r[6] = 3;
							r_x[6] = -1000;
							r_y[6] = -1000;

						}
						in_ch2_hand = 0;
						r[6] = 0;
					}
					//if (in_ch2_hand == 9) {
						//in_ch2_hand = 0;
					//}

				}
				if (in_ch2_hand > 0 && in_ch2_hand < 8) {
					for (int i = 1; i < 7; i++) {
						if (r[i] == 2) {
							in_ch2_hand = 0;
							r[i] = 0;
							mciSendString(TEXT("seek push to start"), NULL, 0, NULL);

							mciSendString(TEXT("play push"), NULL, 0, NULL);
							break;

						}

					}
				}
			}
			if (in_ch2_hand > 0 && in_ch2_hand < 8) {
				for (int i = 1; i < 7; i++) {
					if (r[i] == 1) {
						r_x[i] = p2_x;
						r_y[i] = p2_y;
					}
				}
			}

			/*---------------------------------------------------------*/

		//清空绘制区域
			clearrectangle(0, 0, width, high);
			//绘制背景图片
			putimage(0, 0, &BG);
			setlinestyle(PS_SOLID, 10);   //设置画线的大小
			line(width - 400, high - 400, width - 400, high);
			line(width - 400, high - 400, width, high - 400);
			line(width - 400, high - 400, width - 400, 0);
			if (r[1] == 1) {
				r_x[1] = p_x;
				r_y[1] = p_y;
			}
			if (r[2] == 1) {
				r_x[2] = p_x;
				r_y[2] = p_y;

			}
			if (r[3] == 1) {
				r_x[3] = p_x;
				r_y[3] = p_y;
			}
			if (r[4] == 1) {
				r_x[4] = p_x;
				r_y[4] = p_y;
			}
			if (r[5] == 1) {
				r_x[5] = p_x;
				r_y[5] = p_y;
			}
			if (r[6] == 1) {
				r_x[6] = p_x;
				r_y[6] = p_y;
			}
			if (r[1] == 2) {
				r_x[1] = p2_x;
				r_y[1] = p2_y;
			}
			if (r[2] == 2) {
				r_x[2] = p2_x;
				r_y[2] = p2_y;

			}
			if (r[3] == 2) {
				r_x[3] = p2_x;
				r_y[3] = p2_y;
			}
			if (r[4] == 2) {
				r_x[4] = p2_x;
				r_y[4] = p2_y;
			}
			if (r[5] == 2) {
				r_x[5] = p2_x;
				r_y[5] = p2_y;
			}
			if (r[6] == 2) {
				r_x[6] = p2_x;
				r_y[6] = p2_y;
			}
			if (r[1] == 0) {
				putimage(r_x[1], r_y[1], &rub11, NOTSRCERASE);
				putimage(r_x[1], r_y[1], &rub1, SRCINVERT);

			}
			if (r[2] == 0) {
				putimage(r_x[2], r_y[2], &rub21, NOTSRCERASE);
				putimage(r_x[2], r_y[2], &rub2, SRCINVERT);

			}
			if (r[3] == 0) {
				putimage(r_x[3], r_y[3], &rub31, NOTSRCERASE);
				putimage(r_x[3], r_y[3], &rub3, SRCINVERT);

			}
			if (r[4] == 0) {
				putimage(r_x[4], r_y[4], &rub41, NOTSRCERASE);
				putimage(r_x[4], r_y[4], &rub4, SRCINVERT);

			}
			if (r[5] == 0) {
				putimage(r_x[5], r_y[5], &rub51, NOTSRCERASE);
				putimage(r_x[5], r_y[5], &rub5, SRCINVERT);

			}
			if (r[6] == 0) {
				putimage(r_x[6], r_y[6], &rub61, NOTSRCERASE);
				putimage(r_x[6], r_y[6], &rub6, SRCINVERT);

			}//垃圾定位
			//绘制人物图片
			putimage(la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1], &bin11, NOTSRCERASE);
			putimage(la_ji_xiang_de_wei_zhi[0], la_ji_xiang_de_wei_zhi[1], &bin1, SRCINVERT);
			putimage(lajidai[0], lajidai[1], &dui2, NOTSRCERASE);
			putimage(lajidai[0], lajidai[1], &dui1, SRCINVERT);//卷的位置

			putimage(p_x, p_y, 50, 50, &AC2, 50 * id, 50 * d_id, NOTSRCERASE);
			putimage(p_x, p_y, 50, 50, &AC1, 50 * id, 50 * d_id, SRCINVERT);
			if (in_ch1_hand == 9) {
				if (d_id == 1) {
					putimage(p_x + 15, p_y, &juan2, NOTSRCERASE);
					putimage(p_x + 15, p_y, &juan1, SRCINVERT);
				}
				if (d_id == 2) {
					putimage(p_x - 15, p_y, &juan2, NOTSRCERASE);
					putimage(p_x - 15, p_y, &juan1, SRCINVERT);
				}
				if (d_id == 3) {
					putimage(p_x, p_y + 15, &juan2, NOTSRCERASE);
					putimage(p_x, p_y + 15, &juan1, SRCINVERT);
				}
				if (d_id == 0) {
					putimage(p_x, p_y - 15, &juan2, NOTSRCERASE);
					putimage(p_x, p_y - 15, &juan1, SRCINVERT);
				}

			}
			if (in_ch1_hand > 0 && in_ch1_hand < 8) {
				if (d_id == 1) {
					putimage(p_x + 15, p_y, &BAg2, NOTSRCERASE);
					putimage(p_x + 15, p_y, &BAg1, SRCINVERT);
				}
				if (d_id == 2) {
					putimage(p_x - 15, p_y, &BAg2, NOTSRCERASE);
					putimage(p_x - 15, p_y, &BAg1, SRCINVERT);
				}
				if (d_id == 3) {
					putimage(p_x, p_y + 15, &BAg2, NOTSRCERASE);
					putimage(p_x, p_y + 15, &BAg1, SRCINVERT);
				}
				if (d_id == 0) {
					putimage(p_x, p_y - 15, &BAg2, NOTSRCERASE);
					putimage(p_x, p_y - 15, &BAg1, SRCINVERT);
				}

			}

			//绘制人物2图片

			putimage(p2_x, p2_y, 50, 50, &AC4, 50 * id1, 50 * d_id2, NOTSRCERASE);
			putimage(p2_x, p2_y, 50, 50, &AC3, 50 * id1, 50 * d_id2, SRCINVERT);
			if (in_ch2_hand > 0 && in_ch2_hand < 8) {
				if (d_id2 == 1) {
					putimage(p2_x + 15, p2_y, &BAg2, NOTSRCERASE);
					putimage(p2_x + 15, p2_y, &BAg1, SRCINVERT);
				}
				if (d_id2 == 2) {
					putimage(p2_x - 15, p2_y, &BAg2, NOTSRCERASE);
					putimage(p2_x - 15, p2_y, &BAg1, SRCINVERT);
				}
				if (d_id2 == 3) {
					putimage(p2_x, p2_y + 15, &BAg2, NOTSRCERASE);
					putimage(p2_x, p2_y + 15, &BAg1, SRCINVERT);
				}
				if (d_id2 == 0) {
					putimage(p2_x, p2_y - 15, &BAg2, NOTSRCERASE);
					putimage(p2_x, p2_y - 15, &BAg1, SRCINVERT);
				}

			}
			if (in_ch2_hand == 9) {
				if (d_id2 == 1) {
					putimage(p2_x + 20, p2_y, &juan2, NOTSRCERASE);
					putimage(p2_x + 20, p2_y, &juan1, SRCINVERT);
				}
				if (d_id2 == 2) {
					putimage(p2_x - 20, p2_y, &juan2, NOTSRCERASE);
					putimage(p2_x - 20, p2_y, &juan1, SRCINVERT);
				}
				if (d_id2 == 3) {
					putimage(p2_x, p2_y + 20, &juan2, NOTSRCERASE);
					putimage(p2_x, p2_y + 20, &juan1, SRCINVERT);
				}
				if (d_id2 == 0) {
					putimage(p2_x, p2_y - 20, &juan2, NOTSRCERASE);
					putimage(p2_x, p2_y - 20, &juan1, SRCINVERT);
				}

			}

			loseTime = GetTickCount() - g_BeginTime;
			_stprintf_s(timeStr, _T("time:%02d:%02d"), loseTime / 1000 / 60, loseTime / 1000 % 60);
			settextcolor(RGB(106, 0, 95));
			outtextxy((width - textwidth(timeStr)) / 2, 3, timeStr);

			Sleep(time_sleep);
			FlushBatchDraw();

		}mciSendString(TEXT("close bgm"), NULL, 0, NULL);//关闭bgm
		EndBatchDraw();




		//closegraph();

		return 0;
	}
}