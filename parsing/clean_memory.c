/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:38:32 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/12 17:07:10 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_args(char **strs)
{
	int	i;

	i = 0;
	while(strs[i])
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
		if (config->NO_PATH)
			free(config->NO_PATH);
		if (config->SO_PATH)
			free(config->SO_PATH);
		if (config->WE_PATH)
			free(config->WE_PATH);
		if (config->EA_PATH)
			free(config->EA_PATH);
		if (config->map)
			free_args(config->map);
		// also free your map, textures, etc.

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
