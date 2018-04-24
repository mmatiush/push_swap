/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:23:14 by mmatiush          #+#    #+#             */
/*   Updated: 2017/12/28 15:23:17 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	int	check_line(char **line, char **leftover)
{
	char	*temp;
	char	*ptr_to_n;

	if ((ptr_to_n = ft_strchr(*leftover, '\n')))
	{
		*ptr_to_n = '\0';
		temp = ft_strdup(*line);
		*leftover = ft_strdup(++ptr_to_n);
		free(*line);
		*line = temp;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	char *temp;
	static char *leftover[1000];
	int n_read;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	*line = leftover[fd];
	if (!leftover[fd])
		leftover[fd] = ft_strnew(1);
	else
	{
		if (check_line(&(*line), &leftover[fd]))
			return (1);
	}
	while ((n_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n_read] = '\0';
		temp = ft_strjoin(leftover[fd], buf);
		ft_strdel(&leftover[fd]);
		leftover[fd] = temp;
		*line = temp;
		if (check_line(&(*line), &leftover[fd]))
			return (1);
	}
	if (n_read == -1)
		return (-1);
	if (n_read == 0)
	{	
		if (leftover[fd][0] == '\0')
			return (0);
		leftover[fd] = NULL;
		return (1);
	}
	return (1);
}
