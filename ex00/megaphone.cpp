/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:35:14 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/18 10:34:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

std::string strToupper(std::string& str)  // Passing by reference
{
    for (size_t i = 0; i < str.size(); i++)
        str[i] = std::toupper(str[i]);
    return (str);
}

std::string strCheckSpace(std::string str)  // Passing by value
{
    std::string strRes;
    bool        isLastSpace;

    isLastSpace = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            if (!isLastSpace && i < str.size() - 1)
            {
                strRes += str[i];
                isLastSpace = true;
            }
        }
        else
        {
            strRes += str[i];
            isLastSpace = false;
        }
    }
    return (strRes);
}

int main(int ac, char** av)
{
    std::string cat;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            cat += av[i];
            if (i < ac - 1)
                cat += " ";
        }
        cat = strToupper(cat);
        std::cout << strCheckSpace(cat) << std::endl;
    }
    return (0);
}
