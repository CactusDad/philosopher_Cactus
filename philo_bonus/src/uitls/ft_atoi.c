/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:05:22 by aboudarg          #+#    #+#             */
/*   Updated: 2022/03/06 20:42:03 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include "philosopher.h"

static int	ft_isspace(const char *str, int counter)
{
	while (str[counter] == ' ' || str[counter] == '\t'
		|| str[counter] == '\n' || str[counter] == '\v'
		|| str[counter] == '\f' || str[counter] == '\r')
		counter++;
	return (counter);
}

void	error(long num)
{
	if (num > INT_MAX && num != 2147483648)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

int	ft_atoi(const char *str)
{
	int				counter;
	int				sign;
	long			number;
	long			max;

	counter = 0;
	sign = 1;
	number = 0;
	max = 9223372036854775807 ;
	counter = ft_isspace(str, counter);
	if (str[counter] == '-')
		sign *= -1;
	if (str[counter] == '-' || str[counter] == '+')
		counter++;
	while (ft_isdigit(str[counter]))
	{
		number = (number * 10) + (str[counter++] - '0');
		error(number);
		if (number > max && sign == -1)
			return (0);
		if (number >= max && sign == 1)
			return (-1);
	}
	return (number * sign);
}
