/* common.h - CS50 header file for common functions for sudoku puzzle
 *
 * Mark Gitau, Jeff Gitahi, Andrew Truong, Ryan Wu, Spring 2020
 */

#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define n 9

/**************** copy ****************/
/* Makes a copy of an original puzzle into a copy puzzle
 *
 * Caller provides:
 *  - valid two-dimensional array that is original puzzle
 *  - valid two-dimensional array that will have original values copied to
 */
 void copy(int puzzleCopy[n][n], int puzzle[n][n]);

/**************** clear ****************/
/* Clears a puzzle by turning all of the values to 0
 *
 * Caller provides:
 *  - valid two-dimensional array that is puzzle which values will be made zero
 */
 void clear(int puzzle[n][n]);

/**************** printGrid ****************/
/* Prints the sudoku puzzle to stdout */
 void printGrid(int grid[n][n]);

/**************** isValidInsert ****************/
/* Determines if a number can be inserted at a (row, column) in a grid and follow sudoku rules */
bool isValidInsert(int grid[n][n], int row, int col, int num);

/**************** isValidPuzzle ****************/
/* Determines if a filled out puzzle is a valid puzzle that meets are the rules of a sudoku */
bool isValidPuzzle (int puzzle[n][n]);

/**************** readPuzzle ****************/
/* Reads a puzzle in from stdin and stores it in a two-dimensional array */
void readPuzzle (int input[n][n]);

 #endif