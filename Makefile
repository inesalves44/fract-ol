# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 18:52:22 by idias-al          #+#    #+#              #
#    Updated: 2023/02/02 18:52:36 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	=	mandatory/main.o mandatory/init_mlx.o mandatory/exit_errors.o mandatory/hooks.o mandatory/mandelbrot.o\
			mandatory/imgpixel.o mandatory/julia.o mandatory/fractol_utils.o

BONUS	=	bonus/fractinit_bonus.o bonus/init_mlx_bonus.o bonus/exit_errors_bonus.o bonus/mandelbrot_bonus.o\
			bonus/imgpixel_bonus.o bonus/julia_bonus.o bonus/fractol_utils_bonus.o bonus/keyhooks_bonus.o bonus/mousehooks_bonus.o\
			bonus/burngship.o bonus/color.o bonus/main.o bonus/window2utils.o

CC		= cc
CFLAGS	= -Wextra -Wall -Werror -g
MINILB	= -L./mlx -lmlx -lXext -lX11 -lm -lbsd
NAME	= fractol
LIBFTPRINTF = libftprintf.a

all:	$(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C ft_printf
		cp ft_printf/$(LIBFTPRINTF) $(LIBFTPRINTF)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF) $(MINILB)

bonus: $(NAME) $(BONUS)
		$(CC) $(CFLAGS) -o $(NAME) $(BONUS) $(LIBFTPRINTF) $(MINILB)

clean:
	$(MAKE) clean -C ft_printf
	rm -rf $(OBJS) $(BONUS)

fclean: clean
	$(MAKE) fclean -C ft_printf
	rm -rf $(NAME) $(LIBFTPRINTF)

re: fclean all

rebonus: fclean bonus
