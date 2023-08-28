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

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
};