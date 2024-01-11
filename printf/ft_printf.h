/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:59:18 by lseiberr          #+#    #+#             */
/*   Updated: 2023/07/13 10:07:02 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include "../Libft/libft.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_printchar(int c);
int		ft_format(va_list arg, const char format);
int		ft_printf(const char *input, ...);
char	*ft_itoa(int n);
size_t	ft_nbrlen(int nbr, int base);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
int		ft_numberlen(unsigned int num);
char	*ft_unsigneditoa(unsigned int n);
int		ft_printunsigned(int n);
int		ft_hex_len(long long num);
void	ft_puthex(long long num, const char format);
int		ft_printhex(long long num, const char format);
int		ft_ptrlen(uintptr_t num);
void	ft_putptr(uintptr_t num);
int		ft_printptr(unsigned long long ptr);

#endif
