/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:08:46 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/04/13 20:11:50 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mousehooks(int button, int x, int y, t_data *img)
{
	img->offset_x = (x - (PIXEL / 2)) * 0.1;
	img->offset_y = (y - (PIXEL / 2)) * 0.1;
	if (button == ON_MOUSEDOWN)
	{
		img->m_x = img->m_x * 1.1 + img->offset_x;
		img->m_y = img->m_y * 1.1 + img->offset_y;
		img->zoom *= 1.1;
	}
	if (button == ON_MOUSEUP)
	{
		img->m_x = img->m_x / 1.1 + img->offset_x;
		img->m_y = img->m_y / 1.1 + img->offset_y;
		img->zoom /= 1.1;
	}
	setup_image(img);
	return (0);
}

int	close_window(t_data *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	exit(0);
}

int	close_window_esc(int keycode, t_data *img)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(img->mlx_ptr, img->img);
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		mlx_destroy_display(img->mlx_ptr);
		free(img->mlx_ptr);
		exit(0);
	}
	return (0);
}

void	ft_hooks(t_data *img)
{
	mlx_mouse_hook(img->win_ptr, ft_mousehooks, img);
	mlx_key_hook(img->win_ptr, ft_keyhooks, img);
	mlx_hook(img->win_ptr, ON_DESTROY, 0, close_window, img);
	mlx_hook(img->win_ptr, ON_KEYDOWN, 1, close_window_esc, img);
	mlx_loop(img->mlx_ptr);
}
