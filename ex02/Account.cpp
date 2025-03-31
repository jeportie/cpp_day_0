/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:45:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/31 14:12:42 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

static int _nbAccounts = 0;
static int _totalAmount = 0;
static int _totalNbDeposits = 0;
static int _totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	std::cout << "Account constructor called" << std::endl;
	Account::makeDeposit(initial_deposit);
}

Account::~Account(void)
{
	std::cout << "Account destructor called" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
} 

int  Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int  Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int  Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void displayAccountsInfos(void);
