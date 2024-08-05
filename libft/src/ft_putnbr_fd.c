/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:07:47 by jquicuma          #+#    #+#             */
/*   Updated: 2024/07/31 12:16:38 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

/*
int	main(int ac, char **av)
{
	int	fd;

	fd = open("file", O_RDWR);
	if (fd == -1)
		return (printf("Erro ao abrir!\n"));
	if (ac >= 2)
		ft_putnbr_fd(atoi(av[1]), fd);
	return (0);
}
*/
