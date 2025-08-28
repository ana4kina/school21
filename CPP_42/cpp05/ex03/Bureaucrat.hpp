/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:35:58 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/06 16:09:23 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <stdexcept>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
protected:
	std::string	name;
	int			grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &inst);
	virtual ~Bureaucrat();
	Bureaucrat			&operator=(Bureaucrat const &inst);

	const std::string	&getName(void) const;
	const int			&getGrade(void) const;
	void				incGrade(unsigned int value);
	void				decGrade(unsigned int value);

	void				signForm(AForm &inst);
	void				executeForm(AForm &inst);

	class GradeTooHighException: public std::runtime_error
	{
	public:
		GradeTooHighException(void): runtime_error("Grade to high"){};
	};
	class GradeTooLowException: public std::runtime_error
	{
	public:
		GradeTooLowException(void): runtime_error("Grade to low"){};
	};
};

std::ostream			&operator<<(std::ostream &out, Bureaucrat const &inst);

#endif