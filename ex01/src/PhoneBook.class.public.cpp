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
{
    std::cout << "PhoneBook constructor called!" << std::endl;
    PhoneBook::_arrIndex = 0;
    return;
}

PhoneBook::~PhoneBook(void)
{
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
    Contact     current;

    firstName     = PhoneBook::_getInput("Please enter the new contact first name:");
    lastName      = PhoneBook::_getInput("Please enter the new contact last name:");
    nickname      = PhoneBook::_getInput("Please enter the new contact nickname:");
    phoneNbr      = PhoneBook::_getInput("Please enter the new contact phone number:");
    darkestSecret = PhoneBook::_getInput("Please enter the new contact darkest secret:");

    current = PhoneBook::_contacts[_arrIndex % 8];
    if (!current.setContactInfo(firstName, lastName, nickname, phoneNbr, darkestSecret))
    {
        std::cout << "error: setContactInfo failed" << std::endl;
        return;
    }
    PhoneBook::_contacts[_arrIndex % 8] = current;
    PhoneBook::_arrIndex++;
    std::cout << "first name recorded : " << current.getFirstName() << std::endl;
    return;
}

void PhoneBook::searchContact()
{
    std::string index;
    int         i;

    index = PhoneBook::_getInput("Please enter a PhoneBook index");
    i     = std::atoi(index.c_str()) % 8;
    PhoneBook::_printContact(index, i);
}
