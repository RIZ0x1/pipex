/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:22:45 by jcarlena          #+#    #+#             */
/*   Updated: 2021/10/21 15:45:16 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
			(n++);
		while (s[i] != c && s[i])
			(i++);
		while (s[i] == c && s[i])
			(i++);
	}
	return (n);
}

static size_t	ft_wordsize(const char *word, const char c)
{
	size_t	n;

	n = 0;
	while (*word == c)
		(word)++;
	while (word[n] != c && word[n])
		(n++);
	return (n);
}

static void	*ft_clearlist(char **list, size_t i)
{
	i = 0;
	while (i > 0)
	{
		free(list[i]);
		(i++);
	}
	free(list);
	return (NULL);
}

void	base_assignment(size_t *lsize, char ***list, char const *s, char c)
{
	*lsize = ft_countwords(s, c);
	*list = malloc((*lsize + 1) * sizeof(char *));
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	lsize;
	size_t	i;
	size_t	j;

	base_assignment(&lsize, &list, s, c);
	if (!s)
		return (NULL);
	if (!list)
		return (NULL);
	i = 0;
	j = 0;
	while (i < lsize && lsize != 0)
	{
		while (s[j] == c)
			j++;
		list[i] = ft_substr(s, j, ft_wordsize((s + j), c));
		if (list[i] == NULL)
			return (ft_clearlist(list, i));
		while (s[j] != c && s[j])
			(j++);
		(i++);
	}
	list[i] = NULL;
	return (list);
}
