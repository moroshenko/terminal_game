all: *.o
	gcc *.o -g -Wall -Wextra -Werror -pthread -o BIN/GAME
	rm *.o
*.o: SRC/*.c
	gcc SRC/*.c -g -c 
