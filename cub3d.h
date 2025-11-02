/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:37:11 by hacharka          #+#    #+#             */
/*   Updated: 2025/10/31 17:32:42 by hacharka         ###   ########.fr       */
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

typedef struct s_config
{
	char	*NO_PATH;
	char	*SO_PATH;
	char	*WE_PATH;
	char	*EA_PATH;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	
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

//-----------Parsing------------------
# endif