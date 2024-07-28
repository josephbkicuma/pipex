/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:42:10 by codespace         #+#    #+#             */
/*   Updated: 2024/07/28 10:53:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
    char    *str[] = {"/usr/bin/ls", "."};
    
    if ((execve("/usr/bin/ls", str, env) == -1))
        return (printf("Erro ao executar\n"));
    return (0);
}
