МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 4<br/> по дисциплине "Программирование"
<br/>

студентки 1 курса группы ИВТ-б-о-192(1)  
Николаевой Владимиры Григорьевны  
направления подготовки 09.03.01 "Информатика и вычислительная техника"   
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2020

<br><br><br>

### Цель: <br>
------

1. Закрепить навыки работы с перечислениями;
2. Закрепить навыки работы с структурами;
3. Освоить методы составления многофайловых программ.


### Реализация: <br>
------



#### main.cpp <br>
```C++
#include <iostream>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	char symbol;
	bool isEmpty = false;

	std::cout << "Выбери, X или 0?: ";
	std::cin >> symbol;
	if (symbol != 'X' && symbol != '0') 
	{
		std::cout << "Выберите между Х и 0 >:c" << std::endl;
		while (symbol != 'X' && symbol != '0') {
			std::cin >> symbol;
		}
	}
	Game game = initGame(symbol);
	while (game.status == PLAY) {
		isEmpty = false;
		
		updateDisplay(game);
		if (game.isUserTurn == true) {
			game.isUserTurn = false;
			userTurn(&game);
			updateDisplay(game);
		}
		else {
			game.isUserTurn = true;
			botTurn(&game);
			updateDisplay(game);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (game.bord[i][j] == ' ')
					isEmpty = true;
			}
		}
		if (!isEmpty)
			game.status = NOT_WIN;

	}
	if (game.status == USER_WIN) std::cout << "Вы победили!";
	else if (game.status == BOT_WIN) std::cout << "Вы проиграли!";
	else if (game.status == NOT_WIN)std::cout << "Ничья!";
	return 0;
}
```
</br><br>
#### Header.h
```C++
#pragma once

  enum Status {
    PLAY,
    USER_WIN,
    BOT_WIN,
    NOT_WIN
  };
  struct Game
  {
    char bord[3][3];
    bool isUserTurn;
    char userChar;
    char botChar;
    Status status;
  };
  Game initGame(char userChar);
  void updateDisplay(const Game game);
  void botTurn(Game* game);
  void userTurn(Game* game);
  bool updateGame(Game* game);
```

#### Helper.cpp
```C++
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
	std::cout << "введите горизонтальную координату: ";
	std::cin >> a;
	std::cout << "введите вертикальную координату: ";
	std::cin >> s;
	if (game->bord[a][s]==' ' && ((a>=0 && a<3)&&(s >=0 && s<3)))
	game->bord[a][s] = game->userChar;
	else {
		while (!(game->bord[a][s] == ' ' && ((a >= 0 && a < 3) && (s >= 0 && s < 3)))) {
			std::cout << "Данные введены некорректно, повтоите попытку \n";
			std::cin >> a >> s;
		}
		game->bord[a][s] = game->userChar;
	}
	// проверка по горизонтали
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

	// проверка по вертикали
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

	// проверка по диагонали 1 
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
	// проверка по диагонали 2
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
	//проверка по горизонтали
	for (int i = 0; i < 3; i++)
	{
		if (turned == true) // бот походил, больше поля искать не нужно
			break;

		for (int j = 0; j < 3; j++) {

			if (turned == true)
				break;

			switch (j)
			{
			case 0:
				if ((game->bord[i][j] == game->botChar) && (game->bord[i][j + 1] == game->botChar))
				{
					if (game->bord[i][j + 2] == ' ') // проверочка что поле свободно
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
					if (game->bord[i][j + 1] == ' ') // Проверочка что поле Свободно
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
					if (game->bord[i][j - 1] == ' ')  // Проверочка что поле свободно
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
	// По вертикали
	for (int j = 0; j < 3; j++)
	{
		if (turned == true) // бот походил, больше поля искать не нужно
			break;

		for (int i = 0; i < 3; i++) {

			if (turned == true)
				break;

			switch (i)
			{
			case 0:
				if ((game->bord[i][j] == game->botChar) && (game->bord[i + 1][j] == game->botChar))
				{
					if (game->bord[i + 2][j] == ' ') // проверочка что поле не занято ботом
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
					if (game->bord[i + 1][j] == ' ') // Проверочка что поле не занято ботом
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
					if (game->bord[i - 1][j] == ' ')  // Проверочка что поле не занято ботом
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
	// по диагонали 1 
	if (turned != true)
	{
		if ((game->bord[0][0] == game->botChar) && (game->bord[1][1] == game->botChar))
		{
			if (game->bord[2][2] == ' ') // проверочка что поле не занято ботом
			{
				game->bord[2][2] = game->botChar;
				turned = true;
				game->status = BOT_WIN;
			}
		}
		else
			if ((game->bord[0][0] == game->botChar) && (game->bord[2][2] == game->botChar))
			{
				if (game->bord[1][1] == ' ') // Проверочка что поле не занято ботом
				{
					game->bord[1][1] = game->botChar;
					turned = true;
					game->status = BOT_WIN;
				}
			}
			else
				if ((game->bord[1][1] == game->botChar) && (game->bord[2][2] == game->botChar))
				{
					if (game->bord[0][0] == ' ')  // Проверочка что поле не занято ботом
					{
						game->bord[0][0] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
				}
	}
	// по диагонали 2
	if (turned != true)
	{
		if ((game->bord[0][2] == game->botChar) && (game->bord[1][1] == game->botChar))
		{
			if (game->bord[2][0] == ' ') // проверочка что поле не занято ботом
			{
				game->bord[2][0] = game->botChar;
				turned = true;
				game->status = BOT_WIN;
			}
		}
		else
			if ((game->bord[0][2] == game->botChar) && (game->bord[2][0] == game->botChar))
			{
				if (game->bord[1][1] == ' ') // Проверочка что поле не занято ботом
				{
					game->bord[1][1] = game->botChar;
					turned = true;
					game->status = BOT_WIN;
				}
			}
			else
				if ((game->bord[2][0] == game->botChar) && (game->bord[1][1] == game->botChar))
				{
					if (game->bord[0][2] == ' ')  // Проверочка что поле не занято ботом
					{
						game->bord[0][2] = game->botChar;
						turned = true;
						game->status = BOT_WIN;
					}
				}
	}
	//проверка куда поставитььььь
	for (int i = 0; i < 3; i++)
	{
		if (turned == true) // бот походил, больше поля искать не нужно
			break;

		for (int j = 0; j < 3; j++) {

			if (turned == true)
				break;

			switch (j)
			{
			case 0:
				if ((game->bord[i][j] == game->userChar) && (game->bord[i][j + 1] == game->userChar))
				{
					if (game->bord[i][j + 2] == ' ') // проверочка что поле свободно
					{
						game->bord[i][j + 2] = game->botChar;
						turned = true;
					}
					else break;

					break;
				}
				else if ((game->bord[i][j] == game->userChar) && (game->bord[i][j + 2] == game->userChar))
				{
					if (game->bord[i][j + 1] == ' ') // Проверочка что поле Свободно
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
					if (game->bord[i][j - 1] == ' ')  // Проверочка что поле свободно
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
	// По вертикали
	for (int j = 0; j < 3; j++)
	{
		if (turned == true) // бот походил, больше поля искать не нужно
			break;

		for (int i = 0; i < 3; i++) {

			if (turned == true)
				break;

			switch (i)
			{
			case 0:
				if ((game->bord[i][j] == game->userChar) && (game->bord[i + 1][j] == game->userChar))
				{
					if (game->bord[i + 2][j] == ' ') // проверочка что поле не занято ботом
					{
						game->bord[i + 2][j] = game->botChar;
						turned = true;
					}
					else break;

					break;
				}
				else if ((game->bord[i][j] == game->userChar) && (game->bord[i + 2][j] == game->userChar))
				{
					if (game->bord[i + 1][j] == ' ') // Проверочка что поле не занято ботом
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
					if (game->bord[i - 1][j] == ' ')  // Проверочка что поле не занято ботом
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
	// по диагонали 1 
	if (turned != true)
	{
		if ((game->bord[0][0] == game->userChar) && (game->bord[1][1] == game->userChar))
		{
			if (game->bord[2][2] == ' ') // проверочка что поле не занято ботом
			{
				game->bord[2][2] = game->botChar;
				turned = true;
			}
		}
		else
			if ((game->bord[0][0] == game->userChar) && (game->bord[2][2] == game->userChar))
			{
				if (game->bord[1][1] == ' ') // Проверочка что поле не занято ботом
				{
					game->bord[1][1] = game->botChar;
					turned = true;
				}
			}
			else
				if ((game->bord[1][1] == game->userChar) && (game->bord[2][2] == game->userChar))
				{
					if (game->bord[0][0] == ' ')  // Проверочка что поле не занято ботом
					{
						game->bord[0][0] = game->botChar;
						turned = true;
					}
				}
	}
	// по диагонали 2
	if (turned != true)
	{
		if ((game->bord[0][2] == game->userChar) && (game->bord[1][1] == game->userChar))
		{
			if (game->bord[2][0] == ' ') // проверочка что поле не занято ботом
			{
				game->bord[2][0] = game->botChar;
				turned = true;
			}
		}
		else
			if ((game->bord[0][2] == game->userChar) && (game->bord[2][0] == game->userChar))
			{
				if (game->bord[1][1] == ' ') // Проверочка что поле не занято ботом
				{
					game->bord[1][1] = game->botChar;
					turned = true;
				}
			}
			else
				if ((game->bord[2][0] == game->userChar) && (game->bord[1][1] == game->userChar))
				{
					if (game->bord[0][2] == ' ')  // Проверочка что поле не занято ботом
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
```
### Вывод: 

------

По завершении лабораторной работы мной были закреплены навыки работы с перечислениями и структурами, освоены методы составления многофайловых программ.