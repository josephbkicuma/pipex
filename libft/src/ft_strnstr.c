/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:13:19 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:40:51 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((big == NULL || little == NULL) && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j]
			&& little[j]
			&& big[i + j] == little[j]
			&& i + j < len)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>  // Para strnstr

int main() {
    char haystack[] = "Procurando por algo aqui.";
    char needle[] = "";

    // Procurar por 'needle' dentro dos primeiros 15 caracteres de 'haystack'
    char *result = ft_strnstr(haystack, needle, 15);

    if (result) {
        printf("Substring encontrada: %s\n", result);
    } else {
        printf("Substring não encontrada dentro do limite especificado.\n");
    }

    return 0;
}
*/
