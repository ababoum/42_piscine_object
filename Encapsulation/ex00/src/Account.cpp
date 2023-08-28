#include "Account.hpp"

int Account::id_index = 0;

Account::Account()
{
    id = Account::id_index++;
    value = 0;
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
{
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return (p_os);
}