/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:57:25 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/05 10:15:45 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	if (argc == 1)
		fd = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return (-1);
		printf("%s", line);
		free(line);
	}
	if (fd)
		close(fd);
	return (0);
}
