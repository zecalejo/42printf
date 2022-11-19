/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:04:47 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/18 23:56:54 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_cntdigit_base(int n, char *base);

size_t	ft_strlen(const char *str);

char	*ft_itoa_base(int n, char *base);
char	*ft_strdup(const char *s);


void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif