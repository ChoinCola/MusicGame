#include "head.h"

auto UPDATE() ->	bool;
auto SETUP() ->		void;
auto START() ->		void;
auto RENDER() ->	void;
auto gotoxy(int x, int y) -> void;

map Game_bord(WIDTH,LENGTH,10);
std::vector<MusicP> musicP;
User user;
int count;
int main()
{
	SETUP();
	START();
	while (UPDATE()) {
		RENDER();
	}
	
	return 0;
}

auto UPDATE() ->	bool
{
	MusicP def; 

	def.Set_x(Math::Random(Q, R)).Set_y(0);

	musicP.push_back(def);
	std::vector<std::vector<MusicP>::iterator> to_remove;
	for (auto i = musicP.begin(); i < musicP.end(); i++) {

		i->Set_y(i->Get_y() + 1);// ��ǥ ĭ �Ѱ��� ����

		if (i->Get_y() >= LENGTH - 1) {  // ���� �Ѿ�� ������ ����
			to_remove.push_back(i);
			Game_bord.Down_life();
		}
		else if (i->Get_y() >= LENGTH - 3 && i->Get_x() == user.INPUT()) { // ���߸� �׳� ����
			to_remove.push_back(i);
			Game_bord.UP_life();
			count+=100;
		}
	}

	for (auto it = to_remove.rbegin(); it != to_remove.rend(); it++) {
		musicP.erase(*it);
	}

		if (Game_bord.Get_life() <= 0) { // ������ �ٴ޸� ���
			system("cls");
			printf("���� : %d", count);
			return 0;
		}
		Sleep(200);
		return 1;
}

auto SETUP() ->		void
{
	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		ConsoleCursor.bVisible = 0; // Ŀ�� �� ���ش�.
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor); // �������� �����Ѵ�.
	}
}

auto START() ->		void
{
	system("title Music Game"); // �ܼ�â�� Ÿ��Ʋ�� ����.
	system("mode con:cols=60 lines=200");// �ܼ�â�� ũ�⸦ �����Ѵ�.

	std::cout << "######### ������� #########" << std::endl;

	system("pause"); // �ٸ� Ű�� ������ �����ϰ� ����.
	system("cls");
}

auto RENDER() ->	void
{
	system("cls");
	Game_bord.Print_Map();
	printf("\n���� : %d", count);
	for (auto i = musicP.begin(); i < musicP.end(); i++) {
		gotoxy(i->Get_x(), i->Get_y());
		std::cout << "��";
	}
	std::cout << std::endl;
	
}

auto gotoxy(int x, int y) -> void
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// xy�� �����ϴ°�.
}