# Team Project, CS50 Spring 2020

## Andrew Truong, Jeff Gitahi, Mark Gitau, Ryan Wu

### Sudoku

The objective of the Sudoku puzzle is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that compose the grid contain all of the digits from 1 to 9.

### Compiling

The user should type `make` on the command line, ensuring that they are in the correct directory.
To perform unit and fuzz tests, type `make test`.

## Usage

`./sudoku COMMAND`

where `COMMAND` represents one of four commands:

* `create` which generates an unsolved sudoku puzzle;

* `solve` which takes in an unsolved puzzle and solves it;

* `unique` which takes in an unsolved puzzle and ckecks if it has a unique solution;

* `valid` which takes in a puzzle and checks if it obeys the rules of sudoku.

output:

a solved puzzle is printed out if solvable. If no solution, the unsolved grid is printed out.

### Exit status

0 - success

1 - invalid number command line arguments

2 - invalid command - one that does not include the four mentioned above

### Assumptions

* the puzzle is a 9 x 9 grid
* the puzzle can only contain numbers from 0 - 9



