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

void	drawmap_para(l_event *Scale)
{
	int j;
	int r = 0;
	int tmpx;
	int tmpy;
	int color = 0xFFFFFF;

	/* x cos f - y sin f*/
	/* y cos f + x sin f*/

	Scale->para = TRUE;
	tmpx = Scale->x;
	tmpy = Scale->y;
	while (r < Scale->l)
	{
		j = 0;
		while (j <= Scale->len - 1)
		{
			if (j < Scale->len - 1)
			{
				ft_color(&color, Scale->intholder[r][j] , Scale->intholder[r][j + 1], Scale);
				connect(Scale->mlx, Scale->win,
						Scale->x * cos(Scale->Rot2) - Scale->y * sin(Scale->Rot2),
						Scale->y * cos(Scale->Rot2) + Scale->x *  sin(Scale->Rot2) - Scale->intholder[r][j] * Scale->space,
						(Scale->x + Scale->space) * cos(Scale->Rot2) - Scale->y * sin(Scale->Rot2),
						Scale->y * cos(Scale->Rot2) + (Scale->x + Scale->space) * sin(Scale->Rot2) - Scale->intholder[r][j + 1] * Scale->space,
						color); /*connect to right point*/
			}
			if (r < Scale->l - 1)
			{
				ft_color(&color, Scale->intholder[r][j] , Scale->intholder[r + 1][j], Scale);
				connect(Scale->mlx, Scale->win,
						Scale->x * cos(Scale->Rot2) - Scale->y  * sin(Scale->Rot2) ,
						Scale->y  * cos(Scale->Rot2) + Scale->x * sin(Scale->Rot2) - Scale->intholder[r][j] * Scale->space,
						Scale->x * cos(Scale->Rot2) - (Scale->y + Scale->space)  * sin(Scale->Rot2) ,
						(Scale->y + Scale->space) * cos(Scale->Rot2) + Scale->x * sin(Scale->Rot2) - Scale->intholder[r + 1][j] * Scale->space,
						color); /*connect to lower point*/
			}
			Scale->x += Scale->space; /*grid*/
			j++;
		}
		Scale->x = tmpx;
		Scale->y += Scale->space;
		r++;
	}
	Scale->y = tmpy;
}
