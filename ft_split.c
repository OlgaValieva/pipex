/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:11:31 by carys             #+#    #+#             */
/*   Updated: 2022/04/02 15:38:12 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count(const char *str, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_freee(char **car)
{
	unsigned int	i;

	i = 0;
	while (car[i])
		free(car[i++]);
	free(car);
	return (NULL);
}

static int	count_char(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**write_split(char **result, const char *s, char c)
{
	char			*word;
	unsigned int	i;

	i = 0;
	while (*s)
	{
		if (*s && *s == c)
			s++;
		else
		{
			word = (char *)malloc(sizeof(char) * (count_char(s, c) + 1));
			if (word == 0)
				return (ft_freee(result));
			while (*s && *s != c)
				word[i++] = *s++;
			word[i] = '\0';
			i = 0;
			*result++ = word;
		}
	}
	*result++ = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = ft_count(s, c);
	result = (char **)malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	if (write_split(result, s, c))
		return (result);
	return (NULL);
}
