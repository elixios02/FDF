/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:44:56 by paim              #+#    #+#             */
/*   Updated: 2017/05/03 15:25:46 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stock		*init_struct(void)
{
	t_stock	*t;

	t = (t_stock *)ft_memalloc(sizeof(t_stock));
	t->startx = 1010;
	t->starty = 400;
	t->scale = 1;
	t->onoff = 1;
	return (t);
}

void		ft_ecrit(t_stock *t)
{
	char	*nbr;
	char	*x;
	char	*y;
	char	*strx;
	char	*stry;

	nbr = ft_itoa(t->scale);
	x = ft_itoa(t->startx);
	y = ft_itoa(t->starty);
	t->str = "Scale : ";
	strx = " X = ";
	stry = " Y = ";
	t->str = ft_strjoin(t->str, nbr);
	t->str = ft_strjoin(t->str, strx);
	t->str = ft_strjoin(t->str, x);
	t->str = ft_strjoin(t->str, stry);
	t->str = ft_strjoin(t->str, y);
}

int			ft_key_hook_2(int keycode, t_stock *t)
{
	if (keycode == 15)
	{
		t->onoff = 0;
		t->scale = 12;
		t->startx = 1010;
		t->starty = 400;
	}
	if (keycode == 126)
		t->starty -= 100;
	else if (keycode == 123)
		t->startx -= 100;
	else if (keycode == 37 && t->onoff == 0)
		t->onoff++;
	else if (keycode == 40 && t->onoff == 1)
		t->onoff--;
	return (0);
}

int			ft_key_hook(int keycode, t_stock *t)
{
	mlx_clear_window(t->mlx, t->win);
	mlx_destroy_image(t->mlx, t->img);
	printf("coucou ; %d\n", keycode);
	if (keycode == 124)
		t->startx += 10;
	else if (keycode == 125)
		t->starty += 10;
	else if (keycode == 31)
	{
		if (t->scale >= 1)
			t->scale--;
	}
	else if (keycode == 35)
		t->scale++;
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	else
		ft_key_hook_2(keycode, t);
	t->img = mlx_new_image(t->mlx, 2000, 1000);
	ft_ecrit(t);
	mlx_string_put(t->mlx, t->win, 50, 10, 0xFEFEFE, t->str);
	ft_bresen(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 60);
	return (0);
}

int			main(int argc, char **argv)
{
	t_stock	*t;
	int		**tab;

	t = init_struct();
	if (argc != 2)
		return (error("Il faut 2 arguments "));
	if (mumuse(argc, argv, t) == -1)
		return (EXIT_FAILURE);
	if (splitatoi(argv, t) == -1)
		return (0);
	if ((t->mlx = mlx_init()) == NULL)
		return (0);
	t->win = mlx_new_window(t->mlx, 2000, 1000, "fdf");
	t->img = mlx_new_image(t->mlx, 2000, 1000);
	t->img_color = mlx_get_color_value(t->mlx, 0xF2FEFE);
	t->data = mlx_get_data_addr(t->img, &t->bpp, &t->size_line, &t->endian);
	if (ft_bresen(t) != 0)
		return (EXIT_FAILURE);
	ft_ecrit(t);
	mlx_string_put(t->mlx, t->win, 50, 10, 0xFEFEFE, t->str);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 60);
	mlx_hook(t->win, 2, 64, ft_key_hook, t);
	mlx_loop(t->mlx);
	return (EXIT_SUCCESS);
}
