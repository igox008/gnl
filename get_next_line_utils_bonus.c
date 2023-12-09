/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:54:58 by alaassir          #+#    #+#             */
/*   Updated: 2023/12/08 15:27:54 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*fill(char *buff)
{
	char	*dst;
	ssize_t	i;

	i = 0;
	if (!buff)
		return (NULL);
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

void	get_rmn(char *dst, char **src, int check)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (*src && dst)
	{
		while ((*src)[i] && (*src)[i] != '\n')
			i++;
		if ((*src)[i] == '\n')
			i++;
		while ((*src)[i] && j < BUFFER_SIZE)
		{
			dst[j] = (*src)[i];
			i++;
			j++;
		}
		if (j < BUFFER_SIZE)
			dst[j] = '\0';
		else
			dst[BUFFER_SIZE - 1] = '\0';
		if (check == 1)
			ft_free(NULL, NULL, src, 2);
	}
}

char	*ft_free(char **line, char **next, char **buff, int check)
{
	if (check == 0)
		return (free(*line), *line = NULL, NULL);
	else if (check == 1 && *next)
		return (free(*next), *next = NULL, NULL);
	else if (check == 2)
		return (free(*buff), *buff = NULL, NULL);
	else if (check == 3)
		return (free(*next), free(*line), next = NULL, \
			free(*next), NULL);
	else if (check == 4)
		return (free(*line), free(*buff), *line = NULL, \
			*buff = NULL, NULL);
	else if (check == 5)
		return (free(*next), free(*buff), *next = NULL, \
			*buff = NULL, NULL);
	else if (check == -1)
		return (free(*buff), free(*line), free(*next), \
		*buff = NULL, *line = NULL, *next = NULL, NULL);
	return (NULL);
}

char	*ft_last(int fd, char **next, char **line)
{
	*line = ft_strjoin(line, *next, 0);
	if (!*line)
		return (NULL);
	*line = get_the_line(fd, next, line);
	if (!*line)
		return (NULL);
	return (*line);
}