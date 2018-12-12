/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawCircle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:38:23 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:03:11 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	drawcircle(void *mlx, void *win, int centerx, int centery, int radius, int color)
{
	float z;

	z = 0;
	while (z < 2 * M_PI)
	{
		mlx_pixel_put(mlx, win, centerx - (cos(z) * radius), centery - (sin(z) * radius), color);
		z += 0.01;
	}
}
