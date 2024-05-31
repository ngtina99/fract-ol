/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:24:43 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/05/31 20:15:16 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	setup_tricorn(t_position c, t_data *img)
{
	t_position	value;
	int			i;

	i = 0;
	value.a = 0;
	value.b = 0;
	while (i < img->iter)
	{
		value.x = (value.a * value.a) - (value.b * value.b);
		value.y = -2 * (value.a * value.b);
		value.x += c.a;
		value.y += c.b;
		value.a = value.x;
		value.b = value.y;
		if ((value.a * value.a) + (value.b * value.b) > ESCAPE_VALUE)
			return (i);
		i++;
	}
	return (i);
}

int	setup_julia(t_position value, t_data *img)
{
	t_position	c;
	int			i;

	i = 0;
	c.a = img->arg2;
	c.b = img->arg3;
	while (i < img->iter)
	{
		value.x = (value.a * value.a) - (value.b * value.b);
		value.y = 2 * (value.a * value.b);
		value.x += c.a ;
		value.y += c.b;
		value.a = value.x;
		value.b = value.y;
		if ((value.a * value.a) + (value.b * value.b) > ESCAPE_VALUE)
			return (i);
		i++;
	}
	return (i);
}

int	setup_mandelbrot(t_position c, t_data *img)
{
	t_position	value;
	int			i;
	double		c2;

	i = 0;
	c2 = c.a * c.a + c.b * c.b;
	if (256.0 * c2 * c2 - 96.0 * c2 + 32.0 * c.a - 3.0 < 0.0)
		return (img->iter);
	if (16.0 * (c2 + 2.0 * c.a + 1.0) - 1.0 < 0.0) 
		return (img->iter);
	value.a = 0;
	value.b = 0;
	while (i < img->iter)
	{
		value.x = (value.a * value.a) - (value.b * value.b);
		value.y = 2 * (value.a * value.b);
		value.x += c.a;
		value.y += c.b;
		value.a = value.x;
		value.b = value.y;
		if ((value.a * value.a) + (value.b * value.b) > ESCAPE_VALUE)
			return (i);
		i++;
	}
	return (i);
}
