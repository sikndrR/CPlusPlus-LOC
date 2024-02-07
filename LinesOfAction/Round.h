#pragma once
#include <iostream>
#include <string>
#include <sstream> 
#include "Player.h"
#include "BoardView.h"
#include "Board.h"


using namespace std;

class Round
{
public:
	Round();
	void menu();
	int numinputValid(int start, int end, string message);
	Player* flipcoin(Player* argPlayer1,Player* argPlayer2);


protected:


private:


};

