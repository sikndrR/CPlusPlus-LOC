#include "BoardView.h"

BoardView::BoardView(Board* argBoard)
{
	m_Board = argBoard;
}


//https://stackoverflow.com/questions/8617683/how-to-return-a-2d-array-from-a-function
void BoardView::displayBoard()
{
    char** my2DArray = m_Board->getcopyBoard();

    // Top border
    cout << "  +-----------------+" << endl;

        for (int h = 0; h < 8; h++)
        {
            cout << 8 - h << " | ";
                for (int w = 0; w < 8; w++)
                {
                    cout << my2DArray[h][w] << " ";
                }
            cout << "|" << endl;
        }

    // Bottom border
    cout << "  +-----------------+" << endl;

    // Column labels
    cout << "    A B C D E F G H" << endl;

    // important: clean up memory
    printf("\n");
    printf("Cleaning up memory...\n");
    for (int h = 0; h < 8; h++) // loop variable wasn't declared
    {
        delete[] my2DArray[h];
    }
    delete[] my2DArray;
    my2DArray = 0;
    printf("Ready.\n");

}


