# Tic-Tac-Toe Game with Minimax Algorithm
Overview
This is a command-line implementation of the classic Tic-Tac-Toe game. The project features a single-player mode where the user competes against an intelligent computer opponent powered by the Minimax algorithm. The game includes functionality to handle user input, determine game outcomes, and ensure fair gameplay.


# Features
1.Single-Player Mode: Play against an AI that makes optimal moves.
2.Minimax Algorithm: Ensures the computer always plays its best move.
3.Interactive Gameplay: Users can make moves by selecting positions (1-9).
4.Dynamic Board Display: The game board is updated after every move.
5.Game Outcome: Declares a winner or a draw at the end of the game.
6.User-Friendly Interface: Clear instructions and intuitive design.

# How to Play
1.Run the program in any C++ compiler.
2.Choose whether to start first or let the computer make the first move.
3.Select a cell (1-9) for your move as prompted.
4.The game continues until there's a winner or a draw.
5.The game declares the winner or announces a draw based on the outcome.

# Rules
1.The game is played on a 3x3 grid.
2.Players take turns to place their symbol (X for the human, O for the computer).
3.The first player to align three symbols horizontally, vertically, or diagonally wins.
4.If all nine cells are filled and no player has three symbols in a row, the game ends in a draw.

# Technologies Used
C++: Programming language used for implementation.
Minimax Algorithm: For implementing AI-based decision-making.


# Code Highlights
Minimax Algorithm: Determines the best possible move for the computer at each turn. 

Game Logic: Checks rows, columns, and diagonals for a winner.
Dynamic Board Management: Updates and displays the game board in real time.



# How to Run
1.Clone this repository:
git clone https://github.com/Giri8185/tic_tac_toe.git

2.Navigate to the project directory:
cd tic-tac-toe-ai

3.Compile the program:
g++ tic-tac-toe.cpp -o tic-tac-toe

4.Run the game:
./tic-tac-toe
