/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:08:21 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 10:46:00 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr((char *)set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr((char *)set, s1[end - 1])
			&& end > start)
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1 + start, (end - start + 1));
	}
	return (str);
}
/*
int	main(void) {
	char const *s1;
	char const *set;
	char *result;

	// Exemplo 1: Caracteres variados no conjunto `set`
	s1 = "   ---Hello, World!---   ";
	set = " -!";
	result = ft_strtrim(s1, set);
	if (result) {
		printf("Trimmed string 1: '%s'\n", result);
		free(result); // Liberar a memória alocada
	} else {
		printf("Failed to allocate memory.\n");
	}

	// Exemplo 2: Apenas um caractere no conjunto `set`
	s1 = "###Special###";
	set = "#";
	result = ft_strtrim(s1, set);
	if (result) {
		printf("Trimmed string 2: '%s'\n", result);
		free(result);
	} else {
		printf("Failed to allocate memory.\n");
	}

	// Exemplo 3: Conjunto `set` contendo múltiplos caracteres
	s1 = "abcdeabcd";
	set = "abc";
	result = ft_strtrim(s1, set);
	if (result) {
		printf("Trimmed string 3: '%s'\n", result);
		free(result);
	} else {
		printf("Failed to allocate memory.\n");
	}

	return (0);
}
*/
