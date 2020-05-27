/*
 * create.c - CS50 'create' module
 *
 * Andrew Truong, Mark Gitau, Jeff Gitahi, Spring 2020
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

// Checks whether a number can be placed in the puzzle.
bool is_valid (int row_seen[9], int column_seen[9], int square_seen[9], int random) {
    return (square_seen[random-1] == 0 && row_seen[random-1] == 0 && column_seen[random-1] == 0);
}

// Makes a copy of an original puzzle
void copy(int copy_puzzle[9][9], int puzzle[9][9]) {
    for (int row = 0; row < 9; row ++) {
		for (int column = 0; column < 9; column ++) 
				copy_puzzle[row][column] = puzzle[row][column];
	}
}

// Clears a puzzle by turning all of the values to 0
void clear(int puzzle[9][9]) {
    for (int row = 0; row < 9; row ++) {
		for (int column = 0; column < 9; column ++) 
				puzzle[row][column] = 0;
	}
}

// Fills in 3x3 area whilst following sudoku puzzle rules
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

// Fills out a 3x3 block inside the puzzle
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

// Creates the filled-out puzzle from one with diagonals filled
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

    // Print out the sudoku puzzle in desired form
    for (int row = 0; row < 9; row ++) {
		for (int column = 0; column < 9; column ++) {
				printf("%i ", puzzle[row][column]);
		}
		printf("\n");

	}

    return 0;
}

int main() {
    return create_sudoku();
}
