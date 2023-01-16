
CC=cc

all:
	cc -I.. -g -c -o test.o test.c
	cc -o test test.o -L./mlx -lmlx -lXext -lX11 -lm -lbsd
clean: 
	rm -rf *.o
fclean: clean
	rm -rf test
re: fclean all
