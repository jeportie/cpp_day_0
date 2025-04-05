/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.public.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:05:40 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/20 00:01:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook(void)
: _arrIndex(0)
{
    if (CLASS_LOG)
        std::cout << "PhoneBook constructor called!" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    if (CLASS_LOG)
        std::cout << "PhoneBook destructor called!" << std::endl;
    return;
}

void PhoneBook::addContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNbr;
    std::string darkestSecret;

    firstName     = this->_getInput("Please enter the new contact first name:");
    lastName      = this->_getInput("Please enter the new contact last name:");
    nickname      = this->_getInput("Please enter the new contact nickname:");
    phoneNbr      = this->_getInput("Please enter the new contact phone number:");
    darkestSecret = this->_getInput("Please enter the new contact darkest secret:");

    if (!this->_contacts[_arrIndex % 8].setContactInfo(
            firstName, lastName, nickname, phoneNbr, darkestSecret))
    {
        std::cout << "error: setContactInfo failed" << std::endl;
        return;
    }
    this->_arrIndex++;
    std::cout << "name recorded : " << _contacts[_arrIndex % 8].getFirstName() << std::endl;
    return;
}

void PhoneBook::searchContact()
{
    std::string index;
    int         i;

    index = this->_getInput("Please enter a PhoneBook index");
    i     = std::atoi(index.c_str()) % 8;
    this->_printContact(index, i);
}

const Contact& PhoneBook::getContact(int index) const { return (_contacts[index % 8]); }
