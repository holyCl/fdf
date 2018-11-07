/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:45:52 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/28 21:39:14 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		horizontal(t_struct *new, int x, int y)
{
	new->cur[0] = x;
	new->cur[1] = y;
	new->cur[2] = new->map[y - 1][x - 1];
	new->next[0] = x + 1;
	new->next[1] = y;
	new->next[2] = new->map[y - 1][x];
	convert_cord(new, 0, 0);
}

void		vertical(t_struct *new, int x, int y)
{
	if (new->chars == x)
		new->cur[0] = x;
	new->next[0] = x;
	new->cur[1] = y + 1;
	new->next[1] = y;
	new->next[2] = new->map[y - 1][x - 1];
	new->cur[2] = new->map[y][x - 1];
	convert_cord(new, 0, 0);
}

void		work_with_scale(t_struct *new)
{
	int		x;
	int		y;

	info(new);
	y = 1;
	while (y - 1 < new->lines)
	{
		x = 1;
		while (x - 1 < new->chars)
		{
			if (x != new->chars)
				horizontal(new, x, y);
			if (new->lines > y)
				vertical(new, x, y);
			x++;
		}
		y++;
	}
}

void		convert_cord(t_struct *new, int start_x, int start_y)
{
	double	x;
	double	y;
	double	z;

	hard_math(new, &x, &y, &z);
	new->cord[2] = (x - new->chars / 2) * cos(new->rz) + \
		(y - new->lines / 2) * sin(new->rz) + new->chars / 2;
	new->cord[3] = (y - new->lines / 2) * cos(new->rz) + (x - new->chars / 2)\
		* sin(new->rz) + new->lines / 2;
	start_x = new->cord[2] >= new->cord[0] ? 1 : -1;
	start_y = new->cord[3] >= new->cord[1] ? 1 : -1;
	if (ft_abs(new->cord[3] - new->cord[1]) <= ft_abs(new->cord[2] - \
	new->cord[0]))
		fpos_draw(new, start_x, start_y);
	else
		spos_draw(new, start_x, start_y);
}
