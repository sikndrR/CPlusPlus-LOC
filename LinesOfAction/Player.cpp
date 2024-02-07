#include "Player.h"

using namespace std;

int Player::nextID = 1;

Player::Player()
{
	p_color = 'N';
	p_TotalPieces = 0;
	p_pieces;
	p_ID = nextID++;
}



int Player::getTotalPieces() const
{
	return p_TotalPieces;
}


char Player::getColor() const
{
	return p_color;
}

void Player::setTotalPieces(int totalPiece)
{
	p_TotalPieces = totalPiece;

}

void Player::setColor(char argColor)
{
	 p_color = argColor;
}



void Player::play()
{
	cout << "testing playing from player class" << endl;
}


void Player::displayPieces()
{
	for (int i = 0; i <= (p_pieces.size() - 1); i++) {
		cout << p_pieces[i] << " ";
	}
	cout << endl;
}


//Input validation

bool Player::sizeValidation(string Coordinates)
{
	if (Coordinates.size() == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool Player::letterValidation(string Coordinates)
{
	char letter = Coordinates[0];

	for (char Start = 'A'; Start <= 'H'; Start++) {
		if (letter >= 'A' && letter <= 'H') {
			return true;
		}
	}
	return false;
}

bool Player::numberValidation(string Coordinates)
{
	int number = int(Coordinates[1] - '0');

	for (int i = 0; i <= 8; i++) {
		if (number >= 1 && number <= 8) {
			return true;
		}
	}
	return false;
}

bool Player::caseValidation(string Coordinates)
{

	bool validInput = false;

	while (validInput == false)
	{
		if (sizeValidation(Coordinates) == true) {
			cout << "Valid size " << Coordinates.size() << endl;
			validInput = true;
		}
		else {
			cout << "Enter proper coordinates EX (A1,H8)" << endl;
			validInput = false;
			break;
		}

		if (letterValidation(Coordinates) == true) {
			cout << "Valid letter " << Coordinates[0] << endl;
			validInput = true;
		}
		else {
			cout << "Enter letter from A - H" << endl;
			validInput = false;
			break;
		}

		if (numberValidation(Coordinates) == true) {
			cout << "Valid number " << Coordinates[1] << endl;
			validInput = true;
		}
		else {
			cout << "Enter number from 1-8" << endl;
			validInput = false;
			break;
		}

	}

	return validInput;
}

/*
string Player::inputValidation(string coordinates)
{
	while (true) {
		if (caseValidation(coordinates) == true) {
			cout << "Player entered proper input: " << coordinates << endl;
			break;
		}
		else {
			cout << "Retry: ";
			cin >> coordinates;
		}
	}
	return coordinates;
}*/

string Player::inputValidation(string coordinates)
{
	return string();
}