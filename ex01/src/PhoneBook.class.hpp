/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:58:08 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/19 18:04:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);

	void		addContact();
	void		searchContact();

private:
	int			_arrIndex;
	Contact		_contacts[8];
	std::string	_getInput(const std::string &inputElem);
	void		_printContact(std::string index, int i);
	std::string _formatString(std::string str);
};

#endif /* ********************************************** !PHONEBOOK_CLASS_HPP */
