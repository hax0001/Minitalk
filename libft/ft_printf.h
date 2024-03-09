/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:00:57 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/08 19:21:12 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_nbr(int nbr);
int		ft_print_pointer(unsigned long value);
int		ft_print_hex(unsigned int n, int d);
int		ft_print_unsigned(unsigned int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
size_t		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
