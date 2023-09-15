#include <vector>
#include "Bank.hpp"

int Account::id_index = 0;

Account::Account()
{
    id = Account::id_index++;
    value = 0;
}

int Account::getId() const
{
    return id;
}

int Account::getValue() const
{
    return value;
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
{
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return (p_os);
}

Bank::Bank()
{
    liquidity = 0;
}

Bank::~Bank()
{
    for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
    {
        if (*it)
        {
            delete *it;
        }
    }
}

Account *Bank::openAccount(int deposit)
{
    if (deposit < 0)
    {
        throw std::runtime_error(std::string("An account cannot be opened with a negative deposit"));
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
            delete *it;
            *it = 0;
            return true;
        }
    }
    return false;
}

void Bank::creditAccount(int id, int deposit)
{
    if (deposit < 0)
    {
        throw std::runtime_error(std::string("A deposit cannot be negative"));
    }

    for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
    {
        Account *acc = *it;
        if (acc->id == id)
        {
            int fees = deposit * 5 / 100;

            liquidity += fees;
            acc->value += deposit - fees;
            return;
        }
    }
}

void Bank::lendMoney(int id, int loan)
{
    if (loan <= 0)
    {
        throw std::runtime_error(std::string("Loan cannot be negative or equal to zero"));
    }

    if (loan > liquidity)
    {
        throw std::runtime_error(std::string("The bank has insufficient funds"));
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

Account &Bank::operator[](int id)
{
    if (id < 0)
    {
        throw std::runtime_error(std::string("Account id cannot be negative"));
    }

    try
    {
        return *clientAccounts[id];
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error(std::string("Account id does not exist"));
    }
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