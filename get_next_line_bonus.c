/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <atchelde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:11:50 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/13 15:12:54 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	buffer = NULL;
	return (line);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line || i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	while (i--)
		line[i] = buffer[i];
	return (line);
}

char	*ft_readline(int fd, char *buffer, int bytes_read)
{
	char	*new_buffer;
	char	*tmp;

	new_buffer = (char *)(malloc(BUFFER_SIZE + 1));
	if (! buffer)
		buffer = ft_calloc(1, 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, new_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(new_buffer);
			free(buffer);
			return (NULL);
		}
		new_buffer[bytes_read] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, new_buffer);
		free(tmp);
		if (ft_index(new_buffer, '\n') >= 0)
			break ;
	}
	free(new_buffer);
	new_buffer = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_readline(fd, buffer[fd], bytes_read);
	if (buffer[fd] == NULL)
		line = NULL;
	else
	{
		line = ft_get_line(buffer[fd]);
		buffer[fd] = ft_next(buffer[fd]);
	}
	return (line);
}
