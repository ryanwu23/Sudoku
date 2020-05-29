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
        return create_sudoku();
    }
    else if (strcmp(argv[1], "solve") == 0) {
        solve();
    }

    else {
        fprintf(stderr, "Usage: follow command with \"create\" or \"solve\"\n");
        return 2;
    }

    return 0;
}