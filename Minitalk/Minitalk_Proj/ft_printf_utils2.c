/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:39:15 by fech-cha          #+#    #+#             */
/*   Updated: 2021/12/26 18:39:36 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lower_hexa(unsigned int nb)
{
	char	*hex;
	int		cpt;

	cpt = 0;
	hex = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
	{
		cpt += ft_putchar(hex[nb]);
	}
	else if (nb >= 16)
	{
		cpt += ft_print_lower_hexa(nb >> 4);
		cpt += ft_print_lower_hexa(nb & 0xf);
	}
	return (cpt);
}

int	ft_print_upper_hexa(unsigned int nb)
{
	char	*hex;
	int		cpt;

	cpt = 0;
	hex = "0123456789ABCDEF";
	if (nb >= 0 && nb < 16)
	{
		cpt += ft_putchar(hex[nb]);
	}
	else if (nb >= 16)
	{
		cpt += ft_print_upper_hexa(nb >> 4);
		cpt += ft_print_upper_hexa(nb & 0xf);
	}
	return (cpt);
}

int	ft_print_addrs(long unsigned int nb)
{
	int		cpt;
	char	*hex;

	cpt = 0;
	hex = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
	{
		cpt += ft_putchar(hex[nb]);
	}
	else if (nb >= 16)
	{
		cpt += ft_print_addrs(nb >> 4);
		cpt += ft_print_addrs(nb & 0xf);
	}
	return (cpt);
}