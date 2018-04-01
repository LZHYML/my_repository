#include <stdio.h>		//包含printf()
#include <windows.h>	//包含Sleep()
#include <stdlib.h>		//包含system()、COORD、HANDLE
#include <time.h>		//包含time()

void WelcomeToGame();
void Pos();
void CreatMap();
void CreatSnake();
void RandomFood();
void OperationHints();
void ScoreHints();
void Control();
void SnakeMove();
void FailCondition();
void GameOver();

#define U 1
#define D 2
#define L 3
#define R 4

typedef struct SnakeType
{
	int x;
	int y;
	struct SnakeType *next;
}SNAKE;

int direction, sleeptime = 200, gameover = 0;
SNAKE *head, *tail, *food;
int score = 0, add = 10, maxscore = 0;

void main()
{
	while(1)
	{
		WelcomeToGame();	//游戏开始界面

		CreatMap();		//创建地图
		CreatSnake();	//初始化蛇
		RandomFood();	//随机出现食物
		OperationHints();	//操作提示
		while(1)	//贪吃蛇运行
		{
			ScoreHints();	//得分提示
			Control();		//键盘控制游戏进行
			SnakeMove();	//蛇的移动
			FailCondition();	//失败条件
			if(gameover)		//游戏是否结束
				break;
		}
		GameOver();
	}
}

void WelcomeToGame()	//【游戏开始界面】
{
	system("mode con cols=100 lines=30");
	Pos(40, 12);
	printf("欢迎来到贪吃蛇游戏！");
	Pos(40, 25);
	system("pause");
	Sleep(300);
	system("cls");
}

void Pos(int x, int y)	//【光标坐标】
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void CreatMap()	//【创建地图】
{
	int i;

	for(i = 0; i < 58; i+=2)
	{
		Pos(i, 0);
		printf("█");
		Pos(i, 26);
		printf("█");
	}
	for(i = 1; i < 26; i++)
	{
		Pos(0, i);
		printf("█");
		Pos(56, i);
		printf("█");
	}
//	system("pause");
}

void CreatSnake()	//【初始化蛇】
{
	int i;
	
	tail = (SNAKE*)malloc(sizeof(SNAKE));
	tail->x = 24;
	tail->y = 5;
	tail->next = NULL;
	for(i = 0; i < 4; i++)
	{
		head = (SNAKE*)malloc(sizeof(SNAKE));
		head->x = 24 + 2*i;
		head->y = 5;
		head->next = tail;
		tail = head;
	}
	Pos(tail->x, tail->y);
	printf("⊙");
	tail = tail->next;
	while(tail != NULL)
	{
		Pos(tail->x, tail->y);
		printf("●");
		tail = tail->next;
	}
	direction = R;
}

void RandomFood()	//【随机食物】
{
	SNAKE *rfood;
	
	rfood = (SNAKE*)malloc(sizeof(SNAKE));
loop:
	srand(time(NULL));
	rfood->x = rand()%52 + 2;
	while(rfood->x%2 != 0)
		rfood->x = rand()%52 + 2;
	rfood->y = rand()%25 + 1;
	tail = head;
	while(tail != NULL)
	{
		if(tail->x==rfood->x && tail->y==rfood->y)
			goto loop;
		tail = tail->next;
	}
	food = rfood;
	Pos(food->x, food->y);
	printf("◎");
}

void OperationHints()	//【操作提示】
{
	Pos(64, 16);
	printf("↑ ↓ ← → 控制蛇前进的方向");
	Pos(64, 18);
	printf("F1:加速		F2:减速");
	Pos(64, 20);
	printf("SPACE:暂停	ESC:退出游戏");
}

void ScoreHints()	//【得分提示】
{
	Pos(64, 10);
	printf("得分：%d分", score);
	Pos(64, 11);
	printf("每个食物：%d分", add);
	Pos(64, 12);
	printf("最高分：%d分", maxscore);
}

void Control()	//【键盘控制游戏进程】
{
	if(GetAsyncKeyState(VK_UP) && direction!=D)
		direction = U;
	else if(GetAsyncKeyState(VK_DOWN) && direction!=U)
		direction = D;
	else if(GetAsyncKeyState(VK_LEFT) && direction!=R)
		direction = L;
	else if(GetAsyncKeyState(VK_RIGHT) && direction!=L)
		direction = R;
	else if(GetAsyncKeyState(VK_F1))
	{
		if(sleeptime >= 50)
		{
			sleeptime -= 30;
			add += 2;
		}
	}
	else if(GetAsyncKeyState(VK_F2))
	{
		if(sleeptime < 350)
		{
			sleeptime += 30;
			add -= 2;
		}
	}
	else if(GetAsyncKeyState(VK_SPACE))
	{
		while(1)
		{
			Sleep(300);
			if(GetAsyncKeyState(VK_SPACE))
				break;
		}
	}
	else if(GetAsyncKeyState(VK_ESCAPE))
		gameover = 3;
}

void SnakeMove()	//【蛇的移动】
{
	SNAKE *newhead;
	
	Sleep(sleeptime);
	newhead = (SNAKE*)malloc(sizeof(SNAKE));
	switch(direction)
	{
	case U:
		newhead->x = head->x;
		newhead->y = head->y - 1;
		break;
	case D:
		newhead->x = head->x;
		newhead->y = head->y + 1;
		break;
	case L:
		newhead->x = head->x - 2;
		newhead->y = head->y;
		break;
	case R:
		newhead->x = head->x + 2;
		newhead->y = head->y;
		break;
	}
	newhead->next = head;
	head = newhead;
	tail = head;
	Pos(tail->x, tail->y);
	printf("⊙");
	tail = tail->next;
	if(newhead->x==food->x && newhead->y==food->y)
	{
		while(tail != NULL)
		{
			Pos(tail->x, tail->y);
			printf("●");
			tail = tail->next;
		}
		score += add;
		RandomFood();
	}
	else
	{
		while(tail->next->next != NULL)
		{
			Pos(tail->x, tail->y);
			printf("●");
			tail = tail->next;
		}
		Pos(tail->x, tail->y);
		printf("●");
		Pos(tail->next->x, tail->next->y);
		printf("　");
		free(tail->next);
		tail->next = NULL;
	}
}

void FailCondition()	//【是否失败】
{
	if(head->x==0 || head->x==56 || head->y==0 || head->y==26)
		gameover = 1;	//撞墙
	tail = head->next;
	while(tail->next != NULL)
	{
		if(tail->x==head->x && tail->y==head->y)
		{
			gameover = 2;
			break;
		}
		else
			tail = tail->next;
	}
}

void GameOver()		//游戏结束界面
{
	system("cls");
	Pos(24, 12);
	switch(gameover)
	{
	case 1:
		printf("对不起，您撞到了墙，游戏结束！");
		break;
	case 2:
		printf("对不起，您咬到了自己，游戏结束！");
		break;
	case 3:
		printf("您退出了游戏");
		break;
	}
	Pos(24, 13);
	if(maxscore < score)
	{
		maxscore = score;
		printf("恭喜您打破了记录并成为最高分！");
	}
	Pos(24, 14);
	printf("您的得分是：%d分", score);
	gameover = 0;
	score = 0;
	Pos(24, 16);
	system("pause");
}
