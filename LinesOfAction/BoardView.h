#pragma once
#include "Board.h"


class BoardView
{
public:
	BoardView(Board* argBoard);
	void displayBoard();

protected:


private:
	Board* m_Board;


};

