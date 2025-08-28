/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:22:14 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/01 01:17:16 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ct("Lcombo");

	ct.attack("CppModule03");
	ct.takeDamage(6);
	ct.beRepaired(3);
	ct.takeDamage(3);
	ct.beRepaired(8);
	ct.takeDamage(17);
    ct.beRepaired(112); //died..
    ct.takeDamage(15); // died..
	return (0);
}
