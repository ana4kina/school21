/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:40:48 by lcombo            #+#    #+#             */
/*   Updated: 2022/10/29 18:49:45 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

void	Contact::add(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string	Contact::get(std::string field_name)
{
	if (field_name == std::string("first_name"))
		return (this->first_name);
	if (field_name == std::string("last_name"))
		return (this->last_name);
	if (field_name == std::string("nickname"))
		return (this->nickname);
	if (field_name == std::string("phone_number"))
		return (this->phone_number);
	if (field_name == std::string("darkest_secret"))
		return (this->darkest_secret);
	return (std::string("Contact: Unknown field_name"));
}