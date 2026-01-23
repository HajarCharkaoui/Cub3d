/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:00:00 by azmakhlo          #+#    #+#             */
/*   Updated: 2026/01/22 20:02:07 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_cast *g)
{
	int		speed;
	double	move_x;
	double	move_y;

	speed = MOVE_SPEED;
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
		speed *= 3;
	move_x = g->conf->dir_x * speed;
	move_y = g->conf->dir_y * speed;
	move_with_slide(g, move_x, move_y);
}

void	move_down(t_cast *g)
{
	int		speed;
	double	move_x;
	double	move_y;

	speed = MOVE_SPEED;
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
		speed *= 3;
	move_x = -g->conf->dir_x * speed;
	move_y = -g->conf->dir_y * speed;
	move_with_slide(g, move_x, move_y);
}

void	move_left(t_cast *g)
{
	int		speed;
	double	move_x;
	double	move_y;

	speed = MOVE_SPEED;
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
		speed *= 3;
	move_x = -g->conf->plane_x * speed;
	move_y = -g->conf->plane_y * speed;
	move_with_slide(g, move_x, move_y);
}

void	move_right(t_cast *g)
{
	int		speed;
	double	move_x;
	double	move_y;

	speed = MOVE_SPEED;
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
		speed *= 3;
	move_x = g->conf->plane_x * speed;
	move_y = g->conf->plane_y * speed;
	move_with_slide(g, move_x, move_y);
}

void	movement(t_cast *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		move_up(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		move_down(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		move_left(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		move_right(g);
}
