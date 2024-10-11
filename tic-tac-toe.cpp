#include <iostream>
#include <stdlib.h>
using namespace std;

void InitialiseGameBoard(char Board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Board[i][j] = '-';
		}
	}
}

void DisplayBoard(char Board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void PlayerInput(int& row , int& column)
{
	bool valid = false;

	cout << "Enter Row: ";
	do
	{
		cin >> row;
		if (row <= 3 && row >= 1)
		{
			valid = true;
		}
		else
		{
			cout << "Invalid Row Entered" << endl;
			cout << "Enter Row: ";
		}
	} while (valid == false);

	valid = false;
	cout << "Enter Column: ";
	do
	{
		cin >> column;
		if (column <= 3 && column >= 1)
		{
			valid = true;
		}
		else
		{
			cout << "Invalid Column Entered" << endl;
			cout << "Enter Column: ";
		}
	} while (valid == false);
}

bool UpdateBoard(char Board[][3], int current , int row, int column)
{
	if (Board[row][column] != '-')
	{
		return false;
	}
	else
	{
		if (current == 1)
		{
			Board[row][column] = 'X';
		}
		else
		{
			Board[row][column] = 'O';
		}
		return true;
	}
}

void SwitchPlayers(int& current)
{
	if (current == 1)
	{
		current = 2;
	}
	else
	{
		current = 1;
	}
}

bool CheckWinner(char Board[][3], int current)
{
	char character;
	bool won = false;
	if (current == 1)
	{
		character = 'X';
	}
	else
	{
		character = 'O';
	}

	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Board[i][j] == character)
			{
				if (i == 0) // Checking Vertically 
				{
					if (Board[i + 1][j] == character && Board[i + 2][j] == character)
					{
						won = true;
						break;
					}
					else if (j == 0) // Checking Diagonal 1
					{
						if (Board[i + 1][j + 1] == character && Board[i + 2][j + 2] == character)
						{
							won = true;
							break;
						}
					}
				}
				if (j == 0) // Checking Horizontally
				{
					if (Board[i][j + 1] == character && Board[i][j + 2] == character)
					{
						won = true;
						break;
					}
				}
				if (i == 2 && j == 0) // Checking Diagonal 2
				{
					if (Board[i - 1][j + 1] == character && Board[i - 2][j + 2] == character)
					{
						won = true;
						break;
					}
				}
			}
		}
	}

	return won;

}

bool PlayAgain()
{
	char userInput;
	cout << "Press Y to play again: ";
	cin >> userInput;
	if (userInput == 'Y' || userInput == 'y')
	{
		return true;
	}
	return false;
}

int main()
{
	char Board[3][3];
	char player1 = 'X', player2 = 'O';
	int currentPlayer = 1, turnNumber = 0, row, column;
	bool won = false, again = true;

	InitialiseGameBoard(Board);
	do
	{
		cout << "Ongoing Match" << endl << endl;
		DisplayBoard(Board);
		do
		{
			PlayerInput(row, column);
		} while (!UpdateBoard(Board, currentPlayer, row - 1, column - 1));
		turnNumber++;
		if (turnNumber >= 5)
		{
			won = CheckWinner(Board, currentPlayer);
			if (won)
			{
				DisplayBoard(Board);
				cout << "Player " << currentPlayer << " Won" << endl;
				again = PlayAgain();
				if (again)
				{
					won = false;
					turnNumber = 0;
					InitialiseGameBoard(Board);
				}
			}
			if (turnNumber == 9)
			{
				cout << "Draw" << endl;
				again = PlayAgain();
				if (again)
				{
					turnNumber = 0;
					InitialiseGameBoard(Board);
				}
			}
		}
		SwitchPlayers(currentPlayer);
	} while (again);

	system("pause");
	return 0;
}
