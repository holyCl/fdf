/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:17:23 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/29 15:05:24 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include "../libftprintf/inc/ft_printf.h"
# include "../minilibx_macos/mlx.h"

# define ESC 53
# define HIGH 1280
# define WIDTH 1200
# define UPPER_AR 126
# define LEFT_AR 123
# define DOWN_AR 125
# define RIGHT_AR 124
# define MINUS 27
# define EQUAL 24
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_struct	t_struct;

struct				s_struct
{
	int				fd;
	int				**map;
	void			*mlx_ptr;
	void			*win_ptr;
	int				lines;
	int				chars;
	int				zr;
	double			difhigh;
	double			difwidth;
	int				x;
	int				y;
	float			rx;
	float			ry;
	float			rz;
	float			mult;
	int				*cur;
	int				*next;
	int				*cord;
	int				flag;
};

void				work_with_scale(t_struct *new);
int					events(int nbr, t_struct *new);
void				convert_cord(t_struct *new, int sx, int sy);
int					parser(t_struct *data, char *argv);
void				error(int numb);
void				reading_data(t_struct *new, char *argv);
void				initialize(t_struct *new);
int					ft_abs(int n);
void				check_on_invalid_file(int x);
void				find_delta(t_struct *new, int *delta_x, int *delta_y,\
					int *delta);
int					ft_exit(void);
void				info(t_struct *new);
void				fpos_draw(t_struct *new, int start_x, int start_y);
void				spos_draw(t_struct *new, int start_x, int start_y);
void				hard_math(t_struct *new, double *x, double *y, double *z);
void				ft_esc(int nbr);

#endif
