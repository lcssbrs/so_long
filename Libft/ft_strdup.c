/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:24:07 by lseiberr          #+#    #+#             */
/*   Updated: 2023/07/13 11:21:46 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*tab;
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	tab = (char *)(malloc(sizeof(char) * (len + 1)));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
