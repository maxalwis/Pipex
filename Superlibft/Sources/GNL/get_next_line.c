/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:14:30 by maalwis           #+#    #+#             */
/*   Updated: 2025/01/17 17:27:08 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buffer = read_join(fd, buffer, temp);
	free(temp);
	if (buffer && *buffer)
		return (extract_line(&buffer));
	free(buffer);
	buffer = NULL;
	return (NULL);
}

/* int	main(void)
{
	int		fd = open("file0.txt", O_RDONLY);
	int		number = 1;
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("Ligne lue %d: %s", number, line);
		free(line);
		line = get_next_line(fd);
		number++;
	}
	close(fd);
	return (0);
} */
