/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:56 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/05 11:57:41 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <wait.h>
# include <stdio.h>

# ifndef STD_ERR
#  define STD_ERR

#  define PARAM_ERR "execute: <file1> <cmd1> <cmd2> <file2>\n"
#  define FORK_ERR "fork: fail executing fork\n"

# endif

# include "../libft/src/libft.h"
/*size_t	ft_strlen(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_putstr_fd(char *str, int fd);*/

#endif