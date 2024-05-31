/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:42:55 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/03/31 04:33:28 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	img;

	img.arg2 = 0.0;
	img.arg3 = 0.0;
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
		img.set = 1;
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		img.set = 2;
		img.arg2 = ft_atof(argv[2]);
		img.arg3 = ft_atof(argv[3]);
		if ((img.arg2 > 2 || img.arg2 < -2) || (img.arg3 > 2 || img.arg3 < -2))
			print_message(1);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "Tricorn"))
		img.set = 3;
	else
		print_message(1);
	setup_fractol(&img);
}
