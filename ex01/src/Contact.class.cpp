/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:33:56 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/19 18:10:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>
#include <string>

Contact::Contact(void)
{
	if (CLASS_LOG)
		std::cout << "Contact constructor called !" << std::endl;
    return;

}

Contact::~Contact(void)
{
	if (CLASS_LOG)
		std::cout << "Contact destructor called !" << std::endl;
    return;
}

bool Contact::setContactInfo(const std::string& firstName,
                             const std::string& lastName,
                             const std::string& nickname,
                             const std::string& phoneNbr,
                             const std::string& darkestSecret)
{
    if (firstName.empty() || lastName.empty() || nickname.empty()
		|| phoneNbr.empty() || darkestSecret.empty())
        return (false);
    Contact::_firstName      = firstName;
    Contact::_lastName      = lastName;
    Contact::_nickname      = nickname;
    Contact::_phoneNbr      = phoneNbr;
    Contact::_darkestSecret = darkestSecret;
    return (true);
}

std::string Contact::getFirstName() const
{
	return (Contact::_firstName);
}

std::string Contact::getLastName() const
{
	return (Contact::_lastName);
}

std::string Contact::getNickname() const
{
	return (Contact::_nickname);
}

std::string Contact::getPhoneNbr() const
{
	return (Contact::_phoneNbr);
}

std::string Contact::getDarkestSecret() const
{
	return (Contact::_darkestSecret);
}

bool Contact::checkIfEmpty() const
{
	if (Contact::_firstName.empty())
		return (true);
	else
		return (false);
}
