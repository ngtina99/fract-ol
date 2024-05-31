/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:06:41 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/05/31 20:16:24 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(int iteration, int x, int y, t_data *img)
{
	if (img->scheme == 1)
		red_scheme(iteration, x, y, img);
	else if (img->scheme == 2)
		green_scheme(iteration, x, y, img);
	else if (img->scheme == 3)
		blue_scheme(iteration, x, y, img);
	else if (img->scheme == 4)
		warhol_scheme(iteration, x, y, img);
	else if (img->scheme == 5)
		pastel_scheme(iteration, x, y, img);
	else if (img->scheme == 6)
		outline_scheme(iteration, x, y, img);
	else if (img->scheme == 7)
		psychedelic_scheme(iteration, x, y, img);
	return ;
}

double	ft_place(double value, double bottom, double top, double max)
{
	double	place;
	double	convertunit;

	convertunit = (top - bottom) / max;
	place = (value * convertunit) + bottom;
	return (place);
}

void	setup_image(t_data *img)
{
	int				x;
	int				y;
	int				iteration;
	t_position		c;

	iteration = 0;
	y = -1;
	while (++y <= PIXEL)
	{
		x = -1;
		while (++x <= PIXEL)
		{
			c.a = ft_place(x + img->m_x, -2 / img->zoom, +2 / img->zoom, PIXEL);
			c.b = ft_place(y + img->m_y, +2 / img->zoom, -2 / img->zoom, PIXEL);
			if (img->set == 1)
				iteration = setup_mandelbrot(c, img);
			else if (img->set == 2)
				iteration = setup_julia(c, img);
			else if (img->set == 3)
				iteration = setup_tricorn(c, img);
			ft_color(iteration, x, y, img);
		}
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

void	setup_struct(t_data *img)
{
	img->iter = 100;
	img->zoom = 1;
	img->scheme = 1;
	img->colorrange = 0.001;
	img->red = 1;
	img->green = 2;
	img->blue = 3;
	img->m_x = 0.0;
	img->m_y = 0.0;
	img->offset_x = 0.0;
	img->offset_y = 0.0;
}

void	setup_fractol(t_data *img)
{
	setup_struct(img);
	img->mlx_ptr = mlx_init();
	if (!img->mlx_ptr)
		print_error(1, img);
	if (img->set == 1)
		img->win_ptr = mlx_new_window(img->mlx_ptr, \
		PIXEL, PIXEL, "Mandelbrot");
	else if (img->set == 2)
		img->win_ptr = mlx_new_window(img->mlx_ptr, PIXEL, PIXEL, "Julia");
	else if (img->set == 3)
		img->win_ptr = mlx_new_window(img->mlx_ptr, PIXEL, PIXEL, "Tricorn");
	if (!img->win_ptr)
		print_error(2, img);
	img->img = mlx_new_image(img->mlx_ptr, PIXEL, PIXEL);
	if (!img->img)
		print_error(3, img);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_length, &img->endian);
	if (!img->addr)
		print_error(4, img);
	setup_image(img);
	ft_hooks(img);
}
