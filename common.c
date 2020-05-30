/*
 * common.c - contains common functions used in 'solve.c' and 'create.c'
 *
 * Andrew Truong, Mark Gitau, Jeff Gitahi, Ryan Wu, CS50 Spring 2020
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define n 9


/************copy() - makes a copy of a grid*************************/

void copy(int puzzleCopy[n][n], int puzzle[n][n]) {

    for (int row = 0; row < n; row ++) {
		for (int column = 0; column < n; column ++) 
				puzzleCopy[row][column] = puzzle[row][column];
	}
}

/**************clear() - clears a grid by zeroing it out************/

void clear(int puzzle[n][n]) {

    for (int row = 0; row < n; row ++) {
		for (int column = 0; column < n; column ++) 
				puzzle[row][column] = 0;
	}
}


/**********printGrid() - prints the given grid to stdout**************/

void printGrid(int grid[n][n]){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fprintf(stdout, "%d ", grid[i][j]);
        }
        fprintf(stdout, "\n");
    }
}


/********isValidInsert() - checks whether inserting a number in a certain location is legal*********/

bool isValidInsert(int grid[n][n], int row, int col, int num){

    // check if the number exists elsewhere in the same row
    for (int i = 0; i < n; i++){
        if (i != col && grid[row][i] == num){
            return false;
        }
    }

    // check if the number exists elsewhere in the same column
    for (int i = 0; i < n; i++){
        if (i != row && grid[i][col] == num){
            return false;
        }
    }

    // check if the number exists elsewhere in the 3 x 3 grid

    int startRow = row - (row % 3);  // starting row of the 3 x 3 grid
    int startCol = col - (col % 3);  // starting column of the 3 x 3 grid

    for (int i = startRow; i < startRow + 3; i++){
        for (int j = startCol; j < startCol + 3; j++){
            if (i != row && j != col &&  grid[i][j] == num){
                return false;
            }
        }
    }

    return true;

}

/********isValidPuzzle() - checks whether all the numbers in the grid obey sudoku rules*********/

bool isValidPuzzle (int puzzle[n][n]){

   //loop through each value in the puzzle
   for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            //if the value is 0 or if it doesn't meet the requirements of isValidInsert, then it's a non-valid puzzle
            if (!isValidInsert(puzzle, i, j, puzzle[i][j]) || puzzle[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

/***********readPuzzle() - reads in a grid from stdin****************/

void readPuzzle (int input[n][n]){

    int num; // number that has been read
    char c; 
    int numCount = 0;   // count of numbers read so far

    int i = 0, j = 0;  // row and column

    while ((c = fgetc(stdin)) != EOF && numCount < (n * n)){

        // if it's an integer, insert it in input[i][j]
        if ((num = atoi(&c)) != 0){
            input[i][j] = num;
        }

        // if we have read a digit in the last column, increment row and wrap column back to 0
        if (isdigit(c) != 0){
            if (j + 1 == n){
                i++;
            }
            j = (j + 1) % n;

            numCount++; // increment number of numbers read so far
        } 
    }
}