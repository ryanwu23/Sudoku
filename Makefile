# Variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I ../
PROG = sudoku
OBJS = create.o sudoku.o

# Rules
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Phony targets
.PHONY: clean

clean:
	rm -f core
	rm -f $(PROG) *~ *.o