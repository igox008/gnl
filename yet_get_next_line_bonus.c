/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:35:35 by alaassir          #+#    #+#             */
/*   Updated: 2023/12/07 23:31:25 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_nl(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_null(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(char *line, char *buff, int check)
{
	int		i;
	int		t;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!line || !buff)
		return (NULL);
	t = ft_strlen(line) + ft_strlen(buff);
	new = (char *)malloc(t + 1);
	if (new == NULL)
		return (NULL);
	while (line[j])
		new[i++] = line[j++];
	j = 0;
	while (buff[j])
		new[i++] = buff[j++];
	new[i] = '\0';
	if (check == 1 && buff)
		free(buff);
	else
		get_rmn(buff, buff);
	free(line);
	return (new);
}

char	*get_the_line(int fd, char *next, char **line)
{
	ssize_t	get_rd;
	char	buff[BUFFER_SIZE + 1];
	int		i;

	while (1)
	{
		i = 0;
		get_rd = read(fd, buff, BUFFER_SIZE);
		if (get_rd == -1)
			return (free(*line), NULL);
		if (get_rd <= 0)
			break ;
		buff[get_rd] = '\0';
		*line = ft_strjoin(*line, fill(buff), 1);
		if (check_nl(buff))
		{
			get_rmn(next, buff);
			break ;
		}
	}
	if (*line[0])
		return (*line);
	free(*line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	next_line[OPEN_MAX][BUFFER_SIZE];
	char		*line;

	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (check_nl(next_line[fd]))
	{
		line = fill(next_line[fd]);
		get_rmn(next_line[fd], next_line[fd]);
	}
	else if (check_nl(next_line[fd]) == 0)
	{
		line = ft_strjoin(ft_null(), next_line[fd], 0);
		line = get_the_line(fd, next_line[fd], &line);
	}
	if (!line || !*line)
		return (NULL);
	return (line);
}
