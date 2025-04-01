/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_myPhoneBook.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:51:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/01 16:03:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../src/PhoneBook.class.hpp"
#include "../src/Contact.class.hpp"
#include <string>
#include <sstream>
#include <iostream>

// Test addContact
TEST(phoneBookFunctions, addContact)
{
    PhoneBook phoneBook;
    std::stringstream input("John\nDoe\nJohnny\n1234567890\nSecret\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());

    phoneBook.addContact();

    std::cin.rdbuf(orig); // Restore original buffer

    // Check if the contact was added correctly using the new method
    EXPECT_EQ(phoneBook.getContact(0).getFirstName(), "John");
    EXPECT_EQ(phoneBook.getContact(0).getLastName(), "Doe");
    EXPECT_EQ(phoneBook.getContact(0).getNickname(), "Johnny");
    EXPECT_EQ(phoneBook.getContact(0).getPhoneNbr(), "1234567890");
    EXPECT_EQ(phoneBook.getContact(0).getDarkestSecret(), "Secret");
}

// Test setContactInfo
TEST(ContactFunctions, setContactInfo)
{
    Contact contact;
    bool result = contact.setContactInfo("John", "Doe", "Johnny", "1234567890", "Secret");

    EXPECT_TRUE(result);
    EXPECT_EQ(contact.getFirstName(), "John");
    EXPECT_EQ(contact.getLastName(), "Doe");
    EXPECT_EQ(contact.getNickname(), "Johnny");
    EXPECT_EQ(contact.getPhoneNbr(), "1234567890");
    EXPECT_EQ(contact.getDarkestSecret(), "Secret");
}
