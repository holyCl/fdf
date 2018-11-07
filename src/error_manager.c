/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:38:21 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/29 15:06:29 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error(int numb)
{
	if (numb == 101)
	{
		ft_printf("%s\n", "Usage: ./fdf <map>");
		exit(1);
	}
	if (numb == 102)
	{
		ft_printf("%s\n", "error");
		exit(1);
	}
	if (numb == 103)
	{
		ft_printf("%s\n", "map error");
		exit(1);
	}
}

void	check_on_invalid_file(int x)
{
	if (x == 0)
		exit(1);
}

int		ft_exit(void)
{
	exit(1);
	return (0);
}

void	ft_esc(int nbr)
{
	if (nbr == ESC)
		exit(1);
}
