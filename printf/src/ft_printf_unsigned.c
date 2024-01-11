/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:23:29 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/05 16:28:40 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_unsigneditoa(unsigned int n)
{
	unsigned int	temp;
	int				len;
	char			*num;

	len = 0;
	temp = n;
	while (temp >= 10)
	{
		temp = temp / 10;
		len ++;
	}
	num = (char *)(malloc(sizeof(char) *(len + 1)));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len --;
	}
	return (num);
}

int	ft_printunsigned(int n)
{
	char	*num;
	int		len;

	num = ft_unsigneditoa((unsigned int)n);
	len = ft_printstr(num);
	free (num);
	return (len);
}
