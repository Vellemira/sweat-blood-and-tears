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