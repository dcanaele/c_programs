# File: Makefile
# Author: Daniel Anaele
# Date: 1/22/2026
# Description: Builds the executable

.PHONY: all clean

CC=gcc
CFLAGS= -Wall -Wextra -g
CPFLAGS=
LDFLAGS=

all: cmpt263_ex1

cmpt263_ex1: CMPT263_ex1.o
	$(CC) $(CFLAGS) CMPT263_ex1.o -o cmpt263_ex1

CMPT263_ex1.o: CMPT263_ex1.c
	$(CC) $(CFLAGS) -c CMPT263_ex1.c

clean:
	rm -f $(wildcard *.o) cmpt263_ex1
