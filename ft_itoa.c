/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:38:18 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:37:41 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_quantity_numbers(int z)
{
	int	kolicestvo;
	int	summa;

	if (z == 0)
		return (1);
	kolicestvo = 0;
	summa = z;
	while (z != 0)
	{
		z = z % 10;
		summa = summa / 10;
		z = summa;
		kolicestvo++;
	}
	return (kolicestvo);
}

static int	ft_sign(int z)
{
	if (z < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int z)
{
	char	*string;
	int		sign;
	int		quan_num;
	int		summa;

	sign = ft_sign(z);
	quan_num = ft_quantity_numbers(z) + 1 + (z < 0);
	string = (char *)malloc(sizeof(char) * quan_num);
	if (!string)
		return (NULL);
	ft_bzero(string, quan_num);
	if (z == 0)
		string[0] = '0';
	quan_num = quan_num - 2;
	summa = z;
	while (z != 0)
	{
		z = z % 10;
		string[quan_num--] = z * sign + '0';
		summa = summa / 10;
		z = summa;
	}
	if (sign < 0)
		string[quan_num] = '-';
	return (string);
}
