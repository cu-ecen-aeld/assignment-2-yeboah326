# CROSS_COMPILE
CC=gcc

ifdef CROSS_COMPILE
	CC=$(CROSS_COMPILE)gcc
endif

writer:
	$(CC) -Wall writer.c -o writer

clean:
	rm -f writer *.o

.PHONY: writer