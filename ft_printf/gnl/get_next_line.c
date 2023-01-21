/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:39:43 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/19 19:44:13 by idias-al         ###   ########.fr       */
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
	static char	*left;
	char		*line;
	char		*new;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new = get_buffer(fd, left);
	if (!new || new[0] == '\0')
	{
		free(new);
		new = NULL;
	}
	left = get_left(new);
	if (!left || left[0] == '\0')
	{
		free(left);
		left = NULL;
	}
	line = get_line(new, left);
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
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);

	else if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		char *str;
		int i = 1;
		while(fd)
		{
			str = get_next_line(fd);
			if (!str)
				break;
			printf("-----------line %i---------\n", i++);
			printf("%s", str);
		}
	}
	return (0);
}*/
