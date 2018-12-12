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

void	drline(t_event *boi, int startpoint, int nlines, int color)
{
	int p;
	int o;

	p = startpoint;
	while (p < nlines + startpoint)
	{
		o = 0;
		while (o < boi->winwidth)
		{
			mlx_pixel_put(boi->mlx, boi->win, o, p, color);
			o++;
		}
		p++;
	}
}
