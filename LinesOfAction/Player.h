#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Board.h"

using namespace std;

class Player
{
public:
	Player();
	
	int getTotalPieces() const;
	char getColor() const;

	void setTotalPieces(int totalPiece);
	void setColor(char argColor);

	virtual void play();
	void displayPieces();
	string inputValidation(string coordinates);

	//virtual destructor
	virtual ~Player() {}

protected:
	// Private functions
	bool sizeValidation(string Coordinates);
	bool letterValidation(string Coordinates);
	bool numberValidation(string Coordinates);
	bool caseValidation(string Coordinates);

	// Private members maybe
	char p_color;
	int p_TotalPieces;
	vector<string> p_pieces;
	static int nextID;
	int p_ID;

private:


};

