CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2

.PHONY: all run clean

all: list

list: list.c
	$(CC) $(CFLAGS) list.c -o list

run: list
	./list

clean:
	rm -f list
