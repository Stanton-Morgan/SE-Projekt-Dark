#include "FrameWork.h"
IMAGE door_l, door_r, score1[10], score2[10];
void initiateNumber() {
	loadimage(&score1[0], _T(".\\images\\numbers\\0_1.jpg"));
	loadimage(&score2[0], _T(".\\images\\numbers\\0_2.jpg"));
	loadimage(&score1[1], _T(".\\images\\numbers\\1_1.jpg"));
	loadimage(&score2[1], _T(".\\images\\numbers\\1_2.jpg"));
	loadimage(&score1[2], _T(".\\images\\numbers\\2_1.jpg"));
	loadimage(&score2[2], _T(".\\images\\numbers\\2_2.jpg"));
	loadimage(&score1[3], _T(".\\images\\numbers\\3_1.jpg"));
	loadimage(&score2[3], _T(".\\images\\numbers\\3_2.jpg"));
	loadimage(&score1[4], _T(".\\images\\numbers\\4_1.jpg"));
	loadimage(&score2[4], _T(".\\images\\numbers\\4_2.jpg"));
	loadimage(&score1[5], _T(".\\images\\numbers\\5_1.jpg"));
	loadimage(&score2[5], _T(".\\images\\numbers\\5_2.jpg"));
	loadimage(&score1[6], _T(".\\images\\numbers\\6_1.jpg"));
	loadimage(&score2[6], _T(".\\images\\numbers\\6_2.jpg"));
	loadimage(&score1[7], _T(".\\images\\numbers\\7_1.jpg"));
	loadimage(&score2[7], _T(".\\images\\numbers\\7_2.jpg"));
	loadimage(&score1[8], _T(".\\images\\numbers\\8_1.jpg"));
	loadimage(&score2[8], _T(".\\images\\numbers\\8_2.jpg"));
	loadimage(&score1[9], _T(".\\images\\numbers\\9_1.jpg"));
	loadimage(&score2[9], _T(".\\images\\numbers\\9_2.jpg"));
}
void scorePrint(int score)
{
	IMAGE* fen1[6], * fen2[6];
	int he, weishu = 1, i = 0, sdsf = score;
	if (sdsf == 0)
	{
		putimage(WIN_WIDTH - 50, 50, &score1[0], NOTSRCERASE);
		putimage(WIN_WIDTH - 50, 50, &score2[0], SRCINVERT);

	}
	while (sdsf > 0)
	{
		he = sdsf % 10;
		fen1[i] = &score1[he];
		fen2[i] = &score2[he];
		putimage(WIN_WIDTH - 50 * weishu, 50, fen1[i], NOTSRCERASE);
		putimage(WIN_WIDTH - 50 * weishu, 50, fen2[i], SRCINVERT);
		sdsf /= 10;
		i++;
		weishu++;
	}
}

//界面切换动画
void Door()
{
	loadimage(&door_l, _T(".\\images\\doorl.png"), WIN_WIDTH / 2, WIN_HEIGHT);
	loadimage(&door_r, _T(".\\images\\doorr.png"), WIN_WIDTH / 2, WIN_HEIGHT);
	for (int i = WIN_WIDTH / 2; i <= WIN_WIDTH; i += 2)
	{
		cleardevice();
		putimage(i, 0, &door_r);
		putimage(WIN_WIDTH / 2 - i, 0, &door_l);
		FlushBatchDraw();
		Sleep(1);
	}
	EndBatchDraw();
}

//展示每一关的游戏规则 0 1 2 3 4 5
void showPicture(int i) {
	IMAGE pic;
	char imagename[50];
	sprintf_s(imagename, "./images/%d.png", i);
	loadimage(&pic, imagename, WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &pic);
	system("pause");
	return;
}

void victory() {
	IMAGE p1, p2;
	loadimage(&p1, _T("./images/victory_1.png"), WIN_WIDTH / 2, WIN_HEIGHT / 2);
	loadimage(&p2, _T("./images/victory_2.png"), WIN_WIDTH / 2, WIN_HEIGHT / 2);
	putimage(WIN_WIDTH / 4, WIN_HEIGHT / 4, &p1, SRCAND);
	putimage(WIN_WIDTH / 4, WIN_HEIGHT / 4, &p2, SRCPAINT);
}

void defeat() {
	IMAGE p1, p2;
	loadimage(&p1, _T("./images/defeat_1.png"), WIN_WIDTH / 2, WIN_HEIGHT / 2);
	loadimage(&p2, _T("./images/defeat_2.png"), WIN_WIDTH / 2, WIN_HEIGHT / 2);
	putimage(WIN_WIDTH / 4, WIN_HEIGHT / 4, &p1, SRCAND);
	putimage(WIN_WIDTH / 4, WIN_HEIGHT / 4, &p2, SRCPAINT);
}
