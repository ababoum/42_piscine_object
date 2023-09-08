#include <vector>
#include "Bank.hpp"

Bank::Bank()
{
    liquidity = 0;
}

Account *Bank::openAccount(int deposit)
{
    if (deposit < 0)
    {
        std::cout << "An account cannot be opened with a negative deposit" << std::endl;
        return 0;
    }

    Account *newAccount = new Account;
    int fees = deposit * 5 / 100;

    liquidity += fees;
    newAccount->value = deposit - fees;

    clientAccounts.push_back(newAccount);

    return newAccount;
}

bool Bank::closeAccount(int id)
{
    for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
    {
        Account *acc = *it;
        if (acc->id == id)
        {
            Account *toDelete = *it;

            clientAccounts.erase(it);
            delete toDelete;
            return true;
        } 
    }
    return false;
}

void Bank::lendMoney(int id, int loan)
{
    if (loan <= 0)
    {
        std::cout << "Loan cannot be negative or equal to zero" << std::endl;
        return;
    }

    if (loan > liquidity)
    {
        std::cout << "The bank has insufficient funds" << std::endl;
        return;
    }

    for (size_t i = 0; i < clientAccounts.size(); ++i)
    {
        if (clientAccounts[i]->id == id)
        {
            liquidity -= loan;
            clientAccounts[i]->value += loan;
            return;
        }
    }
    std::cout << "ID does not match any account" << std::endl;
}

void Bank::updateLiquidity(int delta)
{
    liquidity += delta;
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;
     for (std::vector<Account *>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it)
     {
        Account *clientAccount = *it;
        p_os << *clientAccount << std::endl;
     }
    return (p_os);
}