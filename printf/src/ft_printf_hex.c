/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:12:00 by lseiberr          #+#    #+#             */
/*   Updated: 2023/04/25 15:59:24 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hex_len(long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(long long num, const char format)
{
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (num >= 16)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else
	{
		if (format == 'X')
			ft_putchar(base2[num]);
		else
			ft_putchar(base[num]);
	}
}

int	ft_printhex(long long num, const char format)
{
	if (num == 0)
		return (write (1, "0", 1));
	else
		ft_puthex(num, format);
	return (ft_hex_len(num));
}
