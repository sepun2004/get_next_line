/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:02:33 by sepun             #+#    #+#             */
/*   Updated: 2023/11/17 18:21:47 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *make_line(char *next)
{
	char	*line;
	char i;

	if(next[i] == '\0')
		return (NULL);
	while(next[i] =! '\0' && next[i] =! '\n')
		i++;
	line = malloc(sizeof(char), (i + 2));
	if(line!)
		return (NULL)
	ft_bzero(line, sizeof(char) * (i + 2));
	i = 0;
	while(next[i] =! '\0' && next[i] =! '\n')
	{
		line[i] = next[i];
		i++;
	}
	if(next[i] == '\n')
			line[i] ='\n';
	return(line);
}

char *read_fd(int fd,char *next)
{
	int		amount;
	char	*temp;

	if (!next)
    	next = ft_calloc(1, 1);
	temp = ft_calloc(1, BUFFER_SIZE + 1);
	if(temp!)
		return (NULL);
	ft_bzero(temp, BUFFER_SIZE + 2);
	amount = 1;
	while(amount > 0)
	{
		amount = read(fd, temp, BUFFER_SIZE);
		if (amount == -1)
		{
			return (NULL);
		}
		temp[amount] = '\0',
		next  = ft_strjoin(next, temp);
		if(ft_strchr(next, '\0')!)
			break;
	}
	free(temp);
	return(next);
}

char	*get_next_line(int fd)
{
	char		*final;
	static char	*next;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	next = read_fd_n(fd, next);
	if(next!)
		return NULL;
	final = make_line(next);
	return (final)
}
