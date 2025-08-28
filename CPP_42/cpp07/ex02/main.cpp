/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:07:48 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/08 21:24:17 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
# include <stdlib.h>
# include <time.h>

# define ARRAY_MAX_SIZE 10
# define SONS_OF_FEANOR 7
#define MAX_VAL 750

int main(void)
{
	srand(time(NULL));
	{
		Array<std::string>		first_array = Array<std::string>();
		Array<std::string>		second_array = Array<std::string>(ARRAY_MAX_SIZE);
		const char*				feanor_sons[SONS_OF_FEANOR] = {"Maedhros", "Maglor", "Celegorm", "Caranthir", "Curufin", "Amrod", "Amras"};
		
		try
		{
			std::cout << "first el of first_array is: " << first_array[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "first_array is empty" << std::endl;
			std::cout << "size: " << first_array.size() << std::endl;
		}
		
		for ( size_t i = 0; i < ARRAY_MAX_SIZE; i++ ) {
			second_array[i] = feanor_sons[rand() % SONS_OF_FEANOR];
		}
		
		std::cout << "\nCopying second_array in first_array" << std::endl;
		first_array = second_array;
	
		std::cout << std::endl << "Printing first_array" << std::endl;
		std::cout << first_array << std::endl;
		std::cout << std::endl << "Printing second_array" << std::endl;
		std::cout << second_array << std::endl;
		
	
		std::cout << std::endl << "Modifying first el of first_array" << std::endl;
		first_array[0] = "42";
		std::cout << std::endl << "Printing first_array" << std::endl;
		std::cout << first_array << std::endl;
		std::cout << std::endl << "Printing second_array" << std::endl;
		std::cout << second_array << std::endl;
		
		std::cout << std::endl << "Modifying last el of second_array" << std::endl;
		second_array[ARRAY_MAX_SIZE - 1] = "0";
		std::cout << std::endl << "Printing first_array" << std::endl;
		std::cout << first_array << std::endl;
		std::cout << std::endl << "Printing second_array" << std::endl;
		std::cout << second_array << std::endl;
	}
	{
		Array<int>		first_array = Array<int>();
		Array<int>		second_array = Array<int>(ARRAY_MAX_SIZE);
		int				dec_radix[ARRAY_MAX_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		
		try
		{
			std::cout << "first el of first_array is: " << first_array[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "first_array is empty" << std::endl;
			std::cout << "size: " << first_array.size() << std::endl;
		}
		
		//* FILLING second_array
		for ( size_t i = 0; i < ARRAY_MAX_SIZE; i++ ) {
			second_array[i] = dec_radix[i];
		}
		//* ............................
		
		std::cout << "\nCopying second_array in first_array" << std::endl;
		first_array = second_array;
	
		std::cout << std::endl << "Printing first_array" << std::endl;
		std::cout << first_array << std::endl;
		std::cout << std::endl << "Printing second_array" << std::endl;
		std::cout << second_array << std::endl;
		
	
		std::cout << std::endl << "Modifying first el of first_array" << std::endl;
		first_array[0] = 42;
		std::cout << std::endl << "Printing first_array" << std::endl;
		std::cout << first_array << std::endl;
		std::cout << std::endl << "Printing second_array" << std::endl;
		std::cout << second_array << std::endl;
		
		std::cout << std::endl << "Modifying last el of second_array" << std::endl;
		second_array[ARRAY_MAX_SIZE - 1] = 0;
		std::cout << std::endl << "Printing first_array" << std::endl;
		std::cout << first_array << std::endl;
		std::cout << std::endl << "Printing second_array" << std::endl;
		std::cout << second_array << std::endl;
	}
	{

		std::cout << "\n\nSubject tests\n\n";
		
		Array<int>	numbers(MAX_VAL);
		int* 		mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		std::cout << std::endl;
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "Testing subscript operator with const object" << std::endl;
		const Array<int> a = Array<int>(5);
	
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "a[0] = "  << a[0] << std::endl;
	}
	std::cout << std::endl;
	return 0;
}