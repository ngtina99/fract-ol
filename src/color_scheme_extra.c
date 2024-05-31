/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:42:55 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/04/13 16:43:28 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	warhol_scheme(int iteration, int x, int y, t_data *img)
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
	blue += (int)(img->blue * (3 - n) * 255);
	green += (int)(img->green * (3 - n) * 255);
	red += (int)(img->red * (3 - n) * 255);
	color = (red << 16) | (green << 8) | blue;
	calculate_addr(img, x, y, color);
}

void	pastel_scheme(int iteration, int x, int y, t_data *img)
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
	blue += (int)(img->blue * (1 - n) * (1 - n) * (1 - n) * (1 - n) * 255);
	green += (int)(img->green * (1 - n) * (1 - n) * (1 - n) * (1 - n) * 255);
	red += (int)(img->red * (1 - n) * (1 - n) * (1 - n) * (1 - n) * 255);
	color = (red << 16) | (green << 8) | blue;
	calculate_addr(img, x, y, color);
}

void	outline_scheme(int iteration, int x, int y, t_data *img)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	double	n;

	red = 9;
	green = 9;
	blue = 9;
	color = 0;
	n = (double)iteration * img->colorrange;
	if (iteration == 100)
	{
		color = 0x000000;
		calculate_addr(img, x, y, color);
		return ;
	}
	red += (int)(img->red * (1 - n) * (1 - n) * n * n * 255);
	green += (int)(img->green * (1 - n) * (1 - n) * n * n * 255);
	blue += (int)(img->blue * (1 - n) * (1 - n) * n * n * 255);
	color = (red << 16) | (green << 8) | blue;
	calculate_addr(img, x, y, color);
}

void	psychedelic_scheme(int iteration, int x, int y, t_data *img)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	double	n;

	red = 9;
	green = 9;
	blue = 9;
	color = 0;
	n = (double)iteration * img->colorrange;
	if (iteration == 100)
	{
		color = 0x000000;
		calculate_addr(img, x, y, color);
		return ;
	}
	red += (int)(img->red * n * 255);
	green += (int)(img->green * n * 255);
	blue += (int)(img->blue * n * 255);
	color = (red << 16) | (green << 8) | blue;
	calculate_addr(img, x, y, color);
}
