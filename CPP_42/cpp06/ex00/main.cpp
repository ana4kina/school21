/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:02:12 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/06 20:44:54 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2 || std::string(av[1]).length() < 1)
	{
		std::cerr << "Usage:\n" <<
		av[0] << " <input>\n";
		return (1);
	}

	std::string input(av[1]);
	Convert test(input);

	test.displayConvert();
	return (0);
}