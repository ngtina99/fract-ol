/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:42:55 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/04/13 16:39:30 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_addr(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	red_scheme(int iteration, int x, int y, t_data *img)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	double	n;

	n = (double)iteration * img->colorrange;
	red = 0;
	green = 0;
	blue = 0;
	color = 0;
	blue += (int)(img->blue * (1 - n) * n * n * n * 255);
	green += (int)(img->green * (1 - n) * (1 - n) * n * n * 255);
	red += (int)(img->red * (1 - n) * (1 - n) * (1 - n) * n * 255);
	color = (red << 16) | (green << 8) | blue;
	calculate_addr(img, x, y, color);
}

void	green_scheme(int iteration, int x, int y, t_data *img)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	double	n;

	n = (double)iteration * img->colorrange;
	red = 0;
	green = 0;
	blue = 0;
	color = 0;
	blue += (int)(img->blue * (1 - n) * n * n * n * 255);
	red += (int)(img->red * (1 - n) * (1 - n) * n * n * 255);
	green += (int)(img->green * (1 - n) * (1 - n) * (1 - n) * n * 255);
	color = (red << 16) | (green << 8) | blue;
	calculate_addr(img, x, y, color);
}

void	blue_scheme(int iteration, int x, int y, t_data *img)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	double	n;

	n = (double)iteration * img->colorrange;
	red = 0;
	green = 0;
	blue = 0;
	color = 0;
	red += (int)(img->red * (1 - n) * n * n * n * 255);
	green += (int)(img->green * (1 - n) * (1 - n) * n * n * 255);
	blue += (int)(img->blue * (1 - n) * (1 - n) * (1 - n) * n * 255);
	color = (red << 16) | (green << 8) | blue;
	calculate_addr(img, x, y, color);
}
