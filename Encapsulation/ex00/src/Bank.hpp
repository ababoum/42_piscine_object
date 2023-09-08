#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>

#include "Account.hpp"

struct Bank
{
private:
    int liquidity;
    std::vector<Account *> clientAccounts;

public:
    Bank();

    Account *openAccount(int deposit);
    bool closeAccount(int id);
    void lendMoney(int id, int loan);

    void updateLiquidity(int delta);

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
};

#endif