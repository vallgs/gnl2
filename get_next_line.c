/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:39:54 by vallangl          #+#    #+#             */
/*   Updated: 2025/12/01 16:36:34 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *line_pos)
{
    char buffer;
	int len;
	
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
		int i;
        char *check;
        char *new_buffer;

        i = 0;
        if (!buffer)
            return (NULL);
        check = ft_strchr(buffer, '\n');
        if (check)
        {
            i = check - buffer + 1;
            new_buffer = ft_substr(buffer, i, ft_strlen(buffer + i)); 
            // free (buffer);
            return (new_buffer);
        }
        // free (buffer) ;
        return (NULL);        
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char    tmp;
    int bytes_read;
    char    *line;
    
    if (!fd || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {   
        
        bytes_read = read(fd, buffer, BUFFER_SIZE);
    }        
}
