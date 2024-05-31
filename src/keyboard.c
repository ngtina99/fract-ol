/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:42:55 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/05/31 20:27:30 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_moves(int keycode, t_data *img)
{
	if (keycode == UP)
		img->m_y += 10;
	else if (keycode == DOWN)
		img->m_y -= 10;
	else if (keycode == RIGHT)
		img->m_x += 10;
	else if (keycode == LEFT)
		img->m_x -= 10;
	setup_image(img);
}

void	ft_changecolor(int keycode, t_data *img)
{
	if (keycode == R)
		img->red += 1;
	else if (keycode == G)
		img->green += 1;
	else if (keycode == B)
		img->blue += 1;
	else if (keycode == Z)
	{
		if (img->colorrange <= 0.00001)
			return ;
		else if (img->colorrange > 0.0002)
			img->colorrange -= 0.0001;
		else if (img->colorrange >= 0.00002)
			img->colorrange -= 0.00001;
	}
	else if (keycode == X)
	{
		if (img->colorrange < 1)
			img->colorrange += 0.0001;
	}
	setup_image(img);
}

void	ft_changescheme(int keycode, t_data *img)
{
	if (keycode == ONE)
		img->scheme = 1;
	else if (keycode == TWO)
		img->scheme = 2;
	else if (keycode == THREE)
		img->scheme = 3;
	else if (keycode == FOUR)
		img->scheme = 4;
	else if (keycode == FIVE)
		img->scheme = 5;
	else if (keycode == SIX)
		img->scheme = 6;
	else if (keycode == SEVEN)
		img->scheme = 7;
	setup_image(img);
}

void	ft_changejulia(int keycode, t_data *img)
{
	if (keycode == A)
		img->arg2 -= 0.1;
	else if (keycode == D)
		img->arg2 += 0.1;
	else if (keycode == W)
		img->arg3 += 0.1;
	else if (keycode == S)
		img->arg3 -= 0.1;
	setup_image(img);
}

void	ft_iteration(int keycode, t_data *img)
{
	if (keycode == O)
		img->iter -= 10;
	else if (keycode == I)
		img->iter += 10;
	setup_image(img);
}

int	ft_keyhooks(int keycode, t_data *img)
{
	if (keycode == UP || keycode == DOWN \
	|| keycode == RIGHT || keycode == LEFT)
		ft_moves(keycode, img);
	else if (keycode == R || keycode == G \
	|| keycode == B || keycode == Z || keycode == X)
		ft_changecolor(keycode, img);
	else if (keycode == ONE || keycode == TWO || keycode == THREE \
	|| keycode == FOUR || keycode == FIVE || keycode == SIX || keycode == SEVEN)
		ft_changescheme(keycode, img);
	else if (keycode == A || keycode == D || keycode == W || keycode == S)
		ft_changejulia(keycode, img);
	else if (keycode == I || keycode == O)
		ft_iteration(keycode, img);
	else if (keycode == SPACE)
	{
		img->zoom = 1;
		img->colorrange = 0.001;
		img->red = 1;
		img->green = 2;
		img->blue = 3;
		img->m_x = 0.0;
		img->m_y = 0.0;
		img->offset_x = 0.0;
		img->offset_y = 0.0;
		setup_image(img);
	}
	return (0);
}
