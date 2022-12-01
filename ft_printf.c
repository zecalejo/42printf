/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:12:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/12/01 14:08:46 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv(char c, va_list ap)
{
	int		l;
	size_t	ptr;

	l = 0;
	if (c == 'c')
		l += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		l += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
	{
		ptr = va_arg(ap, size_t);
		if (ptr == 0)
			return (write(1, "(nil)", 5));
		ft_putstr("0x");
		l += 2 + ft_putptr_base(ptr, "0123456789abcdef");
	}	
	else if (c == 'd' || c == 'i')
		l += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		l += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		l += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		l += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		l += ft_putchar('%');
	return (l);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	va_start(ap, s);
	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			cnt += ft_conv(s[i + 1], ap);
			i += 2;
		}
		ft_putchar(s[i]);
		cnt++;
	}
	va_end(ap);
	return (cnt);
}

int	main(void)
{
	char	*str = "This is a string.";
	int		pf;
	int		ftpf;

	// Char
	printf("-------------------------\n");
	printf("Char:\n");
	ftpf = ft_printf("ft_printf = \'%c\'\n", '0');
	pf = printf("printf = \'%c\'\n", '0');
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// String
	printf("String:\n");
	ftpf = ft_printf("ft_printf = \"%s\"\n", "");
	pf = printf("printf = \"%s\"\n", "");
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
	ftpf = ft_printf("ft_printf (d) = %d\n", INT_MIN);
	pf = printf("printf (d) = %d\n", INT_MIN);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	ftpf = ft_printf("ft_printf (i) = %i\n", LONG_MAX);
	pf = printf("printf (i) = %i\n", (int)LONG_MAX);
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
	ftpf = ft_printf("ft_printf (X) = %X\n", 44);
	pf = printf("printf (X) = %X\n", 44);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// %
	printf("\'%%\':\n");
	ftpf = ft_printf("ft_printf = %%\n");
	pf = printf("printf = %%\n");
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	// Mix
	printf("Mix:\n");
	ftpf = ft_printf("ft_printf = \"%s\" %d %i %p %X %%\n", str, INT_MAX, INT_MIN, str, 4567);
	pf = printf("printf = \"%s\" %d %i %p %X %%\n", str, INT_MAX, INT_MIN, str, 4567);
	printf("ftpf = %d | pf = %d\n", ftpf, pf);
	printf("-------------------------\n");
	return (0);
}