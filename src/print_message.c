/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:42:55 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/04/13 20:05:55 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_message(int message_type)
{
	if (message_type == 1)
	{
		ft_printf("\033[1;36mPlease enter one of the following:\n");
		ft_printf("\033[1;36m➡️ ./fractol Mandelbrot\n");
		ft_printf("\033[1;36m➡️ ./fractol Julia <number> <number>\n");
		ft_printf("\033[1;36m➡️ ./fractol Tricorn\n\n");
		ft_printf("\033[1;31mRules for <number> args:\n");
		ft_printf("\033[1;31m- It has to be decimal number\n\n");
		ft_printf("\033[1;31m- Can't be smaller than -2.0\n");
		ft_printf("\033[1;31m- Can't be bigger than 2.0\n\n");
		ft_printf("\033[1;105m🤫👉tips for <number> args\n");
		ft_printf("\033[1;105m-0.4 0.6; 0.28 0.008; -0.835 -0.2321\033[0;0m");
	}
	exit (1);
}

void	print_error(int error_type, t_data *img)
{
	ft_printf("\033[1;31mMALLOC ERROR\n");
	if (error_type == 2)
	{
		mlx_loop_end(img->mlx_ptr);
		mlx_destroy_display(img->mlx_ptr);
		free(img->mlx_ptr);
	}
	else if (error_type == 3)
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		mlx_destroy_display(img->mlx_ptr);
		free(img->mlx_ptr);
	}
	else if (error_type == 4)
	{
		mlx_destroy_image(img->mlx_ptr, img->img);
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		mlx_destroy_display(img->mlx_ptr);
		free(img->mlx_ptr);
	}
	exit (1);
}
