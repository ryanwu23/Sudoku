# Sudoku Final Project
## Mark Gitau, Jeff Gitahi, Andrew Truong, Ryan Wu, Spring 2020

### Testing Sudoku 'create' and 'solve'

To test our the creation and solving of our sudoku puzzle, we wrote a small program in `unittesting.sh` and `fuzztesting.sh`
to make sure it does what it's supposed to do.

`unittesting.sh`: this test program will test the parsing of arguments, creation of unique and random sudoku puzzle,
correct solving of sudoku puzzles, and tests if a sudoku puzzle can even be solved

`fuzztesting.sh`: this test program, similar to `unittesting.sh`, will create and solve puzzles as many times as told to by a
command-line argument. It creates a puzzle into a file, confirms it has a unique solution, solves it, confirms it is valid, and then
deletes the files used

### Rundown of tests done
Tests done in `unittesting.sh` and `fuzztesting.sh` involve tests relating to incorrect number of arguments, unsolvable sudoku grids,
incorrect arguments, and tests that run smoothly with correct arguments.

# Test run

An example test run is in `testing.out`. Build with:
```
make test &> testing.out
```
In that file, one can see the result of creating unique and random sudoku puzzles and solving of the sudoku puzzles through recursion.
Sample incorrect arguments produce desired stderr messages, and the checks to ensure a created puzzle is unique and a sovled puzzle is
valid show that the creation and solving process produces desired results.