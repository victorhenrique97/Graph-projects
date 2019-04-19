all:
	gcc -o ex04 src/*.c -I include/  -g -Wall -std=c99
run:
	./ex04 
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ex04 <imput/1.in