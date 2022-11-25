/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:24:45 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/25 13:41:30 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putnbr_base(long long n, char *base)
{
	int		blen;
	int		cnt;
	char	c;

	cnt = 0;
	blen = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n < blen)
	{
		c = base[n];
		write(1, &c, 1);
		cnt++;
	}
	if (n >= blen)
	{
		cnt += ft_putnbr_base(n / blen, base);
		cnt += ft_putnbr_base(n % blen, base);
	}
	return (cnt);
}

int	ft_putptr_base(size_t n, char *base)
{
	char	c;
	int		cnt;
	size_t	blen;

	cnt = 0;
	blen = ft_strlen(base);
	if (n < blen)
	{
		c = base[n];
		write(1, &c, 1);
		cnt++;
	}
	else
	{
		cnt += ft_putptr_base(n / blen, base);
		cnt += ft_putptr_base(n % blen, base);
	}
	return (cnt);
}
