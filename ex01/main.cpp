/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:57:36 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/19 18:00:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/PhoneBook.class.hpp"
#include "includes/colors.hpp"
#include <iostream>
#include <ostream>
#include <string>

int main(void)
{
    PhoneBook   repertory;
    std::string cmd;

    std::cout << RED << "Welcome To My Awsome PhoneBook!" << RESET << std::endl;
	std::cout << std::endl << GREEN << "Loading\t..." << RESET << std::endl;
	std::cout << GREEN << "..." << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "..." << RESET << std::endl;
	std::cout << "===============================================" << std::endl;
	while (1)
	{
		cmd.erase();
		std::cout << ">>" << std::flush;
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		if (cmd == "ADD")
			repertory.addContact();
		if (cmd == "SEARCH")
			repertory.searchContact();
	}
    return (0);
}
