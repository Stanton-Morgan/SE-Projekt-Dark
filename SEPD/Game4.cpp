#include "Game4.h"
Player player; // 玩家全局变量
Element level[B_H][B_L] =
{ {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
{wall,target,target,empty,empty,wall,wall,wall,wall,empty,wall,empty,empty,empty,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
{wall,target,target,empty,box,wall,wall,wall,wall,empty,wall,empty,box,empty,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
{wall,empty,box,wall,empty,wall,empty,empty,wall,empty,wall,empty,box,empty,wall,wall,wall,target,wall,wall,wall,wall,wall,wall},
{wall,empty,empty,box,empty,wall,box,empty,wall,empty,wall,wall,wall,empty,wall,wall,wall,target,wall,wall,wall,wall,wall,wall},
{wall,empty,empty,wall,empty,empty,empty,empty,empty,empty,empty,empty,box,empty,empty,empty,empty,target,wall,wall,wall,wall,wall,wall},
{wall,empty,wall,wall,empty,wall,role,empty,wall,empty,wall,wall,empty,empty,empty,wall,empty,empty,empty,empty,empty,empty,empty,wall},
{wall,empty,empty,empty,empty,empty,empty,empty,wall,empty,wall,wall,empty,empty,empty,wall,wall,wall,wall,wall,wall,wall,empty,wall},
{wall,empty,empty,wall,wall,wall,wall,wall,wall,empty,wall,wall,empty,empty,empty,wall,target,empty,wall,wall,wall,wall,empty,wall},
{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,target,wall,empty,empty,wall,wall,empty,wall},

{wall,empty,empty,empty,empty,wall,wall,wall,empty,empty,empty,empty,empty,wall,wall,empty,target,box,empty,empty,wall,wall,empty,wall},
{wall,empty,empty,empty,target,target,empty,wall,empty,box,empty,empty,empty,empty,empty,empty,target,box,box,target,wall,wall,empty,wall},
{wall,empty,box,box,box,empty,empty,empty,box,box,wall,wall,box,empty,wall,empty,empty,box,target,wall,wall,wall,empty,wall},
{wall,empty,empty,wall,target,target,empty,wall,empty,empty,empty,empty,empty,empty,empty,empty,empty,target,empty,empty,empty,empty,empty,wall},
{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
};
Element levelR[B_H][B_L] =
{ {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
{wall,target,target,empty,empty,wall,wall,wall,wall,empty,wall,empty,empty,empty,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
{wall,target,target,empty,box,wall,wall,wall,wall,empty,wall,empty,box,empty,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
{wall,empty,box,wall,empty,wall,empty,empty,wall,empty,wall,empty,box,empty,wall,wall,wall,target,wall,wall,wall,wall,wall,wall},
{wall,empty,empty,box,empty,wall,box,empty,wall,empty,wall,wall,wall,empty,wall,wall,wall,target,wall,wall,wall,wall,wall,wall},
{wall,empty,empty,wall,empty,empty,empty,empty,empty,empty,empty,empty,box,empty,empty,empty,empty,target,wall,wall,wall,wall,wall,wall},
{wall,empty,wall,wall,empty,wall,role,empty,wall,empty,wall,wall,empty,empty,empty,wall,empty,empty,empty,empty,empty,empty,empty,wall},
{wall,empty,empty,empty,empty,empty,empty,empty,wall,empty,wall,wall,empty,empty,empty,wall,wall,wall,wall,wall,wall,wall,empty,wall},
{wall,empty,empty,wall,wall,wall,wall,wall,wall,empty,wall,wall,empty,empty,empty,wall,target,empty,wall,wall,wall,wall,empty,wall},
{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,target,wall,empty,empty,wall,wall,empty,wall},

{wall,empty,empty,empty,empty,wall,wall,wall,empty,empty,empty,empty,empty,wall,wall,empty,target,box,empty,empty,wall,wall,empty,wall},
{wall,empty,empty,empty,target,target,empty,wall,empty,box,empty,empty,empty,empty,empty,empty,target,box,box,target,wall,wall,empty,wall},
{wall,empty,box,box,box,empty,empty,empty,box,box,wall,wall,box,empty,wall,empty,empty,box,target,wall,wall,wall,empty,wall},
{wall,empty,empty,wall,target,target,empty,wall,empty,empty,empty,empty,empty,empty,empty,empty,empty,target,empty,empty,empty,empty,empty,wall},
{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
};

int targetNum, achievedNum; // 目标位置个数、完成目标个数
int Game4flag = 1;

IMAGE Game4img[10];


void startup()  // 初始化函数
{
	//initgraph(B_L * B_SIZE, B_H * B_SIZE); // 新开一个画面
	setbkcolor(RGB(150, 150, 150)); // 灰色背景
	BeginBatchDraw(); // 开始批量绘图
	int i, j;
	targetNum = 0; // 目标个数，初始为0
	// 对二维数组遍历
	for (i = 0; i < B_H; i++)
		for (j = 0; j < B_L; j++)
		{
			if (level[i][j] == role) // 找到地图中player位置
			{
				player.i = i; // 设定player位置
				player.j = j; // 
				level[i][j] = empty; // 把地图元素变成空白empty
			}
			else if (level[i][j] == target || level[i][j] == achieved) // 如果元素是target或achieved
				targetNum++; // 目标个数+1
		}
}

void show() // 绘制函数
{
	int i, j;
	cleardevice(); // 以背景颜色清空屏幕
	// 遍历关卡二维数组数据
	for (i = 0; i < B_H; i++)
	{
		for (j = 0; j < B_L; j++)
		{
			if (level[i][j] == empty||level[i][j]==role) // empty 元素是空白区域
			{
				setfillcolor(RGB(0, 0, 1)); // 绘制黑色地面
				setlinecolor(RGB(0, 0, 1));
				fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
			}
			else if (level[i][j] == wall)  // wall 元素是墙
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[1]);
			}
			else if (level[i][j] == box) // box 元素是可移动的箱子
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[0]);
			}

			else if (level[i][j] == target) // target 元素是目标
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[4]);
			}
			else if (level[i][j] == achieved) // achieved 元素是已完成目标
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[2]);
			}
		}
	}
	//图像
	loadimage(&Game4img[0], _T(".\\images\\Game4\\C.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[1], _T(".\\images\\Game4\\W.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[2], _T(".\\images\\Game4\\L.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[3], _T(".\\images\\Game4\\down.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[4], _T(".\\images\\Game4\\T.png"), B_SIZE, B_SIZE);

	// 以下绘制玩家
	i =  player.i;
	j =  player.j;
	putimage(j * B_SIZE, i * B_SIZE, &Game4img[3]);


	if (achievedNum == targetNum) // 如完成目标个数==目标个数
	{
		setbkmode(TRANSPARENT); // 透明显示文字
		settextcolor(RGB(0, 255, 255)); // 设置字体颜色
		settextstyle(80, 0, _T("宋体")); // 设置字体大小、样式
		outtextxy(350, 200, _T("游戏胜利")); // 显示游戏胜利文字
		
		
	}
	FlushBatchDraw(); // 开始批量绘制
}

void update()  // 每帧更新运行
{
	if (_kbhit() && (achievedNum < targetNum))  // 如果按键，并且游戏没有胜利
	{
		char input = _getch(); // 获取按键
		mciSendString(TEXT("seek move to start"), NULL, 0, NULL);
		mciSendString(TEXT("play move"), NULL, 0, NULL);
		if (input == 'a' || input == 's' || input == 'd' || input == 'w'||input=='r'||input=='y'||input==27) // 如果是有效按键
		{
			int goal_i = player.i; // 移动的目标位置
			int goal_j = player.j;
			int goalNext_i = goal_i; // 目标位置再向前的一个位置
			int goalNext_j = goal_j;
			// 根据用户的不同按键输入，获得目标位置、再向前的一个位置
			if (input == 'a') // 向左
			{
				goal_j = player.j - 1; // 目标位置在玩家位置的左边
				goalNext_j = goal_j - 1; // 目标的下一个位置，在其再左边
			}
			else if (input == 'd') // 向右
			{
				goal_j = player.j + 1; // 目标位置在玩家位置的右边 
				goalNext_j = goal_j + 1; // 目标的下一个位置，在其再右边
			}
			else if (input == 's') // 向下
			{
				goal_i = player.i + 1; // 目标位置在玩家位置的下边 
				goalNext_i = goal_i + 1; // 目标的下一个位置，在其再下边 
			}
			else if (input == 'w') // 向上
			{
				goal_i = player.i - 1; // 目标位置在玩家位置的上边 
				goalNext_i = goal_i - 1; // 目标的下一个位置，在其再上边 
			}
			else if (input == 'y')
			{
				for (int m = 0; m < B_H; m++)
				{
					for (int n = 0; n < B_L; n++)
					{
						level[m][n] = levelR[m][n];
						
					}
				}
				player.i = 6;
				player.j = 6;
				return;
				
			}
			else if (input == 'r')
			{
				
					setbkmode(TRANSPARENT); // 透明显示文字
					settextcolor(RGB(0, 255, 255)); // 设置字体颜色
					settextstyle(60, 0, _T("宋体")); // 设置字体大小、样式
					outtextxy(350, 200, _T("重新开始？")); // 显示重开？
					outtextxy(300, 300, _T("是：y   否：n")); // 显示重开？
					FlushBatchDraw(); // 开始批量绘制
					Sleep(700);
			}
			else if (input == 27)
			{
				Game4flag = 0;
			}

			// 根据不同地图元素的情况，判断如何移动角色和更新地图元素	
			if (level[goal_i][goal_j] == empty || level[goal_i][goal_j] == target || level[goal_i][goal_j] == role)
			{	// 如果目标位置是empty，或者target
				player.i = goal_i; // 玩家移动到目标位置
				player.j = goal_j;
				return;
			}
			else if (level[goal_i][goal_j] == box && ((level[goalNext_i][goalNext_j] == empty) || (level[goalNext_i][goalNext_j] == role)))
			{	// 如果目标位置是box，再前面一个是empty
				player.i = goal_i; // 玩家移动到目标位置
				player.j = goal_j;
				level[goal_i][goal_j] = empty;  // 目标位置变成empty
				level[goalNext_i][goalNext_j] = box;	 // 再前面变成box
			}
			else if (level[goal_i][goal_j] == box && level[goalNext_i][goalNext_j] == target)
			{	// 如果目标位置是box，再前面一个是target
				player.i = goal_i; // 玩家移动到目标位置
				player.j = goal_j;
				level[goal_i][goal_j] = empty;  // 目标位置变成empty 
				level[goalNext_i][goalNext_j] = achieved;	// 再前面变成achieved
			}
			else if (level[goal_i][goal_j] == achieved && (level[goalNext_i][goalNext_j] == empty))
			{	// 如果目标位置是achieved，再前面一个是empty
				player.i = goal_i; // 玩家移动到目标位置
				player.j = goal_j;
				level[goal_i][goal_j] = target;  // 目标位置变成target 
				level[goalNext_i][goalNext_j] = box; // 再前面变成box 	
			}
			else if (level[goal_i][goal_j] == achieved && level[goalNext_i][goalNext_j] == target)
			{	// 如果目标位置是achieved，再前面一个是target
				player.i = goal_i; // 玩家移动到目标位置
				player.j = goal_j;
				level[goal_i][goal_j] = target;  // 目标位置变成target  
				level[goalNext_i][goalNext_j] = achieved; // 再前面变成achieved  	
			}
			else // 其他情况都推不动
				return; // 不做任何处理，函数直接返回
		}
		achievedNum = 0; // 完成目标个数，初始为0
		int i, j;
		for (i = 0; i < B_H; i++) // 对二维数组遍历
			for (j = 0; j < B_L; j++) // 
				if (level[i][j] == achieved) // 如果元素是achieved
					achievedNum++; // 完成目标个数+1
	}
}

void G4Music() {

	mciSendString(TEXT("open Game4BGM.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);//打开报警音
	mciSendString(TEXT("open Game4move.mp3 alias move"), NULL, 0, NULL);
}
int RunGame4() // 主函数
{
	startup();  // 初始化
	G4Music();
	while (1)  // 游戏主循环
	{
		show();		// 绘制
		
		if (achievedNum == targetNum) 
		{
			victory();
			system("pause");//显示游戏胜利，之后结束程序
			mciSendString(TEXT("close bgm"), NULL, 0, NULL);//关闭bgm
			EndBatchDraw();
			return 0;
		}
		if (Game4flag == 0) {
			mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
			EndBatchDraw();
			return 0;
		}; //按esc跳关
		update();   // 更新
	}
	return 0;
}
