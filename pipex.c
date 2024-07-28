/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:42:10 by codespace         #+#    #+#             */
/*   Updated: 2024/07/28 14:20:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    // Nome do arquivo de saída
    char *outfile = "output.txt";
    
    // Criação do processo filho
    pid_t pid = fork();
    
    if (pid < 0) {
        // Erro ao criar o processo filho
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Processo filho
        // Abre o arquivo de saída
        int fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            perror("open");
            exit(1);
        }

        // Redireciona a saída padrão (stdout) para o arquivo
        if (dup2(fd, STDOUT_FILENO) < 0) {
            perror("dup2");
            exit(1);
        }

        // Fecha o descritor de arquivo, pois ele já está duplicado
        close(fd);

        // Argumentos para o comando ls
        char *cmd = "/bin/ls";
        char *args[] = {cmd, NULL};

        // Executa o comando ls
        if (execve(cmd, args, NULL) < 0) {
            perror("execve");
            exit(1);
        }
    } else {
        // Processo pai
        // Espera o processo filho terminar
        wait(NULL);
    }

    return 0;
}

