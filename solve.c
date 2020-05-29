#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h> 
#include "common.h"

#define n 9

bool findEmptySpace(int grid[n][n], int * row, int * column);
bool isValidInsert(int grid[n][n], int row, int col, int num);
bool isValidGrid(int grid[n][n]);
bool solveSudoku(int grid[n][n]);
void printGrid(int grid[n][n]);
void solve(void);



void solve(void){
      
    int input[n][n] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
                       
    int num;
    char c;
    int number_count = 0;
    int i = 0, j = 0;
    while ((c = fgetc(stdin)) != EOF && number_count < 81){
        if ((num = atoi(&c)) != 0){
            input[i][j] = num;
        }
        if (isdigit(c) != 0){
            if (j + 1 == n){
                i++;
            }
            j = (j + 1) % n;
        }
        
        if(isdigit(c)) 
            number_count++;   
        
    }

    if (isValidGrid(input)){
        if (! solveSudoku(input)){
            printf("Grid cannot be solved.\n");
        }
        printGrid(input);
    }

}


bool findEmptySpace(int grid[n][n], int *row, int *col){
    for (int i = 0; i < n;  i++){
        for (int j = 0; j < n;  j++){
            if (grid[i][j] == 0){
               *row = i ; *col = j; 
               return true;
            }
        }
    }
    return false;
}

bool isValidGrid(int grid[n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] != 0){
                int temp = grid[i][j];
                if(! isValidInsert(grid, i, j, temp)){
                    fprintf(stderr, "Grid must follow sudoku rules %d %d = %d\n", i, j, temp);
                    return false;
                }
            }
            if (grid[i][j] < 0){
                fprintf(stderr, "Grid cannot have negative numbers.\n");
                return false;

        
            }
            if (grid[i][j] > 9){
                fprintf(stderr, "Grid cannot have numbers > 9.\n");
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[n][n]){
    int row, col;

    // if no empty space is found, we solved it
    if (! findEmptySpace(grid, &row, &col)){
        return true;
    }

    for (int i = 1; i <= n; i++){
        if (isValidInsert(grid, row, col, i)){
            grid[row][col] = i;
            if (solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}