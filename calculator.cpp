#include <iostream>
#include <conio.h>
using namespace std;

void Calculator()
{
	bool valid = false;
	char operation, userInput;
	double num1, num2;
	while (true)
	{
		cout << "Enter a number: ";
		do
		{
			cin >> num1;
			if (cin.fail())
			{
				cout << "Invalid Input" << endl << "Enter a number: ";
				cin.clear();
				cin.ignore();
			}
			else
			{
				valid = true;
			}
		} while (!valid);

		valid = false;
		cout << "Enter the operation you want to perform: ";
		do
		{
			cin >> operation;
			if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
			{
				valid = true;
			}
			else
			{
				cout << "Invalid Operation" << endl << "Enter Again: ";
			}
		} while (!valid);

		valid = false;
		cout << "Enter a second number: ";
		do
		{
			cin >> num2;
			if (cin.fail())
			{
				cout << "Invalid Input" << endl << "Enter a second number: ";
				cin.clear();
				cin.ignore();
			}
			else
			{
				valid = true;
			}
		} while (!valid);

		if (operation == '+')
		{
			cout << "Sum = " << num1 + num2 << endl << endl;
		}
		else if (operation == '-')
		{
			cout << "Difference = " << num1 - num2 << endl << endl;
		}
		else if (operation == '*')
		{
			cout << "Product = " << num1 * num2 << endl << endl;
		}
		else
		{
			if (num2 == 0)
			{
				cout << "Math Error" << endl << endl;
			}
			else
			{
				cout << "Quotient = " << num1 / num2 << endl << endl;
			}
		}

		cout << "Press E to Exit or Press any other key to continue" << endl;
		userInput = _getch();
		if (userInput == 'E' || userInput == 'e')
		{
			break;
		}
		cout << endl << endl;
	}
}

int main()
{
	Calculator();
	system("pause");
	return 0;
}
