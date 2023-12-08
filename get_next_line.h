/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:35:02 by alaassir          #+#    #+#             */
/*   Updated: 2023/12/08 00:55:47 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*fill(char *buff);
void	get_rmn(char *dst, char **src, int check);
size_t	ft_strlen(const char *str);
char	*ft_free(char **line, char **next, char **buff, int check);
char	*ft_last(int fd, char **next, char **line);
char	*ft_strjoin(char **line, char *buff, int check);
char	*get_the_line(int fd, char **next, char **line);

#endif