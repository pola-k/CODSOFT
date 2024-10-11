#include <iostream>
#include <cstdlib>
using namespace std;

void GuessingGame()
{
	srand(time(0));
	int random = rand() , number;
	bool guessed = false;
	cout << "Generating Random Number" << endl << endl << endl;
	cout << "Guess the Number: ";
	while (!guessed)
	{
		cin >> number;
		if (number != random)
		{
			if (number > random)
			{
				cout << "Too High" << endl << "Guess Again: ";
			}
			else
			{
				cout << "Too Low" << endl << "Guess Again: ";
			}
		}
		else
		{
			cout << "Congratulations You have guessed the number" << endl << endl;
			guessed = true;
		}
	}
}


int main()
{
	GuessingGame();
	system("pause");
	return 0;
}
