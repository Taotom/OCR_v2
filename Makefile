# Makefile

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
LDFLAGS = -lm

SRC = $(wildcard *.c)
DEP = $(wildcard *.h)

EXEC = test



all: $(EXEC)

test:
	$(CC) -o test $(SRC) $(DEP) $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o
	rm -rf *.gch

mrproper: clean
	rm -rf $(EXEC)
