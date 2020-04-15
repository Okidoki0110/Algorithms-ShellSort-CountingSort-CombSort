CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo.o algo2.o algo3.o test.o
	g++ $^ -o tema

cpp.o:
	g++ $< -c $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o