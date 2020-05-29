/* create.h - CS50 'create' module header file
 *
 * Mark Gitau, Jeff Gitahi, Andrew Truong, Ryan Wu, Spring 2020
 */

#ifndef __CREATE_H
#define __CREATE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include "solve.h"
#include "common.h"

/**************** form_three ****************/
/* Fills in a 3x3 square in a 9x9 puzzle following sudoku rules
 *
 * We return:
 *  - false if a 3x3 square cannot be found after many attempts
 *  - true if a 3x3 square has been found
 */
 bool form_three(int puzzle[9][9], int row_start, int column_start);

/**************** create ****************/
/* Will attempt to restart the creation of forming a 3x3 if it fails
 * Contiuous restarts leads to indication that no possible 3x3 exists
 *
 * We return:
 *  - false if there are over 3000 failed attempts overall
 *  - true a 3x3 has been formed
 */
bool create(int copy_puzzle[9][9], int puzzle[9][9], int attempt[1][1], int row_start, int column_start);

/**************** compute ****************/
/* Will attempt to form 3x3 at all non-diagonal 3x3 squares
 *
 * We return:
 *  - false if there create indicates that there is failure
 *  - true all squares have been filled out
 */

bool compute(int very_very_original_puzzle[9][9], int puzzle[9][9], int copy_puzzle[9][9], int attempt[1][1]);

bool check_uniqueness (int puzzle[9][9]);

void take_num(int puzzle[9][9]);

/**************** create_sudoku ****************/
/* Creates all variables and calls all functions to make entire sudoku puzzle */
int create_sudoku();

 #endif // __CREATE_H
