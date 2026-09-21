/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 16:56:06 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 15:26:49 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*str_join_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	**build_args(char **argv)
{
	char	**args;
	char	*str;
	int		i;

	if (!argv || !argv[1])
		return (NULL);
	str = ft_strdup("");
	i = 1;
	while (str && argv[i])
	{
		str = str_join_free(str, argv[i]);
		if (str && argv[i + 1])
			str = str_join_free(str, " ");
		i++;
	}
	if (!str)
		return (NULL);
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

void	parse_args(char **args, t_flags *flags, t_stacks *stacks)
{
	int		i;
	t_mode	mode;

	i = 0;
	while (args[i])
	{
		mode = get_mode(args[i]);
		if (mode == DEFAULT)
			ft_lstadd_back(&stacks->a, ft_lstnew((int)ft_atol(args[i])));
		else if (mode == BENCH)
			flags->bench = 1;
		else
			flags->mode = mode;
		i++;
	}
	assign_index(stacks->a);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
