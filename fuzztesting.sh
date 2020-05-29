# Fuzz testing script for create.c and solver.c
# Authors: Mark Gitau, Jeff Gitahi, Andrew Truong, Ryan Wu,
# May 29, 2020
#
# usage: bash -v fuzztesting.sh

# Generate random puzzles and then solve it 10 times
COUNTER=0
while [ $COUNTER -lt 10 ]
do
    # Creating
    ./sudoku create > fuzztesting_puzzle
    echo Created sudoku puzzle:
    cat fuzztesting_puzzle
    sleep 0.5

    #Solving
    echo Solved Sudoku puzzle
    ./sudoku solve < fuzztesting_puzzle

    echo

    COUNTER=$((COUNTER+1))
done


rm -f fuzztesting_puzzle