/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:54:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/18 11:55:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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
