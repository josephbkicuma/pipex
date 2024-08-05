/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:53:00 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:45:14 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = -1;
	ptr = (unsigned char *)s;
	while (++i < n)
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "Joseph Kicuma";

	printf("%s\n", (char *)memchr(str, 'K', 6));
}
*/
