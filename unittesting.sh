# Unit testing script for create.c and solver.c
# Authors: Mark Gitau, Jeff Gitahi, Andrew Truong, Ryan Wu,
# May 29, 2020
#
# usage: bash -v testing.sh

#####################################
### These tests should fail ###

# Incorrect number of arguments
./sudoku

./sudoku argument number not one

# Command is not "create" or "solve"
./sudoku generate

#####################################
### create.c tests should pass ###
# sleep used because doing create too quickly will not generate new puzzle
echo Results of create:

# Simple test
./sudoku create
sleep 1

# Simple test (2), should be unique
./sudoku create 
sleep 1

# Simple test (3), should be unique
./sudoku create 
sleep 1

#####################################
### solve.c tests that should pass ###
echo Results of solve:

# Simple test (1)
cat ./unittesting_input/unittesting.in1 | ./sudoku solve
echo

# Simple test (2)
cat ./unittesting_input/unittesting.in2 | ./sudoku solve
echo

# Simple test (3)
cat ./unittesting_input/unittesting.in3 | ./sudoku solve
echo