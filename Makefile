CC=gcc

all: server

clean: server
	rm -f *.o server *~

.PHONY: all clean

server: main.o
	$(CC) $^ -o server

