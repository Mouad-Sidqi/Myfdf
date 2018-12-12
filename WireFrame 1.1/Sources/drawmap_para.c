/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap_para.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:02:14 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:03:30 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static int		*short2(int x0, int y0, int x1, int y1)
{
	int *tab;

	tab = malloc(sizeof(int) * 4);
	tab[0] = x0;
	tab[1] = y0;
	tab[2] = x1;
	tab[3] = y1;
	return (tab);
}

static void		drmap_para(t_event *boi, int *r, int *color, int j)
{
	int *tab;

	while (j <= boi->len - 1)
	{
		if (j < boi->len - 1)
		{
			ft_color(color, boi->inth[*r][j], boi->inth[*r][j + 1], boi);
			tab = short2(X_HP, Y_HP - boi->inth[*r][j]
				* boi->space, X1_HP, Y1_HP - boi->inth[*r][j + 1]
				* boi->space);
			connect(boi, tab, *color);
		}
		if (*r < boi->l - 1)
		{
			ft_color(color, boi->inth[*r][j], boi->inth[*r + 1][j], boi);
			tab = short2(X_HP, Y_HP - boi->inth[*r][j]
				* boi->space, X1_HP2, Y1_HP2 - boi->inth[*r + 1][j]
				* boi->space);
			connect(boi, tab, *color);
		}
		boi->x += boi->space;
		j++;
	}
}

void			drawmap_para(t_event *boi)
{
	int r;
	int tmpx;
	int tmpy;
	int color;

	r = 0;
	boi->para = TRUE;
	boi->iso = FALSE;
	tmpx = boi->x;
	tmpy = boi->y;
	while (r < boi->l)
	{
		drmap_para(boi, &r, &color, 0);
		boi->x = tmpx;
		boi->y += boi->space;
		r++;
	}
	boi->y = tmpy;
}
