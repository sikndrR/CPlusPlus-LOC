# C++ Game Project

## Data Structures and Classes

### Classes
- **Tournament**: Manages tournament statistics, displays winners, and handles serialization for saved games.
- **Round**: Tracks round scores, decides the starting player via a coin flip, manages player turns, and handles input validation.
- **Player**: Stores strategies, player characteristics (color, total pieces, score, etc.), and keeps track of pieces.
- **Human**: Derived from `Player`, handles user input validation.
- **Computer**: Derived from `Player`, finds and executes strategies.
- **BoardView**: Displays the game board.
- **Board**: Validates movement, checks for win conditions, modifies the board state, and converts user-readable coordinates to game coordinates.

### Data Structures
- **Player**:
  - `p_pieces`: List of current player's pieces on the board.
  - `p_newpos`: List of potential new positions for pieces.
  - `allStrats`: Contains all found strategies.
- **Board**:
  - `b_visited`: Tracks pieces for win condition logic.

### Algorithms
- **Depth-First Search (DFS)**:
  - Used to determine the win condition. The algorithm recursively checks connected pieces of the same color and tracks visited pieces. If the total visited matches the board's piece count, the player wins.

## Development Log

### Feb 3 - Board Initialization
- Created an 8x8 board and displayed it using `BoardView`.
- **Time Spent**: 2 hours.

### Feb 4 - Menu and Coin Toss Setup
- Added menu options (Human vs. Human, Human vs. Computer, Serialization, Exit) and coin toss logic.
- **Time Spent**: 1.5 hours.

### Feb 5 - Player Input Validation
- Ensured player input was a two-character string (A-H and 1-8).
- **Time Spent**: 1 hour.

### Feb 6 - Piece and Movement Validation
- Implemented piece selection validation and split movement validation into four directional functions.
- **Time Spent**: 2.5 hours.

### Feb 7 - Coin Toss and Player Swap
- Updated coin toss to return a player pointer and implemented player swapping logic.
- **Time Spent**: 45 minutes.

### Feb 8 - Design Changes
- Modified class hierarchy to avoid circular dependencies.
- **Time Spent**: 1 hour.

### Feb 9 - Input Conversion
- Created functions to convert user input into board-readable data.
- **Time Spent**: 1.5 hours.

### Feb 10 - Win Condition Design
- Designed win condition using a recursive function with a static counter.
- **Time Spent**: 2 hours.

### Feb 12 - Movement Issues
- Fixed diagonal movement and hardcoded color checks.
- **Time Spent**: 1 hour.

### Feb 16 - Saving and Serialization
- Implemented game saving at the end of rounds and serialized game state restoration.
- **Time Spent**: 4 hours.

### Feb 17 - Win Condition Fix
- Resolved issues with the win condition by modifying the visited pieces counter.
- **Time Spent**: 1 hour.

### Feb 18-20 - Strategy Implementation
- Added strategies such as thwarting, delay, capture, and blocking.
- **Time Spent**: 5.5 hours.

### Feb 21-22 - Strategy Redesign
- Replaced text file-based strategies with vector storage and restructured strategy logic.
- **Time Spent**: 4 hours.

## Screenshots
![image](https://github.com/user-attachments/assets/56b18a38-ca6f-43b3-8638-680af732b72e)
![image](https://github.com/user-attachments/assets/cb353698-9987-40b3-99db-cb1b1689e5ca)
![image](https://github.com/user-attachments/assets/68031d02-3bb0-4185-8d44-0d9d92e6acd8)



