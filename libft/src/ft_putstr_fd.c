/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:46:53 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 11:56:22 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	return ((int)len);
}

/*
int	main(int ac, char **av)
{
	int	fd;

	fd = open("file", O_RDWR);
	if (fd == -1)
		return (printf("Fail opening\n"));
	if (ac >= 2)
		ft_putstr_fd(av[1], fd);
	return (0);
}
*/
