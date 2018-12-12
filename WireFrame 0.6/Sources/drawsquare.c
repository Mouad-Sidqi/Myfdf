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

void	drawnsquare(void *mlx, void *win, int startpointx, int startpointy, int onedlen, int color)
{
	int x;
	int j;

	x = 0;
	j = 0;
	while (j < onedlen)
	{
		x = 0;
		while (x < onedlen)
		{
			mlx_pixel_put(mlx,win, startpointx + x, startpointy + j, color);
			x++;
		}
		j++;
	}
}
