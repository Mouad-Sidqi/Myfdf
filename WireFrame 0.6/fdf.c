/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 04:54:22 by msidqi            #+#    #+#             */
/*   Updated: 2018/12/10 22:02:10 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fdf.h"

static int **tabtoi(char ***holder, l_event *boi)
{
	int i = 0;
	int j = 0;
	int **intholder;

	if (!(intholder = (int **)malloc(sizeof(int*) * (boi->l + 1))))
	{	
		ft_putstr("malloc error2\n");
		return (NULL);
	}
	intholder[boi->l] = NULL;
	while (holder[i])
	{
		j = 0;
		if (!(intholder[i] = (int *)malloc(sizeof(int) * (boi->len))))
		{	
			ft_putstr("malloc error3\n");
			return (NULL);
		}
		while (holder[i][j])
		{
			intholder[i][j] = ft_atoi(holder[i][j]);
			j++;
		}
		i++;
	}
	return (intholder);
}

static char ***checker(int argc, char **argv, l_event *boi)
{
	int fd;
	char *map;
	char ***holder;
	int i;
	int stp;

	boi->l = 0;
	i = 0;
	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <path to file>\n");
		exit (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("No file Named");
		ft_putstr(argv[1]);
		ft_putchar('\n');
		exit (-1);
	}
	while (get_next_line(fd, &map))
		boi->l++;
	if (!(holder = malloc(sizeof(char**) * boi->l + 1)))
	{	
		ft_putstr("malloc error1\n");
		return (0);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &map))
	{
		holder[i++] = ft_strsplit(map, ' ');
	}
	holder[i] = NULL;
	i = 0;
	boi->len = 0;
	while (holder[i])
	{
		boi->len = 0;
		while (holder[i][boi->len])
			boi->len++;
		if (i == 0)
			stp = boi->len;
		if (boi->len > stp)
		{
			ft_putstr("Detected error in a line\n");
			exit (-1);
		}
		i++;
	}
	free(map);
	return (holder);
}


int main(int argc, char **argv)
{

	void *mlx;
	void *win;
	char ***holder;
	l_event *boi;

	if (!(boi = malloc(sizeof(l_event))))
		return (0);
	holder = checker(argc, argv, boi);
	boi->space = 20;
	boi->x = 800;
	boi->y = -200;
	boi->holder = holder;
	boi->winheight = 1080;
	boi->winwidth = 1920;
	if (!(mlx = mlx_init()))
		return (0);
	if (!(win = mlx_new_window(mlx, boi->winwidth, boi->winheight, "Wired")))
		return (0);
	boi->win = win;
	boi->mlx = mlx;
	boi->Rot = 0.523599;
	boi->Rot2 = 0;
	boi->pchoice = 1;
	boi->intholder = tabtoi(holder, boi);
	/*Mapping*/ 
	drawmap(boi);
	/*Interface*/
	interface(boi);
	/*Events*/ 
	mlx_hook(win, 2, 0, &key_pressed, boi);
	mlx_loop(mlx);
	return (0);
}
