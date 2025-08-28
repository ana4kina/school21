/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:08:03 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/08 21:33:21 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		Array();
		Array( size_t _size );
		Array(const Array &copy);
		~Array();
		
		const Array&	operator=(const Array &assign);
		const T&			operator[](size_t index) const;
		T&					operator[](size_t index);
		size_t	size() const;
		
	private:
		size_t	__size;
		T*		__array;
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T>& array);

# include "Array.tpp"
#endif