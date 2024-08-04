/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:56 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/04 05:30:07 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_arr(char **arr)
{
	char	**temp;

	temp = arr;
	if (temp && *temp)
		while (*temp)
			free(*temp++);
	free(arr);
}

int	exec_cmd(char *comand)
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
	return (0);
}

int	filein(char *input_file, char *comand, int pipe_fd[2])
{
	int	fd;

	close(pipe_fd[0]);
	fd = open(input_file, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipe_fd[1]);
	close(fd);
	exec_cmd(comand);
	return (0);
}

int	fileout(char *output_file, char *comand, int pipe_fd[2])
{
	int	fd;

	close(pipe_fd[1]);
	fd = open(output_file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	close(fd);
	exec_cmd(comand);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	if (argc != 5)
		return (ft_putstr_fd(PARAM_ERR, 2));
	pid1 = fork();
	if (pid1 == 0)
		filein(argv[1], argv[2], fd);
	pid2 = fork();
	if (pid2 < 0 || pid1 < 0)
		return (ft_putstr_fd(FORK_ERR, 2));
	if (pid2 == 0)
		fileout(argv[4], argv[3], fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
