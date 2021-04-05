CC = gcc
CFLAGS = -g

.PHONY: all clean

all: main.c
	$(CC) $(CFLAGS) -o trumpet $?

clean:
	rm -rf trumpet trumpet.dSYM
