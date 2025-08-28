/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:56:09 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/02 18:00:22 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string		type;

public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(WrongAnimal const &inst);
	virtual ~WrongAnimal();

	WrongAnimal 		&operator=(WrongAnimal const &inst);

	const std::string	&getType(void) const;
	void				makeSound(void) const;
};

std::ostream			&operator<<(std::ostream &out, const WrongAnimal &inst);

#endif
