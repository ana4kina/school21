/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:56:00 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/02 17:59:38 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
# define Animal_HPP
# include <iostream>
# include <string>

class Animal
{
protected:
	std::string		type;

public:
	Animal();
	Animal(std::string name);
	Animal(Animal const &inst);
	Animal 		&operator=(Animal const &inst);
	virtual ~Animal();

	const std::string	&getType(void) const;
	virtual void		makeSound(void) const;
};

std::ostream			&operator<<(std::ostream &out, const Animal &inst);

#endif
