/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:00:00 by azmakhlo          #+#    #+#             */
/*   Updated: 2026/01/23 01:24:09 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	action_rotate(t_config *c, double angle)
{
	double	old;

	old = c->dir_x;
	c->dir_x = c->dir_x * cos(angle) - c->dir_y * sin(angle);
	c->dir_y = old * sin(angle) + c->dir_y * cos(angle);
	old = c->plane_x;
	c->plane_x = c->plane_x * cos(angle) - c->plane_y * sin(angle);
	c->plane_y = old * sin(angle) + c->plane_y * cos(angle);
}

void	rotate(t_cast *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
		action_rotate(g->conf, ROTATION_SPEED);
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
		action_rotate(g->conf, -ROTATION_SPEED);
}

int	is_wall(double x, double y, t_config *conf)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = (int)(x / TILE);
	map_y = (int)(y / TILE);
	if (!conf->map[map_y])
		return (1);
	if (map_x >= (int)ft_strlen(conf->map[map_y]))
		return (1);
	if (conf->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	check_collision(double x, double y, t_config *conf)
{
	if (is_wall(x, y, conf))
		return (1);
	if (is_wall(x - PLAYER_MINI, y - PLAYER_MINI, conf))
		return (1);
	if (is_wall(x + PLAYER_MINI, y - PLAYER_MINI, conf))
		return (1);
	if (is_wall(x - PLAYER_MINI, y + PLAYER_MINI, conf))
		return (1);
	if (is_wall(x + PLAYER_MINI, y + PLAYER_MINI, conf))
		return (1);
	return (0);
}
