/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:28:23 by azmakhlo          #+#    #+#             */
/*   Updated: 2026/01/22 23:43:37 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(t_cast *g, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = g->conf->dir_x + g->conf->plane_x * camera_x;
	ray->dir_y = g->conf->dir_y + g->conf->plane_y * camera_x;
	ray->map_x = (int)(g->player_x / TILE);
	ray->map_y = (int)(g->player_y / TILE);
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
}

void	calc_step_side_x(t_cast *g, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (g->player_x / TILE - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - g->player_x / TILE) * ray->delta_x;
	}
}

void	calc_step_side_y(t_cast *g, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (g->player_y / TILE - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - g->player_y / TILE) * ray->delta_y;
	}
}

void	perform_dda(t_cast *g, t_ray *ray)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (g->conf->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

double	calc_wall_dist(t_cast *g, t_ray *ray)
{
	double	dist;

	if (ray->side == 0)
		dist = (ray->map_x - g->player_x / TILE + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		dist = (ray->map_y - g->player_y / TILE + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	if (dist < 0.01)
		dist = 0.01;
	return (dist);
}
