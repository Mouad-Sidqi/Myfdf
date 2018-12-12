/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:06:57 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:02:23 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static void		plotlinelow2(t_event *boi, int *tab, int color, int x)
{
	int d;
	int dx;
	int dy;
	int yi;
	int y;

	init3(&dx, &dy, tab, &yi);
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	y = tab[3];
	x = tab[2];
	while (x <= tab[0])
	{
		mlx_pixel_put(boi->mlx, boi->win, x++, y, color);
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
	}
}

static void		plotlinehigh2(t_event *boi, int *tab, int color, int x)
{
	int d;
	int dx;
	int dy;
	int xi;
	int y;

	init3(&dx, &dy, tab, &xi);
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	x = tab[2];
	y = tab[3];
	while (y <= tab[1])
	{
		mlx_pixel_put(boi->mlx, boi->win, x, y++, color);
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
	}
}

static void		plotlinelow1(t_event *boi, int *tab, int color, int x)
{
	int d;
	int dx;
	int dy;
	int yi;
	int y;

	init4(&dx, &dy, tab, &yi);
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	y = tab[1];
	x = tab[0];
	while (x <= tab[2])
	{
		mlx_pixel_put(boi->mlx, boi->win, x++, y, color);
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
	}
}

static void		plotlinehigh1(t_event *boi, int *tab, int color, int x)
{
	int d;
	int dx;
	int dy;
	int xi;
	int y;

	init4(&dx, &dy, tab, &xi);
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	x = tab[0];
	y = tab[1];
	while (y <= tab[3])
	{
		mlx_pixel_put(boi->mlx, boi->win, x, y++, color);
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
	}
}

void			connect(t_event *boi, int *tab, int color)
{
	if (abs(tab[3] - tab[1]) < abs(tab[2] - tab[0]))
	{
		if (tab[0] > tab[2])
			plotlinelow2(boi, tab, color, 0);
		else
			plotlinelow1(boi, tab, color, 0);
	}
	else
	{
		if (tab[1] > tab[3])
			plotlinehigh2(boi, tab, color, 0);
		else
			plotlinehigh1(boi, tab, color, 0);
	}
}
