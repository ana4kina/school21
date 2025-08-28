/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:08:00 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/08 21:36:14 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

template <typename T>
size_t	Array<T>::size() const
{
	return (this->__size);
}

template <typename T>
T&			Array<T>::operator[](size_t index)
{
	if (index < 0 || index >= this->__size)
		throw (std::exception());
	else
		return (this->__array[index]);
}

template <typename T>
const T&			Array<T>::operator[](size_t index) const
{
	if (index < 0 || index >= this->__size)
		throw (std::exception());
	else
		return (this->__array[index]);
}

template <typename T>
const Array<T>&	Array<T>::operator=(const Array &assign)
{
	this->~Array();
	this->__array = new T[assign.__size];
	this->__size = assign.__size;
	
	for (size_t i = 0; i < this->__size; i++)
		this->__array[i] = assign.__array[i];
	
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->__array;
	this->__array = nullptr;
	this->__size = 0;
	std::cout << "<<Array Destroyed>>" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : __array(nullptr)
{
	std::cout << "Array Copy Constructor called" << std::endl;
	*this = copy;
}

template <typename T>
Array<T>::Array(size_t _size)
{
	std::cout << "Array fields Constructor called" << std::endl;
	this->__array = new T[_size];
	this->__size = _size;
}

template <typename T>
Array<T>::Array()
{
	std::cout << "Array Default Constructor called" << std::endl;
	this->__array = nullptr;
	this->__size = 0;
}

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T>& array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
	return (stream);
}

#endif