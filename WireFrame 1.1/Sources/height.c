/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:43:59 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:04:10 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	height(t_event *boi, int h)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (boi->inth[i])
	{
		j = 0;
		while (j < boi->len)
		{
			if (ft_strcmp(boi->holder[i][j], "0"))
				boi->inth[i][j] += h;
			j++;
		}
		i++;
	}
}
