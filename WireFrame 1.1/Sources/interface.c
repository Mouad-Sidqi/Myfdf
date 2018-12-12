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

void	interface(t_event *boi)
{
	int i;

	i = 0;
	while (i < 12)
	{
		drline(boi, 0 + (i * 5) + 2, 3, 0x111b1f);
		drline(boi, 0 + i++ * 5, 2, 0x212b2f);
	}
	drline(boi, 60, 2, 0x550055);
	mlx_string_put(boi->mlx, boi->win, 2, 1, 0xEEEEEE, "Quit : ESC");
	mlx_string_put(boi->mlx, boi->win, 2, 20, 0xEEEEEE, "Move : Arrows");
	mlx_string_put(boi->mlx, boi->win, 2, 39, 0xEEEEEE, "Size : + -");
	mlx_string_put(boi->mlx, boi->win, 170, 1, 0xEEEEEE, "Alt    : 1 2");
	mlx_string_put(boi->mlx, boi->win, 170, 39, 0xEEEEEE, "Palette : 7 8");
	mlx_string_put(boi->mlx, boi->win, 170, 20, 0xEEEEEE, "Small Size  : 0");
	drawnsquares(boi, 20);
}
