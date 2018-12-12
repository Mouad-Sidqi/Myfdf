/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 01:38:04 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:04:01 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static	void	ft_palette3(t_event *boi)
{
	if (boi->pchoice == 5)
	{
		boi->palette[0] = 0x30b1c3;
		boi->palette[1] = 0xabe9f0;
		boi->palette[2] = 0x9a4e00;
		boi->palette[3] = 0xba7e00;
		boi->palette[4] = 0xff6700;
		boi->palette[5] = 0xffa700;
		boi->palette[6] = 0xffF700;
		boi->palette[7] = 0xfcffcd;
	}
	else if (boi->pchoice == 6)
	{
		boi->palette[0] = 0xb9c1d1;
		boi->palette[1] = 0xe9d1e1;
		boi->palette[2] = 0x909cb5;
		boi->palette[3] = 0xa0bcd5;
		boi->palette[4] = 0x707a8a;
		boi->palette[5] = 0x7f7b81;
		boi->palette[6] = 0x9f9ba1;
		boi->palette[7] = 0xc2bdb7;
	}
}

static	void	ft_palette2(t_event *boi)
{
	if (boi->pchoice == 3)
	{
		boi->palette[0] = 0xe5c883;
		boi->palette[1] = 0xf5f8b3;
		boi->palette[2] = 0xfffef2;
		boi->palette[3] = 0xff8080;
		boi->palette[4] = 0xffa0a0;
		boi->palette[5] = 0xf4d8ac;
		boi->palette[6] = 0xffA16c;
		boi->palette[7] = 0xf0d38c;
	}
	else if (boi->pchoice == 4)
	{
		boi->palette[0] = 0x8bd9f0;
		boi->palette[1] = 0xabe9f0;
		boi->palette[2] = 0xa2e7f6;
		boi->palette[3] = 0xb2d7f6;
		boi->palette[4] = 0xb5f2fb;
		boi->palette[5] = 0xbb813c;
		boi->palette[6] = 0x77f6f5;
		boi->palette[7] = 0x33f455;
	}
	else if (boi->pchoice >= 5)
		ft_palette3(boi);
}

void			ft_palette(t_event *boi)
{
	if (boi->pchoice == 1)
	{
		boi->palette[0] = 0x0000e6;
		boi->palette[1] = 0x4ddbff;
		boi->palette[2] = 0xccff66;
		boi->palette[3] = 0xffff00;
		boi->palette[4] = 0xffcc00;
		boi->palette[5] = 0xff9933;
		boi->palette[6] = 0xff6600;
		boi->palette[7] = 0xFFFFFE;
	}
	else if (boi->pchoice == 2)
	{
		boi->palette[0] = 0x230827;
		boi->palette[1] = 0x491647;
		boi->palette[2] = 0x7c265e;
		boi->palette[3] = 0xff5454;
		boi->palette[4] = 0xff9494;
		boi->palette[5] = 0xff813c;
		boi->palette[6] = 0xffA16c;
		boi->palette[7] = 0xfff400;
	}
	else if (boi->pchoice >= 3)
		ft_palette2(boi);
}
