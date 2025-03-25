# Tic-Tac-Toe with Vanishing Symbols

## Overview

This project is a unique take on the classic Tic-Tac-Toe game, introducing **vanishing symbols** as an additional challenge. In this version, each placed symbol lasts for **only 3 turns** before disappearing. This dynamic element forces players to think strategically and adapt their approach to secure a win before their symbols vanish.

## Features

- **Two-player gameplay**
- **3×3 board representation** using a 2D array
- **Turn-based mechanics**, where players take turns placing their symbols (`X` or `O`)
- **Vanishing symbols**: A placed symbol lasts only for **3 turns** before fading (indicated by a lowercase letter: `x` or `o`), and disappears completely on the **4th turn**
- **Win detection** for horizontal, vertical, and diagonal victories
- **Draw detection** when the board is full and no player has won
- **Pointer arithmetic usage** for efficient board updates

## How to Play

1. **Players take turns** placing their symbols (`X` or `O`) by entering a column and row number.
2. **Each symbol remains for 3 turns** before changing to a lowercase (`x` or `o`) on the third turn.
3. **On the 4th turn**, the symbol disappears from the board.
4. The game **checks for a winner** after each move.
5. If a player aligns **three symbols in a row (horizontally, vertically, or diagonally)**, they win!
6. If the board fills up without a winner, the game ends in a **draw**.

## Compilation and Execution

To compile and run the program, use the following commands:

```sh
# Compile the program
gcc main.c -o main.o

# Run the executable
./main.o
```

## Code Breakdown

- **`printBoard()`**: Displays the current state of the board.
- **`scanTurn()`**: Handles user input and ensures valid moves.
- **`saveChoice()`**: Records the player’s move on the board.
- **`updateBoard()`**: Updates the board, applying the **vanishing symbol logic**.
- **`checkWin()`**: Determines if a player has won.
- **`main()`**: Controls the game loop, alternating turns until a win or draw condition is met.

## Future Improvements

- Implement AI for a **single-player mode**
- Add a **graphical user interface (GUI)**
- Introduce a **timer-based vanishing effect** for real-time gameplay

Enjoy the challenge of **Tic-Tac-Toe with Vanishing Symbols**!
