/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:58:04 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:46:41 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

/*
int	main(int ac, char **av)
{
	int	fd;

	fd = open("file", O_RDWR);
	if (fd == -1)
		return (printf("Erro ao abrir\n"));
	if (ac >= 2)
		ft_putendl_fd(av[1], fd);
}
*/
