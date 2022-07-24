#ifndef _TEMPLATEDBOARD_H
#define _TEMPLATEDBOARD_H
#include <iostream>
#include <string>
using namespace std;

template<class bType>
class Board{

	private:
		bType ** M;
		int row;
		int col;
	public:
		Board(bType toFill,int row, int col);
		~Board();
		void printBoard() const;
		void updateRow(bType val, int rowNum);
		void updateCell(bType val, int r, int c);
		int getRow() const;
		int getCol() const;
		bool checkDiag() const;
		bType* Board::operator[](int idx);

};

#include "templatedBoard.cpp";




#endif