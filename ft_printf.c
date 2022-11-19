/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:12:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/18 09:16:09 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_conv(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, char), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
	
	else if (c == 'd')
	
	else if (c == 'i')
	
	else if (c == 'u')
	
	else if (c == 'x')
	
	else if (c == 'X')
	
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return ()
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	char	x;

	va_start(ap, s);
	i = -1;
	while (s[++i] && s[i] != '%')
		ft_putchar_fd(s[i], 1);
	if (s[i] == '%' && s[i + 1] == 'c')
	{
		x = va_arg(ap, char);
		ft_putchar_fd(x, 1);
	}
	else if (s[i] == '%' && s[i + 1] == 's')
	{
		x =
	}
}
