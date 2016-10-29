all: run

build:
	gcc main.c user_interface.c matrix_algebra.c	-o main.exe

run: build
	./main.exe

test:
	gcc -Wall -o add_test matrix_algebra.c matrix_algebra-test.c user_interface.c -pthread -lcheck_pic -pthread -lrt -lm -lsubunit

