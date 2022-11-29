/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:24:45 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/24 15:49:22 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (write(1, "(null)", 6));
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

int	ft_putnbr_base(size_t n, char *base)
{
	size_t	blen;
	int		cnt;
	char	c;

	cnt = 0;
	blen = ft_strlen(base);
	if (n < blen)
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
