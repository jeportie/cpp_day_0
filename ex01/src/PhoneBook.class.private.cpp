/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.private.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:00:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/20 00:01:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

/**
 * @brief Prompts the user for input and ensures it is not empty.
 * @param promptText The text to display as a prompt to the user.
 * @return A non-empty string input by the user.
 */
std::string PhoneBook::_getInput(const std::string& promptText)
{
    std::string input;

    while (input.empty())
    {
        std::cout << promptText << std::endl;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Error: Cannot be empty!" << std::endl;
    }
    return (input);
}

std::string PhoneBook::_formatString(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + "."); 
	else
		return (str);
}

void PhoneBook::_printContact(std::string index, int i)
{
	Contact	current;

	current = PhoneBook::_contacts[i];
	if (current.checkIfEmpty())
	{
		std::cout << "Error: index in the PhoneBook is empty" << std::endl;
		return;
	}
	std::cout	<< "|" << std::setw(10) << std::setfill(' ') << "index"
				<< "|" << std::setw(10) << std::setfill(' ') << "first name"
				<< "|" << std::setw(10) << std::setfill(' ') << "last name"
				<< "|" << std::setw(10) << std::setfill(' ') << "nickname"
				<< "|" << std::endl;
	std::cout	<< "|" << std::setw(10) << std::setfill(' ') << PhoneBook::_formatString(index)
				<< "|" << std::setw(10) << std::setfill(' ') << PhoneBook::_formatString(current.getFirstName())
				<< "|" << std::setw(10) << std::setfill(' ') << PhoneBook::_formatString(current.getLastName())
				<< "|" << std::setw(10) << std::setfill(' ') << PhoneBook::_formatString(current.getNickname())
				<< "|" << std::endl;
}
