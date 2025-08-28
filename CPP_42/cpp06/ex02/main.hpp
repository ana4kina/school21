/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:25:28 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/07 01:09:36 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <ctime>

class Base
{
public:
	virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif