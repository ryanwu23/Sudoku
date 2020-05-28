#ifndef __SOLVE_H
#define __SOLVE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h> 
#define n 9

bool findEmptySpace(int grid[n][n], int * row, int * column);
bool isValidInsert(int grid[n][n], int row, int col, int num);
bool isValidGrid(int grid[n][n]);
bool solveSudoku(int grid[n][n]);
void printGrid(int grid[n][n]);
void solve(void);

#endif