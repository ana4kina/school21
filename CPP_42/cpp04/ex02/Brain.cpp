/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:40 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/02 15:56:48 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: default constructor called." << std::endl;
}

Brain::Brain(Brain const &inst)
{
	*this = inst;
	std::cout << "Brain: copy constructor called. " << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called." << std::endl;
}

Brain	&Brain::operator=(Brain const &inst)
{
	std::copy(inst.ideas, inst.ideas + 100, this->ideas);
	std::cout << "Brain: default assignment called." << std::endl;
	return (*this);
}

std::string	&Brain::getIdea(int i)
{
	return (this->ideas[i]);
}

void	Brain::setIdea(int i, std::string &value)
{
	this->ideas[i] = value;
}
