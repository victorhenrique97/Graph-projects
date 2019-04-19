all:
	gcc -o bfs src/*.c -I include/  -g -Wall -std=c99
run:
	./bfs
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes  ./bfs <imput/1.in
