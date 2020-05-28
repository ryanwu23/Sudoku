# CS50 Final Project
## Jeff Gitahi, Mark Gitau, Andrew Truong, Ryan Wu, CS50 Spring

### User Interface
Sudoku's interface is with the user on the command-line and with one command line argument
To create a random Sudoku puzzle:
```
./sudoku create
```
To solve a random Sudoku puzzle:
```
./sudoku solve
```

### Inputs and Outputs
Input: the inputs are the command-line parameters (see the User Interface above) and stdin for solving (give a sudoku to solve)

Output: If command is to "create", a randomly-generated puzzle will be printed to `stdout`. If command is to "solve", puzzle with solution is printed to `stdout`.

### Pseudo-code for logic/algorithmic flow to create a sudoku puzzle
### create
```
1. Execute from command-line as shown on user interface
2. Fill in the diagonal 3x3 squares with guarantee that these three WILL be valid
3. Save a copy of the puzzle containing diagonal fills
4. For each other 3x3 square not along the diagonal
  4.1 Attempt to make a 3x3 square there
  4.2 If valid 3x3 square cannot be found after many attempts, return to diagonally-filled puzzle and try again
5. Repeat removal process until 14 values has been removed
  5.1 Find random point in two-dimensional array to remove
  5.2 If unique solution exists if this value is removed, remove it
```
### solve
```
1. Execute from the command -line as shown on user interface
2. Generate a 9x9 sudoku grid using a two dimensional array initialised to all 0s
3. Read from stdin and populate the grid with the given numbers 
4. check if the sudoku grid is valid before trying to solve it 
  4.1 check that there are no similar numbers in the same row column or square
  4.2 check that there are no negative numbers
  4.3 check that the range of numbers is 1-9
5. solve the sudoku
  5.1 find if there is any empty space in the grid
  5.2 try and insert numbers starting from 1-9
    5.2.1 if the insert is valid ( i.e. follows the sudoku rules)
      5.2.2 recursively call the solve function
    5.2.3 if the insert is not valid reassign space back to empty
 6. print the grid to stdout
    
```


### Functional decomposition modules into functions
We anticipate the following functions:
1. *main*, which parses the arguments and calls functions to either create or solve a puzzle
#### Decomposition into create
1. *clear*, which assigns all values in a matrix to zero, indicating an empty value
2. *is_valid*, checks that a number can be addded given row, column, and 3x3 values
3. *copy*, which copies all values in a matrix to another matrix
4. *form_three*, which attempts to create a 3x3
5. *create*, which will setup and create 3x3 through calling a series of functions
6. *compute*, which will create majority of puzzle through series of function calls
7. *create_sudoku*, which creates all variables and calls all functions to make entire sudoku puzzle

#### Decomposition into solve
1. *findEmptySpace* which finds an empty space in the grid 
2. *isValidInsert* which checks if a number can be inserted into a particular position following sudoku rules
3. *isValidGrid* checks wether the grid is valid, i.e. no negative numbers, within range and rules observed
4. *solveSudoku* recursuvely tries to solve the sudoku and backtracks until the grid is solved fully 
5. *printGrid* prints the grid out in the given format 
6. *solve* which creates the two-dimensional array, reads stdin and calls the other functions


### Major data structures
1. *two-dimensional array* forming the puzzle
2. *array* holding numbers existent in a set area

### Dataflow through functions
We anticipate the following functions:
1. *main* parses the arguments and calls appropriate function given command; calls *create_sudoku* when told to create
#### Dataflow through create
1. *create_sudoku*, when given command to "create", will form necessary structures, making use of *copy*, makes diagonals using *form_three*, use *compute* to fill in other 3x3 squares, and print out the resulting sudoku puzzle
2. *compute* fills in the 3x3 squares using *create*
3. *create* will attempt to find the set values for the 3x3 square with *form_three*
4. *form_three* attempts to find random values to fill in each point the the 3x3 square, using *is_valid* to see if a random value will work

#### Dataflow through solve
1.  *solve* when given command to "solve", will create a two dimensional array, read from stdin (reading only numbers) and populate the grid to form the sudoku grid; calls *isValidGrid* to confirm that the grid does not have any errors; calls *solveSudoku* to find a solution and *printGrid* to print the grid to stdout
2.  *solveSudoku*  recieves a grid with empty spaces; recursuvely tries to solve the sudoku and backtracks until the grid is solved fully; calls *isValidInsert* on numbers 1-9 trying to add them to the grid and backtracks on dead end;  
2. *isValidInsert* which checks if a number can be inserted into a particular position following sudoku rules; checks the row if then number is already there, then the column, then the square and returns true if the number can be inserted
3. *isValidGrid* checks wether the grid is valid; checks that the grid has no negative numbers, checks that all the numbers fall within range 1-9; calls *isValidInsert* on the number in the position if not 0 and checks whether it exists in the row, column or square
5. *printGrid* prints the grid out in the given format 


### Testing Plan
- test that a sudoku puzzle forms within short amount of time
- test that sudoku puzzle is randomly-genertaed by making another and comparing
- test that sudoku puzzle can be solved within a short amount of time
- test that randomly-generated puzzle given to solver can be solved
- test that the sudoku solve can handle edge cases such as negative numbers in the grid/ numbers >9/<1
