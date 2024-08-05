/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:34:20 by jquicuma          #+#    #+#             */
/*   Updated: 2024/07/31 11:44:36 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main()
{
	int	fd;

	fd = open("file", O_RDWR);
	if (fd == -1)
		return (printf("Erro ao abrir\n"));
	ft_putchar_fd('a', fd);
	return (0);
}
*/
