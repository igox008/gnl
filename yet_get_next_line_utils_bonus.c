/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:54:58 by alaassir          #+#    #+#             */
/*   Updated: 2023/12/06 06:32:45 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*fill(char *buff)
{
	char	*dst;
	ssize_t	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	dst = (char *)malloc(i + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (buff[++i] && buff[i] != '\n')
		dst[i] = buff[i];
	if (buff[i] == '\n')
	{
		dst[i] = buff[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	get_rmn(char *dst, char *src)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (src && dst)
	{
		while (src[i] && src[i] != '\n')
			i++;
		if (src[i] == '\n')
			i++;
		while (src[i])
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		while (dst[j] != '\0')
		{
			dst[j] = '\0';
			j++;
		}
	}
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
