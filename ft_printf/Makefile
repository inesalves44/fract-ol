# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 19:02:37 by idias-al          #+#    #+#              #
#    Updated: 2023/01/20 19:33:06 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_LIBFT		=	libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o \
					libft/ft_isprint.o libft/ft_memcmp.o libft/ft_putchar_fd.o libft/ft_split.o \
					libft/ft_strlcat.o libft/ft_strncmp.o libft/ft_substr.o libft/ft_atoi.o \
					libft/ft_itoa.o libft/ft_memcpy.o libft/ft_putendl_fd.o libft/ft_strchr.o libft/ft_strlcpy.o \
					libft/ft_strnstr.o libft/ft_tolower.o libft/ft_bzero.o  libft/ft_strmapi.o\
					libft/ft_memmove.o libft/ft_putnbr_fd.o libft/ft_strdup.o libft/ft_strlen.o libft/ft_strrchr.o\
					libft/ft_toupper.o libft/ft_calloc.o libft/ft_memchr.o libft/ft_memset.o \
					libft/ft_putstr_fd.o libft/ft_strjoin.o libft/ft_strtrim.o libft/ft_striteri.o

BONUS			=	libft/ft_lstadd_back.o libft/ft_lstadd_front.o libft/ft_lstclear.o \
					libft/ft_lstdelone.o libft/ft_lstiter.o libft/ft_lstlast.o \
					libft/ft_lstmap.o libft/ft_lstnew.o libft/ft_lstsize.o
OBJS			=	srcs/ft_printf.o srcs/ft_printhexa.o srcs/ft_print_simple.o srcs/ft_printunsigned.o srcs/ft_pointer.o srcs/ft_printf_float.o
OBJS_GNL		=	gnl/get_next_line.o gnl/get_next_line_utils.o gnl/get_next_line_bonus.o \
				   	gnl/get_next_line_utils_bonus.o
CC				= cc
RM				= rm -f
INCLUDES		= incs/
CFLAGS			= -Wall -Wextra -Werror -I $(INCLUDES)
NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS) $(OBJS_GNL)
				$(MAKE) bonus -C libft
				ar rcs $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_LIBFT)

clean:
				$(MAKE) clean -C libft
				$(RM) $(OBJS) $(OBJS_LIBFT) $(OBJS_GNL)

fclean:			clean
				$(MAKE) fclean -C libft
				$(RM) $(NAME)

re:				fclean $(NAME)

