#pragma once
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


class Board {

public:
	//constructor
	Board();

	//getters
	char** getcopyBoard();

	//setters


	//meaningful functions

	string convertCoordinates(string argCoordinates); //testing meant to be in protected or private


protected:
	
private:
	void printBoard();
	void movePiece(string argCurrentPiece, string argNewPosition, char argPlayer);
	bool pieceSelectionValidation(string argCurrentPiece, char argPlayer);
	bool horizontalValidation(string argCurrentPiece, string argNewPosition, char argPlayer);
	bool verticalValidation(string argCurrentPiece, string argNewPosition, char argPlayer);
	bool rightDiagonalValidation(string argCurrentPiece, string argNewPosition, char argPlayer);
	bool leftDiagonalValidation(string argCurrentPiece, string argNewPosition, char argPlayer);

	char m_board[8][8];
	vector<string> b_potentialMoves;

};