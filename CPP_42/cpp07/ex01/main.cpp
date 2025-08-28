/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:26:43 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/08 20:33:40 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// class Awesome
// {
// public:
//     Awesome(void) : _n(42) { return; }
//     int get(void) const { return this->_n; }

// private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
// template< typename T >
// void print( T const & x) { std::cout << x << std::endl; return; }

// int main(void)
// {
//     int tab[] = { 0, 1, 2, 3, 4 };
//     Awesome tab2[5];

//     iter( tab, 5, print);
//     iter( tab2, 5, print);
// 	return 0;
// }

template< typename T >
void print(T const & x) { std::cout << x << std::endl; return; }

int main(void)
{
	int a[3] = {1, 2, 3};
	unsigned int size = 3;
	std::string strs[] = { "Salut", "Comment" , "Tutu", "Vasil", "?"};

	iter(a, size, print);
	iter(strs, strs->length(), print);
	return 0;
}
