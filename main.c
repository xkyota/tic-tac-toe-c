#include <stdio.h> 
#include <stdlib.h> // For exit() function to  stop the while loop

char playBoard[3][3] = { 
    {' ', ' ', ' '}, 
    {' ', ' ', ' '}, 
    {' ', ' ', ' '}
}; 
int turns[3][3]; 
int whoseTurn = 1; 

void printBoard(char array[3][3])
{ 
    printf("\n"); 
    printf("  1   2   3\n"); 
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i + 1);
        for(int j = 0; j < 3; j++){ 
            printf("%c", array[i][j]);
            if (j < 2) printf(" | "); 
        }
        printf("\n");
        if (i < 2) printf(" -----------\n");
    }
    printf("\n"); 
}

void saveChoice(int x, int y, char playBoard[3][3]) {  
    playBoard[y][x] = (whoseTurn % 2 == 0) ? 'X' : 'O';  
    turns[y][x] = whoseTurn; 
}

void scanTurn() { 
    int x, y;

    while (1)
    { 
        printf("Player %c, enter your move (column row): ", (whoseTurn % 2 == 0) ? 'X' : 'O'); 
        scanf("%d %d", &x, &y); 

        x--; 
        y--;

        if (x >= 0 && x < 3 && y >= 0 && y < 3)
        { 
            if (playBoard[y][x] == ' ') 
            { 
                saveChoice(x, y, playBoard);
                whoseTurn++; 
                break; 
            } else 
            {
                printf("Cell is already taken! Try again.\n");
            }
        } else 
        {
            printf("Invalid move. Try again.\n");
        }
    }
}

void updateBoard(char playBoard[3][3]) 
{
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) 
        {
            if (turns[y][x] > 0) 
            {
                int age = (whoseTurn - turns[y][x]) / 2; 
                
                if (age == 2) 
                {  
                    if (playBoard[y][x] == 'X') playBoard[y][x] = 'x';
                    if (playBoard[y][x] == 'O') playBoard[y][x] = 'o';
                } 
                else if (age == 3) 
                {  
                    playBoard[y][x] = ' ';  
                    turns[y][x] = 0;  
                }
            }
        }
    }
}

void checkWin(char playBoard[3][3]) { 
    char winner = ' '; 

    //* Rows
    for (int i = 0; i < 3; i++) {
        if ((playBoard[i][0] == 'X' || playBoard[i][0] == 'x') &&
            (playBoard[i][1] == 'X' || playBoard[i][1] == 'x') &&
            (playBoard[i][2] == 'X' || playBoard[i][2] == 'x')) {
            winner = 'X';
        }
        if ((playBoard[i][0] == 'O' || playBoard[i][0] == 'o') &&
            (playBoard[i][1] == 'O' || playBoard[i][1] == 'o') &&
            (playBoard[i][2] == 'O' || playBoard[i][2] == 'o')) {
            winner = 'O';
        }
    }

    //* Columns
    for (int i = 0; i < 3; i++) {
        if ((playBoard[0][i] == 'X' || playBoard[0][i] == 'x') &&
            (playBoard[1][i] == 'X' || playBoard[1][i] == 'x') &&
            (playBoard[2][i] == 'X' || playBoard[2][i] == 'x')) {
            winner = 'X';
        }
        if ((playBoard[0][i] == 'O' || playBoard[0][i] == 'o') &&
            (playBoard[1][i] == 'O' || playBoard[1][i] == 'o') &&
            (playBoard[2][i] == 'O' || playBoard[2][i] == 'o')) {
            winner = 'O';
        }
    }

    //* Main diagonal
    if ((playBoard[0][0] == 'X' || playBoard[0][0] == 'x') &&
        (playBoard[1][1] == 'X' || playBoard[1][1] == 'x') &&
        (playBoard[2][2] == 'X' || playBoard[2][2] == 'x')) {
        winner = 'X';
    }
    if ((playBoard[0][0] == 'O' || playBoard[0][0] == 'o') &&
        (playBoard[1][1] == 'O' || playBoard[1][1] == 'o') &&
        (playBoard[2][2] == 'O' || playBoard[2][2] == 'o')) {
        winner = 'O';
    }

    //* Secondary diagonal
    if ((playBoard[0][2] == 'X' || playBoard[0][2] == 'x') &&
        (playBoard[1][1] == 'X' || playBoard[1][1] == 'x') &&
        (playBoard[2][0] == 'X' || playBoard[2][0] == 'x')) {
        winner = 'X';
    }
    if ((playBoard[0][2] == 'O' || playBoard[0][2] == 'o') &&
        (playBoard[1][1] == 'O' || playBoard[1][1] == 'o') &&
        (playBoard[2][0] == 'O' || playBoard[2][0] == 'o')) {
        winner = 'O';
    }

    if (winner != ' ') {
        printf("Player %c wins!\n", winner);
        exit(0); 
    }
}

int main(void) { 
    printBoard(playBoard);

    while (1) { 
        scanTurn();
        updateBoard(playBoard);
        printBoard(playBoard);
        checkWin(playBoard);
    }
    
    return 0; 
}
