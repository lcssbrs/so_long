/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:23:25 by lseiberr          #+#    #+#             */
/*   Updated: 2023/02/09 17:15:19 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	if (!size || !count)
		return (malloc(0));
	tot_size = size * count;
	if ((tot_size / size != count) || (tot_size / count != size))
		return (NULL);
	dst = malloc(tot_size);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, tot_size);
	return (dst);
}
