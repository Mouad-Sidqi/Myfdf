/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 00:38:12 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:01:10 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	drawmap(l_event *boi)
{
	int j;
	int r;
	int tmpx;
	int tmpy;
	int color;

	color = 0xFFFFFF;
	r = 0;
	tmpx = boi->x;
	tmpy = boi->y;
	boi->iso = TRUE;
	while (r < boi->l)
	{
		j = 0;
		while (j <= boi->len - 1)
		{
			if (j < boi->len - 1)
			{
				ft_color(&color, boi->intholder[r][j], boi->intholder[r][j + 1], boi);
				connect(boi->mlx, boi->win,
						(boi->x - boi->y) * cos(boi->Rot),
						((boi->x + boi->y) * sin(boi->Rot)) - boi->intholder[r][j] * boi->space,
						(boi->x + boi->space - boi->y) * cos(boi->Rot),
						(boi->x + boi->space + boi->y) * sin(boi->Rot) - boi->intholder[r][j + 1] * boi->space,
						color); /* connect to right point */
			}
			if (r < boi->l - 1)
			{
				ft_color(&color, boi->intholder[r][j], boi->intholder[r + 1][j], boi);
				connect(boi->mlx, boi->win,
						(boi->x - boi->y) * cos(boi->Rot),
						(boi->x + boi->y) * sin(boi->Rot) - boi->intholder[r][j] * boi->space,
						(boi->x - (boi->y + boi->space)) * cos(boi->Rot),
						(boi->x + boi->y + boi->space) * sin(boi->Rot) - boi->intholder[r + 1][j] * boi->space,
						color); /* connect to lower point */
			}
			boi->x += boi->space; /*grid*/
			j++;
		}
		boi->x = tmpx;
		boi->y += boi->space;
		r++;
	}
	boi->y = tmpy;
}
