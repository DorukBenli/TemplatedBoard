#include <iostream>
#include <string>
#include "templatedBoard.h"
using namespace std;

bool checkRow(Board<char> &M)
{
	if(M[0][0] == M[0][1] && M[0][0] == M[0][2] && M[0][0] != '-')
	{
		return true;
	}
	if(M[1][0] == M[1][1] && M[1][0] == M[1][2] && M[1][0] != '-')
	{
		return true;
	}
	if(M[2][0] == M[2][1] && M[2][0] == M[2][2] && M[2][0] != '-')
	{
		return true;
	}
	return false;
}

bool checkCol(Board<char> &M)
{
	if(M[0][0] == M[1][0] && M[0][0] == M[2][0] && M[0][0] != '-')
	{
		return true;
	}
	if(M[0][1] == M[1][1] && M[0][1] == M[2][1] && M[0][1] != '-')
	{
		return true;
	}
	if(M[0][2] == M[1][2] && M[0][2] == M[2][2] && M[0][2] != '-')
	{
		return true;
	}
	return false;
}


bool checkWinCond(Board<char> &test)
{
	if(test.checkDiag() == true)
	{
		return true;
	}
	if(checkRow(test) == true)
	{
		return true;
	}
	if(checkCol(test) == true)
	{
		return true;
	}
	return false;
}

bool checkIsFull(Board<char> & test)
{
	// a function to check wether the board is full or not. If the board is full then the while loop ends.
	int ctr = 0;
	for(int i =0; i <test.getRow(); i++)
	{
		for(int j = 0; j < test.getCol(); j++)
		{
			if(test[i][j] == '-')
			{
				ctr += 1;
			}
		}
	}

	if(ctr == 0)
	{
		return true;
	}
	return  false;
}


int main()
{
	bool flag = false;
	int r1,r2,c1,c2;
	Board<char> game('-', 3,3);
	cout << "Welcome to the game of XOX!" << endl;
	game.printBoard();
	string P1, P2;
	cout << "Player 1 please enter your name: ";
	cin >> P1;
	cout << endl;
	cout << "Player 2 please enter your name: ";
	cin >> P2;
	cout << endl;
	while(checkIsFull(game) == false && checkWinCond(game) == false)
	{
		if(checkIsFull(game) == false)
		{
			cout << P1 <<" enter row index and column index(1 to 3) to place X:" << endl;
			cout << "Row: ";
			cin >> r1;
			cout << "Column: ";
			cin >> c1;
			game.updateCell('X',r1-1,c1-1);
			cout << endl;
			game.printBoard();
			if(checkWinCond(game) == true)
			{
				cout << P1 << " Has won the game" << endl;
				flag = true;
				break;
			}
			else
			{
				if(checkIsFull(game) == false)
				{
					cout << P2 <<" enter row index and column index(1 to 3) to place O:" << endl;
					cout << "Row: ";
					cin >> r2;
					cout << "Column: ";
					cin >> c2;
					while(r2 == r1 && c2 == c1)
					{
						cout << "You cant update an already updated cell!" << endl;
						cout << "Please try again" << endl;
						cout << "Row: ";
						cin >> r2;
						cout << "Column: ";
						cin >> c2;
					}
				}
				game.updateCell('0',r2-1,c2-1);
				cout << endl;
				game.printBoard();
			}
		}
	}

	cout << "------------------------------------------"<< endl;

	if(flag == false && checkIsFull(game) == false)
	{
		cout << P2 << " Has won the game" << endl;
	}
	else
	{
		cout << "The game is Draw" << endl;
	}


	return 0;
}
