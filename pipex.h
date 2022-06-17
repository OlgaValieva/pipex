/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:12:16 by carys             #+#    #+#             */
/*   Updated: 2022/04/02 15:04:29 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

int		main(int argc, char **argv, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_free(char **str);
void	ft_perror(char *str);
void	ft_putstr_fd(char *s1, int fd);
char	*path(char **cmd, char **envp);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);

#endif
