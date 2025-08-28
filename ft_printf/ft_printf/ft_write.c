/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:01:03 by lcombo            #+#    #+#             */
/*   Updated: 2022/01/12 20:59:39 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = 6;
		write(1, "(null)", 6);
	}
	else
	{
		while (s[i])
			i += ft_char(*(s + i));
	}		
	return (i);
}

int	ft_num(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_str("-2147483648"));
	if (n < 0)
	{
		count += ft_char('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_num(n / 10);
		count += ft_num(n % 10);
	}
	else
		count += ft_char((char)(n + '0'));
	return (count);
}

int	ft_num_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_num(n / 10);
		count += ft_num(n % 10);
	}
	else
		count += ft_char((char)(n + '0'));
	return (count);
}

int	ft_base(unsigned long int n, char c)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count += ft_base(n / 16, c);
		count += ft_base(n % 16, c);
	}
	else if (c == 'x')
	{
		if (n >= 0 && n <= 9)
			count += ft_char(n + '0');
		else
			count += ft_char(n - 10 + 'a');
	}
	else
	{
		if (n >= 0 && n <= 9)
			count += ft_char(n + '0');
		else
			count += ft_char(n - 10 + 'A');
	}
	return (count);
}
