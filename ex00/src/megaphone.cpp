/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:35:14 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/18 11:56:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>

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
