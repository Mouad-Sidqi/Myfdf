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

void ft_palette(l_event *Scale)
{
	if (Scale->pchoice == 1)
	{
		Scale->palette[0] = 0x0000e6;
		Scale->palette[1] = 0x4ddbff;
		Scale->palette[2] = 0xccff66;
		Scale->palette[3] = 0xffff00;
		Scale->palette[4] = 0xffcc00;
		Scale->palette[5] = 0xff9933;
		Scale->palette[6] = 0xff6600;
		Scale->palette[7] = 0xFFFFFE;
	}
	else if (Scale->pchoice == 2)
	{
		Scale->palette[0] = 0x230827;
		Scale->palette[1] = 0x491647;
		Scale->palette[2] = 0x7c265e;
		Scale->palette[3] = 0xff5454;
		Scale->palette[4] = 0xff9494;
		Scale->palette[5] = 0xff813c;
		Scale->palette[6] = 0xffA16c;
		Scale->palette[7] = 0xfff400;
	}
	else if (Scale->pchoice == 3)
	{
		Scale->palette[0] = 0xe5c883;
		Scale->palette[1] = 0xf5f8b3;
		Scale->palette[2] = 0xfffef2;
		Scale->palette[3] = 0xff8080;
		Scale->palette[4] = 0xffa0a0;
		Scale->palette[5] = 0xf4d8ac;
		Scale->palette[6] = 0xffA16c;
		Scale->palette[7] = 0xf0d38c;
	}
	else if (Scale->pchoice == 4)
	{
		Scale->palette[0] = 0x8bd9f0;
		Scale->palette[1] = 0xabe9f0;
		Scale->palette[2] = 0xa2e7f6;
		Scale->palette[3] = 0xb2d7f6;
		Scale->palette[4] = 0xb5f2fb;
		Scale->palette[5] = 0xbb813c;
		Scale->palette[6] = 0x77f6f5;
		Scale->palette[7] = 0x33f455;
	}
	else if (Scale->pchoice == 5)
	{
		Scale->palette[0] = 0x30b1c3;
		Scale->palette[1] = 0xabe9f0;
		Scale->palette[2] = 0x9a4e00;
		Scale->palette[3] = 0xba7e00;
		Scale->palette[4] = 0xff6700;
		Scale->palette[5] = 0xffa700;
		Scale->palette[6] = 0xffF700;
		Scale->palette[7] = 0xfcffcd;
	}
	else if (Scale->pchoice == 6)
	{
		Scale->palette[0] = 0xb9c1d1;
		Scale->palette[1] = 0xe9d1e1;
		Scale->palette[2] = 0x909cb5;
		Scale->palette[3] = 0xa0bcd5;
		Scale->palette[4] = 0x707a8a;
		Scale->palette[5] = 0x7f7b81;
		Scale->palette[6] = 0x9f9ba1;
		Scale->palette[7] = 0xc2bdb7;
	}
}
