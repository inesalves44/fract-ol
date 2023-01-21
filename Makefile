
CC=cc

all:
	cc -I.. -g -c -o test.o test.c
	cc -o test test.o -L./mlx -lmlx -lXext -lX11 -lm -lbsd

hook:
	cc -I.. -g -c -o hooks.o hooks.c
	cc -o hooks hooks.o -L./mlx -lmlx -lXext -lX11 -lm -lbsd

mandelbrot:
	cc -I.. -g -c -o mandelbrot.o mandelbrot.c
	cc -o mandelbrot mandelbrot.o -L./mlx -lmlx -lXext -lX11 -lm -lbsd

mtest:
	cc -I.. -g -c -o mandelbrot_test.o mandelbrot_test.c
	cc -o mandelbrot mandelbrot_test.o -L./mlx -lmlx -lXext -lX11 -lm -lbsd

clean: 
	rm -rf *.o

fclean: clean
	rm -rf test hooks mandelbrot

re: fclean all