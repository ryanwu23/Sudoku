/*
 * create.c - CS50 'create' module
 *
 * Mark Gitau, Jeff Gitahi, Andrew Truong, Ryan Wu, Spring 2020
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include "solve.h"
#include "common.h"
#define n 9

// Checks whether a number can be placed in the puzzle.
static bool isValid (int rowSeen[n], int colSeen[n], int squareSeen[n], int random) {
    return (squareSeen[random-1] == 0 && rowSeen[random-1] == 0 && colSeen[random-1] == 0);
}

// Fixes occasional zero left behind in puzzle
// Puzzle in this case would have valid values, but zero is left
static void fix(int puzzle[n][n]) {

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            
            // For zero case, find the value that fits into it
            if (puzzle[row][column] == 0) {

                for (int i = 1; i <=n; i++) {
                     
                    if (isValidInsert(puzzle, row, column, i)) {
                        puzzle[row][column] = i;
                    }
                        
                }      
                
            }
        }
    }
}

/**************** formThree ****************/
bool formThree(int puzzle[n][n], int startRow, int startCol) {
    int rowSeen[n];
	int colSeen[n];
	int squareSeen[n];
    
    // Assigns values to "seen" arrays to '0', indicating unseen
	for (int i = 0; i < n; i++) {
		rowSeen[i] = 0;
		colSeen[i] = 0;
		squareSeen[i] = 0;

    }

    int value;
    int random;

    for (int row = startRow; row < (startRow + 3); row++) {
        
        // Gets all the values of numbers seen in the row
        for (int i = 0; i < n; i++) {
            value = puzzle[row][i];

            if (value > 0)
                rowSeen[value-1] = 1;
        }

        // Reset squareSeen when at new 3x3 square
        if (row % 3 == 0) {
                for (int i = 0; i < n; i++)
                    squareSeen[i] = 0;
        }

        for (int column = startCol; column < startCol + 3; column++) {
            
            // Reset columns
            for (int i = 0; i < n; i++) {
                colSeen[i] = 0;
            }

            // Gets all the values of numbers seen in the column
            for (int i = 0; i < n; i++) {
                value = puzzle[i][column];
                if (value > 0)
                    colSeen[value-1] = 1;
            }

            // Picks a random number from 1-n
            random = (rand() % n ) + 1;    

            int stuck = 0;

            // Keeps on trying to put in the random number
            while (!isValid(rowSeen, colSeen, squareSeen, random)) {
                random = (rand() % n ) + 1;
                 stuck++;

                 // Continuous failure indicates no appropriate value exists
                if (stuck > 20) 
                    return false;

            }
            
            puzzle[row][column] = random;

            // Update "seen" arrays to show value just included 
            squareSeen[random-1] = 1;
            rowSeen[random-1] = 1;
            colSeen[random-1] = 1;

        }

        // Reset rows
        for (int i = 0; i < n; i++) {
            rowSeen[i] = 0;
        }

    }
    return true;
}

/**************** create ****************/
bool create(int puzzleCopy[n][n], int puzzle[n][n], int attempt[1][1], int startRow, int startCol) {
    copy(puzzleCopy, puzzle); 

    // Attempts to fill 3x3
    // Failure in attempt resets puzzle to make another, fresh attempt
    while (!formThree(puzzle, startRow, startCol)) {
        memcpy(puzzle, puzzleCopy, sizeof(int [n][n]));
        attempt[0][0]++;

        // Continuous failure indicates that no appropriate 3x3 exists
        if (attempt[0][0] > 3000)
            return false;
    }

    clear(puzzleCopy);

    return true;

}

/**************** compute ****************/
bool compute(int originalPuzzle[n][n], int puzzle[n][n], int puzzleCopy[n][n], int attempt[1][1]) {
    attempt[0][0] = 0;

    // Second 3x3 on first row
    if (!create(puzzleCopy, puzzle, attempt, 0, 3))
        return false;
    
    // Third 3x3 on first row
    if (!create(puzzleCopy, puzzle, attempt, 0, 6))
        return false;
    
    // First 3x3 on second row
    if (!create(puzzleCopy, puzzle, attempt, 3, 0))
        return false;
    
    // Third 3x3 on second row
    if (!create(puzzleCopy, puzzle, attempt, 3, 6))
        return false;
    
    // First 3x3 on third row
    if (!create(puzzleCopy, puzzle, attempt, 6, 0))
        return false;

    // Second 3x3 on third row
    if (!create(puzzleCopy, puzzle, attempt, 6, 3))
        return false;

    return true;

}

/**************** checkUniqueness ****************/
bool checkUniqueness (int puzzle[n][n]){
    //get the number of missing spots
    int missing=0;

    for (int i=0; i<n; i++){

         for (int j=0; j<n; j++){

            if (puzzle[i][j]==0){
                missing++;
            }
        }
    }


    //get the rows and cols for each missing one
    int row[missing]; // ex. row[1], col[1] corresponds with one 0 point
    int col[missing];
    int counter=0;

    for (int i=0; i<n; i++){

        for (int j=0; j<n; j++){

            if (puzzle[i][j]==0){
                row[counter]=i;
                col[counter]=j;
                counter++;
            }
        }
    }

    if (missing==1 || missing==0){  // acounts for corner cases
        return true;
    }

    // get a completely solved puzzle as an example
    int solved[n][n];

    copy(solved, puzzle);
    if (!solveSudoku(solved)){  // if can't be solved, no solution so return false
        return false;
    }
    
    //search for another solution
    for (int i = 0; i<missing; i++){ // for each missing spot

        for (int j=0; j<n; j++){ // try each potential number

            if (j!=solved[row[i]][col[i]]){ //skip over the number in solution

                int test[n][n];

                copy(test, puzzle);

                //try solving with new number
                if (isValidInsert(test,row[i], col[i], j)){

                    test[row[i]][col[i]]=j;

                    if (solveSudoku(test)){ //if it can be solved, return false
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/**************** takeNum ****************/
void takeNum(int puzzle[n][n]){
    int row;
    int col;
    int left = 40;

    //loop through until 45 numbers are taken out
    while (left > 0){

        //get random row and col
        row = (rand() % n ); 
        col = (rand() % n );  

        if (puzzle[row][col] != 0){ //try to take out if position is non-zero

            int test[n][n];

            copy(test, puzzle);

            test[row][col] = 0;
            
            if (checkUniqueness (test)){ //check uniqueness with the number replaced with a 0
                puzzle[row][col]=0; //update actual puzzle with zero if it has unique solutions
                left--; //one less to update
            }
        }
    }
}

/**************** createSudoku ****************/
int createSudoku() {
    srand(time(0)); // https://www.geeksforgeeks.org/generating-random-number-range-c/

    int puzzle[n][n];

    clear(puzzle);
    
    // Complete diagonals
    formThree(puzzle, 0, 0);
    formThree(puzzle, 3, 3);
    formThree(puzzle, 6, 6);
    
    // Exact copy of diagonal puzzle — guaranteed to be valid
    int originalPuzzle[n][n];
    copy(originalPuzzle, puzzle);
    
    int puzzleCopy[n][n];
    int attempt[1][1];
    attempt[0][0] = 1;

    // Attempt to compute sudoku puzzle
    // If attempt fails, try again with original puzzle with diagonals filled
    while (!compute(originalPuzzle, puzzle, puzzleCopy, attempt)) {
        copy(puzzleCopy, originalPuzzle);
        copy(puzzle, originalPuzzle);

    }

    fix(puzzle); // ensure no zeroes left behind

    takeNum(puzzle); // remove values to form puzzle that would have unique solution

    // Print out the sudoku puzzle in desired form
    printGrid(puzzle);
    
    return 0;
}