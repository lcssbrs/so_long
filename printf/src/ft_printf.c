/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:36:27 by lseiberr          #+#    #+#             */
/*   Updated: 2023/04/25 15:55:53 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list arg, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(arg, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(arg, int));
	else if (format == '%')
		print_length += ft_printpercent();
	else if (format == 'u')
		print_length += ft_printunsigned(va_arg(arg, int));
	else if (format == 'x' || format == 'X')
		print_length += ft_printhex(va_arg(arg, unsigned int), format);
	else if (format == 'p')
		print_length += ft_printptr(va_arg(arg, unsigned long long));
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_format(arg, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (print_length);
}

/*#include <stdio.h>

int	main()
{
	void	*ptr = "-1";
	printf("len : %d\n", printf("%p\n", ptr));
	printf("len : %d\n", ft_printf("%p\n", ptr));
}*/
