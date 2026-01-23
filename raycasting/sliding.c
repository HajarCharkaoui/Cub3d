/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:01:20 by azmakhlo          #+#    #+#             */
/*   Updated: 2026/01/22 20:02:44 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_with_slide(t_cast *g, double move_x, double move_y)
{
	double	nx;
	double	ny;

	nx = g->player_x + move_x;
	ny = g->player_y + move_y;
	if (!check_collision(nx, ny, g->conf))
	{
		g->player_x = nx;
		g->player_y = ny;
		return ;
	}
	nx = g->player_x + move_x;
	if (!check_collision(nx, g->player_y, g->conf))
	{
		g->player_x = nx;
		return ;
	}
	ny = g->player_y + move_y;
	if (!check_collision(g->player_x, ny, g->conf))
		g->player_y = ny;
}

void	clean_exit(void *param)
{
	t_cast	*g;

	g = (t_cast *)param;
	if (g->img)
		mlx_delete_image(g->mlx, g->img);
	if (g->conf->no_texture)
		mlx_delete_texture(g->conf->no_texture);
	if (g->conf->so_texture)
		mlx_delete_texture(g->conf->so_texture);
	if (g->conf->we_texture)
		mlx_delete_texture(g->conf->we_texture);
	if (g->conf->ea_texture)
		mlx_delete_texture(g->conf->ea_texture);
	mlx_terminate(g->mlx);
	exit(EXIT_SUCCESS);
}
