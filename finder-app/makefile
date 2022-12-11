all:
	make clean
	make default

default: writer.o obj
	$(CROSS_COMPILE)gcc -g -Wall -o writer writer.o

obj: writer.c
	$(CROSS_COMPILE)gcc -g -Wall -c -o writer.o writer.c

clean:
	rm -rf ./*.o ./writer



