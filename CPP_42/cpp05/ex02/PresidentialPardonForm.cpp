/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:10 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/06 17:53:24 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	AForm("PresidentialPardonForm", target, 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &inst):
	AForm(inst.getName(), inst.getTarget(), inst.getGradeToSign(),
		inst.getGradeToExecute())
{
	this->setIsSigned(inst.getIsSigned());
}

PresidentialPardonForm::~PresidentialPardonForm() {};

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->beExecuted(executor);
		std::cout << this->getTarget() << " was pardoned by Zaphod Beeblebrox."
			<< std::endl;

	}
	catch(const AForm::AFormNotSignedException& e)
	{
		throw e;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		throw e;
	}
}
