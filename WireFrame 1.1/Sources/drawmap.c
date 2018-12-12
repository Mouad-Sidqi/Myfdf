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

static int		*short1(int x0, int y0, int x1, int y1)
{
	int *tab;

	tab = (int *)malloc(sizeof(int) * 4);
	tab[0] = x0;
	tab[1] = y0;
	tab[2] = x1;
	tab[3] = y1;
	return (tab);
}

static void		drmap(t_event *boi, int *r, int *color, int j)
{
	int *tab;

	while (j <= boi->len - 1)
	{
		if (j < boi->len - 1)
		{
			ft_color(color, boi->inth[*r][j], boi->inth[*r][j + 1], boi);
			tab = short1(X_H, Y_H - boi->inth[*r][j] * boi->space, X1_H,
					Y1_H - boi->inth[*r][j + 1] * boi->space);
			connect(boi, tab, *color);
		}
		if (*r < boi->l - 1)
		{
			ft_color(color, boi->inth[*r][j], boi->inth[*r + 1][j], boi);
			tab = short1(X_H, Y_H - boi->inth[*r][j] * boi->space,
					(boi->x - (boi->y + boi->space)) * cos(boi->rot),
					(boi->x + boi->y + boi->space) * sin(boi->rot)
					- boi->inth[*r + 1][j] * boi->space);
			connect(boi, tab, *color);
		}
		boi->x += boi->space;
		j++;
	}
}

void			drawmap(t_event *boi)
{
	int r;
	int tmpx;
	int tmpy;
	int color;

	r = 0;
	tmpx = boi->x;
	tmpy = boi->y;
	boi->iso = TRUE;
	boi->para = FALSE;
	while (r < boi->l)
	{
		drmap(boi, &r, &color, 0);
		boi->x = tmpx;
		boi->y += boi->space;
		r++;
	}
	boi->y = tmpy;
}
