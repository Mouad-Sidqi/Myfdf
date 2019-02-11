/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:10:17 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:03:47 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int key_pressed(int key_code, void *param)
{
	l_event *tmp;

	tmp = param;
	if (key_code == 53)
		exit(1);
	else if (key_code == 89 && tmp->pchoice > 1) /* color palette */
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->pchoice -= 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
		interface(tmp);
	}
	else if (key_code == 91 && tmp->pchoice < 6)
	{
		mlx_clear_window(tmp->mlx, tmp->win); /* color palette */
		tmp->pchoice += 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
		interface(tmp);
	}
	else if (key_code == 82)
	{
		mlx_clear_window(tmp->mlx, tmp->win); /* size 1 */
		tmp->space = 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
		interface(tmp);
	}
	else if (key_code == 78 && tmp->space > 1)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->space -= 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
		interface(tmp);
	}
	else if (key_code == 69)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->space += 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
		interface(tmp);
	}
	else if (key_code == 126)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->y -= 30;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
		{
			tmp->x -= 30;
			drawmap(tmp);
		}
		interface(tmp);
	}
	else if (key_code == 125)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->y += 30;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
		{
			tmp->x += 30;
			drawmap(tmp);
		}
		interface(tmp);
	}
	else if (key_code == 123)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->x -= 30;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
		{
			tmp->y += 30;
			drawmap(tmp);
		}
		interface(tmp);
	}
	else if (key_code == 124)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->x += 30;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
		{
			tmp->y -= 30;
			drawmap(tmp);
		}
		interface(tmp);
	}
	else if (key_code == 83)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		height(tmp, 7);
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
		interface(tmp);
	}
	else if (key_code == 84)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		height(tmp, -7);
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
		interface(tmp);
	}
	else if (key_code == 86)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		if (tmp->para == TRUE)
		{
			tmp->Rot2 += 1.5708;
			drawmap_para(tmp);
		}
		else if (tmp->iso == TRUE)//
		{
			tmp->Rot += 0.174533;
			drawmap(tmp);
		}
		interface(tmp);
	}
	else if (key_code == 87)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		if (tmp->para == TRUE)
		{
			tmp->Rot2 -= 1.5708;
			drawmap_para(tmp);
		}
		else if (tmp->iso == TRUE)//
		{
			tmp->Rot -= 0.174533;
			drawmap(tmp);
		}
		interface(tmp);
	}
	else if (key_code == 35)
	{
		tmp->para = TRUE;
		tmp->conic = FALSE;
		tmp->iso = FALSE;
		mlx_clear_window(tmp->mlx, tmp->win);
		drawmap_para(tmp);
		interface(tmp);
	}
	else if (key_code == 34)
	{
		tmp->para = FALSE;
		tmp->conic = FALSE;
		tmp->iso = TRUE;
		mlx_clear_window(tmp->mlx, tmp->win);
		drawmap(tmp);
		interface(tmp);
	}
	return (0);
}
