/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:56:21 by lcombo            #+#    #+#             */
/*   Updated: 2022/01/11 23:33:06 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_char(char c);
int	ft_str(char *s);
int	ft_num(int n);
int	ft_num_u(unsigned int n);
int	ft_base(unsigned long int n, char c);
int	ft_ptr(unsigned long int n);
int	ft_parse(char arg, va_list ap);
int	ft_len_va(const char *str, va_list ap);
int	ft_printf(const char *s, ...);

#endif
