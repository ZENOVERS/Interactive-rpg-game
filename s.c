#define _CRT_SECURE_NO_WARNINGS 
#define cls system("cls")
#define S(x) Sleep(x)
#define T 1600
#define MandA 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); \
				printf("소지금: %d     공격력: %d\n\n\n", money_g, power_g); \
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


char nickname_g[100];
char way_g;
int power_g = 5;
int money_g;


void CRB(void)
{
	while (getchar() != '\n');
}

void Cursor(int n) // 커서 보이기 & 숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n; //0이면 안 보이고 1이면 보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Set_Nickname()
{
	puts("닉네임을 입력해주세요: ");
	scanf("%s", nickname_g);
	cls;
}

void Tutorial_Story()
{
	puts("당신은 미지의 숲으로 보물을 찾기 위해 모험을 떠납니다.");
	S(T);
	puts("길은 총 3갈래가 있으며, a s d 로 선택이 가능합니다.");
	S(T);
	puts("탐험 도중 각종 이벤트가 발생합니다.");
	S(T);
	puts("그럼... 시작합니다.");
	S(T + 500);

	cls;
}

void Select_Way()
{
	MandA
	puts("당신의 눈 앞에 세 가지 길이 펼쳐져 있습니다.a s d로 선택해주세요.\n");
	scanf("%c", &way_g);
	cls;
}

void Monster_Way()
{
	PlaySound(TEXT("2-12.wav"), NULL, SND_ASYNC | SND_LOOP);
	MandA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	puts("몬스터가 나타났다!!\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T + 500);

	int monster_hp = ((rand() % (power_g + 3)) + (power_g - 3)); //몬스터를 이길 기준을, 캐릭터의 힘 플마3을 기준으로 랜덤 생성
	printf("이 몬스터는 공격력이 %d이상이면 이길 수 있을 것 같다.\n\n", monster_hp);
	S(T + 500);

	if (power_g >= monster_hp)
	{
		puts("몬스터를 쓰려뜨렸다.\n");
		S(T);
		printf("%d원을 입수했다.\n", monster_hp);
		money_g += monster_hp;
	}
	else
	{
		puts("몬스터가 너무 강하다. 왔던 길로 도망치자..\n");
		S(T);
	}
	S(T * 2);
	cls;
}

void Treasure_Way()
{
	MandA
	puts("터벅 터벅.\n");
	S(T);
	puts("콰당\n");
	S(T);
	puts("길을 걷다 돌부리에 걸려 넘어졌다.\n");
	S(T);
	PlaySound(TEXT("cb.wav"), NULL, SND_ASYNC | SND_LOOP);
	puts("자세히 살펴보니 땅에 상자가 박혀있다!\n");
	S(T);
	puts("끼이이이익\n");
	S(T + 500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("놀랍게도 상자 안에는 %d원이 들어 있었다!\n", power_g + 100);
	money_g += power_g + 100;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T * 2);

	cls;
}

void Trap_Way()
{
	MandA
	puts("... 왠지 이쪽 길은 묘하게 불길한 느낌이 든다.\n");
	S(T);
	PlaySound(TEXT("Trap.wav"), NULL, SND_ASYNC | SND_LOOP);
	puts("쩌저저적\n");
	S(T);
	puts("땅이 밑으로 꺼지기 시작한다. 아무래도 함정인 모양이다.\n");
	S(T);
	puts("후두두두둑. 내 지갑에서 동전들이 떨어지는 소리가 들렸다.\n");
	S(T);
	puts("도망치는데 열중한 나머지 다른 곳에 신경 쓸 겨를이 없었다.\n");
	if (money_g >= power_g + 10)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d원을 놓쳐버렸다...\n", power_g + 10);
		money_g -= power_g + 10;
		if (money_g < 0)
			money_g = 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T * 2);

	cls;
}

void Upgrade_Way()
{
	MandA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("..! %d원을 던지면 공격력을 랜덤으로 올려준다는 우물을 발견했다!\n\n", power_g + 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T + 500);

	if (money_g >= power_g + 10)
	{
		puts("우물에 돈을 던지자 성스러운 빛이 나를 감싼다.\n");
		S(1500);
		printf("공격력이 %d만큼 증가했다.", (int)(power_g / 2));
		power_g += (int)(power_g / 2);
	}
	else
	{
		puts("아쉽지만 돈이 부족하다.. 다음에 다시 오자.\n");
	}
	S(T * 2);
	cls;
}

void Nothing_Way()
{
	MandA
	puts("터벅 터벅.\n");
	S(T);
	puts("아무것도 찾을 수 없다.\n");
	S(T * 2);
	cls;
}

void Obstacle_Way()
{
	MandA
	puts("뚜벅 뚜벅.\n");
	S(T);
	puts("...? 거대한 돌덩이가 길을 가로막고있다.\n");
	S(T);
	puts("왔던길로 돌아가자.\n");
	S(T * 2);

	cls;
}

void Money_Way()
{
	MandA
	puts("..계속 반복되는 이 풍경이 이제는 지겨워지기 시작한다.\n");
	S(T);
	PlaySound(TEXT("Gang.wav"), NULL, SND_ASYNC | SND_LOOP);
	puts("툭.\n");
	S(T);
	puts("데굴데굴.\n");
	S(T);
	puts("...? 길을 걷다 무심코 무언가를 발로 차버렸다.\n");
	S(T);
	printf("..!! %d원을 주웠다.\n", power_g + 10);
	money_g += power_g + 10;
	S(T * 2);

	cls;
}

void Badmood_Way()
{
	MandA
	puts("..? 이 길은 왠지 예감이 좋지 않다. 다른 길을 선택하자.\n");
	S(T*2);

	cls;
}

void Rest_Way()
{
	MandA
	puts("저벅 저벅.\n");
	S(T);
	puts("한참을 계속 걸어도 특별히 눈에 띄는건 없다.\n");
	S(T);
	puts("갈수록 지쳐간다....\n");
	S(T * 2);

	cls;
}

void Unique_Event()
{
	MandA
	puts("..! 숲 속에서 거대한 동굴을 발견했다.\n");
	S(T);
	puts("문에 손을 대는 순간, 하늘에서 용이 모습을 드러낸다.\n");
	S(T);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	puts("난 여기를 지키는 신룡이다... 여긴 인간따위가 올 곳이 아니다.. 썩 물러가라!!\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T + 500);

	if (power_g >= 500)
	{
		puts("지금 내 공격력이라면 저 용도 거뜬할 것 같다.\n");
		S(T);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		puts("어리석은 인간이여... 어디 덤벼보아라!!\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		S(T);
		puts("날개를 펄럭이자 온 대지가 요동친다.\n");
	}
	else
	{
		puts("저 용을 이긴다면 이 곳에 들어갈 수 있겠지만, 너무 강해보인다. 나중에 실력을 더 키워서 오자.\n");
		S(T + 500);
		puts("과연.. 이곳에는 무엇이 감춰져 있는 걸까.\n");
	}
	S(T * 2);
	cls;
}


int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	system("title 대화형 RPG게임 - beta Ver");
	Cursor(0);
	srand(time(NULL));

	Set_Nickname();

	Tutorial_Story();


	for (;;)
	{
		PlaySound(TEXT("Tears of The World.wav"), NULL, SND_ASYNC | SND_LOOP);
		CRB(); // 버퍼 비우기
		Select_Way();

		int random = rand() % 135; // 0 ~ 134

		if (random <= 19)
			Monster_Way();
		else if (random < 30)
			Treasure_Way();
		else if (random <= 41)
			Trap_Way();
		else if (random <= 52)
			Upgrade_Way();
		else if (random <= 73)
			Nothing_Way();
		else if (random <= 94)
			Obstacle_Way();
		else if (random <= 105)
			Money_Way();
		else if (random <= 116)
			Badmood_Way();
		else if (random <= 128)
			Rest_Way();
		else
			Unique_Event();
	}

	/*
몬스터 등장 20프로 0 ~ 19

보물상자 발견10프로 20 ~ 30

트랩 함정, 돈 감소  10프로  31 ~ 41

공격력 상승 10프로 42 ~ 52

아무것도 없음 20프로 53 ~ 73

길 막힘 20프로 74 ~ 94

돈 주음 10프로 95 ~ 105

나쁜 예감 길 다른곳 106 ~ 116

휴식 117 ~ 128

신룡과의 전투 129 ~ 134



----브금
배경음 - 티어즈 오브 월드
몬스터 등장음 - 2-12
보물상자 발견 - 컴머스 배틀
트랩 - Trap
공격력 상승
돈 주음
휴식 - gang
	*/


	return 0;
}