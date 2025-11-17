/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:32:54 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/17 20:37:07 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ll(void)
{
	system("leaks -q cub3D");
}

int	main(int ac, char **av)
{
	t_config	*game_conf;

	// atexit(ll);
	if (ac != 2)
		return (1);
	game_conf = malloc(sizeof(t_config));
	if (!game_conf)
		return (1);
	if (parsing(av[1], game_conf) == -1)
		return (free_config(game_conf), free(game_conf), 1);
	free_config(game_conf);
	free(game_conf);
	return (0);
}
