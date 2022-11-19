/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:45:20 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/19 00:47:33 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_cntdigit_base(int n, char *base)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
	{
		n *= -1;
		cnt++;
	}
	while (n > 0)
	{
		n /= ft_strlen(base);
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*ptr;
	int		size;

	size = ft_cntdigit_base(n, base);
	// if (n == -2147483648)
	// 	return (ft_strdup("-2147483648"));
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	ptr [size] = '\0';
	while (n > 0)
	{
		ptr[size - 1] = base[(n % ft_strlen(base))];
		n /= ft_strlen(base);
		size--;
	}
	return (ptr);
}

int	main(void)
{
	printf("cnt = %d\n", ft_cntdigit_base(29, "01"));
	printf("\n%s\n", ft_itoa_base(29, "01"));
	return (0);
}
