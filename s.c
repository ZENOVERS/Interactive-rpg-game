#define _CRT_SECURE_NO_WARNINGS 
#define cls system("cls")
#define S(x) Sleep(x)
#define T 1600
#define MandA 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); \
				printf("������: %d     ���ݷ�: %d\n\n\n", money_g, power_g); \
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

void Cursor(int n) // Ŀ�� ���̱� & �����
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n; //0�̸� �� ���̰� 1�̸� ����
	ConsoleCursor.dwSize = 1; // Ŀ�� ������

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Set_Nickname()
{
	puts("�г����� �Է����ּ���: ");
	scanf("%s", nickname_g);
	cls;
}

void Tutorial_Story()
{
	puts("����� ������ ������ ������ ã�� ���� ������ �����ϴ�.");
	S(T);
	puts("���� �� 3������ ������, a s d �� ������ �����մϴ�.");
	S(T);
	puts("Ž�� ���� ���� �̺�Ʈ�� �߻��մϴ�.");
	S(T);
	puts("�׷�... �����մϴ�.");
	S(T + 500);

	cls;
}

void Select_Way()
{
	MandA
	puts("����� �� �տ� �� ���� ���� ������ �ֽ��ϴ�.a s d�� �������ּ���.\n");
	scanf("%c", &way_g);
	cls;
}

void Monster_Way()
{
	PlaySound(TEXT("2-12.wav"), NULL, SND_ASYNC | SND_LOOP);
	MandA
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	puts("���Ͱ� ��Ÿ����!!\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T + 500);

	int monster_hp = ((rand() % (power_g + 3)) + (power_g - 3)); //���͸� �̱� ������, ĳ������ �� �ø�3�� �������� ���� ����
	printf("�� ���ʹ� ���ݷ��� %d�̻��̸� �̱� �� ���� �� ����.\n\n", monster_hp);
	S(T + 500);

	if (power_g >= monster_hp)
	{
		puts("���͸� �����߷ȴ�.\n");
		S(T);
		printf("%d���� �Լ��ߴ�.\n", monster_hp);
		money_g += monster_hp;
	}
	else
	{
		puts("���Ͱ� �ʹ� ���ϴ�. �Դ� ��� ����ġ��..\n");
		S(T);
	}
	S(T * 2);
	cls;
}

void Treasure_Way()
{
	MandA
	puts("�͹� �͹�.\n");
	S(T);
	puts("���\n");
	S(T);
	puts("���� �ȴ� ���θ��� �ɷ� �Ѿ�����.\n");
	S(T);
	PlaySound(TEXT("cb.wav"), NULL, SND_ASYNC | SND_LOOP);
	puts("�ڼ��� ���캸�� ���� ���ڰ� �����ִ�!\n");
	S(T);
	puts("����������\n");
	S(T + 500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("����Ե� ���� �ȿ��� %d���� ��� �־���!\n", power_g + 100);
	money_g += power_g + 100;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T * 2);

	cls;
}

void Trap_Way()
{
	MandA
	puts("... ���� ���� ���� ���ϰ� �ұ��� ������ ���.\n");
	S(T);
	PlaySound(TEXT("Trap.wav"), NULL, SND_ASYNC | SND_LOOP);
	puts("¼������\n");
	S(T);
	puts("���� ������ ������ �����Ѵ�. �ƹ����� ������ ����̴�.\n");
	S(T);
	puts("�ĵεεε�. �� �������� �������� �������� �Ҹ��� ��ȴ�.\n");
	S(T);
	puts("����ġ�µ� ������ ������ �ٸ� ���� �Ű� �� �ܸ��� ������.\n");
	if (money_g >= power_g + 10)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d���� ���Ĺ��ȴ�...\n", power_g + 10);
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
	printf("..! %d���� ������ ���ݷ��� �������� �÷��شٴ� �칰�� �߰��ߴ�!\n\n", power_g + 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T + 500);

	if (money_g >= power_g + 10)
	{
		puts("�칰�� ���� ������ �������� ���� ���� ���Ѵ�.\n");
		S(1500);
		printf("���ݷ��� %d��ŭ �����ߴ�.", (int)(power_g / 2));
		power_g += (int)(power_g / 2);
	}
	else
	{
		puts("�ƽ����� ���� �����ϴ�.. ������ �ٽ� ����.\n");
	}
	S(T * 2);
	cls;
}

void Nothing_Way()
{
	MandA
	puts("�͹� �͹�.\n");
	S(T);
	puts("�ƹ��͵� ã�� �� ����.\n");
	S(T * 2);
	cls;
}

void Obstacle_Way()
{
	MandA
	puts("�ѹ� �ѹ�.\n");
	S(T);
	puts("...? �Ŵ��� �����̰� ���� ���θ����ִ�.\n");
	S(T);
	puts("�Դ���� ���ư���.\n");
	S(T * 2);

	cls;
}

void Money_Way()
{
	MandA
	puts("..��� �ݺ��Ǵ� �� ǳ���� ������ ���ܿ����� �����Ѵ�.\n");
	S(T);
	PlaySound(TEXT("Gang.wav"), NULL, SND_ASYNC | SND_LOOP);
	puts("��.\n");
	S(T);
	puts("��������.\n");
	S(T);
	puts("...? ���� �ȴ� ������ ���𰡸� �߷� �����ȴ�.\n");
	S(T);
	printf("..!! %d���� �ֿ���.\n", power_g + 10);
	money_g += power_g + 10;
	S(T * 2);

	cls;
}

void Badmood_Way()
{
	MandA
	puts("..? �� ���� ���� ������ ���� �ʴ�. �ٸ� ���� ��������.\n");
	S(T*2);

	cls;
}

void Rest_Way()
{
	MandA
	puts("���� ����.\n");
	S(T);
	puts("������ ��� �ɾ Ư���� ���� ��°� ����.\n");
	S(T);
	puts("������ ���İ���....\n");
	S(T * 2);

	cls;
}

void Unique_Event()
{
	MandA
	puts("..! �� �ӿ��� �Ŵ��� ������ �߰��ߴ�.\n");
	S(T);
	puts("���� ���� ��� ����, �ϴÿ��� ���� ����� �巯����.\n");
	S(T);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	puts("�� ���⸦ ��Ű�� �ŷ��̴�... ���� �ΰ������� �� ���� �ƴϴ�.. �� ��������!!\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	S(T + 500);

	if (power_g >= 500)
	{
		puts("���� �� ���ݷ��̶�� �� �뵵 �Ŷ��� �� ����.\n");
		S(T);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		puts("����� �ΰ��̿�... ��� �������ƶ�!!\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		S(T);
		puts("������ �޷����� �� ������ �䵿ģ��.\n");
	}
	else
	{
		puts("�� ���� �̱�ٸ� �� ���� �� �� �ְ�����, �ʹ� ���غ��δ�. ���߿� �Ƿ��� �� Ű���� ����.\n");
		S(T + 500);
		puts("����.. �̰����� ������ ������ �ִ� �ɱ�.\n");
	}
	S(T * 2);
	cls;
}


int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	system("title ��ȭ�� RPG���� - beta Ver");
	Cursor(0);
	srand(time(NULL));

	Set_Nickname();

	Tutorial_Story();


	for (;;)
	{
		PlaySound(TEXT("Tears of The World.wav"), NULL, SND_ASYNC | SND_LOOP);
		CRB(); // ���� ����
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
���� ���� 20���� 0 ~ 19

�������� �߰�10���� 20 ~ 30

Ʈ�� ����, �� ����  10����  31 ~ 41

���ݷ� ��� 10���� 42 ~ 52

�ƹ��͵� ���� 20���� 53 ~ 73

�� ���� 20���� 74 ~ 94

�� ���� 10���� 95 ~ 105

���� ���� �� �ٸ��� 106 ~ 116

�޽� 117 ~ 128

�ŷ���� ���� 129 ~ 134



----���
����� - Ƽ���� ���� ����
���� ������ - 2-12
�������� �߰� - �ĸӽ� ��Ʋ
Ʈ�� - Trap
���ݷ� ���
�� ����
�޽� - gang
	*/


	return 0;
}