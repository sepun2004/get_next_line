/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:01:21 by sepun             #+#    #+#             */
/*   Updated: 2024/06/17 20:07:54 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	i = atoi(argv[2]);
	fd = open (argv[1], O_RDONLY);
	while (i--)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
}
