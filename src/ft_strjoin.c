/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:54:52 by kicuma            #+#    #+#             */
/*   Updated: 2024/08/03 14:40:01 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	char	*ret;

	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	ret = joined;
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	*joined = '\0';
	return (ret);
}

/*
int	main()
{
	char	*str = ft_strjoin("Joseph ", "Kicuma");

	printf("%s\n", str);
	free(str);
	return (0);
}
*/
