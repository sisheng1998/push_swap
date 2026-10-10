/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 18:57:45 by siooi             #+#    #+#             */
/*   Updated: 2026/10/10 20:08:18 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_operation(char *operation)
{
	if (ft_strcmp(operation, "pa") == 0
		|| ft_strcmp(operation, "pb") == 0)
		return (1);
	else if (ft_strcmp(operation, "sa") == 0
		|| ft_strcmp(operation, "sb") == 0
		|| ft_strcmp(operation, "ss") == 0)
		return (1);
	else if (ft_strcmp(operation, "ra") == 0
		|| ft_strcmp(operation, "rb") == 0
		|| ft_strcmp(operation, "rr") == 0)
		return (1);
	else if (ft_strcmp(operation, "rra") == 0
		|| ft_strcmp(operation, "rrb") == 0
		|| ft_strcmp(operation, "rrr") == 0)
		return (1);
	return (0);
}

void	check_operations(char **args, char **operations)
{
	int	i;

	if (!operations)
		return ;
	i = 0;
	while (operations[i])
	{
		if (!is_operation(operations[i]))
		{
			free_args(operations);
			print_error(args);
		}
		i++;
	}
}

static void	execute_operation(t_stacks *stacks, char *operation)
{
	if (ft_strcmp(operation, "pa") == 0)
		pa(stacks, 0);
	else if (ft_strcmp(operation, "pb") == 0)
		pb(stacks, 0);
	else if (ft_strcmp(operation, "sa") == 0)
		sa(stacks, 0);
	else if (ft_strcmp(operation, "sb") == 0)
		sb(stacks, 0);
	else if (ft_strcmp(operation, "ss") == 0)
		ss(stacks, 0);
	else if (ft_strcmp(operation, "ra") == 0)
		ra(stacks, 0);
	else if (ft_strcmp(operation, "rb") == 0)
		rb(stacks, 0);
	else if (ft_strcmp(operation, "rr") == 0)
		rr(stacks, 0);
	else if (ft_strcmp(operation, "rra") == 0)
		rra(stacks, 0);
	else if (ft_strcmp(operation, "rrb") == 0)
		rrb(stacks, 0);
	else if (ft_strcmp(operation, "rrr") == 0)
		rrr(stacks, 0);
}

void	execute_operations(t_stacks *stacks, char **operations)
{
	int	i;

	if (!stacks || !operations)
		return ;
	i = 0;
	while (operations[i])
	{
		execute_operation(stacks, operations[i]);
		i++;
	}
}
