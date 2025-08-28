/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:40:50 by lcombo            #+#    #+#             */
/*   Updated: 2022/10/29 18:49:50 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
    private:
        std::string	first_name;
	    std::string	last_name;
	    std::string	nickname;
	    std::string	phone_number;
	    std::string	darkest_secret;
    public:
        void add(std::string first_name, std::string last_name,
		    std::string nickname, std::string phone_number,
		    std::string darkest_secret);
	    std::string	get(std::string fild_name);
};

#endif