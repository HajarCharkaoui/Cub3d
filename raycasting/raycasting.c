/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:18:14 by azmakhlo          #+#    #+#             */
/*   Updated: 2026/01/22 20:02:31 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_wall_stripe(t_cast *g, t_wall *wall, int x)
{
	int			y;
	int			tex_y;
	uint32_t	color;

	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		tex_y = (int)wall->tex_pos;
		wall->tex_pos += wall->step;
		color = get_texture_color(wall->texture, wall->tex_x, tex_y);
		safe_pixel(g->img, x, y, color);
		y++;
	}
}

void	draw_wall_stripe(t_cast *g, t_ray *ray, int x)
{
	t_wall	wall;

	init_wall_drawing(g, ray, &wall);
	render_wall_stripe(g, &wall, x);
}

void	cast_rays(t_cast *g)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(g, &ray, x);
		calc_step_side_x(g, &ray);
		calc_step_side_y(g, &ray);
		perform_dda(g, &ray);
		ray.dist = calc_wall_dist(g, &ray);
		draw_wall_stripe(g, &ray, x);
		x++;
	}
}

void	game_loop(void *param)
{
	t_cast	*g;

	g = param;
	movement(g);
	rotate(g);
	draw_floor_and_ceiling(g->img);
	cast_rays(g);
}

int	raycasting(t_config *conf)
{
	t_cast	g;

	g.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!g.mlx)
		return (1);
	g.img = mlx_new_image(g.mlx, WIDTH, HEIGHT);
	if (!g.img)
		return (1);
	g.conf = conf;
	g.player_x = conf->x_player * TILE;
	g.player_y = conf->y_player * TILE;
	mlx_image_to_window(g.mlx, g.img, 0, 0);
	mlx_loop_hook(g.mlx, game_loop, &g);
	mlx_close_hook(g.mlx, clean_exit, &g);
	mlx_loop(g.mlx);
	mlx_terminate(g.mlx);
	return (0);
}
