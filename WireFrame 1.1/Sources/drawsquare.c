/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:27:53 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:02:32 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	drawnsquares(t_event *boi, int onedlen)
{
	int x;
	int j;
	int sx;

	sx = 1890;
	x = 0;
	j = 0;
	while (j < onedlen)
	{
		x = 0;
		while (x < onedlen)
		{
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 80 + j, boi->palette[7]);
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 110 + j, boi->palette[6]);
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 140 + j, boi->palette[5]);
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 170 + j, boi->palette[4]);
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 200 + j, boi->palette[3]);
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 230 + j, boi->palette[2]);
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 260 + j, boi->palette[1]);
			mlx_pixel_put(boi->mlx, boi->win, sx + x, 290 + j, boi->palette[0]);
			x++;
		}
		j++;
	}
}
