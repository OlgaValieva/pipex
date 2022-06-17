/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:12:10 by carys             #+#    #+#             */
/*   Updated: 2022/04/13 11:20:37 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	childing1(int *pid, char **argv, char **envp)
{
	int		infile;
	char	**cmd1;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		write(2, "pipex: ", 7);
		ft_perror(argv[1]);
	}
	close(pid[0]);
	dup2(pid[1], STDOUT_FILENO);
	close(pid[1]);
	dup2(infile, STDIN_FILENO);
	cmd1 = ft_split(argv[2], ' ');
	if (execve((path(cmd1, envp)), cmd1, envp) == -1)
	{
		ft_putstr_fd("command_1 not found: ", 2);
		ft_putstr_fd(argv[2], 2);
		exit(127);
	}
}

static void	childing2(int *pid, char **argv, char **envp)
{
	int		outfile;
	char	**cmd2;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (outfile < 0)
	{
		write(2, "pipex: ", 7);
		ft_perror(argv[4]);
	}
	close(pid[1]);
	dup2(pid[0], STDIN_FILENO);
	close(pid[0]);
	dup2(outfile, STDOUT_FILENO);
	cmd2 = ft_split(argv[3], ' ');
	if (execve((path(cmd2, envp)), cmd2, envp) == -1)
	{
		ft_putstr_fd("command_2 not found: ", 2);
		ft_putstr_fd(argv[3], 2);
		exit(127);
	}
}

static void	forking(int *pid, char **argv, char **envp)
{
	int	child1;
	int	child2;

	child1 = fork();
	if (child1 == -1)
		ft_perror("forking1 error ");
	if (child1 == 0)
		childing1(pid, argv, envp);
	child2 = fork();
	if (child2 == -1)
		ft_perror("forking2 error ");
	if (child2 == 0)
		childing2(pid, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	int	pid[2];

	if (argc != 5)
	{
		ft_putstr_fd("invalid number of arguments\n", 2);
		return (1);
	}
	if (pipe(pid) == -1)
	{
		perror("Error pipe");
		return (1);
	}
	forking(pid, argv, envp);
	close(pid[0]);
	close(pid[1]);
	waitpid(-1, &status, 0);
	return (0);
}
