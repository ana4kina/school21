/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:56:37 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/04 20:12:15 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	this->name = "NoName";
	std::cout << "Dog: default constructor called." << std::endl;
}

Dog::Dog(std::string name): Animal("Dog")
{
	this->name = name;
	std::cout << "Dog: Name constructor called. " << this->name << std::endl;
}

Dog::Dog(Dog const &inst): Animal("Dog")
{
	*this = inst;
	std::cout << "Dog: copy constructor called. " << this->name << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called." << std::endl;
}

Dog	&Dog::operator=(Dog const &inst)
{
	this->name = inst.name;
	std::cout << "Dog: default assignment called." << this->name << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog " << getName() << " Gav" << std::endl;
}

const std::string		&Dog::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const Dog &inst)
{
	return (out << "Dog: " << inst.getName() << std::endl);
}
