/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:33:41 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/19 18:10:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>
class Contact
{
public:
	Contact(void);
	~Contact(void);

	bool setContactInfo(const std::string &firstName,
						const std::string &lastName,
						const std::string &nickname,
						const std::string &phoneNbr,
						const std::string &darkestSecret);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNbr() const;
	std::string	getDarkestSecret() const;

	bool		checkIfEmpty() const;

private:
	std::string	_fistName;
	std::string	_lastName;
	std::string	_nickname;
	std::string _phoneNbr;
	std::string _darkestSecret;
};

#endif /* ************************************************ !CONTACT_CLASS_HPP */
