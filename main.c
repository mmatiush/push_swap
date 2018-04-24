/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:46:53 by mmatiush          #+#    #+#             */
/*   Updated: 2017/12/28 17:46:56 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char *av[])
{
	char	*res;
	//char	*res2;
	int		fd1;
	int		result;
	//int 	fd2;
	int i = 0;
	res = 0;
	if (ac == 2)
	{
		if ((fd1 = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr("Open error;");
			return (1);
		}
		// if ((fd2 = open(av[2], O_RDONLY)) < 0)
		// {
		// 	ft_putstr("Open error;");
		// 	return (1);
		// }
		while ((result = get_next_line(fd1, &res)) == 1)
		{
			printf("%s\n", res);
			free(res);
		}
		
		if (close(fd1) < 0)
		{
			ft_putstr("Close error;");
			return (1);
		}
	}
	else 
		ft_putstr("Usage: get_next_line file1");
	//system("leaks get_next_line");
	return (0);
}
