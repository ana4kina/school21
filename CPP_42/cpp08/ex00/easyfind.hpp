/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:02:41 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/08 21:50:18 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iostream>
# include <vector>

template< template<typename, typename> class T>
int	easyfind(T<int, std::allocator<int> > &arr, int i);

# include "easyfind.tpp"
#endif
