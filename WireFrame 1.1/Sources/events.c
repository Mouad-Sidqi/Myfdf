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

static void		events4(int key_code, t_event *tmp)
{
	if (key_code == 83)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		height(tmp, 7);
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
	}
	else if (key_code == 84)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		height(tmp, -7);
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
	}
	events5(key_code, tmp);
}

static void		events3(int key_code, t_event *tmp)
{
	if (key_code == 35)
	{
		tmp->para = TRUE;
		tmp->iso = FALSE;
		mlx_clear_window(tmp->mlx, tmp->win);
		drawmap_para(tmp);
	}
	else if (key_code == 34)
	{
		tmp->para = FALSE;
		tmp->iso = TRUE;
		mlx_clear_window(tmp->mlx, tmp->win);
		drawmap(tmp);
	}
	events4(key_code, tmp);
}

static	void	fevents(t_event *tmp)
{
	mlx_clear_window(tmp->mlx, tmp->win);
	if (tmp->para == TRUE)
	{
		tmp->r2 += 1.5708;
		drawmap_para(tmp);
	}
	else if (tmp->iso == TRUE)
	{
		tmp->rot += 0.174533;
		drawmap(tmp);
	}
}

static void		events2(int key_code, t_event *tmp)
{
	if (key_code == 87)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		if (tmp->para == TRUE)
		{
			tmp->r2 -= 1.5708;
			drawmap_para(tmp);
		}
		else if (tmp->iso == TRUE)
		{
			tmp->rot -= 0.174533;
			drawmap(tmp);
		}
	}
	else if (key_code == 86)
		fevents(tmp);
	events3(key_code, tmp);
}

int				key_pressed(int key_code, void *param)
{
	t_event *tmp;

	tmp = param;
	if (key_code == 53)
		exit(1);
	else if (key_code == 82)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->space = 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
	}
	events2(key_code, tmp);
	return (0);
}
