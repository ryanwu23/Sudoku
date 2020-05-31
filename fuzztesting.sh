# Fuzz testing script for create.c and solver.c
# Authors: Mark Gitau, Jeff Gitahi, Andrew Truong, Ryan Wu,
# May 29, 2020
#
# usage: ./fuzztesting.sh NUMBER_OF_TESTS
# example: ./fuzztesting.sh 5

if [ $# -ne 1 ]
then
    echo "Usage: Enter one numerical argument for how many tests to be done"
    exit 1
fi

AMOUNT=$1

# Generate random puzzles and then solve it amount of times specified by user
COUNTER=0
while [ $COUNTER -lt $AMOUNT ]
do
    echo Test: $((COUNTER+1))

    # Creating
    sleep 0.5
    ./sudoku create > fuzztesting_puzzle
    echo Created sudoku puzzle:
    cat fuzztesting_puzzle

    ./sudoku unique < fuzztesting_puzzle # Show if sudoku created has unique solution

    echo

    #Solving
    echo Solved Sudoku puzzle
    ( ./sudoku solve < fuzztesting_puzzle ) > fuzztesting_puzzle_solved
    cat fuzztesting_puzzle_solved

    ./sudoku valid < fuzztesting_puzzle_solved # Show if solved sudoku is a valid sudoku

    echo -------------------------------------

    COUNTER=$((COUNTER+1))
done


# Clean up files
rm -f fuzztesting_puzzle
rm -f fuzztesting_puzzle_solved