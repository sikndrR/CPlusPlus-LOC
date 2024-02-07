#include "Tournament.h"

Tournament::Tournament()
{

}

void Tournament::startgame()
{
    Round currRound;
    Player* player1;
    Player* player2;
    Player* currentPlayer = nullptr;

    currRound.menu();

    int input = currRound.numinputValid(0,4,"Invalid, enter a number between 1-4: "); // Validation works until i enter nums

    switch (input) {
    case 1: // Human VS Human
        player1 = new Human;
        player2 = new Human;
        currentPlayer = currRound.flipcoin(player1,player2);

        while (true) {


            // Call the play function of the current player
            currentPlayer->play();

            // Add any additional game logic or exit conditions here

            // For demonstration purposes, break the loop after a few iterations
            // Remove this line for an infinite loop

            // Swap turns between player1 and player2
            if (currentPlayer == player1) {
                currentPlayer = player2;
            }
            else {
                currentPlayer = player1;
            }

            static int iterations = 0;
            if (++iterations >= 5) {
                break;
            }
        }

        delete player1;
        delete player2;

        break;
    case 2: // Human VS Computer 
        player1 = new Human;
        player2 = new Computer;

        break;
    case 3: // Serialization
            //Need to work on
        
        break;
    case 4:// Exit
        
        break;
    }


}
