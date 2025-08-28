/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:11:21 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/02 17:34:31 by lcombo           ###   ########.fr       */
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
	virtual ~Animal();

	virtual Animal 		&operator=(Animal const &inst);

	const std::string	&getType(void) const;
	virtual void		makeSound(void) const;
	virtual std::string	&getIdea(int i);
	virtual void		setIdea(int i, std::string value);
};

std::ostream			&operator<<(std::ostream &out, const Animal &inst);

#endif
