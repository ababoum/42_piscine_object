#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>

struct Bank
{
    struct Account
    {
    private:
        int id;
        int value;
        static int id_index;

        Account();

    public:
        int getId() const;
        int getValue() const;

        friend Bank;
        friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
    };

private:
    int liquidity;
    std::vector<Account *> clientAccounts;

public:
    Bank();
    ~Bank();

    Account *openAccount(int deposit);
    bool closeAccount(int id);
    void lendMoney(int id, int loan);
    void creditAccount(int id, int deposit);
    void updateLiquidity(int delta);

    Account &operator[](int id);

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
};

typedef Bank::Account Account;

#endif