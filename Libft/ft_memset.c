/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:46:40 by lseiberr          #+#    #+#             */
/*   Updated: 2023/02/07 15:12:26 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*tmp;
	size_t	i;

	tmp = (char *) pointer;
	i = 0;
	while (i < count)
	{
		tmp[i] = (char) value;
		i++;
	}
	return (pointer);
}
