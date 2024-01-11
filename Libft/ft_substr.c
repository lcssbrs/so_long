/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:07:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/02/15 18:31:33 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		new_str = malloc(sizeof(char) * 1);
		new_str[0] = '\0';
		return (new_str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (0);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
