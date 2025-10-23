
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/hashmap.c
TESTSRC = test/hashmap_test.c src/hashmap.c

all: main

main: $(SRC)
	$(CC) $(CFLAGS) -o main $(SRC)

run: main
	./main

test: $(TESTSRC)
	$(CC) $(CFLAGS) -o test $(TESTSRC)
	./test

test_debug: $(TESTSRC)
	$(CC) -g $(CFLAGS) -o test $(TESTSRC)
	gdb ./test

clean:
	rm -f main.exe test.exe