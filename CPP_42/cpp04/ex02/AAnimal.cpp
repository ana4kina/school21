/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:32 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/04 19:45:16 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: destructor called." << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	this->setType(type);
	std::cout << "AAnimal: constructor called." << std::endl;
}

void		AAnimal::setType(std::string type)
{
	this->type = type;
}

const std::string		&AAnimal::getType(void) const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &out, const AAnimal &inst)
{
	return (out << inst.getType() << std::endl);
}
