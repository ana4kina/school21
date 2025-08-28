/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:06 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/04 22:31:31 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	AForm("ShrubberyCreationForm", target, 145, 137){};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &inst):
	AForm(inst.getName(), inst.getTarget(), inst.getGradeToSign(),
		inst.getGradeToExecute())
{
	this->setIsSigned(inst.getIsSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream file;

	try
	{
		this->beExecuted(executor);
		file.open(std::string(this->getTarget() + "_shrubbery").c_str(),
		std::ios::out | std::ios::app);
		if(file.is_open())
		{
			file << TREE << std::endl;
			file.close();
		}
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
