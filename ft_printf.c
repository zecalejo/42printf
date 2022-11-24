/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:12:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/24 12:03:04 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_conv(char c, va_list ap)
{
	int	l;

	if (c == 'c')
		l = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		l = ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
	{
		ft_putstr("0x");
		l = 2 + ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	}	
	else if (c == 'd' || c == 'i')
		l = ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		l = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		l = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		l = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		l = ft_putchar('%');
	return (l);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	char	x;
	int		cnt;

	va_start(ap, s);
	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			x = ft_conv(s[i + 1], ap);
			i += 2;
		}
		ft_putchar(s[i]);
		cnt++;
	}
	return (x + cnt);
}

int	main(void)
{
	char	*str = "This is a string.";
	int		pf;
	int		ftpf;

	// Char
	printf("-------------------------\n");
	printf("Char:\n");
	ftpf = ft_printf("ft_printf = \'%c\'\n", 'z');
	pf = printf("printf = \'%c\'\n", 'z');
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// String
	printf("String:\n");
	ftpf = ft_printf("ft_printf = \"%s\"\n", str);
	pf = printf("printf = \"%s\"\n", str);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// Pointer
	printf("Pointer:\n");
	ftpf = ft_printf("ft_printf = \"%p\"\n", str);
	pf = printf("printf = \"%p\"\n", str);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// Int
	printf("Int:\n");
	ftpf = ft_printf("ft_printf (d) = %d\n", 12345);
	pf = printf("printf (d) = %d\n", 12345);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	ftpf = ft_printf("\nft_printf (i) = %i\n", -123);
	pf = printf("printf (i) = %i\n", -123);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// Unsigned int
	printf("Unsigned int:\n");
	ftpf = ft_printf("ft_printf = %u\n", 123456);
	pf = printf("printf = %u\n", 123456);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// Hexadecimal
	printf("Hexadecimal:\n");
	ftpf = ft_printf("ft_printf (x) = %x\n", 44);
	pf = printf("printf (x) = %x\n", 44);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	ftpf = ft_printf("\nft_printf (X) = %X\n", 44);
	pf = printf("printf (X) = %X\n", 44);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// %
	printf("\'%%\':\n");
	ftpf = ft_printf("ft_printf = %%\n");
	pf = printf("printf = %%\n");
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	return (0);
}
