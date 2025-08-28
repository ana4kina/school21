/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:57:03 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/02 15:57:05 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
protected:
	std::string		ideas[100];

public:
	Brain();
	Brain(Brain const &inst);
	virtual ~Brain();

	Brain 		&operator=(Brain const &inst);
	std::string	&getIdea(int i);
	void		setIdea(int i, std::string &value);
};

#endif
