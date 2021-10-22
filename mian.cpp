#include<iostream>
#include<cmath>
#include"account.h"

int main()
{ 
    account* num_1 = new account("User", "User", 10000);
    num_1 -> add_balance(2000);
    std::cout << *num_1 << std::endl << std::endl;
    
    account* num_2 = new Extra_account("Ivan", "Ivanov", 8000, 10);
    num_2 -> add_balance(3000);
    std::cout << *num_2 << std::endl << std::endl;

    num_1 -> negative_add_balance(13000);
    std::cout << *num_1 << std::endl << std::endl;

    num_2 -> negative_add_balance(14000);
    std::cout << *num_2 << std::endl << std::endl;

    num_2 -> negative_add_balance(1000);
    std::cout << *num_2 << std::endl << std::endl;
  
    num_2 -> negative_add_balance(1000);
    std::cout << *num_2 << std::endl << std::endl;

    std::cout << "Number of objects with basic class 'account' = " << account::get() - 1 << std::endl;
    
}