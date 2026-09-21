/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:50:45 by siooi             #+#    #+#             */
/*   Updated: 2026/09/19 17:24:06 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	new_word;
	int	i;

	count = 0;
	i = 0;
	new_word = 1;
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		else if (new_word == 1)
		{
			new_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *str_index)
{
	char	*str;
	int		str_len;
	int		i;
	int		start_index;

	while (s[*str_index] && s[*str_index] == c)
		(*str_index)++;
	str_len = 0;
	start_index = (*str_index);
	while (s[*str_index] && s[*str_index] != c)
	{
		str_len++;
		(*str_index)++;
	}
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str[i] = s[start_index + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**free_arr(char **arr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_len;
	int		i;
	int		str_index;

	if (!s)
		return (NULL);
	arr_len = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	str_index = 0;
	while (i < arr_len)
	{
		arr[i] = get_word(s, c, &str_index);
		if (!arr[i])
			return (free_arr(arr, i));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
