/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/10/31 16:45:45 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	size_t	len;
	char	*file_name;

	if (ac != 2)
		return (1);
	file_name = av[1];
	len = ft_strlen (av[1]);
	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
		return(,1)
	
}