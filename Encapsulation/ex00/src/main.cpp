#include "Account.hpp"
#include "Bank.hpp"

int main()
{
	Bank bank = Bank();

	Account *accountA = bank.openAccount(100);
	Account *accountB = bank.openAccount(100);
	
	bank.updateLiquidity(999);
	bank.updateLiquidity(-200);


	std::cout << "Account : " << std::endl;
	std::cout << *accountA << std::endl;
	std::cout << *accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
