ifndef CROSS_COMPILE
CC = gcc
else
CC = $(CROSS_COMPILE)gcc
endif

all:
	make clean
	make default

default: writer.o obj
	$(CC) -g -Wall -o writer writer.o

obj: writer.c
	$(CC) -g -Wall -c -o writer.o writer.c

clean:
	rm -rf ./*.o ./writer



