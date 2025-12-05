/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:39:54 by vallangl          #+#    #+#             */
/*   Updated: 2025/12/05 19:01:43 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*extract_line(char *buffer)
{
	char	*line_pos;
	int		len;

	if (!buffer)
		return (NULL);
	line_pos = ft_strchr(buffer, '\n');
	if (line_pos)
	{
		len = line_pos - buffer + 1;
		return (ft_substr(buffer, 0, len));
	}
	return (ft_strdup(buffer));
}

char	*checkbuffer(char *buffer)
{
	int		i;
	char	*check;
	char	*new_buffer;

	i = 0;
	if (!buffer)
		return (NULL);
	check = ft_strchr(buffer, '\n');
	if (check)
	{
		i = check - buffer + 1;
		new_buffer = ft_substr(buffer, i, ft_strlen(buffer + i));
		free(buffer);
		return (new_buffer);
	}
	free(buffer);
	return (NULL);
}

char	*read_and_accumulate(int fd, char *static_buffer)
{
	char	*temp_buffer;
	char	*new_buffer;
	int		bytes_read;

	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{ 
            free(temp_buffer);
		    free(static_buffer);
	 		return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		new_buffer = ft_strjoin(static_buffer, temp_buffer);
		free(static_buffer);
		static_buffer = new_buffer;
		if (ft_strchr(static_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_accumulate(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = checkbuffer(buffer);
	return (line);
}
