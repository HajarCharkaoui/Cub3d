/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:46:30 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/03 16:19:14 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_data(t_list *lines, t_config *config)
{
	t_list	*tmp;

	tmp = lines;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "\n", 1) == 0 || ft_strncmp(tmp->line, "\0", 1) == 0)
			tmp = tmp->next;
		else if (!valide_line(tmp))
		{
			free_list(lines);
			free_config(config);
			exit(1);
		}
		else
		{
			if (is_deriction(tmp->line))
				set_path(tmp->line, config);
			else if (is_color(tmp->line))
				set_color(tmp->line, config);
			tmp = tmp->next;
		}
		
	}
	free_list(lines);
}
int	parse_file(int fd, t_config *config)
{
	char	*line;
	t_list	*head;
	t_list	*new_node;

	head = NULL;
	while ((line = get_next_line(fd)))
	{
		new_node = node(line);
		if (!new_node)
		{
			free(line);
			free_list(head);
			perror("malloc");
			return (-1);
		}
		free(line);
		ft_lstadd_back(&head, new_node);
	}
	close(fd);
	fill_data(head, config);
	return (1);
}
