# CS50 Final Project
## Jeff Gitahi, Mark Gitau, Andrew Truong, Ryan Wu, CS50 Spring

### User Interface
Sudoku's interface is with the user on the command-line and with one command line argument
```
./sudoku create // to create a random Sudoku puzzle
```
```
./sudoku solve // to solve a random Sudoku puzzle
```

### Inputs and Outputs
Input: the only inputs are the command-line parameters; see the User Interface above.

Output: If command is to "create", a randomly-generated puzzle will be printed to `stdout`. If command is to "solve", puzzle with solution is printed to `stdout`.

## Pseudo-code for logic/algorithmic flow to create a sudoku puzzle
```
1. Execute from command-line as shown on user interface
2. Fill in the diagonal 3x3 squares with guarantee that these three WILL be valid
3. Save a copy of the puzzle containing diagonal fills
4. For each other 3x3 square not along the diagonal
  4.1 Attempt to make a 3x3 square there
  4.2 If valid 3x3 square cannot be found after many attempts, return to diagonally-filled puzzle and try again
```

### Functional decomposition modules into functions
We anticipate the following functions:
1. *main*, which parses the arguments and calls functions to either create or solve a puzzle
2. *clear*, which assigns all values in a matrix to zero, indicating an empty value
3. *is_valid*, checks that a number can be addded given row, column, and 3x3 values
4. *copy*, which copies all values in a matrix to another matrix
5. *form_three*, which attempts to create a 3x3
6. *create*, which will setup and create 3x3 through calling a series of functions
7. *compute*, which will create majority of puzzle through series of function calls
8. *create_sudoku*, which creates all variables and calls all functions to make entire sudoku puzzle

### Major data structures
1. *two-dimensional array* forming the puzzle
2. *array* holding numbers existent in a set area

### Dataflow through functions
We anticipate the following functions:
1. *main* parses the arguments and calls appropriate function given command; calls *create_sudoku* 
2. *create_sudoku*, when given command to "create", will form necessary structures, making use of *copy*, makes diagonals using *form_three*, use *compute* to fill in other 3x3 squares, and print out the resulting sudoku puzzle
3. *compute* fills in the 3x3 squares using *create*
4. *create* will attempt to find the set values for the 3x3 square with *form_three*
5. *form_three* attempts to find random values to fill in each point the the 3x3 square, using *is_valid* to see if a random value will work

### Testing Plan
- test that a sudoku puzzle forms within short amount of time
- test that sudoku puzzle is randomly-genertaed by making another and comparing
- test that sudoku puzzle can be solved within a short amount of time
- test that randomly-generated puzzle given to solver can be solved
