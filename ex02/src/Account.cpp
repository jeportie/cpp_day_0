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
: _accountIndex(Account::_nbAccounts)
, _amount(initial_deposit)
, _nbDeposits(0)
, _nbWithdrawals(0)
{
    static int index;

    this->_accountIndex = index;
    index++;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created"
              << std::endl;
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed"
              << std::endl;
}

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int Account::getTotalAmount(void) { return (Account::_totalAmount); }

int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void Account::_displayTimestamp(void)
{
    std::time_t now       = std::time(NULL);
    std::tm*    localTime = std::localtime(&now);
    char        buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << buffer;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount;

    p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
              << ";deposit:" << deposit << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
    return;
}

int Account::checkAmount(void) const { return (this->_amount); }

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount;

    p_amount = this->checkAmount();
    Account::_displayTimestamp();
    if (this->_amount < withdrawal)
    {
        std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
                  << ";withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
                  << ";withdrawal:" << withdrawal << ";amount:" << this->checkAmount()
                  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount()
              << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
    return;
}
