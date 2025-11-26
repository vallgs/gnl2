/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:05:38 by vallangl          #+#    #+#             */
/*   Updated: 2025/11/25 05:05:50 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = (char)c;
	while (s[i])
	{
		if (s[i] == j)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	b = malloc(sizeof(char) * (len + 1));
	if (!b)
		return (NULL);
	while (i < len && s[start + i])
	{
		b[i] = s[start + i];
		i++;
	}
	b[i] = '\0';
	return (b);
}



