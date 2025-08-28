/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:35:35 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/06 16:10:03 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	a("Buro_1", 5);
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
	}
	return (0);
}
