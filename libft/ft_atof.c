/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:22:25 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/03/31 17:35:35 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	int		i;
	double	decimal;

	i = 0;
	decimal = 0.0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9') 
	{
		decimal = decimal * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[++i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9') 
	{
		decimal = decimal * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (3);
	else if (str[0] == '-' || str[0] == '+')
		return ((decimal / pow(10, i - 3)) * -1);
	else
		return ((decimal / pow(10, i - 2)) * 1);
}
