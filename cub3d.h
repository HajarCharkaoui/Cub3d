/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:37:11 by hacharka          #+#    #+#             */
/*   Updated: 2026/01/23 01:41:18 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define HEIGHT 1080
# define WIDTH 1920
# define TILE 31
# define PLAYER_MINI 8
# define MOVE_SPEED 3
# define ROTATION_SPEED 0.04
# define CEILING_COLOR 0x87CEEBFF
# define FLOOR_COLOR 0x444444FF

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>

typedef struct s_tex
{
	int				tex_x;
	int				tex_y;
	double			tex_pos;
	double			step;
}					t_tex;

typedef struct s_list
{
	char			*line;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_ray
{
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			delta_x;
	double			delta_y;
	int				step_x;
	int				step_y;
	double			side_x;
	double			side_y;
	int				hit;
	int				side;
	double			dist;
	double			wall_x;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_config
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				floor_color;
	int				ceiling_color;
	int				setting_count;
	char			**map;
	double			x_player;
	double			y_player;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
}					t_config;

typedef struct s_cast
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	double			player_x;
	double			player_y;
	double			angle;
	t_config		*conf;
}					t_cast;

typedef struct s_wall
{
	mlx_texture_t	*texture;
	int				tex_x;
	int				line_h;
	double			wall_x;
	int				draw_start;
	int				draw_end;
	double			step;
	double			tex_pos;
}					t_wall;
//---------Libft--------------------
size_t				ft_strlen(char *s);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strdup(char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *s, int c);
char				**ft_split(char *s, char c);
int					ft_atoi(char *str);
char				*get_next_line(int fd);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strtrim(char *s1, char const *set);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*node(char *line);
int					ft_lstsize(t_list *lst);

//-----------Parsing------------------
int					is_color(char *str);
int					is_deriction(char *str);
int					is_map(char *str);
void				free_args(char **strs);
void				free_config(t_config *config);
int					read_lines(int fd, t_list **map, t_config *config);
void				free_list(t_list *list);
void				set_path(char *path, t_config *conf);
void				init_config(t_config *config);
int					set_color(char *str, t_config *conf);
int					skip_whitespaces(char *str);
void				error(char *msg);
int					is_space(char c);
int					check_settings(t_config *conf);
int					empty_line(char *line);
void				save_map(t_list **map_list, char *data);
void				set_map(t_list *map_list, t_config *conf);
int					set_player_pos(t_config *conf);
int					parsing(char *file_name, t_config *config);
void				set_coordinates(t_config *conf, int y, int x);
int					valide_path(t_config *conf);

//-----------Raycasting------------------
int					raycasting(t_config *game_conf);
void				game_loop(void *param);
void				clean_exit(void *param);
void				cast_rays(t_cast *g);
void				draw_wall_stripe(t_cast *g, t_ray *ray, int x);
void				init_wall_drawing(t_cast *g, t_ray *ray, t_wall *wall);
void				render_wall_stripe(t_cast *g, t_wall *wall, int x);
void				init_ray(t_cast *g, t_ray *ray, int x);
void				calc_step_side_x(t_cast *g, t_ray *ray);
void				calc_step_side_y(t_cast *g, t_ray *ray);
void				perform_dda(t_cast *g, t_ray *ray);
double				calc_wall_dist(t_cast *g, t_ray *ray);
void				movement(t_cast *g);
void				move_up(t_cast *g);
void				move_down(t_cast *g);
void				move_left(t_cast *g);
void				move_right(t_cast *g);
void				move_with_slide(t_cast *g, double move_x, double move_y);
void				rotate(t_cast *g);
void				action_rotate(t_config *c, double angle);
int					check_collision(double x, double y, t_config *conf);
int					is_wall(double x, double y, t_config *conf);
mlx_texture_t		*get_texture(t_cast *g, t_ray *ray);
double				calc_wall_x(t_cast *g, t_ray *ray);
uint32_t			get_texture_color(mlx_texture_t *tex, int tex_x, int tex_y);
void				safe_pixel(mlx_image_t *img, int x, int y, uint32_t color);
int					load_all_textures(t_config *conf);
void				free_textures(t_config *conf);
int					get_map_rows(char **map);
int					get_map_cols(char **map);
void				draw_floor_and_ceiling(mlx_image_t *img);

#endif