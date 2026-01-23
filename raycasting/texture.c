/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:27:43 by azmakhlo          #+#    #+#             */
/*   Updated: 2026/01/22 19:54:34 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_texture_t	*get_texture(t_cast *g, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (g->conf->ea_texture);
		else
			return (g->conf->we_texture);
	}
	else
	{
		if (ray->dir_y > 0)
			return (g->conf->so_texture);
		else
			return (g->conf->no_texture);
	}
}

double	calc_wall_x(t_cast *g, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = g->player_y / TILE + ray->dist * ray->dir_y;
	else
		wall_x = g->player_x / TILE + ray->dist * ray->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

uint32_t	get_texture_color(mlx_texture_t *tex, int tex_x, int tex_y)
{
	int		index;
	uint8_t	*pixel;

	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= (int)tex->width)
		tex_x = tex->width - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= (int)tex->height)
		tex_y = tex->height - 1;
	index = (tex_y * tex->width + tex_x) * tex->bytes_per_pixel;
	pixel = &tex->pixels[index];
	return ((pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3]);
}

void	safe_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(img, x, y, color);
}
