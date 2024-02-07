#include "Board.h"

//Reason the constructer was done like this was because C++ wasnt allow to populate a 2D array
Board::Board() {
        // Initialize the board with your desired setup
        char initialSetup[8][8] = {
            {'.', 'B', 'B', 'B', 'B', 'B', 'B', '.'},
            {'W', '.', '.', '.', '.', '.', '.', 'W'},
            {'W', '.', '.', '.', '.', '.', '.', 'W'},
            {'W', '.', '.', '.', '.', '.', '.', 'W'},
            {'W', '.', '.', '.', '.', '.', '.', 'W'},
            {'W', '.', '.', '.', '.', '.', '.', 'W'},
            {'W', '.', '.', '.', '.', '.', '.', 'W'},
            {'.', 'B', 'B', 'B', 'B', 'B', 'B', '.'}
        };

        // Copy the initial setup to the board
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                m_board[i][j] = initialSetup[j][i];
            }
        }
    }


//https://stackoverflow.com/questions/8617683/how-to-return-a-2d-array-from-a-function
char** Board::getcopyBoard()
{
    char** array2D = 0;
    array2D = new char* [8];

    for (int h = 0; h < 8; h++)
    {
        array2D[h] = new char[8];

        for (int w = 0; w < 8; w++)
        {
            // Copying existing board array to return
            array2D[h][w] = m_board[w][h];
        }
    }

    return array2D;
}

void Board::printBoard() {

    // Top border
    cout << "  +-----------------+" << endl;

    for (int x = 0; x <= 7; x++) {
        cout << 8 - x << " | ";             //Displaying the row numbers
        for (int y = 0; y <= 7; y++) {
            cout << m_board[y][x] << " ";
        }
        cout << "|" << endl;
    }

    // Bottom border
    cout << "  +-----------------+" << endl;

    // Column labels
    cout << "    A B C D E F G H" << endl;

}

bool Board::pieceSelectionValidation(string argCurrentPiece, char argPlayer) //Fix wording of variables
{
    
    string convertPos;
    int Letternum;
    int numNum;
    bool validation = false;

    do {

        convertPos = convertCoordinates(argCurrentPiece);
        Letternum = stoi(convertPos) / 10 % 10;
        numNum = stoi(convertPos) % 10;

        if (m_board[Letternum][numNum] != '.' && argPlayer == m_board[Letternum][numNum]) {
            validation = true;
            cout << argCurrentPiece << " is a valid selection." << endl;
        }
        else {
            cout << argCurrentPiece << " not a valid piece selected" << endl;
        }

        if (validation == false) {
            cout << "Enter a valid input: ";    // Implement the check for userinput from human class maybe
            cin >> argCurrentPiece;
        }

    } while (validation == false);

    return validation;
}

bool Board::horizontalValidation(string argCurrentPiece, string argNewPosition, char argPlayer)
{
    bool validation = false;
    string convertOld = convertCoordinates(argCurrentPiece);
    int oldRow = stoi(convertOld) / 10 % 10;
    int oldColumn = stoi(convertOld) % 10;

    int availableSpaces = 0;

    //Getting spaces able to move

    for (int i = 0; i <= 7; i++) {
        if (m_board[i][oldColumn] == 'B' || m_board[i][oldColumn] == 'W') {
            availableSpaces++;
        }
    }

    string convertNew = convertCoordinates(argNewPosition);
    int newRow = stoi(convertNew) / 10 % 10;
    int newColumn = stoi(convertNew) % 10;

    //Checking Right

    for (int i = 1; i <= availableSpaces; i++) {

        //Checking to see if piece is being blocked
        if ((i < availableSpaces) && (m_board[oldRow + i][oldColumn] == '.' || m_board[oldRow + i][oldColumn] == argPlayer)) {
            cout << m_board[oldRow + i][oldColumn] << " ";
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if ((availableSpaces == i) && ((oldRow + availableSpaces) == newRow)
            && (m_board[oldRow + i][oldColumn] == '.' || m_board[oldRow + i][oldColumn] == 'W')) {
            cout << m_board[oldRow + i][oldColumn] << " valid";
            validation = true;
        }
        //Block happened
        else {
            cout << m_board[oldRow + i][oldColumn] << " invalid";
            validation = false;
            break;
        }
    }

    //Checking Left
    
    for (int i = 1; i <= availableSpaces; i++) {

        //Checking to see if piece is being blocked
        if ((i < availableSpaces) && m_board[oldRow - i][oldColumn] == '.' || m_board[oldRow - i][oldColumn] == argPlayer) {
            cout << m_board[oldRow - i][oldColumn] << " ";
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if ((availableSpaces == i) && ((oldRow - availableSpaces) == newRow)
            && (m_board[oldRow - i][oldColumn] == '.' || m_board[oldRow - i][oldColumn] == 'W')) {
            cout << m_board[oldRow - i][oldColumn] << " valid";
            validation = true;
        }
        //Block happened
        else {
            cout << m_board[oldRow - i][oldColumn] << " invalid";
            validation = false;
            break;
        }
    }

    if (validation == false) {
        cout << " invalid";
    }
    
    return validation;
}

bool Board::verticalValidation(string argCurrentPiece, string argNewPosition, char argPlayer)
{
    bool validation = false;
    string convertOld = convertCoordinates(argCurrentPiece);
    int oldRow = stoi(convertOld) / 10 % 10;
    int oldColumn = stoi(convertOld) % 10;

    int availableSpaces = 0;

    //Getting spaces able to move

    for (int i = 0; i <= 7; i++) {
        if (m_board[oldRow][i] == 'B' || m_board[oldRow][i] == 'W') {
            availableSpaces++;
        }
    }

    string convertNew = convertCoordinates(argNewPosition);
    int newRow = stoi(convertNew) / 10 % 10;
    int newColumn = stoi(convertNew) % 10;

    //Checking downwards

    for (int i = 1; i <= availableSpaces; i++) {

        //Checking to see if piece is being blocked
        if ( (i < availableSpaces) && (m_board[oldRow][oldColumn + i] == '.' || m_board[oldRow][oldColumn + i] == argPlayer)) {
            cout << m_board[oldRow][oldColumn + i] << " ";
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if((availableSpaces == i) && ((oldColumn + availableSpaces) == newColumn)
            && (m_board[oldRow][oldColumn + i] == '.' || m_board[oldRow][oldColumn + i] == 'W')) {
            cout << m_board[oldRow][oldColumn + i] << " valid";
            validation = true;
        }   
        //Block happened
        else {
            cout << m_board[oldRow][oldColumn + i] << " invalid";
            validation = false;
            break;
        }
    }

    //Checking upwards

    for (int i = 1; i <= availableSpaces; i++) {

        //Checking to see if piece is being blocked
        if ((i < availableSpaces) && m_board[oldRow][oldColumn - i] == '.' || m_board[oldRow][oldColumn - i] == argPlayer) {
            cout << m_board[oldRow][oldColumn - i] << " ";
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if ((availableSpaces == i) && ((oldColumn - availableSpaces) == newColumn) 
                && (m_board[oldRow][oldColumn - i] == '.' || m_board[oldRow][oldColumn - i] == 'W')) {
            cout << m_board[oldRow][oldColumn - i] << " valid";
            validation = true;
        }
        //Block happened
        else {
            cout << m_board[oldRow][oldColumn - i] << " invalid";
            validation = false;
            break;
        }
    }

    if (validation == false) {
        cout << " invalid";
    }
    return validation;
}

bool Board::rightDiagonalValidation(string argCurrentPiece, string argNewPosition, char argPlayer)
{
    bool validation = false;
    string convertOld = convertCoordinates(argCurrentPiece);
    int oldRow = stoi(convertOld) / 10 % 10;
    int oldColumn = stoi(convertOld) % 10;

    int availableSpaces = 0;

    //Getting spaces able to move

    //Spaces from top right

    for (int i = 0; i <= 7; i++) {
        cout << m_board[oldRow + i][oldColumn - i] << " ";
        if ((oldColumn - i > 0) && (oldRow + i < 8)) {
            if (m_board[oldRow + i][oldColumn - i] == 'B' || m_board[oldRow + i][oldColumn - i] == 'W') {
                availableSpaces++;
            }
        }
        else {
            break;
        }
    }

    //Spaces from bottom Left

    for (int i = 1; i <= 7; i++) {
        cout << m_board[oldRow - i][oldColumn + i] << " ";
        if ((oldRow - i > 0) && (oldColumn + i < 8)) {
            if (m_board[oldRow - i][oldColumn + i] == 'B' || m_board[oldRow - i][oldColumn + i] == 'W') {
                availableSpaces++;
            }
        }
        else {
            break;
        }
    }


    string convertNew = convertCoordinates(argNewPosition);
    int newRow = stoi(convertNew) / 10 % 10;
    int newColumn = stoi(convertNew) % 10;

    //Checking top right

    for (int i = 1; i <= availableSpaces; i++) {

        //Checking to see if piece is being blocked
        if ((i < availableSpaces) && (m_board[oldRow + i][oldColumn - i] == '.' || m_board[oldRow + i][oldColumn - i] == argPlayer)) {
            cout << m_board[oldRow + i][oldColumn - i] << " ";
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if ((availableSpaces == i) && ((oldColumn - availableSpaces) == newColumn) && (oldRow + availableSpaces == newRow)
            && (m_board[oldRow + i][oldColumn - i] == '.' || m_board[oldRow + i][oldColumn - i] == 'W')) {
            cout << m_board[oldRow + i][oldColumn - i] << " valid";
            validation = true;
        }
        //Block happened
        else {
            cout << m_board[oldRow + i][oldColumn - i] << " invalid";
            validation = false;
            break;
        }
    }

    //Checking bottom left

    for (int i = 1; i <= availableSpaces; i++) {

        //Checking to see if piece is being blocked
        if ((i < availableSpaces) && (m_board[oldRow - i][oldColumn + i] == '.' || m_board[oldRow - i][oldColumn + i] == argPlayer)) {
            cout << m_board[oldRow - i][oldColumn + i] << " ";
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if ((availableSpaces == i) && ((oldColumn + availableSpaces) == newColumn) && (oldRow - availableSpaces == newRow)
            && (m_board[oldRow - i][oldColumn + i] == '.' || m_board[oldRow - i][oldColumn + i] == 'W')) {
            cout << m_board[oldRow - i][oldColumn + i] << " valid";
            validation = true;
        }
        //Block happened
        else {
            cout << m_board[oldRow - i][oldColumn + i] << " invalid";
            validation = false;
            break;
        }
    }

    if (validation == false) {
        cout << " invalid";
    }
    cout << endl;
    return validation;
}

bool Board::leftDiagonalValidation(string argCurrentPiece, string argNewPosition, char argPlayer)
{
    bool validation = false;
    string convertOld = convertCoordinates(argCurrentPiece);
    int oldRow = stoi(convertOld) / 10 % 10;
    int oldColumn = stoi(convertOld) % 10;

    int availableSpaces = 0;

    //Getting spaces able to move

    //Spaces from top right

    for (int i = 0; i <= 7; i++) {
        cout << m_board[oldRow - i][oldColumn - i] << " ";
        if ((oldColumn - i >= 0) && (oldRow - i >= 0)) {
            if (m_board[oldRow - i][oldColumn - i] == 'B' || m_board[oldRow - i][oldColumn - i] == 'W') {
                availableSpaces++;
            }
        }
        else {
            break;
        }
    }

    //Spaces from bottom Left

    for (int i = 1; i <= 7; i++) {
        cout << m_board[oldRow + i][oldColumn + i] << " ";
        if ((oldColumn + i <= 7) && (oldRow + i <= 7)) {
            if (m_board[oldRow + i][oldColumn + i] == 'B' || m_board[oldRow + i][oldColumn + i] == 'W') {
                availableSpaces++;
            }
        }
        else {
            break;
        }
    }

    string convertNew = convertCoordinates(argNewPosition);
    int newRow = stoi(convertNew) / 10 % 10;
    int newColumn = stoi(convertNew) % 10;

    //Checking top right

    for (int i = 1; i <= availableSpaces; i++) {
        cout << m_board[oldRow - i][oldColumn - i] << " ";
        //Checking to see if piece is being blocked
        if ((i < availableSpaces) && (m_board[oldRow - i][oldColumn - i] == '.' || m_board[oldRow - i][oldColumn - i] == argPlayer)) {
            
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if ((availableSpaces == i) && ((oldColumn + (availableSpaces + 1)) == newColumn) && (oldRow - (availableSpaces + 1) == newRow)
            && (m_board[oldRow - i][oldColumn - i] == '.' || m_board[oldRow - i][oldColumn - i] == 'W')) {
            cout << " valid";
            validation = true;
        }
        //Block happened
        else {
            cout << " invalid";
            validation = false;
            break;
        }
    }

    cout << endl;

    //Checking bottom left

    for (int i = 1; i <= availableSpaces; i++) {
        cout << m_board[oldRow + i][oldColumn + i] << " ";

        //Checking to see if piece is being blocked
        if ((i < availableSpaces) && (m_board[oldRow + i][oldColumn + i] == '.' || m_board[oldRow + i][oldColumn + i] == argPlayer)) {
            
        }
        //Check max space to see if the piece is placeable. Check to see max loop is met,
        //the piece of current position matches the position of the new position, And sees
        //if the final piece is empty or able to remove oppsite color
        else if ((availableSpaces == i) && ((oldColumn + availableSpaces) == newColumn) && (oldRow + availableSpaces == newRow)
            && (m_board[oldRow + i][oldColumn + i] == '.' || m_board[oldRow + i][oldColumn + i] == 'W')) {
            cout << " valid";
            validation = true;
        }
        //Block happened
        else {
            cout << " invalid";
            validation = false;
            break;
        }
    }

    if (validation == false) {
        cout << " invalid";
    }

    cout << endl;
 
    return validation;

}

void Board::movePiece(string CurrentPiece, string NewPosition, char argPlayer) {

    //Logic to see if the piece choosen is moveable
        //See if the position has a piece  
            //See if the piece is the correct color

    //Logic to see if the selected Position is allowable
        //Horizontal check
            //Being blocked by another color?
        //Vertical Check
            //Being blocked by other color?
        //Diagonal Check
            //Being blocked by other color?

}


// Converts coordinates that user put in into numbers
// and where they would be placed into the grid
string Board::convertCoordinates(string argCoordinates)
{
    int convertedLetter = (argCoordinates[0] - 'A');
    int convertedNumber = 8 - (argCoordinates[1] - '0');

    string combine;
    stringstream ss;

    ss << convertedLetter;
    ss << convertedNumber;
    ss >> combine;

    cout << "running function convertCoordinates: " << combine << endl;

        return combine;
}
