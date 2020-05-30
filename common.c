/*
 * common.c - CS50 'create' module
 *
 * Andrew Truong, Mark Gitau, Jeff Gitahi, Ryan Wu, Spring 2020
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


/**************** copy ****************/
void copy(int copy_puzzle[9][9], int puzzle[9][9]) {
    for (int row = 0; row < 9; row ++) {
		for (int column = 0; column < 9; column ++) 
				copy_puzzle[row][column] = puzzle[row][column];
	}
}

/**************** clear ****************/
void clear(int puzzle[9][9]) {
    for (int row = 0; row < 9; row ++) {
		for (int column = 0; column < 9; column ++) 
				puzzle[row][column] = 0;
	}
}

/**************** printGrid ****************/
void printGrid(int grid[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            fprintf(stdout, "%d ", grid[i][j]);
        }
        fprintf(stdout, "\n");
    }
}

/**************** isValidInsert ****************/
bool isValidInsert(int grid[9][9], int row, int col, int num){
    // check row (row is constant)
    for (int i = 0; i < 9; i++){
        if (i != col && grid[row][i] == num){
            return false;
        }
    }

    // check column (column is constant)
    for (int i = 0; i < 9; i++){
        if (i != row && grid[i][col] == num){
            return false;
        }
    }

    // check grid
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int i = startRow; i < startRow + 3; i++){
        for (int j = startCol; j < startCol + 3; j++){
            if (i != row && j != col &&  grid[i][j] == num){
                return false;
            }
        }
    }

    return true;

}

/**************** isValidPuzzle ****************/
bool isValidPuzzle (int puzzle[9][9]){
   //loop through each value in the puzzle
   for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            //if the value is 0 or if it doesn't meet the requirements of isValidInsert, then it's a non-valid puzzle
            if (!isValidInsert(puzzle, i, j, puzzle[i][j]) || puzzle[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

/**************** readPuzzle ****************/
void readPuzzle (int input[9][9]){
    int num;
    char c;
    int number_count = 0;
    int i = 0, j = 0;
    while ((c = fgetc(stdin)) != EOF && number_count < 81){
        if ((num = atoi(&c)) != 0){
            input[i][j] = num;
        }
        if (isdigit(c) != 0){
            if (j + 1 == 9){
                i++;
            }
            j = (j + 1) % 9;
        }
        
        if(isdigit(c)) 
            number_count++;   
        
    }
}