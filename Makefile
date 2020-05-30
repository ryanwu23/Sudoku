# Variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I ../
PROG = sudoku
OBJS = common.o create.o sudoku.o

# Rules
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Phony targets
.PHONY: clean test valgrind

clean:
	rm -f *core*
	rm -f $(PROG) *~ *.o

test:
	bash -v unittesting.sh
	bash -v fuzztesting.sh 8

valgrind:
	valgrind ./sudoku create | ./sudoku solve