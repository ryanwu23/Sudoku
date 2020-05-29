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

// Checks whether a number can be placed in the puzzle.
static bool is_valid (int row_seen[9], int column_seen[9], int square_seen[9], int random) {
    return (square_seen[random-1] == 0 && row_seen[random-1] == 0 && column_seen[random-1] == 0);
}

// Fixes occasional zero left behind in puzzle
// Puzzle in this case would have valid values, but zero is left
static void fix(int puzzle[9][9]) {

    for (int row = 0; row < 9; row++) {
        for (int column = 0; column < 9; column++) {
            
            // For zero case, find the value that fits into it
            if (puzzle[row][column] == 0) {
                for (int i = 1; i <=9; i++) {
                    if (isValidInsert(puzzle, row, column, i))
                        puzzle[row][column] = i;

                }      
                
            }
        }
    }


}

/**************** form_three ****************/
bool form_three(int puzzle[9][9], int row_start, int column_start) {
    int row_seen[9];
	int column_seen[9];
	int square_seen[9];
    
    // Assigns values to "seen" arrays to '0', indicating unseen
	for (int i = 0; i < 9; i++) {
		row_seen[i] = 0;
		column_seen[i] = 0;
		square_seen[i] = 0;

    }

    int value;
    int random;

    for (int row = row_start; row < (row_start + 3); row++) {
        
        // Gets all the values of numbers seen in the row
        for (int i = 0; i < 9; i++) {
            value = puzzle[row][i];

            if (value > 0)
                row_seen[value-1] = 1;
        }

        // Reset square_seen when at new 3x3 square
        if (row % 3 == 0) {
                for (int i = 0; i < 9; i++)
                    square_seen[i] = 0;
        }

        for (int column = column_start; column < column_start + 3; column++) {
            
            // Reset columns
            for (int i = 0; i < 9; i++) {
                column_seen[i] = 0;
            }

            // Gets all the values of numbers seen in the column
            for (int i = 0; i < 9; i++) {
                value = puzzle[i][column];
                if (value > 0)
                    column_seen[value-1] = 1;
            }

            // Picks a random number from 1-9
            random = (rand() % 9 ) + 1;    

            int bro_we_stuck = 0;

            // Keeps on trying to put in the random number
            while (!is_valid(row_seen, column_seen, square_seen, random)) {
                random = (rand() % 9 ) + 1;
                 bro_we_stuck++;

                 // Continuous failure indicates no appropriate value exists
                if (bro_we_stuck > 20) 
                    return false;

            }
            
            puzzle[row][column] = random;

            // Update "seen" arrays to show value just included 
            square_seen[random-1] = 1;
            row_seen[random-1] = 1;
            column_seen[random-1] = 1;

        }

        // Reset rows
        for (int i = 0; i < 9; i++) {
            row_seen[i] = 0;
        }

    }
    return true;
}

/**************** create ****************/
bool create(int copy_puzzle[9][9], int puzzle[9][9], int attempt[1][1], int row_start, int column_start) {
    copy(copy_puzzle, puzzle); 

    // Attempts to fill 3x3
    // Failure in attempt resets puzzle to make another, fresh attempt
    while (!form_three(puzzle, row_start, column_start)) {
        memcpy(puzzle, copy_puzzle, sizeof(int [9][9]));
        attempt[0][0]++;

        // Continuous failure indicates that no appropriate 3x3 exists
        if (attempt[0][0] > 3000)
            return false;
    }

    clear(copy_puzzle);

    return true;

}

/**************** compute ****************/
bool compute(int very_very_original_puzzle[9][9], int puzzle[9][9], int copy_puzzle[9][9], int attempt[1][1]) {
    attempt[0][0] = 0;

    // Second 3x3 on first row
    if (!create(copy_puzzle, puzzle, attempt, 0, 3))
        return false;
    
    // Third 3x3 on first row
    if (!create(copy_puzzle, puzzle, attempt, 0, 6))
        return false;
    
    // First 3x3 on second row
    if (!create(copy_puzzle, puzzle, attempt, 3, 0))
        return false;
    
    // Third 3x3 on second row
    if (!create(copy_puzzle, puzzle, attempt, 3, 6))
        return false;
    
    // First 3x3 on third row
    if (!create(copy_puzzle, puzzle, attempt, 6, 0))
        return false;

    // Second 3x3 on third row
    if (!create(copy_puzzle, puzzle, attempt, 6, 3))
        return false;

    return true;

}

/**************** check_uniqueness ****************/
bool check_uniqueness (int puzzle[9][9]){
    //get the number of missing spots
    int missing=0;
    for (int i=0; i<9; i++){
         for (int j=0; j<9; j++){
                if (puzzle[i][j]==0){
                    missing++;
                }
         }
    }
    //get the rows and cols for each missing one
    int row[missing]; // ex. row[1], col[1] corresponds with one 0 point
    int col[missing];
    int counter=0;
    for (int i=0; i<9; i++){
         for (int j=0; j<9; j++){
             if (puzzle[i][j]==0){
                    row[counter]=i;
                    col[counter]=j;
                    counter++;
             }
         }
    }
    if (missing==1 || missing==0){ //acounts for corner cases
        return true;
    }

    // get a completely solved puzzle as an example
    int solved[9][9];
    copy(solved, puzzle);
    if (!solveSudoku(solved)){ //if can't be solved, no solution so return false
        return false;
    }
    
    //search for another solution
    for (int i=0; i<missing; i++){ //for each missing spot
        for (int j=0; j<9; j++){ //try each potential number
            if (j!=solved[row[i]][col[i]]){ //skip over the number in solution
                int test[9][9];
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

/**************** take_num ****************/
void take_num(int puzzle[9][9]){
        int row;
        int col;
        int left=14;
        //loop through until 14 numbers are taken out
        while (left > 0){
            //get random row and col
            row = (rand() % 9 ); 
            col = (rand() % 9 );  
            if (puzzle[row][col]!=0){ //try to take out if position is non-zero
                int test[9][9];
                copy(test, puzzle);
                test[row][col]=0;
                if (check_uniqueness (test)){ //check uniqueness with the number replaced with a 0
                    puzzle[row][col]=0; //update actual puzzle with zero if it has unique solutions
                    left--; //one less to update
                }
            }
        }
}

/**************** create_sudoku ****************/
int create_sudoku() {
    srand(time(0)); // https://www.geeksforgeeks.org/generating-random-number-range-c/

    int puzzle[9][9];

    for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			puzzle[i][j] = 0;
	}

    // Complete diagonals
    form_three(puzzle, 0, 0);
    form_three(puzzle, 3, 3);
    form_three(puzzle, 6, 6);
    
    // Exact copy of diagonal puzzle — guaranteed to be valid
    int very_very_original_puzzle[9][9];
    copy(very_very_original_puzzle, puzzle);
    
    int copy_puzzle[9][9];
    int attempt[1][1];
    attempt[0][0] = 1;

    // Attempt to compute sudoku puzzle
    // If attempt fails, try again with original puzzle with diagonals filled
    while (!compute(very_very_original_puzzle, puzzle, copy_puzzle, attempt)) {
        copy(copy_puzzle, very_very_original_puzzle);
        copy(puzzle, very_very_original_puzzle);

    }

    fix(puzzle); // ensure no zeroes left behind

    take_num(puzzle); // remove values to form puzzle that would have unique solution

    // Print out the sudoku puzzle in desired form
    printGrid(puzzle);
    
    printf("\n");

    return 0;
}