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

void	height(l_event *Scale, int h)//, l_event *Scale)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (Scale->intholder[i])
	{
		j = 0;
		while (j < Scale->len)
		{
			if (ft_strcmp(Scale->holder[i][j] , "0"))
				Scale->intholder[i][j] += h;
			j++;
		}
		i++;
	}
}
