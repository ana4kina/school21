/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:41:52 by lcombo            #+#    #+#             */
/*   Updated: 2022/01/12 19:28:32 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long int n)
{
	int	len;

	len = ft_str("0x");
	len += ft_base(n, 'x');
	return (len);
}

int	ft_parse(char arg, va_list ap)
{
	int	count;

	count = 0;
	if (arg == 'i' || arg == 'd')
		count += ft_num(va_arg(ap, int));
	else if (arg == 'u')
		count += ft_num_u(va_arg(ap, unsigned int));
	else if (arg == 'c')
		count += ft_char(va_arg(ap, int));
	else if (arg == 'x' || arg == 'X')
		count += ft_base(va_arg(ap, unsigned int), arg);
	else if (arg == 'p')
		count += ft_ptr(va_arg(ap, unsigned long int));
	else if (arg == 's')
		count += ft_str(va_arg(ap, char *));
	else if (arg == '%')
		count += ft_char('%');
	return (count);
}

int	ft_len_va(const char *str, va_list ap)
{
	int	length;

	length = 0;
	while (*str)
	{
		if (*str == '%')
			length += ft_parse(*++str, ap);
		else
			length += ft_char(*str);
		++ str;
	}
	return (length);
}

int	ft_printf(const char *s, ...)
{
	int				count;
	va_list			ap;

	va_start(ap, s);
	count = ft_len_va(s, ap);
	va_end(ap);
	return (count);
}
