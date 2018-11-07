/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:42:13 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/29 15:06:54 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		events(int nbr, t_struct *new)
{
	ft_esc(nbr);
	if (nbr == DOWN_AR)
		new->rx += 0.14;
	if (nbr == UPPER_AR)
		new->rx -= 0.14;
	if (nbr == LEFT_AR)
		new->ry += 0.14;
	if (nbr == RIGHT_AR)
		new->ry -= 0.14;
	if (nbr == EQUAL)
		new->mult += 0.10;
	if (nbr == MINUS)
		if (new->mult > 0.10)
			new->mult -= 0.10;
	if (nbr == D)
		new->difwidth += 25;
	if (nbr == A)
		new->difwidth -= 25;
	if (nbr == S)
		new->difhigh += 25;
	if (nbr == W)
		new->difhigh -= 25;
	mlx_clear_window(new->mlx_ptr, new->win_ptr);
	work_with_scale(new);
	return (0);
}
