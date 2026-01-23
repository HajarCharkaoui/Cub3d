/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:38:32 by hacharka          #+#    #+#             */
/*   Updated: 2026/01/20 16:37:46 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_args(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_config(t_config *config)
{
	if (config)
	{
		if (config->no_path)
			free(config->no_path);
		if (config->so_path)
			free(config->so_path);
		if (config->we_path)
			free(config->we_path);
		if (config->ea_path)
			free(config->ea_path);
		if (config->map)
			free_args(config->map);
	}
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
	}
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}
