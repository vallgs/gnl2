/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallangl <vallangl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:02:58 by vallangl          #+#    #+#             */
/*   Updated: 2025/12/11 19:04:36 by vallangl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

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
		printf("Error: Could not open file '%s': %s\n", argv[1], strerror(errno));
		return (1);
	}
	i = 1;
	// line = get_next_line(fd);
	// printf("Line %d: %s", i, line);
	// puts("closed");
	// close(fd);
	// fd = open(argv[1], O_RDONLY);
	puts("openned");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: '%s'", i, line);
		free(line);
		i++;
	}
	printf("Line %d: '%s'", i, line);
	close(fd);
	printf("\n--- Total lines read: %d ---\n", i - 1);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// close(fd);
	return (0);
}
