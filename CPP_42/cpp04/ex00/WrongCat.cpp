/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:00:25 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/04 17:46:05 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): name("WrongCat")
{
	this->name = "NoName";
	std::cout << "WrongCat: default constructor called." << std::endl;
}

WrongCat::WrongCat(std::string name): WrongAnimal("WrongCat")
{
	this->name = name;
	std::cout << "WrongCat: Name constructor called. " << this->name << std::endl;
}

WrongCat::WrongCat(WrongCat const &inst): WrongAnimal("WrongCat")
{
	*this = inst;
	std::cout << "WrongCat: copy constructor called. " << this->name << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor called." << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &inst)
{
	this->name = inst.name;
	std::cout << "WrongCat: default assignment called." << this->name << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat " << getName() << " Meow" << std::endl;
}

const std::string		&WrongCat::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const WrongCat &inst)
{
	return (out << "WrongCat: " << inst.getName() << std::endl);
}
