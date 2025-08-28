/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:35:27 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/06 18:34:36 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static AForm	*createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern() {};

Intern::Intern(Intern const &inst)
{
	*this = inst;
}
Intern::~Intern() {};

AForm*	Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm			*form;
	typedef AForm	*(*_func)(std::string const &target); // пустой массив функций
	typedef struct	{std::string name; _func func;} FormTypes;

	form = NULL;
	FormTypes	forms[] =
	{
		{"presidential pardon", &createPresidentialPardonForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"shrubbery creation", &createShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
		{
			form = forms[i].func(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern can`t create the form " << name << std::endl;
	return (form);
}
