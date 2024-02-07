/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:08:04 by avaldin           #+#    #+#             */
/*   Updated: 2023/12/25 15:03:37 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (start > (unsigned int)ft_strlen(s) || !s)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	str = malloc(((len + 1) * sizeof(char)));
	if (!str)
		return (NULL);
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_countword(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[0] == '\0' || s == NULL)
		return (0);
	if (s[i] != c)
		count++;
	i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	*ft_addword(const char *s, char c, int *i)
{
	int		j;
	int		p;
	char	*str;

	p = *i;
	j = 0;
	while (s[p + j] != c && s[p + j])
		j++;
	str = ft_substr(s, *i, j);
	*i = *i + j;
	return (str);
}

char	**ft_freeee(char **str, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c, int *argc)
{
	int		i;
	int		n;
	char	**split;

	if (!s)
		return (NULL);
	*argc = ft_countword(s, c) + 1;
	split = malloc(*argc * sizeof(char *));
	i = 0;
	n = 0;
	if (!split)
		return (NULL);
	split[0] = NULL;
	while (n < *argc - 1)
	{
		if (s[i] != c)
		{
			split[n++ + 1] = ft_addword(s, c, &i);
			if (!split[n])
				return (ft_freeee(split, n));
		}
		else
			i++;
	}
	return (split);
}
