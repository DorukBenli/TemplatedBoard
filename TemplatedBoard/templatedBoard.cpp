#include <iostream>
#include "templatedBoard.h"
using namespace std;


template<class bType>
Board<bType>::Board(bType toFill, int r, int c)
{
	row = r;
	col = c;
	M = new bType * [row];
	for(int i=0; i < row; i++)
	{
		M[i] = new bType [col];
	}
	
	for(int i = 0; i < row; i++)
	{
		for(int j= 0; j < col; j++)
		{
			M[i][j] =toFill;
		}
	}


}

template<class bType>
Board<bType>::~Board()
{
	for(int i= 0; i < row; i ++)
	{
		delete [] M[i];
	}
	delete []M;
}

template<class bType>

void Board<bType>::printBoard() const
{
	for(int i= 0; i< row; i++)
	{
		cout <<"|";
		for(int j= 0; j < col; j++)
		{
			cout << M[i][j] <<"|";
		}
		cout << endl;
	}
}

template<class bType>
void Board<bType>::updateRow(bType val, int rowNum)
{
	//this function updates all the values of a specified row to the specified value.
	for(int i = 0; < col; i++)
	{
		M[rowNum][i] = val;
	}

}

template<class bType>
void Board<bType>::updateCell(bType val, int r, int c)
{
	M[r][c] = val;
}

template<class bType>
int Board<bType>::getRow() const
{
	return row;
}

template<class bType>
int Board<bType>::getCol() const
{
	return col;
}

template<class bType>
bool Board<bType>::checkDiag() const
{
	//returns true if diagonals are same val.
	if(M[0][0] == M[1][1] && M[0][0] == M[2][2] && M[0][0] != '-')
	{
		return true;
	}
	else if(M[2][0] == M[1][1] && M[2][0] == M[0][2] && M[2][0] != '-')
	{
		return true;
	}
	return false;
}


template<class bType>
bType*  Board<bType>::operator[](int idx)
{
	return M[idx];
}