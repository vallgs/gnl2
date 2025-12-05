/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:26:33 by vallangl          #+#    #+#             */
/*   Updated: 2025/12/05 18:24:43 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1024
# endif
 
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*extract_line(char *buffer);
char	*checkbuffer(char *buffer);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const*s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif