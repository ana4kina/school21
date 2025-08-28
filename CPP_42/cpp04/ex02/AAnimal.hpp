/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:56:36 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/04 20:05:21 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP
# include <iostream>
# include <string>

class AAnimal
{
protected:
	std::string		type;

public:
	AAnimal(std::string type);
	virtual ~AAnimal();

	void				setType(std::string type);
	const std::string	&getType(void) const;
	virtual void		makeSound(void) const = 0;
	virtual std::string	&getIdea(int i) = 0;
	virtual void		setIdea(int i, std::string value) = 0;
};

std::ostream			&operator<<(std::ostream &out, const AAnimal &inst);

#endif
