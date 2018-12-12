/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:05:18 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:04:19 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	interface(l_event *boi)
{
	int i;

	i = 0;
	while (i < 12)
	{
		drline(boi->mlx, boi->win, 0 + (i * 5) + 2, 3, boi->winwidth, 0x111b1f);
		drline(boi->mlx, boi->win, 0 + i++ * 5, 2, boi->winwidth, 0x212b2f);
	}
	drline(boi->mlx, boi->win, 60, 2, boi->winwidth, 0x550055);
	mlx_string_put(boi->mlx, boi->win, 2, 1, 0xEEEEEE, "Quit : ESC");
	mlx_string_put(boi->mlx, boi->win, 2, 20, 0xEEEEEE, "Move : Arrows");
	mlx_string_put(boi->mlx, boi->win, 2, 39, 0xEEEEEE, "Size : + -");
	mlx_string_put(boi->mlx, boi->win, 170, 1, 0xEEEEEE, "Alt    : 1 2");
	mlx_string_put(boi->mlx, boi->win, 170, 20, 0xEEEEEE, "Rotate : 4 5");
	mlx_string_put(boi->mlx, boi->win, 170, 39, 0xEEEEEE, "Palette : 7 8");
	mlx_string_put(boi->mlx, boi->win, 170, 1, 0xEEEEEE, "S Size  : 0");
	drawnsquare(boi->mlx, boi->win, 1890, 80, 20, boi->palette[7]);
	drawnsquare(boi->mlx, boi->win, 1890, 110, 20, boi->palette[6]);
	drawnsquare(boi->mlx, boi->win, 1890, 140, 20, boi->palette[5]);
	drawnsquare(boi->mlx, boi->win, 1890, 170, 20, boi->palette[4]);
	drawnsquare(boi->mlx, boi->win, 1890, 200, 20, boi->palette[3]);
	drawnsquare(boi->mlx, boi->win, 1890, 230, 20, boi->palette[2]);
	drawnsquare(boi->mlx, boi->win, 1890, 260, 20, boi->palette[1]);
	drawnsquare(boi->mlx, boi->win, 1890, 290, 20, boi->palette[0]);
}
