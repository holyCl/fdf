/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:39:52 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/29 14:27:12 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		creating_scale(t_struct *new)
{
	if ((new->lines * (30 * new->mult)) > WIDTH ||\
		((new->lines * (30 * new->mult)) > HIGH))
	{
		while ((new->lines * (30 * new->mult)) > WIDTH * 0.9 ||\
		(new->lines * (30 * new->mult)) > HIGH * 0.9)
			new->mult -= 0.05;
	}
}

int			c_lines(t_struct *data, int x, int i)
{
	char	*line;
	char	**tab;

	data->chars = 0;
	data->lines = 0;
	while ((get_next_line(data->fd, &line)) > 0)
	{
		i = -1;
		tab = ft_strsplit(line, ' ');
		while (tab[x])
			x++;
		if (!data->lines)
			data->chars = x;
		else if (data->lines && (data->chars > x || data->chars < x))
			error(103);
		data->lines++;
		while (tab[++i])
			free(tab[i]);
		free(tab);
		free(line);
	}
	check_on_invalid_file(x);
	data->map = ft_memalloc(sizeof(int *) * data->lines);
	close(data->fd);
	return (0);
}

int			parser(t_struct *data, char *argv)
{
	char	*line;
	char	**tab;
	int		x;
	int		y;

	if (c_lines(data, 0, -1) == -1)
		return (-1);
	data->fd = open(argv, O_RDONLY);
	y = 0;
	while ((get_next_line(data->fd, &line)) > 0)
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
		data->map[y] = ft_memalloc(sizeof(int) * data->chars);
		while (tab[x])
		{
			data->map[y][x] = ft_atoi(tab[x]);
			free(tab[x]);
			x++;
		}
		free(tab);
		y++;
		free(line);
	}
	return (0);
}

void		reading_data(t_struct *new, char *argv)
{
	new->fd = open(argv, O_RDONLY);
	if (parser(new, argv) == -1)
		error(102);
	creating_scale(new);
	new->difwidth = (HIGH - (new->lines * (30 * new->mult))) * 0.5;
	new->difhigh = (WIDTH - (new->chars * (30 * new->mult))) * 0.5;
}
