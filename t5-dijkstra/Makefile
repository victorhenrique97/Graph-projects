all:
	gcc -o ex06 src/*.c -I include/  -g -Wall -std=c99
run:
	./ex06
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ex06 <entrada/13.in