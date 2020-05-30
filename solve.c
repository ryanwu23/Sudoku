#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h> 
#include "common.h"

#define n 9


// function prototypes - see header files for more details.

bool findEmptySpace(int grid[n][n], int * row, int * column);
bool isValidInsert(int grid[n][n], int row, int col, int num);
bool isValidGrid(int grid[n][n]);
bool solveSudoku(int grid[n][n]);
void printGrid(int grid[n][n]);
void solve(void);


// reads puzzle, validates it, and attempts to solve it.
void solve(void){
      
    int input[n][n];

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			input[i][j] = 0;
        }
	}
        
    readPuzzle(input);  // read puzzle from stdin

    // attempt to solve the puzzle if input is valid
    if (isValidGrid(input)){

        if (! solveSudoku(input)){
            printf("Grid cannot be solved.\n");
        }

        printGrid(input);
    }
}


// finds an empty space in the grid

bool findEmptySpace(int grid[n][n], int *row, int *col){

    for (int i = 0; i < n;  i++){

        for (int j = 0; j < n;  j++){

            // if it is zero, it is an empty space
            if (grid[i][j] == 0){

                // save the row and column of the empty space
                *row = i ; *col = j;  
                return true;
            }
        }
    }
    return false;
}

// checks if the grid follows sudoku rules

bool isValidGrid(int grid[n][n]){

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){

            // validates only the non-zero entries
            if (grid[i][j] != 0){

                int temp = grid[i][j];

                if(! isValidInsert(grid, i, j, temp)){
                    fprintf(stderr, "Grid must follow sudoku rules: row %d col %d\n", i, j);
                    return false;
                }
            }
        }
    }
    return true;
}

// attempts to solve the puzzle with backtracking
bool solveSudoku(int grid[n][n]){
    int row, col;

    // if no empty space is found, we solved it
    if (! findEmptySpace(grid, &row, &col)){
        return true;
    }

    // attempt to insert numbers 1 - 9
    for (int i = 1; i <= n; i++){

        // check if inserting tht number is allowed
        if (isValidInsert(grid, row, col, i)){

            grid[row][col] = i;   // if allowed, insert it

            // if that number leads to a solution, great, stop.
            if (solveSudoku(grid)){
                return true;
            }

            // if it doesn't, replace that number with a 0 and try the next number
            grid[row][col] = 0;
        }
    }
    // if it gets here, there is no solution
    return false;
}