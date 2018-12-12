/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawNline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:21:36 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:03:39 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	drline(void *mlx, void *win, int startpoint, int nlines, int winsize, int color)
{
	int p;
	int o;

	p = startpoint;
	while (p < nlines + startpoint)
	{
		o = 0;
		while (o < winsize)
		{
			mlx_pixel_put(mlx, win, o, p, color);
			o++;
		}
		p++;
	}
}
