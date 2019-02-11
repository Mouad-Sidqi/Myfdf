/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:19:39 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:03:55 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void    ft_color(int *color, int height, int nextheight, l_event *boi)
{
	ft_palette(boi);
	if (height > nextheight)
	{  
		if (height <= 0)
			*color = boi->palette[0];
		else if ((height > 0 && height <= 10))
			*color = boi->palette[1];
		else if ((height > 10 && height <= 20))
			*color = boi->palette[2];
		else if ((height > 20 && height <= 40))
			*color = boi->palette[3];
		else if ((height > 40 && height <= 50))
			*color = boi->palette[4];
		else if ((height > 50 && height <= 60))
			*color = boi->palette[5];
		else if ((height > 60 && height <= 80))
			*color = boi->palette[6];
		else
			*color = boi->palette[7];
	}
	else if (height <= nextheight)
	{
		if (nextheight <= 0)
			*color = boi->palette[0];
		else if ((nextheight > 0 && nextheight <= 10))
			*color = boi->palette[1];
		else if ((nextheight > 10 && nextheight <= 20))
			*color = boi->palette[2];
		else if ((nextheight > 20 && nextheight <= 40))
			*color = boi->palette[3];
		else if ((nextheight > 40 && nextheight <= 50))
			*color = boi->palette[4];
		else if ((nextheight > 50 && nextheight <= 60))
			*color = boi->palette[5];
		else if ((nextheight > 60 && nextheight <= 80))
			*color = boi->palette[6];
		else
			*color = boi->palette[7];
	}
	/* if (height == nextheight)*/
	/*     *color += 1;*/
}
