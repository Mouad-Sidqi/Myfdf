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

# include "mlx.h"
# include "../Sources/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef	struct 	s_event
{
	int x;
	int y;
	int space;
	int l;
	int	len;
	int winwidth;
	int winheight;
	void *mlx;
	void *win;
	char ***holder;
	int **intholder;
	float Rot;
	float Rot2;
	int para;
	int iso;
	int conic;
	int palette[8];
	int pchoice;
}				l_event;

void	drawcircle(void *mlx, void *win, int centerx,
					int centery, int radius, int color);
void	drline(void *mlx, void *win, int startpoint,
					int nlines, int winsize, int color);
void	drawnsquare(void *mlx, void *win, int startpointx, int startpointy,
					int onedlen, int color);
void	rotatepointiso(int *tab);
void	rotatepointtrueiso(int *x, int *y);
void	connect(void *mlx, void *win, int x0, int y0, int x1,
					int y1, int color);
int		key_pressed(int key_code, void *param);
void    ft_color(int *color, int height, int nextheight,l_event *Scale);
void	drawmap(l_event *Scale);
void	interface(l_event *Scale);
void	height(l_event *Scale, int h);
void	drawmap_para(l_event *Scale);
void	ft_palette(l_event *Scale);

#endif
