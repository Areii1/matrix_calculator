all: run

build:
	gcc main.c user_interface.c matrix_algebra.c	-o matrix_calc.exe

run: build
	./matrix_calc.exe
