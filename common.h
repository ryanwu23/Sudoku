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

/**************** copy ****************/
/* Makes a copy of an original puzzle into a copy puzzle
 *
 * Caller provides:
 *  - valid two-dimensional array that is original puzzle
 *  - valid two-dimensional array that will have original values copied to
 */
 void copy(int copy_puzzle[9][9], int puzzle[9][9]);

/**************** clear ****************/
/* Clears a puzzle by turning all of the values to 0
 *
 * Caller provides:
 *  - valid two-dimensional array that is puzzle which values will be made zero
 */
 void clear(int puzzle[9][9]);

/**************** printGrid ****************/
/* Prints the sudoku puzzle to stdout */
 void printGrid(int grid[9][9]);

/**************** isValidInsert ****************/
/* Determines if a number can be inserted at a (row, column) in a grid and follow sudoku rules */
bool isValidInsert(int grid[9][9], int row, int col, int num);

/**************** isValidPuzzle ****************/
/* Determines if a filled out puzzle is a valid puzzle that meets are the rules of a sudoku */
bool isValidPuzzle (int puzzle[9][9]);

 #endif