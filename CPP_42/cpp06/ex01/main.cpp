/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:21:55 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/07 00:41:54 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdint>

struct Data
{
	std::string	name;
	int			age;
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main(void)
{
	Data before;
	before.name	= "lcombo";
	before.age	= 20;

	uintptr_t raw = serialize(&before);
	Data *after = deserialize(raw);

	std::cout	<< "Address of Data before serialize:  " << &before << std::endl
				<< "Address of Data after deserialize: " << after  << std::endl;

	std::cout << std::endl;

	std::cout
	<< "Data before.Name: " << before.name << std::endl
	<< "Data before.Age: "  << before.age  << std::endl;

	std::cout << std::endl;

	std::cout
	<< "Data after.Name: " << after->name << std::endl
	<< "Data after.Age: "  << after->age  << std::endl;
}