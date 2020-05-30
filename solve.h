#ifndef __SOLVE_H
#define __SOLVE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h> 
#include "common.h"
#define n 9

/************** findEmptySpace()**********************/
/* if it finds an empty space (0), it returns true. */
/* else, returns false  */

bool findEmptySpace(int grid[n][n], int * row, int * column);


/****************isValidGrid() ************************/
/* checks whether the grid follows sudoku rules. */
/* returns true if grid is valid, false otherwise. */

bool isValidGrid(int grid[n][n]);

/**************** solveSudoku() *************************/
/* attempts to solve the sudoku puzzle. if solved, it returns true. false otherwise  */

bool solveSudoku(int grid[n][n]);


/************************* solve() *************************/
/* reads grid, validates it and calls solveSudoku. */

void solve(void);

#endif