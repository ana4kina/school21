/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:40:55 by lcombo            #+#    #+#             */
/*   Updated: 2022/10/29 18:59:40 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include <iostream>
# include "Contacts.hpp"
# define SEARCH_HEADER "\
---------------------------------------------\n\
|     Index|First name| Last name|  Nickname|\n\
---------------------------------------------\n"
# define SEARCH_FOOTER "\
---------------------------------------------"

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
    public:
        PhoneBook();
        void	add(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number,
		std::string darkest_secret);
	    void	search();
	    void	display_contact(void);
};

#endif