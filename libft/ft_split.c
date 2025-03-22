/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:14:16 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/27 16:27:12 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *str, char c)
{
	size_t		i;
	size_t		words;

	i = 0;
	words = 0;
	if (str[i] == '\0' && c == '\0')
		return (0);
	while (str[i] == c)
	{
		i++;
	}
	while (str[i])
	{
		if ((!str[i + 1] || str[i + 1] == c)
			&& (str[i] != c))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static size_t	ft_wordlen(const char *str, size_t *i, char c)
{
	size_t	l;
	size_t	j;

	l = 0;
	j = *i;
	while (str[j] != c && str[j] != '\0')
	{
		j++;
		l++;
	}
	return (l);
}

static char	*ft_filltab(const char *str, char c, size_t *i)
{
	size_t	y;
	size_t	l;
	char	*temp;

	y = 0;
	l = ft_wordlen(str, i, c);
	temp = malloc(sizeof(char) * (l + 1));
	if (!temp)
		return (NULL);
	while (str[*i] != c && str[*i])
	{
		temp[y] = str[(*i)++];
		y++;
	}
	if (y > 0)
		temp[y] = '\0';
	return (temp);
}

static char	**ft_sepstr(char **tab, const char *str, char c, size_t w)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (words < w)
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c && (i == 0 || (i > 0 && str[i - 1] == c)))
		{
			tab[words] = ft_filltab(str, c, &i);
			if (!tab[words])
			{
				return (NULL);
			}
			words++;
		}
	}
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	size_t	w;
	int		i;
	char	**tab;

	i = 0;
	if (!str)
		return (NULL);
	w = ft_countwords(str, c);
	tab = malloc(sizeof(char *) * (w + 1));
	if (!tab)
		return (NULL);
	tab[w] = NULL;
	if (!(ft_sepstr(tab, str, c, w)))
	{
		while (tab[i])
		{
			free (tab[i]);
			tab[i] = NULL;
			i++;
		}
		free (tab);
		tab = NULL;
		return (NULL);
	}
	return (tab);
}
