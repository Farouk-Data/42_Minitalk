/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:14:24 by fech-cha          #+#    #+#             */
/*   Updated: 2021/12/26 18:39:03 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	cpt;

	cpt = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		cpt += ft_putchar(*str);
		str++;
	}
	return (cpt);
}

int	ft_putnbr(int nb)
{
	int				cpt;
	unsigned int	n;

	cpt = 0;
	n = nb;
	if (nb < 0)
	{
		cpt += ft_putchar('-');
		n *= -1;
	}
	if (n < 10 && n >= 0)
	{
		cpt += ft_putchar(n + '0');
	}
	else if (n > 9)
	{
		cpt += ft_putnbr(n / 10);
		cpt += ft_putnbr(n % 10);
	}
	return (cpt);
}

int	ft_print_unsigned(unsigned int n)
{
	int	cpt;

	cpt = 0;
	if (n < 10 && n >= 0)
	{
		cpt += ft_putchar(n + '0');
	}
	else if (n > 9)
	{
		cpt += ft_putnbr(n / 10);
		cpt += ft_putnbr(n % 10);
	}
	return (cpt);
}
