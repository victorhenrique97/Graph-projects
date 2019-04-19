all:
	gcc -o exercicio1 src/*.c -I include/  -g -Wall -std=c99
run:
	./exercicio1 
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes  ./exercicio1 <imput/16.in
