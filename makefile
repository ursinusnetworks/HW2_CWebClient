CC=gcc
CFLAGS=-g -Wall -pedantic

all: client

client: arraylist.h util.h client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	rm client