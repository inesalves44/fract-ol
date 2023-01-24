/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:55:09 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/19 15:47:54 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

char	*get_next_line(int fd);
char	*get_buffer(int fd, char *new);
char	*get_left(char *new);
char	*get_line(char *new, char *left);
int		mod_strlen(char *s);
char	*mod_strjoin(char *s1, char *s2);
char	*mod_strchr(char *s, int c);
char	*mod_strdup(char *s);

#endif
