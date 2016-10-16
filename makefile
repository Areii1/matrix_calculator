all: run

build:
	gcc main.c matrix_algebra.c	-o main.exe

run: build
	./main.exe
