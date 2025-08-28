/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:35:50 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/06 16:10:18 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <cstdlib>
# include "AForm.hpp"

class	Bureaucrat;

class RobotomyRequestForm : virtual public AForm
{
public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &inst);
		virtual ~RobotomyRequestForm();

		void		execute(Bureaucrat const &executor) const;
};

#endif
