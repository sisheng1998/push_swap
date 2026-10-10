/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:57:29 by siooi             #+#    #+#             */
/*   Updated: 2026/10/10 20:04:48 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_args_bonus(char **args)
{
	int		i;
	t_mode	mode;
	long	num;

	i = 0;
	while (args[i])
	{
		mode = get_mode(args[i]);
		if (mode == DEFAULT)
		{
			num = check_number(args, args[i]);
			check_duplicate(args, i, num);
		}
		else
			print_error(args);
		i++;
	}
}

void	parse_args_bonus(char **args, t_stacks *stacks)
{
	int		i;

	i = 0;
	while (args[i])
	{
		ft_lstadd_back(&stacks->a, ft_lstnew((int)ft_atol(args[i])));
		i++;
	}
	assign_index(stacks->a);
}

static char	*ft_read(int fd, char *text)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*new_text;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(text), NULL);
		buffer[bytes_read] = '\0';
		new_text = ft_strjoin(text, buffer);
		if (!new_text)
			return (free(buffer), free(text), NULL);
		free(text);
		text = new_text;
	}
	free(buffer);
	return (text);
}

char	**build_operations(int fd)
{
	char	**operations;
	char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_strdup("");
	text = ft_read(fd, text);
	if (!text || text[0] == '\0')
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	operations = ft_split(text, '\n');
	free(text);
	return (operations);
}
