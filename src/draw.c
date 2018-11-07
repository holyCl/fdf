/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:28:55 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/28 21:35:46 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../inc/fdf.h"

void		spos_draw(t_struct *new, int start_x, int start_y)
{
	int		count;
	int		delta;
	int		delta_x;
	int		delta_y;

	count = 0;
	new->flag = 1;
	new->x = new->cord[0];
	new->y = new->cord[1] + start_y;
	mlx_pixel_put(new->mlx_ptr, new->win_ptr, new->cord[0], new->cord[1],\
	64769);
	find_delta(new, &delta_x, &delta_y, &delta);
	while (ft_abs(new->cord[3] - new->cord[1]) >= count)
	{
		if (delta <= 0)
			delta += delta_x;
		else
		{
			delta += delta_y;
			new->x += start_x;
		}
		mlx_pixel_put(new->mlx_ptr, new->win_ptr, new->x, new->y, 3980800);
		new->y += start_y;
		count++;
	}
}

void		fpos_draw(t_struct *new, int start_x, int start_y)
{
	int		count;
	int		delta;
	int		delta_x;
	int		delta_y;

	new->flag = 2;
	count = 0;
	new->x = new->cord[0] + start_x;
	new->y = new->cord[1];
	mlx_pixel_put(new->mlx_ptr, new->win_ptr, new->cord[0], new->cord[1],\
	5281280);
	find_delta(new, &delta_x, &delta_y, &delta);
	while (ft_abs(new->cord[2] - new->cord[0]) >= count)
	{
		if (delta <= 0)
			delta += delta_x;
		else
		{
			delta += delta_y;
			new->y += start_y;
		}
		mlx_pixel_put(new->mlx_ptr, new->win_ptr, new->x, new->y, 5281280);
		new->x += start_x;
		count++;
	}
}
