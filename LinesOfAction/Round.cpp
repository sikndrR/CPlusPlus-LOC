#include "Round.h"

Round::Round() {

}


void Round::menu() {

	for (int i = 1; i <= 40; i++) {
		cout << "=";
	}

	cout << endl;

	cout << "	Select option: " << endl;
	cout << "	(1) Human VS Human " << endl;
	cout << "	(2) Human VS Computer " << endl;
	cout << "	(3) Serialization " << endl;
	cout << "	(4) Exit " << endl;

	for (int i = 1; i <= 40; i++) {
		cout << "=";
	}

	cout << endl;
}

int Round::numinputValid(int end, int start, string message)
{
	int input;
	while (true) {
		cin >> input;

		if (cin.fail()) {
			// Input is not an integer, clear the error flag and ignore the input
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << std::endl;
		}
		else if (start >= input || end >= input) {
			break;
		}
		else {
			// Input is an integer, but not 0 or 1
			cout << message << std::endl;
		}
	}
	return input;
}


Player* Round::flipcoin(Player* argPlayer1, Player* argPlayer2) {

	// coin = 1, heads
	// coin = 0, tails
	// Heads >= 4
	// Tails <= 5

	// Providing a seed value
	srand((unsigned)time(NULL));
	// Get a random number 0 - 9
	int random = rand() % 10;
	bool heads = false;
	bool tails = false;

	//Menu for input from user to choose heads or tails
	for (int i = 0; i <= 60; i++) {
		cout << "=";
	}

	cout << endl << "Flipping coin to see who plays first (1) Heads (0) for tails" << endl;

	for (int i = 0; i <= 60; i++) {
		cout << "=";
	}
	
	cout << endl;

	int coin = numinputValid(0,1,"Invalid input. Please enter either 1 or 0.");


	if(random <= 4){
		cout << "Coin landed tails" << endl;
		tails = true;
	}
	else {
		cout << "Coin landed heads" << endl;
		heads = true;
	}

	if ((coin == 1 && heads == true) || (coin == 0 && tails == true)) {
		argPlayer1->setColor('B');
		argPlayer2->setColor('W');
		cout<< "Player 1 color: " << argPlayer1->getColor() << endl
			<< "Player 2 color: " << argPlayer2->getColor() << endl;
		return argPlayer1;
	}
	else {
		argPlayer1->setColor('W');
		argPlayer2->setColor('B');
		cout<< "Player 1 color: " << argPlayer1->getColor() << endl
			<< "Player 2 color: " << argPlayer2->getColor() << endl;
		return argPlayer2;
	}
}

