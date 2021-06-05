/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:06:54 by paim              #+#    #+#             */
/*   Updated: 2016/10/13 18:45:15 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_stock
{
	int				onoff;
	void			*img;
	int				p;
	char			*str;
	unsigned int	cc;
	float			color;
	int				startx;
	int				starty;
	int				scale;
	int				cgnl;
	int				abs;
	int				ordo;
	char			**tab;
	int				splat;
	int				**coord;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				dx;
	int				dy;
	int				i;
	int				j;
	int				sx;
	int				sy;
	int				xbis;
	int				ybis;
	void			*win;
	void			*mlx;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	img_color;
}					t_stock;

int					error(const char *str);
int					ft_bresen(t_stock *t);
int					ft_color_alt(t_stock *t);
int					draw_line(t_stock *t);
int					draw_point(t_stock *t);
int					splitatoi(char **argv, t_stock *t);
int					countgnl(int const fd, t_stock *t);
int					savetab(int const fd, t_stock *t);
int					mumuse(int argc, char **argv, t_stock *t);
int					ft_charatoi(char c);
int					linegnl(char **argv);
t_stock				*init_struct(void);
void				ft_put_pixel_to_image(t_stock *t);
//int					comput_stock(t_stock *t);
//int					comput_stock2(t_stock *t);
void				ft_ecrit(t_stock *t);
int					ft_key_hook(int keycode, t_stock *t);
int					ft_key_hook_2(int keycode, t_stock *t);
int					atoicoord(t_stock *t, char **argv);
int					checkline(t_stock *t);
#endif
