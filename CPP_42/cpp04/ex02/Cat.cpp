/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:46 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/02 15:57:13 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat"), brain(new Brain())
{
	this->name = "NoName";
	//this->brain = new Brain();
	std::cout << "Cat: default constructor called." << std::endl;
}

Cat::Cat(std::string name): AAnimal("Cat"), brain(new Brain())
{
	this->name = name;
	//this->brain = new Brain();
	std::cout << "Cat: Name constructor called. " << this->name << std::endl;
}

Cat::Cat(Cat const &inst): AAnimal("Cat")
{
	*this = inst;
	std::cout << "Cat: copy constructor called. " << this->name << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor called." << std::endl;
	delete this->brain;
}

Cat	&Cat::operator=(Cat const &inst)
{
	this->name = inst.name;
	*this->brain = *inst.brain;
	std::cout << "Cat: default assignment called." << this->name << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << " " << getName() << " Myau" << std::endl;
}

const std::string		&Cat::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const Cat &inst)
{
	return (out << "Cat: " << inst.getName() << std::endl);
}

std::string	&Cat::getIdea(int i)
{
	return (this->brain->getIdea(i));
}

void	Cat::setIdea(int i, std::string value)
{
	this->brain->setIdea(i, value);
}
