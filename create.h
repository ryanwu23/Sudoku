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
#define n 9

/**************** form_three ****************/
/* Fills in a 3x3 square in a 9x9 puzzle following sudoku rules
 *
 * We return:
 *  - false if a 3x3 square cannot be found after many attempts
 *  - true if a 3x3 square has been found
 */
 bool formThree(int puzzle[n][n], int startRow, int startCol);

/**************** create ****************/
/* Will attempt to restart the creation of forming a 3x3 if it fails
 * Contiuous restarts leads to indication that no possible 3x3 exists
 *
 * We return:
 *  - false if there are over 3000 failed attempts overall
 *  - true a 3x3 has been formed
 */
bool create(int puzzleCopy[n][n], int puzzle[n][n], int attempt[1][1], int startRow, int startCol);

/**************** compute ****************/
/* Will attempt to form 3x3 at all non-diagonal 3x3 squares
 *
 * We return:
 *  - false if there create indicates that there is failure
 *  - true all squares have been filled out
 */

bool compute(int originalPuzzle[n][n], int puzzle[n][n], int puzzleCopy[n][n], int attempt[1][1]);

/**************** check_uniqueness ****************/
/* Checks whether a given puzzle has one unique solution
 *
 * We return:
 * - false if there are other solutions
 * - true if there is only one unique solution
 */
bool checkUniqueness (int puzzle[n][n]);

/**************** take_num ****************/
/* Takes away  numbers from the puzzle to create a sudoku to be solved */
void takeNum(int puzzle[n][n]);

/**************** create_sudoku ****************/
/* Creates all variables and calls all functions to make entire sudoku puzzle */
int createSudoku();

 #endif // __CREATE_H
