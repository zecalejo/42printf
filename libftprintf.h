/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:04:47 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/25 13:37:20 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_base(long long n, char *base);
int		ft_putptr_base(size_t n, char *base);

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s);

void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif