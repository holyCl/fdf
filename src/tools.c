/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:37:52 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/29 13:15:18 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	find_delta(t_struct *new, int *delta_x, int *delta_y, int *delta)
{
	if (new->flag == 1)
	{
		*delta = (ft_abs(new->cord[2] - new->cord[0]) << 1) - \
		abs(new->cord[3] - new->cord[1]);
		*delta_x = ft_abs(new->cord[2] - new->cord[0]) << 1;
		*delta_y = (ft_abs(new->cord[2] - new->cord[0]) - \
		ft_abs(new->cord[3] - new->cord[1])) << 1;
	}
	if (new->flag == 2)
	{
		*delta = (ft_abs(new->cord[3] - new->cord[1]) << 1) - \
		ft_abs(new->cord[2] - new->cord[0]);
		*delta_x = ft_abs(new->cord[3] - new->cord[1]) << 1;
		*delta_y = (ft_abs(new->cord[3] - new->cord[1]) - \
		ft_abs(new->cord[2] - new->cord[0])) << 1;
	}
}

void	hard_math(t_struct *new, double *x, double *y, double *z)
{
	*y = ((new->cur[1] - new->lines / 2) * (30 * new->mult)) * cos(new->rx) + \
			(new->cur[2] * 30 * new->mult) * sin(new->rx) + \
			((new->lines / 2) * (30 * new->mult)) + new->difhigh;
	*z = ((new->cur[2] * 30 * new->mult) * cos(new->rx) - ((new->\
		cur[1] - new->lines / 2) * (30 * new->mult)) * sin(new->rx));
	*x = ((new->cur[0] - new->chars / 2) * (30 * new->mult)) * cos(new->ry) - \
		(*z) * sin(new->ry) + (new->chars / 2) * (30 * new->mult) + \
			new->difwidth;
	new->cord[0] = (*x - new->chars / 2) * cos(new->rz) + \
		(*y - new->lines / 2) * sin(new->rz) + new->chars / 2;
	new->cord[1] = (*y - new->lines / 2) * cos(new->rz) + \
		(*x - new->chars / 2) * sin(new->rz) + new->lines / 2;
	*y = ((new->next[1] - new->lines / 2) * (30 * new->mult)) * cos(new->rx)\
		+ (new->next[2] * (30 * new->mult)) * sin(new->rx) + \
			(new->lines / 2) * (30 * new->mult) + new->difhigh;
	*z = (new->next[2] * (30 * new->mult)) * cos(new->rx) - \
		((new->next[1] - new->lines / 2) * (30 * new->mult)) * sin(new->rx);
	*x = ((new->next[0] - new->chars / 2) * (30 * new->mult)) * cos(new->ry) -\
		(*z - new->zr) * sin(new->ry) + (new->chars / 2) * (30 * new->mult) + \
			new->difwidth;
}

void	info(t_struct *new)
{
	mlx_string_put(new->mlx_ptr, new->win_ptr, 20, 20, 0x0000FF00,
	"MOVE:   W A S D");
	mlx_string_put(new->mlx_ptr, new->win_ptr, 20, 40, 0x0000FF00,
	"ROTATE: arrows");
	mlx_string_put(new->mlx_ptr, new->win_ptr, 1032, 20, 0x0000FF00,\
	"FDF by ivoloshi");
	mlx_string_put(new->mlx_ptr, new->win_ptr, 20, 90, 0x0000FF00,\
	"ZOOM:   + -");
}
