#include"FrameWork.h"
#include "Game1.h"
#include "Game2.h"
#include "Game3.h"
#include "Game4.h"
IMAGE cover;
int main() {
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	loadimage(&cover, _T("./images/cover.png"), WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &cover);
	Sleep(3000);
	showPicture(0);
	showPicture(1);
	Door();
	showPicture(2);
	showPicture(3);
	showPicture(16);
	Door();
	RunGame1();
	showPicture(4);
	showPicture(5);
	showPicture(6);
	showPicture(7);
	Door();
	RunGame2();
	showPicture(8);
	showPicture(9);
	showPicture(10);
	Door();
	RunGame3();
	showPicture(11);
	showPicture(12);
	showPicture(13);
	showPicture(14);
	Door();
	RunGame4();
	showPicture(15);
}