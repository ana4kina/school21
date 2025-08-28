/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:19:48 by lcombo            #+#    #+#             */
/*   Updated: 2022/10/29 17:22:05 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void megaphone(int argc, char **argv)
{
    int i, j;

    i = 1;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return ;
    }
    while (argv && argv[i] && i <= argc)
    {
        j = 0;
        while (argv[i][j])
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j += 1;
        }
        i += 1;
    }
}

int main(int argc, char** argv)
{
    megaphone(argc, argv);
    return 0;
}