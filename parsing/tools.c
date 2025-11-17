/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:59:44 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/17 20:34:59 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	direction_vector(t_config *conf, double dir_x, double dir_y)
{
	conf->dir_x = dir_x;
	conf->dir_y = dir_y;
}

void	camera_vector(t_config *conf, double plane_x, double plane_y)
{
	conf->plane_x = plane_x;
	conf->plane_y = plane_y;
}

void	set_coordinates(t_config *conf, int y, int x)
{
	char	dir;

	dir = conf->map[y][x];
	conf->x_player = x;
	conf->y_player = y;
	if (dir == 'N')
	{
		direction_vector(conf, 0, -1);
		camera_vector(conf, 0.66, 0);
	}
	else if (dir == 'S')
	{
		direction_vector(conf, 0, 1);
		camera_vector(conf, -0.66, 0);
	}
	else if (dir == 'E')
	{
		direction_vector(conf, 1, 0);
		camera_vector(conf, 0, 0.66);
	}
	else if (dir == 'W')
	{
		direction_vector(conf, -1, 0);
		camera_vector(conf, 0, -0.66);
	}
}
