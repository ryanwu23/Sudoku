/*
 * sudoku.c - CS50 sudoku puzzle
 *
 * Andrew Truong, Mark Gitau, Jeff Gitahi, Ryan Wu, Spring 2020
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include "create.h"
#include "solve.c"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: Must include one argument\n");
        return 1;
    }

    // Sudoku can either create a sudoku puzzle or solve a puzzle depending on user's argument
    if (strcmp(argv[1], "create") == 0) {
        return createSudoku();
    }
    else if (strcmp(argv[1], "solve") == 0) {
        solve();
    }

    // If user wants to check uniqueness or validity of a puzzle
    // Used for testing
    else if (strcmp(argv[1], "unique") == 0) {

        // Initialize puzzle from stdin
        int puzzle[9][9];
        clear(puzzle);
        readPuzzle(puzzle);

        if (checkUniqueness(puzzle))
            printf("Puzzle is unique.\n");
        else   
            printf("Puzzle is not unique.\n");
    }
    else if (strcmp(argv[1], "valid") == 0) {

        // Initilialize puzzle from stdin
        int puzzle[9][9];
        clear(puzzle);
        readPuzzle(puzzle);
        
        if (isValidPuzzle(puzzle))
            printf("Puzzle is valid.\n");
        else   
            printf("Puzzle is not valid.\n");
    }

    // For when command given is not valid
    else {
        fprintf(stderr, "Usage: follow command with \"create\", \"solve\", \"unique\", or \"valid\"\n");
        return 2;
    }

    return 0;
}