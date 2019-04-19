all:
	gcc -o dfs src/*.c -I include/  -g -Wall -std=c99
run:
	./dfs 
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes  ./dfs
