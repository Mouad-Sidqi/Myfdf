/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:43:22 by msidqi            #+#    #+#             */
/*   Updated: 2018/11/24 04:59:23 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../Sources/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef	struct	s_event
{
	int			x;
	int			y;
	int			space;
	int			l;
	int			len;
	int			winwidth;
	int			winheight;
	void		*mlx;
	void		*win;
	char		***holder;
	int			**inth;
	float		rot;
	float		r2;
	int			para;
	int			iso;
	int			palette[8];
	int			pchoice;
}				t_event;

void			drawcircle(void *mlx, void *win, int centerx,
					int centery, int radius, int color);
void			drline(t_event *boi, int startpoint, int nlines, int color);
void			drawnsquares(t_event *boi, int onedlen);
void			rotatepointiso(int *tab);
void			rotatepointtrueiso(int *x, int *y);
void			connect(t_event *boi, int *tab, int color);
int				key_pressed(int key_code, void *param);
void			ft_color(int *color, int height, int nextheight,
					t_event *scale);
void			drawmap(t_event *scale);
void			interface(t_event *scale);
void			height(t_event *scale, int h);
void			drawmap_para(t_event *scale);
void			ft_palette(t_event *scale);
void			events5(int key_code, t_event *tmp);
void			init(t_event *boi, void *mlx, void *win);
void			init3(int *dx, int *dy, int *tab, int *yi);
void			init4(int *dx, int *dy, int *tab, int *yi);
# define X_H  (boi->x - boi->y) * cos(boi->rot)
# define Y_H  ((boi->x + boi->y) * sin(boi->rot))
# define X1_H (boi->x + boi->space - boi->y) * cos(boi->rot)
# define Y1_H (boi->x + boi->space + boi->y) * sin(boi->rot)

# define X_HP boi->x * cos(boi->r2) - boi->y * sin(boi->r2)
# define Y_HP boi->y * cos(boi->r2) + boi->x * sin(boi->r2)
# define X1_HP (boi->x + boi->space) * cos(boi->r2) - boi->y * sin(boi->r2)
# define Y1_HP boi->y * cos(boi->r2) + (boi->x + boi->space) * sin(boi->r2)

# define X1_HP2 boi->x * cos(boi->r2) - (boi->y + boi->space) * sin(boi->r2)
# define Y1_HP2 (boi->y + boi->space) * cos(boi->r2) + boi->x * sin(boi->r2)

#endif
