/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:14:30 by maalwis           #+#    #+#             */
/*   Updated: 2025/04/17 14:24:50 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#define MAX_FD 1024

char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	char	*new_buffer;

	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		line = ft_substr(*buffer, 0, newline_pos - *buffer + 1);
		new_buffer = ft_strdup(newline_pos + 1);
		free(*buffer);
		*buffer = new_buffer;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*join_buffers(char *buffer, char *temp)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, temp);
	free(buffer);
	return (new_buffer);
}

char	*read_join(int fd, char *buffer, char *temp)
{
	int	bytes_read;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		temp[bytes_read] = '\0';
		buffer = join_buffers(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, temp, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd, int mode)
{
	static char	*buffer[MAX_FD];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (mode == 1)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buffer[fd] = read_join(fd, buffer[fd], temp);
	free(temp);
	if (!buffer[fd])
		return (NULL);
	if (buffer[fd] && *buffer[fd])
		return (extract_line(&buffer[fd]));
	free(buffer[fd]);
	return (buffer[fd] = NULL, NULL);
}

/* int main(void)
{
	int fd1, fd2, fd3;
	char *line;
	int	i = 0;

	fd1 = open("filebonus1.txt", O_RDONLY);
	fd2 = open("filebonus2.txt", O_RDONLY);
	fd3 = open("filebonus3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Erreur sur l'ouvertude de fichier");
		return (1);
	}
	while (i < 5)
	{
		line = get_next_line(fd1);
		if (line)
		{
			printf("File1: %s", line);
			free(line);
		}
		line = get_next_line(fd2);
		if (line)
		{
			printf("File2: %s", line);
			free(line);
		}
		line = get_next_line(fd3);
		if (line)
		{
			printf("File3: %s", line);
			free(line);
		}
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
} */
