/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:08:09 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:40:38 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
	return (s);
}

/*
int	main()
{
	char	*str;

	str = malloc(8);
	ft_memset(str, 'A', 7);
	printf("%s\n", str);
	ft_bzero(str, 7);
	printf("Zero: %s\n", str);
	return (0);
}
*/
