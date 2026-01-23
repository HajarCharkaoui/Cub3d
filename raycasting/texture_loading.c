/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 00:00:00 by azmakhlo          #+#    #+#             */
/*   Updated: 2026/01/22 23:43:45 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_texture(mlx_texture_t **texture, char *path)
{
	*texture = mlx_load_png(path);
	if (!*texture)
	{
		write(2, "Error\nFailed to load texture: ", 30);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		return (1);
	}
	return (0);
}

void	free_textures(t_config *conf)
{
	if (conf->no_texture)
		mlx_delete_texture(conf->no_texture);
	if (conf->so_texture)
		mlx_delete_texture(conf->so_texture);
	if (conf->we_texture)
		mlx_delete_texture(conf->we_texture);
	if (conf->ea_texture)
		mlx_delete_texture(conf->ea_texture);
}

int	load_all_textures(t_config *conf)
{
	conf->no_texture = NULL;
	conf->so_texture = NULL;
	conf->we_texture = NULL;
	conf->ea_texture = NULL;
	if (load_texture(&conf->no_texture, conf->no_path))
		return (free_textures(conf), 1);
	if (load_texture(&conf->so_texture, conf->so_path))
		return (free_textures(conf), 1);
	if (load_texture(&conf->we_texture, conf->we_path))
		return (free_textures(conf), 1);
	if (load_texture(&conf->ea_texture, conf->ea_path))
		return (free_textures(conf), 1);
	return (0);
}

void	init_wall_drawing(t_cast *g, t_ray *ray, t_wall *wall)
{
	wall->texture = get_texture(g, ray);
	wall->line_h = (int)(HEIGHT / ray->dist);
	wall->wall_x = calc_wall_x(g, ray);
	wall->tex_x = (int)(wall->wall_x * wall->texture->width);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		wall->tex_x = wall->texture->width - wall->tex_x - 1;
	wall->draw_start = -wall->line_h / 2 + HEIGHT / 2;
	wall->draw_end = wall->line_h / 2 + HEIGHT / 2;
	wall->step = (double)wall->texture->height / wall->line_h;
	wall->tex_pos = 0;
	if (wall->draw_start < 0)
	{
		wall->tex_pos = -wall->draw_start * wall->step;
		wall->draw_start = 0;
	}
	if (wall->draw_end >= HEIGHT)
		wall->draw_end = HEIGHT - 1;
}

void	draw_floor_and_ceiling(mlx_image_t *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, CEILING_COLOR);
			else
				mlx_put_pixel(img, x, y, FLOOR_COLOR);
			x++;
		}
		y++;
	}
}
