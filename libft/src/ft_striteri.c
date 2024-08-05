/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:37:23 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:40:51 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	to_lower(unsigned int i, char *str);

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}

/*
void reverse_char(unsigned int index, char *c) 
{
    size_t len = ft_strlen(c);
    *c = c[len - 1 - index];
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac >= 2)
	{
		str = av[1];
		ft_striteri(str, reverse_char);
		printf("%s\n", str);
	}
	return (0);
}
*/
