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

static int		**tabtoi(char ***holder, t_event *boi)
{
	int i;
	int j;
	int **intholder;

	j = 0;
	i = 0;
	if (!(intholder = (int **)malloc(sizeof(int*) * (boi->l + 1))))
		return (NULL);
	intholder[boi->l] = NULL;
	while (holder[i])
	{
		j = 0;
		if (!(intholder[i] = (int *)malloc(sizeof(int) * (boi->len))))
			return (NULL);
		while (holder[i][j])
		{
			intholder[i][j] = ft_atoi(holder[i][j]);
			j++;
		}
		i++;
	}
	return (intholder);
}

static void		errors(int n)
{
	if (n == 1)
		ft_putstr("Usage : ./fdf <path to file>\n");
	if (n == 2)
		ft_putstr("No file with that name\n");
	if (n == 3)
		ft_putstr("malloc error1\n");
	if (n == 4)
		ft_putstr("Detected error in a line\n");
	exit(-1);
}

static void		checker2(int *i, t_event *boi, char ***holder)
{
	int		stp;

	*i = 0;
	boi->len = 0;
	while (holder[*i])
	{
		boi->len = 0;
		while (holder[*i][boi->len])
			boi->len++;
		if (*i == 0)
			stp = boi->len;
		if (boi->len > stp)
			errors(4);
		(*i)++;
	}
}

static char		***checker(int argc, char **argv, t_event *boi)
{
	int		fd;
	char	*map;
	char	***holder;
	int		i;

	boi->l = 0;
	i = 0;
	if (argc != 2)
		errors(1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		errors(2);
	while (get_next_line(fd, &map))
		boi->l++;
	if (!(holder = malloc(sizeof(char**) * boi->l + 1)))
		errors(3);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &map))
		holder[i++] = ft_strsplit(map, ' ');
	holder[i] = NULL;
	checker2(&i, boi, holder);
	free(map);
	return (holder);
}

int				main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	char	***holder;
	t_event	*boi;

	if (!(boi = malloc(sizeof(t_event))))
		return (0);
	holder = checker(argc, argv, boi);
	boi->holder = holder;
	boi->winheight = 1080;
	boi->winwidth = 1920;
	if (!(mlx = mlx_init()))
		return (0);
	if (!(win = mlx_new_window(mlx, boi->winwidth, boi->winheight, "Wired")))
		return (0);
	init(boi, mlx, win);
	boi->inth = tabtoi(holder, boi);
	drawmap(boi);
	interface(boi);
	mlx_hook(win, 2, 0, &key_pressed, boi);
	mlx_loop(mlx);
	return (0);
}
