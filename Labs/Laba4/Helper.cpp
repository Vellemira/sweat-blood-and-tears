#include <iostream>
#include <time.h>
#include "Header.h"

void updateDisplay(const Game game) {
	system("cls");
	std::cout << "\t      *\t   0   1   2                                                   \n  \t\t -------------" << std::endl;
	std::cout << "\t      0\t | " << game.bord[0][0] << " | " << game.bord[0][1] << " | " << game.bord[0][2] << " | \n  \t\t -------------" << std::endl;
	std::cout << "\t      1\t | " << game.bord[1][0] << " | " << game.bord[1][1] << " | " << game.bord[1][2] << " | \n  \t\t -------------" << std::endl;
	std::cout << "\t      2\t | " << game.bord[2][0] << " | " << game.bord[2][1] << " | " << game.bord[2][2] << " | \n  \t\t -------------" << std::endl;
}

void userTurn(Game* game)
{
	int a, s;
	char tri[3];
	std::cout << "������� �������������� ����������: ";
	std::cin >> a;
	std::cout << "������� ������������ ����������: ";
	std::cin >> s;
	if (game->bord[a][s]==' ' && ((a>=0 && a<3)&&(s >=0 && s<3)))
	game->bord[a][s] = game->userChar;
	else {
		while (!(game->bord[a][s] == ' ' && ((a >= 0 && a < 3) && (s >= 0 && s < 3)))) {
			std::cout << "������ ������� �����������, �������� ������� \n";
			std::cin >> a >> s;
		}
		game->bord[a][s] = game->userChar;
	}
	// �������� �� �����������
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tri[j] = game->bord[i][j];
		}
		if (tri[0] == game->botChar && tri[1] == game->botChar && tri[2] == game->botChar)
		{
			game->status = BOT_WIN;
			break;
		}
		else
			if (tri[0] == game->userChar && tri[1] == game->userChar && tri[2] == game->userChar)
			{
				game->status = USER_WIN;
				break;
			}
	}

	// �������� �� ���������
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tri[j] = game->bord[j][i];
		}
		if (tri[0] == game->botChar && tri[1] == game->botChar && tri[2] == game->botChar)
		{
			game->status = BOT_WIN;
			break;
		}
		else
			if (tri[0] == game->userChar && tri[1] == game->userChar && tri[2] == game->userChar)
			{
				game->status = USER_WIN;
				break;
			}
	}

	// �������� �� ��������� 1 
	for (int i = 0; i < 3; i++)
	{
		tri[i] = game->bord[i][i];
	}
	if (tri[0] == game->botChar && tri[1] == game->botChar && tri[2] == game->botChar)
	{
		game->status = BOT_WIN;
	}
	else
		if (tri[0] == game->userChar && tri[1] == game->userChar && tri[2] == game->userChar)
		{
			game->status = USER_WIN;
		}
	// �������� �� ��������� 2
	tri[0] = game->bord[0][2];
	tri[1] = game->bord[1][1];
	tri[2] = game->bord[2][0];
	if (tri[0] == game->botChar && tri[1] == game->botChar && tri[2] == game->botChar)
	{
		game->status = BOT_WIN;
	}
	else
		if (tri[0] == game->userChar && tri[1] == game->userChar && tri[2] == game->userChar)
		{
			game->status = USER_WIN;
		}


}

Game initGame(char userChar) {
	Game game;
	srand(time(0));
		game.isUserTurn = rand()%2;
		game.userChar = userChar;
		if (userChar == 'X')
			game.botChar = '0';
		else
			game.botChar = 'X';
		game.status = PLAY;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				game.bord[i][j] = ' ';
			}
		}
	return game;
}

void botTurn(Game* game)
{
	bool turned = false;
	//�������� �� �����������
	for (int i = 0; i < 3; i++)
	{
		if (turned == true) // ��� �������, ������ ���� ������ �� �����
			break;

		for (int j = 0; j < 3; j++) {

			if (turned == true)
				break;

			switch (j)
			{
			case 0:
				if ((game->bord[i][j] == game->botChar) && (game->bord[i][j + 1] == game->botChar))
				{
					if (game->bord[i][j + 2] == ' ') // ���������� ��� ���� ��������
					{
						game->bord[i][j + 2] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
					else break;

					break;
				}
				else if ((game->bord[i][j] == game->botChar) && (game->bord[i][j + 2] == game->botChar))
				{
					if (game->bord[i][j + 1] == ' ') // ���������� ��� ���� ��������
					{
						game->bord[i][j + 1] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
					else break;
					break;
				}
				break;
			case 1:
				if ((game->bord[i][j] == game->botChar) && (game->bord[i][j + 1] == game->botChar))
				{
					if (game->bord[i][j - 1] == ' ')  // ���������� ��� ���� ��������
					{
						game->bord[i][j - 1] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
					else break;

					break;
				}
				break;
			}
		}
	}
	// �� ���������
	for (int j = 0; j < 3; j++)
	{
		if (turned == true) // ��� �������, ������ ���� ������ �� �����
			break;

		for (int i = 0; i < 3; i++) {

			if (turned == true)
				break;

			switch (i)
			{
			case 0:
				if ((game->bord[i][j] == game->botChar) && (game->bord[i + 1][j] == game->botChar))
				{
					if (game->bord[i + 2][j] == ' ') // ���������� ��� ���� �� ������ �����
					{
						game->bord[i + 2][j] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
					else break;

					break;
				}
				else if ((game->bord[i][j] == game->botChar) && (game->bord[i + 2][j] == game->botChar))
				{
					if (game->bord[i + 1][j] == ' ') // ���������� ��� ���� �� ������ �����
					{
						game->bord[i + 1][j] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
					else
						break;

					break;
				}
				else
					break;

			case 1:
				if ((game->bord[i][j] == game->botChar) && (game->bord[i + 1][j] == game->botChar))
				{
					if (game->bord[i - 1][j] == ' ')  // ���������� ��� ���� �� ������ �����
					{
						game->bord[i - 1][j] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
					else break;

					break;
				}
				else
					break;
			}
		}
	}
	// �� ��������� 1 
	if (turned != true)
	{
		if ((game->bord[0][0] == game->botChar) && (game->bord[1][1] == game->botChar))
		{
			if (game->bord[2][2] == ' ') // ���������� ��� ���� �� ������ �����
			{
				game->bord[2][2] = game->botChar;
				turned = true;
				game->status = BOT_WIN;
			}
		}
		else
			if ((game->bord[0][0] == game->botChar) && (game->bord[2][2] == game->botChar))
			{
				if (game->bord[1][1] == ' ') // ���������� ��� ���� �� ������ �����
				{
					game->bord[1][1] = game->botChar;
					turned = true;
					game->status = BOT_WIN;
				}
			}
			else
				if ((game->bord[1][1] == game->botChar) && (game->bord[2][2] == game->botChar))
				{
					if (game->bord[0][0] == ' ')  // ���������� ��� ���� �� ������ �����
					{
						game->bord[0][0] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
				}
	}
	// �� ��������� 2
	if (turned != true)
	{
		if ((game->bord[0][2] == game->botChar) && (game->bord[1][1] == game->botChar))
		{
			if (game->bord[2][0] == ' ') // ���������� ��� ���� �� ������ �����
			{
				game->bord[2][0] = game->botChar;
				turned = true;
				game->status = BOT_WIN;
			}
		}
		else
			if ((game->bord[0][2] == game->botChar) && (game->bord[2][0] == game->botChar))
			{
				if (game->bord[1][1] == ' ') // ���������� ��� ���� �� ������ �����
				{
					game->bord[1][1] = game->botChar;
					turned = true;
					game->status = BOT_WIN;
				}
			}
			else
				if ((game->bord[2][0] == game->botChar) && (game->bord[1][1] == game->botChar))
				{
					if (game->bord[0][2] == ' ')  // ���������� ��� ���� �� ������ �����
					{
						game->bord[0][2] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
				}
	}
	//�������� ���� �������������
	for (int i = 0; i < 3; i++)
	{
		if (turned == true) // ��� �������, ������ ���� ������ �� �����
			break;

		for (int j = 0; j < 3; j++) {

			if (turned == true)
				break;

			switch (j)
			{
			case 0:
				if ((game->bord[i][j] == game->userChar) && (game->bord[i][j + 1] == game->userChar))
				{
					if (game->bord[i][j + 2] == ' ') // ���������� ��� ���� ��������
					{
						game->bord[i][j + 2] = game->botChar;
						turned = true;
					}
					else break;

					break;
				}
				else if ((game->bord[i][j] == game->userChar) && (game->bord[i][j + 2] == game->userChar))
				{
					if (game->bord[i][j + 1] == ' ') // ���������� ��� ���� ��������
					{
						game->bord[i][j + 1] = game->botChar;
						turned = true;
					}
					else break;
					break;
				}
				break;
			case 1:
				if ((game->bord[i][j] == game->userChar) && (game->bord[i][j + 1] == game->userChar))
				{
					if (game->bord[i][j - 1] == ' ')  // ���������� ��� ���� ��������
					{
						game->bord[i][j - 1] = game->botChar;
						turned = true;
					}
					else break;

					break;
				}
				break;
			}
		}
	}
	// �� ���������
	for (int j = 0; j < 3; j++)
	{
		if (turned == true) // ��� �������, ������ ���� ������ �� �����
			break;

		for (int i = 0; i < 3; i++) {

			if (turned == true)
				break;

			switch (i)
			{
			case 0:
				if ((game->bord[i][j] == game->userChar) && (game->bord[i + 1][j] == game->userChar))
				{
					if (game->bord[i + 2][j] == ' ') // ���������� ��� ���� �� ������ �����
					{
						game->bord[i + 2][j] = game->botChar;
						turned = true;
					}
					else break;

					break;
				}
				else if ((game->bord[i][j] == game->userChar) && (game->bord[i + 2][j] == game->userChar))
				{
					if (game->bord[i + 1][j] == ' ') // ���������� ��� ���� �� ������ �����
					{
						game->bord[i + 1][j] = game->botChar;
						turned = true;
					}
					else
						break;

					break;
				}
				else
					break;

			case 1:
				if ((game->bord[i][j] == game->userChar) && (game->bord[i + 1][j] == game->userChar))
				{
					if (game->bord[i - 1][j] == ' ')  // ���������� ��� ���� �� ������ �����
					{
						game->bord[i - 1][j] = game->botChar;
						turned = true;
					}
					else break;

					break;
				}
				else
					break;
			}
		}
	}
	// �� ��������� 1 
	if (turned != true)
	{
		if ((game->bord[0][0] == game->userChar) && (game->bord[1][1] == game->userChar))
		{
			if (game->bord[2][2] == ' ') // ���������� ��� ���� �� ������ �����
			{
				game->bord[2][2] = game->botChar;
				turned = true;
			}
		}
		else
			if ((game->bord[0][0] == game->userChar) && (game->bord[2][2] == game->userChar))
			{
				if (game->bord[1][1] == ' ') // ���������� ��� ���� �� ������ �����
				{
					game->bord[1][1] = game->botChar;
					turned = true;
				}
			}
			else
				if ((game->bord[1][1] == game->userChar) && (game->bord[2][2] == game->userChar))
				{
					if (game->bord[0][0] == ' ')  // ���������� ��� ���� �� ������ �����
					{
						game->bord[0][0] = game->botChar;
						turned = true;
					}
				}
	}
	// �� ��������� 2
	if (turned != true)
	{
		if ((game->bord[0][2] == game->userChar) && (game->bord[1][1] == game->userChar))
		{
			if (game->bord[2][0] == ' ') // ���������� ��� ���� �� ������ �����
			{
				game->bord[2][0] = game->botChar;
				turned = true;
			}
		}
		else
			if ((game->bord[0][2] == game->userChar) && (game->bord[2][0] == game->userChar))
			{
				if (game->bord[1][1] == ' ') // ���������� ��� ���� �� ������ �����
				{
					game->bord[1][1] = game->botChar;
					turned = true;
				}
			}
			else
				if ((game->bord[2][0] == game->userChar) && (game->bord[1][1] == game->userChar))
				{
					if (game->bord[0][2] == ' ')  // ���������� ��� ���� �� ������ �����
					{
						game->bord[0][2] = game->botChar;
						turned = true;
					}
				}
				else if (!turned) {
				again:
					int a = rand() % 3, b = rand() % 3;
					if (game->bord[a][b] == ' ')
						game->bord[a][b] = game->botChar;
					else
						goto again;
				}
	}
}