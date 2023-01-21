/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:39:43 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/20 10:46:04 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buffer(int fd, char *new)
{
	char	*buffer;
	int		bit;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bit = 1;
	while (!mod_strchr(new, '\n') && bit != 0)
	{
		bit = read(fd, buffer, BUFFER_SIZE);
		if (bit == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		if (bit == 0)
			break ;
		buffer[bit] = '\0';
		new = mod_strjoin(new, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (new);
}

char	*get_left(char *new)
{
	char	*temp;
	char	*left;

	if (!new || new[0] == '\0')
		return (NULL);
	temp = mod_strchr(new, '\n') + 1;
	left = mod_strdup(temp);
	return (left);
}

char	*get_line(char *new, char *left)
{
	char	*line;
	int		i;
	int		total;

	if (!new && !left)
		return (NULL);
	total = mod_strlen(new) - mod_strlen(left);
	line = malloc(sizeof(char) * (total + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < total)
	{
		line[i] = new[i];
		i++;
	}
	line[i] = '\0';
	free(new);
	new = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left[4096];
	char		*line;
	char		*new;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new = get_buffer(fd, left[fd]);
	if (!new || new[0] == '\0')
	{
		free(new);
		new = NULL;
	}
	left[fd] = get_left(new);
	if (!left[fd] || left[fd][0] == '\0')
	{
		free(left[fd]);
		left[fd] = NULL;
	}
	line = get_line(new, left[fd]);
	if (!line || line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}

/*int		main(int argc, char *argv[])
 {	
	if (argc < 2) 
		write(2, "File name missing.\n", 19);
	else
	{
		int fd = open(argv[1], O_RDONLY);
		int fd2 = open(argv[2], O_RDONLY);
		int fd3 = open(argv[3], O_RDONLY);
		char *str;
		char *str1;
		char *str2;
		int i = 1;
		while(fd)
		{
			str = get_next_line(fd);
			str1 = get_next_line(fd2);
			str2 = get_next_line(fd3);			
			if (!str)
				break;
			printf("-----------line %i---------\n", i++);
			printf("first doc: %s\n", str);
			printf("second doc: %s\n", str1);
			printf("third doc: %s\n", str2);			
		}
	}
	return (0);
}*/
