
CC = cc

test:
	cc -I.. -g -c -o test.o test.c
	cc -o test test.o libftprintf.a -L./mlx -lmlx -lXext -lX11 -lm -lbsd

hook: 
	cc -I.. -g -c -o hooks.o hooks.c
	$(CC) -o hooks hooks.o ft_printf/libftprintf.a -L./mlx -lmlx -lXext -lX11 -lm -lbsd

mandelbrot:
	cc -I.. -g -c -o mandelbrot.o mandelbrot.c
	cc -o mandelbrot mandelbrot.o libftprintf.a  -L./mlx -lmlx -lXext -lX11 -lm -lbsd

mtest:
	cc -I.. -g -c -o mandelbrot_test.o mandelbrot_test.c
	cc -o mandelbrot mandelbrot_test.o -L./mlx -lmlx -lXext -lX11 -lm -lbsd

clean: 
	rm -rf *.o

fclean: clean
	rm -rf test hooks mandelbrot

remandelbrot: fclean mandelbrot

remtest: fclean mtest

rehook: fclean hook

retest: fclean test

#cc -I.. -g -c -o hooks.o hooks.c
#make -C ft_printf
#cp ft_printf/libftprintf.a libftprintf.a 