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

static void	    plotLineLow(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
	int D;
	int dx;
	int dy;
	int yi;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = 2*dy - dx;
	y = y0;
	x = x0;
	while (x <= x1)
	{
		mlx_pixel_put(mlx,win, x, y, color);
		if (D > 0)
		{
			y = y + yi;
			D = D - 2*dx;
		}
		D = D + 2*dy;
		x++;
	}
}

static void	    plotLineHigh(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
	int D;
	int dx;
	int dy;
	int xi;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = 2*dx - dy;
	x = x0;
	y = y0;
	while (y <= y1)
	{
		mlx_pixel_put(mlx,win, x, y, color);
		if (D > 0)
		{
			x = x + xi;
			D = D - 2*dy;
		}
		D = D + 2*dx;
		y++;
	}
}

void	        connect(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plotLineLow(mlx, win, x1, y1, x0, y0, color);
		else
			plotLineLow(mlx, win, x0, y0, x1, y1, color);
	}
	else
	{
		if (y0 > y1)
			plotLineHigh(mlx, win, x1, y1, x0, y0, color);
		else
			plotLineHigh(mlx, win, x0, y0, x1, y1, color);
	}
}
