/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:34:27 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/08 20:30:04 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T>
void	iter(T const *arr, unsigned int const &size, void (*f)(T const &i))
{
	unsigned int	i;

	i = 0;
	while (i < size)
		f(arr[i++]);
}

#endif