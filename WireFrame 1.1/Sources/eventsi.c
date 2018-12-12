/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventsi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:48:01 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/11 18:48:02 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static void		events8(int key_code, t_event *tmp)
{
	if (key_code == 126)
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
	}
	interface(tmp);
}

static void		events7(int key_code, t_event *tmp)
{
	if (key_code == 123)
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
	}
	events8(key_code, tmp);
}

static void		events6(int key_code, t_event *tmp)
{
	if (key_code == 89 && tmp->pchoice > 1)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->pchoice -= 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
	}
	else if (key_code == 91 && tmp->pchoice < 6)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->pchoice += 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
	}
	events7(key_code, tmp);
}

void			events5(int key_code, t_event *tmp)
{
	if (key_code == 78 && tmp->space > 1)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->space -= 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
	}
	else if (key_code == 69)
	{
		mlx_clear_window(tmp->mlx, tmp->win);
		tmp->space += 1;
		if (tmp->para == TRUE)
			drawmap_para(tmp);
		else if (tmp->iso == TRUE)
			drawmap(tmp);
	}
	events6(key_code, tmp);
}
