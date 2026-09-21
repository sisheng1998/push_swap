/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:23:42 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 12:53:43 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mode	get_mode(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(str, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(str, "--complex") == 0)
		return (COMPLEX);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (ADAPTIVE);
	if (ft_strcmp(str, "--bench") == 0)
		return (BENCH);
	return (DEFAULT);
}

void	init_flags(t_flags *flags)
{
	flags->mode = DEFAULT;
	flags->bench = 0;
}
