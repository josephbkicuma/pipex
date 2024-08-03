/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:42:10 by codespace         #+#    #+#             */
/*   Updated: 2024/08/03 14:30:01 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_cmd(char *comand)
{
	char    **argv;
    char    *path;

    argv = ft_split(comand, ' ');
    path = ft_strjoin("/bin/", argv[0]);
    if (execve(path, argv, NULL) == -1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

void    filein(char *filename, char *comand)
{
    int fd;
    
    fd = open(filename, O_WRONLY, 0777);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    exec_cmd(comand);
}

int	main(int argc, char *argv[], char *envp[])
{
    if (argc >= 3)
    {
        filein(argv[1], argv[2]);
    }
    return (0);
}
