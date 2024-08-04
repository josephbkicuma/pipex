/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:56 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/04 01:38:02 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	k;

	p = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!p)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		p[j] = malloc(sizeof(char) * (word_len(&s[i], c) + 1));
		if (!p[j])
			return (NULL);
		while (s[i] && s[i] != c)
			p[j][k++] = s[i++];
		p[j][k] = '\0';
		j++;
	}
	p[j] = NULL;
	return (p);
}

/*
int	main(int ac, char **av)
{
	char	**p;
	size_t	i;

	if (ac < 2)
		return (0);
	p = ft_split(av[1], 'x');
	i = -1;
	while (p[++i])
	{
		printf("%s\n", p[i]);
		free(p[i]);
	}
	free(p);
	return (0);
}
*/
