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
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNbr.empty()
        || darkestSecret.empty())
        return (false);
    this->_firstName     = firstName;
    this->_lastName      = lastName;
    this->_nickname      = nickname;
    this->_phoneNbr      = phoneNbr;
    this->_darkestSecret = darkestSecret;
    return (true);
}

std::string Contact::getFirstName() const { return (this->_firstName); }

std::string Contact::getLastName() const { return (this->_lastName); }

std::string Contact::getNickname() const { return (this->_nickname); }

std::string Contact::getPhoneNbr() const { return (this->_phoneNbr); }

std::string Contact::getDarkestSecret() const { return (this->_darkestSecret); }

bool Contact::checkIfEmpty() const
{
    if (this->_firstName.empty())
        return (true);
    else
        return (false);
}
