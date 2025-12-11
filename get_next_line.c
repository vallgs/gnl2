/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:39:54 by vallangl          #+#    #+#             */
/*   Updated: 2025/12/11 19:37:17 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

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
		return (line);
	}
	return (ft_strdup(full_line));
}

void	checkbuffer(char *full_line, char *buffer)
{
	int		len;
	int len_buffer;
	int		i;
	char	*newline_pos;

	i = 0;
	len_buffer = ft_strlen(buffer);
	newline_pos = ft_strchr(full_line, '\n');
	if (newline_pos)
	{
		len = ft_strlen(newline_pos + 1);
		while (i < len)
		{
			buffer[i] = newline_pos[i + 1];
			i++;
		}
	}
	while (i < len_buffer)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*read_and_accumulate(int fd, char *buffer)
{
	char	*full_line = NULL;
	int		br;

	if (buffer[0] != '\0')
	{
		full_line = ft_strdup(buffer);
		if (!full_line)
			return (NULL);
	}
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
	if (!full_line)
		return (NULL);
	line = extract_line(full_line);
	checkbuffer(full_line, buffer);
	free(full_line);
	if ((!line || !line[0]))
	{
		return (NULL);
	}
	return (line);
}


// char	*extract_line(char *buffer)
// {
// 	char	*line_pos;
// 	int		len;

// 	if (!buffer)
// 		return (NULL);
// 	line_pos = ft_strchr(buffer, '\n');
// 	if (line_pos)
// 	{
// 		len = line_pos - buffer + 1;
// 		return (ft_substr(buffer, 0, len));
// 	}
// 	return (ft_strdup(buffer));
// }

// char	*checkbuffer(char *buffer)
// {
// 	int		i;
// 	char	*check;
// 	char	*new_buffer;

// 	i = 0;
// 	if (!buffer)
// 		return (NULL);
// 	check = ft_strchr(buffer, '\n');
// 	if (check)
// 	{
// 		i = check - buffer + 1;
// 		new_buffer = ft_substr(buffer, i, ft_strlen(buffer + i));
// 		free(buffer);
// 		if (new_buffer && !new_buffer[0])
// 		{
// 			free(new_buffer);
// 			return (NULL);
// 		}
// 		return (new_buffer);
// 	}
// 	free(buffer);
// 	return (NULL);
// }

// // char	*read_and_accumulate(int fd, char *static_buffer)
// // {
// // 	char	*temp_buffer;
// // 	char	*new_buffer;
// // 	int		bytes_read;

// // 	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// // 	if (!temp_buffer)
// // 		return (NULL);
// // 	bytes_read = 1;
// // 	while (bytes_read > 0)
// // 	{
// // 		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
// // 		if (bytes_read < 0)
// // 	 		return (freebuf(temp_buffer, static_buffer), NULL);
// // 		if (bytes_read == 0)
// // 			break ;
// // 		temp_buffer[bytes_read] = '\0';
// // 		new_buffer = ft_strjoin(static_buffer, temp_buffer);
// // 		free(static_buffer);
// // 		static_buffer = new_buffer;
// // 		if (ft_strchr(static_buffer, '\n'))
// // 			break ;
// // 	}
// // 	free(temp_buffer);
// // 	return (static_buffer);
// // }

// // char	*read_and_accumulate(int fd, char *static_buffer)
// // {
// //     char	*temp_buffer;
// //     char	*new_buffer;
// //     int		bytes_read;

// //     if (static_buffer && ft_strchr(static_buffer, '\n'))
// //         return (static_buffer);
// //     temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// //     if (!temp_buffer)
// //         return (NULL);
// //     bytes_read = 1;
// //     while (bytes_read > 0)
// //     {
// //         bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
// //         if (bytes_read < 0)
// //             return (freebuf(temp_buffer, static_buffer), NULL);
// //         if (bytes_read == 0)
// //             break ;
// //         temp_buffer[bytes_read] = '\0';
// //         new_buffer = ft_strjoin(static_buffer, temp_buffer);
// //         if (!new_buffer)
// //             return (freebuf(temp_buffer, static_buffer), NULL);
// //         free(static_buffer);
// //         static_buffer = new_buffer;
// //         if (ft_strchr(static_buffer, '\n'))
// //             break ;
// //     }
// //     free(temp_buffer);
// //     return (static_buffer);
// // }

// char	*read_and_accumulate(int fd, char *s)
// {
// 	char	*t;
// 	char	*n;
// 	int		br;

// 	if (s && ft_strchr(s, '\n'))
// 		return (s);
// 	t = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!t)
// 		return (NULL);
// 	br = 1;
// 	while (br > 0 && (br = read(fd, t, BUFFER_SIZE)) > 0)
// 	{
// 		t[br] = '\0';
// 		if (!(n = ft_strjoin(s, t)))
// 			return (free(t), free(s), NULL);
// 		free(s);
// 		s = n;
// 		if (ft_strchr(s, '\n'))
// 			break ;
// 	}
// 	if (br < 0)
// 		return (free(t), free(s), NULL);
// 	return (free(t), s);
// }

// // void freebuf(char *temp_buffer, char *buffer)
// // // {
// // // 	if (temp_buffer)
// // // 		free(temp_buffer);
// // // 	if (buffer)
// // // 		free(buffer);
// // // }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buffer = read_and_accumulate(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	line = extract_line(buffer);
// 	buffer = checkbuffer(buffer);
// 	if (!buffer && (!line || !line[0]))
// 	{
// 		free(line);
// 		free(buffer);
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	return (line);
// }

