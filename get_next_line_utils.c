/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:02:33 by sepun             #+#    #+#             */
/*   Updated: 2023/11/17 18:21:47 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;

// 	if (count == SIZE_MAX && size == SIZE_MAX)
// 		return (NULL);
// 	ptr = malloc(count * size);
// 	if (ptr == NULL)
// 		return (ptr);
// 	ft_bzero(ptr, size * count);
// 	return (ptr);
// }

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		j;
	int		i;

	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str == 0)
			return (NULL);
		j = 0;
		i = 0;
		while (s1[j])
		{
			str[j] = s1 [j];
			j++;
		}
		while (s2[i])
		{
			str[j++] = s2 [i++];
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	char			*str;

	cc = (unsigned char)c;
	str = (char *)s;
	while (*str != cc)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}