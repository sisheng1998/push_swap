/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:15:43 by siooi             #+#    #+#             */
/*   Updated: 2026/10/04 17:44:51 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

void	check_args_bonus(char **args);
void	parse_args_bonus(char **args, t_stacks *stacks);
char	**build_operations(int fd);
void	check_operations(char **args, char **operations);
void	execute_operations(t_stacks *stacks, char **operations);

#endif
