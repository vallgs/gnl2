/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:02:58 by vallangl          #+#    #+#             */
/*   Updated: 2025/12/05 19:07:27 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open file '%s'\n", argv[1]);
		return (1);
	}
	i = 1;
	line = get_next_line(fd);
	printf("Line %d: %s", i, line);
	line = get_next_line(fd);
	line = get_next_line(fd);
	printf("Line %d: %s", i, line);
	puts("closed");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	puts("openned");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	printf("\n--- Total lines read: %d ---\n", i - 1);
	return (0);
}
