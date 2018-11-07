/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:44:10 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/29 15:08:46 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			initialize(t_struct *new)
{
	new->x = 0;
	new->y = 0;
	new->flag = 0;
	new->chars = 0;
	new->fd = 0;
	new->lines = 0;
	new->map = 0;
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, WIDTH, HIGH, "ivoloshi");
	new->rx = -0.4;
	new->ry = 0.4;
	new->rz = 0;
	new->mult = 1;
	new->zr = 0;
	new->cur = malloc(sizeof(int *) * 3);
	new->next = malloc(sizeof(int *) * 3);
	new->cord = malloc(sizeof(int *) * 4);
}

int				main(int argc, char **argv)
{
	t_struct	new;

	if (argc != 2)
		error(101);
	initialize(&new);
	reading_data(&new, argv[1]);
	work_with_scale(&new);
	mlx_hook(new.win_ptr, 2, 0, events, &new);
	mlx_loop(new.mlx_ptr);
	return (0);
}
