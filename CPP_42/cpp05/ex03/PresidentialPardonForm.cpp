/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:35:38 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/04 22:32:20 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	AForm("PresidentialPardonForm", target, 25, 5){};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &inst):
	AForm(inst.getName(), inst.getTarget(), inst.getGradeToSign(),
		inst.getGradeToExecute())
{
	this->setIsSigned(inst.getIsSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(){};

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
