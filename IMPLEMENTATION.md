# Team Project, CS50 Spring 2020

## Andrew Truong, Jeff Gitahi, Mark Gitau, Ryan Wu

### Implementation Spec

### Modules

#### Common

Implemented in `common.c`, this module contains all the common functions used in both Create and Solve.

It consists of the following functions:

```c
/* Makes a copy of an original puzzle into a copy puzzle
 *
 * Caller provides:
 *  - valid two-dimensional array that is original puzzle
 *  - valid two-dimensional array that will have original values copied to
 */
 void copy(int puzzleCopy[n][n], int puzzle[n][n]);
 ```

 ```c
 /* Clears a puzzle by turning all of the values to 0
 *
 * Caller provides:
 *  - valid two-dimensional array that is puzzle which values will be made zero
 */
 void clear(int puzzle[n][n]);
 ```

 ```c
 /* Prints the sudoku puzzle to stdout */
 void printGrid(int grid[n][n]);
 ```

 ```c
 /* Determines if a number can be inserted at a (row, column) in a grid and follow sudoku rules */
bool isValidInsert(int grid[n][n], int row, int col, int num);
```

```c
/* Determines if a filled out puzzle is a valid puzzle that meets are the rules of a sudoku */
bool isValidPuzzle (int puzzle[n][n]);
```

```c
/* Reads a puzzle in from stdin and stores it in a two-dimensional array */
void readPuzzle (int input[n][n]);
```

#### Create

Implemented in `create.c`, this module creates an incomplete puzzle, but with a guaranteed unique solution.

It consists of the following functions (unique to the create module):

```c
/* Fills in a 3x3 square in a 9x9 puzzle following sudoku rules
 */
 bool formThree(int puzzle[n][n], int startRow, int startCol);
 ```

 ```c
 /* Will attempt to restart the creation of forming a 3x3 if it fails
 * Contiuous restarts leads to indication that no possible 3x3 exists
 */
bool create(int puzzleCopy[n][n], int puzzle[n][n], int attempt[1][1], int startRow, int startCol);
```

```c
/* Will attempt to form 3x3 at all non-diagonal 3x3 squares
 */

bool compute(int originalPuzzle[n][n], int puzzle[n][n], int puzzleCopy[n][n], int attempt[1][1]);
```

```c
/* Checks whether a given puzzle has one unique solution
 */
bool checkUniqueness (int puzzle[n][n]);
```

```c
/* Takes away  numbers from the puzzle to create a sudoku to be solved */
void takeNum(int puzzle[n][n]);
```

```c
/* Creates all variables and calls all functions to make entire sudoku puzzle */
int createSudoku();
```

The createSudoku function works as follows:

1. (TO BE FILLED IN)


#### Solve 

Implemented in `solve.c`, this module takes an incomplete grid and solves it.

It consists of the following functions (unique to the solve module):

```c
/* if it finds an empty space (0), it returns true. */
/* else, returns false  */

bool findEmptySpace(int grid[n][n], int * row, int * column);
```

```c
/* checks whether the grid follows sudoku rules. */
/* returns true if grid is valid, false otherwise. */

bool isValidGrid(int grid[n][n]);
```

```c
/* attempts to solve the sudoku puzzle. if solved, it returns true. false otherwise  */

bool solveSudoku(int grid[n][n]);
```

The solveSudoku function works as follows:

1. Try to find an empty space in the grid.  If no empty space, the puzzle has been solved (return)
2. For each number 1 - 9
    1. check if inserting that number is allowed. if allowed, insert it.
    2. check if that number leads to a solution by calling solveSudoku recursively. if it leads to a solution, stop.
    3. if it doesn't lead to a solution, replace that number with a 0 and try the next number.
3. return false - if it reaches this point it means there is no solution.


```c
/* reads grid, validates it and calls solveSudoku. */

void solve(void);
```

The solve function integrates all the modules into solving the puzzle.

#### Sudoku

Implemented in `sudoku.c`, this module takes cmand line arguments and calls the above mentioned modules accordingly.

* `create` generates an unsolved sudoku puzzle by calling `createSudoku`

* `solve` takes in an unsolved puzzle and solves it by calling `solve`

* `unique` takes in an unsolved puzzle and ckecks if it has a unique solution by calling `checkUniqueness`

* `valid` takes in a puzzle and checks if it obeys the rules of sudoku by calling `isValidGrid`

