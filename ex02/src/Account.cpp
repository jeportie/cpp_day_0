/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:45:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/03/31 19:07:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static int	index;

	Account::_accountIndex = index;
	index++;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout	<< " index:" << Account::_accountIndex
				<< ";amount:" << Account::_amount
				<< ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += Account::_amount;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout	<< " index:" << Account::_accountIndex
				<< ";amount:" << Account::_amount
				<< ";closed" << std::endl;
}

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int Account::getTotalAmount(void) { return (Account::_totalAmount); }

int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm*	localTime = std::localtime(&now);
	char		buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< " accounts:" << Account::getNbAccounts()
				<< ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits()
				<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = Account::_amount;
	Account::_amount += deposit;
	Account::_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout	<< " index:" << Account::_accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << Account::_amount
				<< ";nb_deposits:" << Account::_nbDeposits 
				<< std::endl;
	return ;
}

int  Account::checkAmount(void) const 
{
	return (Account::_amount);
}

bool Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = Account::checkAmount();
	Account::_displayTimestamp();
	if (Account::_amount < 0)
	{
		std::cout	<< " index:" << Account::_accountIndex
					<< ";p_amount:" << p_amount
					<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	else 
	{
		Account::_amount -= withdrawal;
		Account::_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout	<< " index:" << Account::_accountIndex
					<< ";p_amount:" << p_amount
					<< ";withdrawal:" << withdrawal
					<< ";amount:" << Account::checkAmount()
					<< ";nb_withdrawals:" << Account::_nbWithdrawals
					<< std::endl;
		return (true);
	}
}

void Account::displayStatus(void) const 
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << Account::_accountIndex
				<< ";amount:" << Account::checkAmount()
				<< ";deposits:" << Account::_nbDeposits 
				<< ";withdrawals:" << Account::_nbWithdrawals
				<< std::endl;
	return ;
}
