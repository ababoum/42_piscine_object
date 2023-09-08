#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <vector>

struct Bank;

struct Account
{
private:
    int id;
    int value;
    static int id_index;

    Account();

    friend Bank;

public:
    friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
};

#endif