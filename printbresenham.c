/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:52:17 by paim              #+#    #+#             */
/*   Updated: 2016/11/18 15:38:00 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pixel_to_image(t_stock *t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t->img_color = mlx_get_color_value(t->mlx, t->cc);
	if (t->y0 <= 0 || t->x0 <= 0 || t->x0 >= 2000 || t->y0 >= 1000)
		return ;
	r = (t->img_color & 0xFF0000) >> 16;
	g = (t->img_color & 0xFF00) >> 8;
	b = (t->img_color & 0xFF) >> 0;
	t->data[t->y0 * t->size_line + t->x0 * t->bpp / 8] = b;
	t->data[t->y0 * t->size_line + t->x0 * t->bpp / 8 + 1] = g;
	t->data[t->y0 * t->size_line + t->x0 * t->bpp / 8 + 2] = r;
}

int			draw_line(t_stock *t)
{
	int		err;
	int		e2;

	t->dx = ft_abs(t->x1 - t->x0);
	t->dy = ft_abs(t->y1 - t->y0);
	t->sx = t->x0 < t->x1 ? 1 : -1;
	t->sy = t->y0 < t->y1 ? 1 : -1;
	err = (t->dx > t->dy ? t->dx : -t->dy) / 2;
	while (t->x0 != t->x1 || t->y0 != t->y1)
	{
		ft_color_alt(t);
		ft_put_pixel_to_image(t);
		e2 = err;
		if (e2 > -t->dx)
		{
			err -= t->dy;
			t->x0 += t->sx;
		}
		if (e2 < t->dy)
		{
			err += t->dx;
			t->y0 += t->sy;
		}
	}
	return (0);
}

int			comput_stock(t_stock *t)
{
	int		z;

	z = t->coord[t->i][t->j];
	t->x0 = t->startx + (t->i * t->scale) + (t->j) * t->scale;
	t->y0 = t->starty + (t->i * t->scale) / 2 - (t->j * t->scale / 2) - z;
	t->x1 = t->startx + (t->i * t->scale) + (t->j + 1) * t->scale;
	z = t->j + 1 == t->abs ? 0 : t->coord[t->i][t->j + 1];
	t->y1 = t->starty + (t->i * t->scale) / 2 - ((t->j + 1) * t->scale) / 2 - z;
	t->color = z;
	return (0);
}

int			comput_stock2(t_stock *t)
{
	int		z;

	z = t->coord[t->i][t->j];
	t->x0 = t->startx + (t->i * t->scale) + (t->j * t->scale);
	t->y0 = t->starty + (t->i * t->scale) / 2 - (t->j * t->scale / 2) - z;
	t->x1 = t->startx + (t->i + 1) * t->scale + t->j * t->scale;
	z = t->i + 1 == t->ordo ? 0 : t->coord[t->i + 1][t->j];
	t->y1 = t->starty + (t->i + 1) * t->scale / 2 - (t->j * t->scale) / 2 - z;
	t->color = z;
	return (0);
}

int			ft_bresen(t_stock *t)
{
	t->i = 0;
	while (t->i != t->ordo)
	{
		t->j = 0;
		while (t->j != t->abs)
		{
			if (t->j + 1 != t->abs)
			{
				comput_stock(t);
				if (t->onoff == 0)
					draw_line(t);
				draw_point(t);
			}
			if (t->i + 1 != t->ordo)
			{
				comput_stock2(t);
				if (t->onoff == 0)
					draw_line(t);
				draw_point(t);
			}
			t->j++;
		}
		t->i++;
	}
	return (0);
}
