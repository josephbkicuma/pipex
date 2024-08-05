/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:57:35 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:40:51 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if ((dest == NULL || src == NULL) && !size)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size < dest_len + 1)
		return (size + src_len);
	else if (size > dest_len + 1)
	{
		while (src[i] && (dest_len + i) < (size - 1))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = 0;
	return (dest_len + src_len);
}

/*
int main() {
    // Inicializando duas strings
    char str1[50] = "Olá, ";
    char str2[] = "mundo!";
    size_t max_size = sizeof(str1); // Tamanho máximo do buffer de str1

    size_t result = ft_strlcat(str1, str2, max_size);

    printf("Resultado da concatenação: %s\n", str1);
    printf("Tamanho total esperado da string: %zu\n", result);

    return 0;
}
*/
