# CS50 Final Project
## Mark Gitahi, Mark Gitau, Andrew Truong, Ryan Wu, CS50 Spring

### Functional decomposition modules into functions
We anticipate the following functions:
1. *main*, which parses the arguments and calls functions to either create or solve a puzzle

Functions for create:
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

Functions for create:
2. *create_sudoku*, when given command to "create", will form necessary structures, making use of *copy*, makes diagonals using *form_three*, use *compute* to fill in other 3x3 squares, and print out the resulting sudoku puzzle
3. *compute* fills in the 3x3 squares using *create*
4. *create* will attempt to find the set values for the 3x3 square with *form_three*
5. *form_three* attempts to find random values to fill in each point the the 3x3 square, using *is_valid* to see if a random value will work

