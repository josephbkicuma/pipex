/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:16:22 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:40:51 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	to_lower(unsigned int index, char c);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = -1;
	while (++i < len)
		res[i] = f(i, s[i]);
	res[i] = '\0';
	return (res);
}

/*
int	main(int ac, char *av[])
{
	if (ac >= 2)
		printf("%s\n", ft_strmapi(av[1], to_lower));
}

char	to_lower(unsigned int index, char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	index++;
	return (c);
}
*/
