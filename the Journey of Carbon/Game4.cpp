#include "Game4.h"
Player player; // ���ȫ�ֱ���
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

int targetNum, achievedNum; // Ŀ��λ�ø��������Ŀ�����
int Game4flag = 1;

IMAGE Game4img[10];


void startup()  // ��ʼ������
{
	//initgraph(B_L * B_SIZE, B_H * B_SIZE); // �¿�һ������
	setbkcolor(RGB(150, 150, 150)); // ��ɫ����
	BeginBatchDraw(); // ��ʼ������ͼ
	int i, j;
	targetNum = 0; // Ŀ���������ʼΪ0
	// �Զ�ά�������
	for (i = 0; i < B_H; i++)
		for (j = 0; j < B_L; j++)
		{
			if (level[i][j] == role) // �ҵ���ͼ��playerλ��
			{
				player.i = i; // �趨playerλ��
				player.j = j; // 
				level[i][j] = empty; // �ѵ�ͼԪ�ر�ɿհ�empty
			}
			else if (level[i][j] == target || level[i][j] == achieved) // ���Ԫ����target��achieved
				targetNum++; // Ŀ�����+1
		}
}

void show() // ���ƺ���
{
	int i, j;
	cleardevice(); // �Ա�����ɫ�����Ļ
	// �����ؿ���ά��������
	for (i = 0; i < B_H; i++)
	{
		for (j = 0; j < B_L; j++)
		{
			if (level[i][j] == empty||level[i][j]==role) // empty Ԫ���ǿհ�����
			{
				setfillcolor(RGB(0, 0, 1)); // ���ƺ�ɫ����
				setlinecolor(RGB(0, 0, 1));
				fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
			}
			else if (level[i][j] == wall)  // wall Ԫ����ǽ
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[1]);
			}
			else if (level[i][j] == box) // box Ԫ���ǿ��ƶ�������
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[0]);
			}

			else if (level[i][j] == target) // target Ԫ����Ŀ��
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[4]);
			}
			else if (level[i][j] == achieved) // achieved Ԫ���������Ŀ��
			{
				putimage(j * B_SIZE, i * B_SIZE, &Game4img[2]);
			}
		}
	}
	//ͼ��
	loadimage(&Game4img[0], _T(".\\images\\Game4\\C.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[1], _T(".\\images\\Game4\\W.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[2], _T(".\\images\\Game4\\L.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[3], _T(".\\images\\Game4\\down.png"), B_SIZE, B_SIZE);
	loadimage(&Game4img[4], _T(".\\images\\Game4\\T.png"), B_SIZE, B_SIZE);

	// ���»������
	i =  player.i;
	j =  player.j;
	putimage(j * B_SIZE, i * B_SIZE, &Game4img[3]);


	if (achievedNum == targetNum) // �����Ŀ�����==Ŀ�����
	{
		setbkmode(TRANSPARENT); // ͸����ʾ����
		settextcolor(RGB(0, 255, 255)); // ����������ɫ
		settextstyle(80, 0, _T("����")); // ���������С����ʽ
		outtextxy(350, 200, _T("��Ϸʤ��")); // ��ʾ��Ϸʤ������
		
		
	}
	FlushBatchDraw(); // ��ʼ��������
}

void update()  // ÿ֡��������
{
	if (_kbhit() && (achievedNum < targetNum))  // ���������������Ϸû��ʤ��
	{
		char input = _getch(); // ��ȡ����
		mciSendString(TEXT("seek move to start"), NULL, 0, NULL);
		mciSendString(TEXT("play move"), NULL, 0, NULL);
		if (input == 'a' || input == 's' || input == 'd' || input == 'w'||input=='r'||input=='y'||input==27) // �������Ч����
		{
			int goal_i = player.i; // �ƶ���Ŀ��λ��
			int goal_j = player.j;
			int goalNext_i = goal_i; // Ŀ��λ������ǰ��һ��λ��
			int goalNext_j = goal_j;
			// �����û��Ĳ�ͬ�������룬���Ŀ��λ�á�����ǰ��һ��λ��
			if (input == 'a') // ����
			{
				goal_j = player.j - 1; // Ŀ��λ�������λ�õ����
				goalNext_j = goal_j - 1; // Ŀ�����һ��λ�ã����������
			}
			else if (input == 'd') // ����
			{
				goal_j = player.j + 1; // Ŀ��λ�������λ�õ��ұ� 
				goalNext_j = goal_j + 1; // Ŀ�����һ��λ�ã��������ұ�
			}
			else if (input == 's') // ����
			{
				goal_i = player.i + 1; // Ŀ��λ�������λ�õ��±� 
				goalNext_i = goal_i + 1; // Ŀ�����һ��λ�ã��������±� 
			}
			else if (input == 'w') // ����
			{
				goal_i = player.i - 1; // Ŀ��λ�������λ�õ��ϱ� 
				goalNext_i = goal_i - 1; // Ŀ�����һ��λ�ã��������ϱ� 
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
				
					setbkmode(TRANSPARENT); // ͸����ʾ����
					settextcolor(RGB(0, 255, 255)); // ����������ɫ
					settextstyle(60, 0, _T("����")); // ���������С����ʽ
					outtextxy(350, 200, _T("���¿�ʼ��")); // ��ʾ�ؿ���
					outtextxy(300, 300, _T("�ǣ�y   ��n")); // ��ʾ�ؿ���
					FlushBatchDraw(); // ��ʼ��������
					Sleep(700);
			}
			else if (input == 27)
			{
				Game4flag = 0;
			}

			// ���ݲ�ͬ��ͼԪ�ص�������ж�����ƶ���ɫ�͸��µ�ͼԪ��	
			if (level[goal_i][goal_j] == empty || level[goal_i][goal_j] == target || level[goal_i][goal_j] == role)
			{	// ���Ŀ��λ����empty������target
				player.i = goal_i; // ����ƶ���Ŀ��λ��
				player.j = goal_j;
				return;
			}
			else if (level[goal_i][goal_j] == box && ((level[goalNext_i][goalNext_j] == empty) || (level[goalNext_i][goalNext_j] == role)))
			{	// ���Ŀ��λ����box����ǰ��һ����empty
				player.i = goal_i; // ����ƶ���Ŀ��λ��
				player.j = goal_j;
				level[goal_i][goal_j] = empty;  // Ŀ��λ�ñ��empty
				level[goalNext_i][goalNext_j] = box;	 // ��ǰ����box
			}
			else if (level[goal_i][goal_j] == box && level[goalNext_i][goalNext_j] == target)
			{	// ���Ŀ��λ����box����ǰ��һ����target
				player.i = goal_i; // ����ƶ���Ŀ��λ��
				player.j = goal_j;
				level[goal_i][goal_j] = empty;  // Ŀ��λ�ñ��empty 
				level[goalNext_i][goalNext_j] = achieved;	// ��ǰ����achieved
			}
			else if (level[goal_i][goal_j] == achieved && (level[goalNext_i][goalNext_j] == empty))
			{	// ���Ŀ��λ����achieved����ǰ��һ����empty
				player.i = goal_i; // ����ƶ���Ŀ��λ��
				player.j = goal_j;
				level[goal_i][goal_j] = target;  // Ŀ��λ�ñ��target 
				level[goalNext_i][goalNext_j] = box; // ��ǰ����box 	
			}
			else if (level[goal_i][goal_j] == achieved && level[goalNext_i][goalNext_j] == target)
			{	// ���Ŀ��λ����achieved����ǰ��һ����target
				player.i = goal_i; // ����ƶ���Ŀ��λ��
				player.j = goal_j;
				level[goal_i][goal_j] = target;  // Ŀ��λ�ñ��target  
				level[goalNext_i][goalNext_j] = achieved; // ��ǰ����achieved  	
			}
			else // ����������Ʋ���
				return; // �����κδ�������ֱ�ӷ���
		}
		achievedNum = 0; // ���Ŀ���������ʼΪ0
		int i, j;
		for (i = 0; i < B_H; i++) // �Զ�ά�������
			for (j = 0; j < B_L; j++) // 
				if (level[i][j] == achieved) // ���Ԫ����achieved
					achievedNum++; // ���Ŀ�����+1
	}
}

void G4Music() {

	mciSendString(TEXT("open Game4BGM.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);//�򿪱�����
	mciSendString(TEXT("open Game4move.mp3 alias move"), NULL, 0, NULL);
}
int RunGame4() // ������
{
	startup();  // ��ʼ��
	G4Music();
	while (1)  // ��Ϸ��ѭ��
	{
		show();		// ����
		
		if (achievedNum == targetNum) 
		{
			victory();
			system("pause");//��ʾ��Ϸʤ����֮���������
			mciSendString(TEXT("close bgm"), NULL, 0, NULL);//�ر�bgm
			EndBatchDraw();
			return 0;
		}
		if (Game4flag == 0) {
			mciSendString(TEXT("close mysong"), NULL, 0, NULL);//�رձ�����
			EndBatchDraw();
			return 0;
		}; //��esc����
		update();   // ����
	}
	return 0;
}
