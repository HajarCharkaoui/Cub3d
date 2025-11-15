/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:37:11 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/15 16:52:12 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_list
{
	char			*line;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_config
{
	char		*NO_PATH;
	char		*SO_PATH;
	char		*WE_PATH;
	char		*EA_PATH;
	int			floor_color;
	int			ceiling_color;
	int			setting_count;
	char		**map;
	double		X_player;
	double		Y_player;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_config;

//---------Libft--------------------
size_t	ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr (char *s, int c);
char	**ft_split(char *s, char c);
int		ft_atoi (char *str);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strtrim(char *s1, char const *set);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*node(char *line);
int		ft_lstsize(t_list *lst);

//-----------Parsing------------------
int		is_color(char *str);
int		is_deriction(char *str);
int		is_map(char *str);
void	free_args(char **strs);
void	free_config(t_config *config);
int		read_lines(int fd, t_list **map, t_config *config);
void	free_list(t_list *list);
void	set_path(char *path, t_config *conf);
void	init_config(t_config *config);
int		set_color(char *str, t_config *conf);
int		skip_whitespaces(char *str);
void	error(char *msg);
int		is_space(char c);
int		check_settings(t_config *conf);
int		empty_line(char *line);
void	save_map(t_list **map_list, char *data);
void	set_map(t_list *map_list, t_config *conf);
# endif