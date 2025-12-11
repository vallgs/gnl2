/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:32:44 by vallangl          #+#    #+#             */
/*   Updated: 2025/12/11 18:48:42 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *full_line)
{
	char	*newline_pos;
	char	*line;
	int		len;

	if (!full_line)
		return (NULL);
	newline_pos = ft_strchr(full_line, '\n');
	if (newline_pos)
	{
		len = newline_pos - full_line + 1;
		line = ft_substr(full_line, 0, len);
		if (!line)
			return (NULL);
		return (ft_substr(full_line, 0, len));
	}
	return (ft_strdup(full_line));
}

char	*checkbuffer(char *full_line, char *buffer)
{
	int		len;
	int		i;
	char	*newline_pos;
	char	*new_buffer;

	i = 0;
	if (!buffer)
		return (NULL);
	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos)
	{
		len = ft_strlen(newline_pos + 1);
		while (i < len)
		{
			buffer[i] = newline_pos[i + 1];
			i++;
		}
		buffer[i] = '\0';
	}
}

char	*read_and_accumulate(int fd, char *buffer)
{
	char	*full_line;
	int		br;

	br = 1;
	while (br > 0 && (br = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[br] = '\0';
		full_line = ft_strjoin(full_line, buffer);
		if (!full_line)
			return (NULL);
		if (ft_strchr(full_line, '\n'))
			break ;
	}
	if (br < 0)
		return (free(full_line), NULL);
	return (full_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*full_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = read_and_accumulate(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(full_line);
	checkbuffer(full_line, buffer);
	if (!buffer && (!line || !line[0]))
	{
		free(full_line);
		free(buffer);
		return (NULL);
	}
	return (line);
}
