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

static char *ft_free_nose(char *next, char *temp)
{
	char *tmp;

	tmp = ft_strjoin(next, temp);
	free(next);
	return (temp);
}


char *the_rest_in_the_new_line(char *next)
{
	int i;
	int j;
	char *next_line;

	i = 0;
	j = 0;
	while(next[i] != '\n' && next[i] != '\0')
		i++;
	if (next[i] == '\0')
	{
		free(next);
		return NULL;
	}
	next_line = malloc(sizeof(char) * (ft_strlen(next) - i + 1));
	if(!next_line)
		return NULL;
	i++
	while (next[i] != '\0')
	{
		next_line[j] = next[i];
		j++;
		i++;
	}
	next_line = '\0';
	free(next);
	return (next_line);
}

char *make_line(char *next)
{
	char	*line;
	int i;

	i = 0;
	if(next[i] == '\0')
		return (NULL);
	i = ft_strlen(next); //Warning
	while(next[i] != '\0' && next[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i);
	if(!line)
		return (NULL);
	i = 0;
	while(next[i] != '\0' && next[i] != '\n')
	{
		line[i] = next[i];
		i++;
	}
	line[i] ='\0';
	return(line);
}

char *read_fd_n(int fd,char *next)
{
	int		amount;
	char	*temp;

	// if (!next)
    // 	next = malloc(sizeof(char));
    next = malloc(sizeof(char));
	if (!next)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if(!temp)
		return (NULL);
	amount = 1;
	while(amount > 0 && !ft_strchr(next, '\n'))
	{
		amount = read(fd, temp, BUFFER_SIZE);
		if (amount == -1)
		{
			free(temp);
			free(next);
			return (NULL);
		}
		temp[amount] = '\0',
		next  = ft_free_nose(next, temp);
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
	if(!next)
		return NULL;
	final = make_line(next);
	printf("Final es : %s\n", final);
	next = the_rest_in_the_new_line(next);
	printf("Final es : %s\n", next);

	return (final);
}
