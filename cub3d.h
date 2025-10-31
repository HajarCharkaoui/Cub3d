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

typedef struct s_config
{
	char	*NO_PATH;
	char	*SO_PATH;
	char	*WE_PATH;
	char	*EA_PATH;
	int		floor_color;
	int		ceiling_color;
	
}	t_config;
size_t	ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

# endif