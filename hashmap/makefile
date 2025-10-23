
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -I../c_unit/include
SRC = src/main.c src/hashmap.c
TESTSRC = test/hashmap_test.c src/hashmap.c ../c_unit/src/c_unit.c

all: main

main: $(SRC)
	$(CC) $(CFLAGS) -o main $(SRC)

run: main
	./main

test: $(TESTSRC)
	$(CC) $(CFLAGS) -o test $(TESTSRC) $(CUNITSRC)
	./test

test_debug: $(TESTSRC)
	$(CC) -g $(CFLAGS) -o test $(TESTSRC) $(CUNITSRC)
	gdb ./test

clean:
	rm -f main.exe test.exe