/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:42:10 by codespace         #+#    #+#             */
/*   Updated: 2024/08/03 15:31:39 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    free_arr(char **argv)
{
    size_t  i;

    i = -1;
    while (argv[++i])
        free(argv[i]);
    free(argv);
    argv = NULL;
}

void	exec_cmd(char *comand)
{
	char	**argv;
	char	*path;

	argv = ft_split(comand, ' ');
	path = ft_strjoin("/bin/", argv[0]);
	if (execve(path, argv, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
    free_arr(argv);
    free(path);
}

void	filein(char *filename, char *comand, int fd[2])
{
	int	fd_open;

	fd_open = open(filename, O_WRONLY, 0777);
	if (fd_open == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    dup2(fd_open, STDOUT_FILENO);
    close(fd_open);
	exec_cmd(comand);
}

void    fileout(char *filename, char *comand, int fd[2])
{
    int fd_open;

    fd_open = open(filename, O_TRUNC | O_CREAT | O_RDWR, 0777);
    if (fd_open == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    dup2(fd_open, STDIN_FILENO);
    close(fd_open);
    exec_cmd(comand);
}

int	main(int argc, char *argv[])
{
    int fd[2];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }    
	if (argc >= 3)
	{
		filein(argv[1], argv[2], fd);
        fileout(argv[4], argv[3], fd);
	}
	return (0);
}
