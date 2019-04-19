all:
	gcc -o ex05 src/*.c -I include/  -g -Wall -std=c99
run:
	./ex05
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ex05 <imput/5.in