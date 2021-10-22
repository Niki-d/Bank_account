#include<iostream>
#include<conio.h>
#include<cmath>
#include"account.h"


int account::id = 1;

account::account()
{
    ID = id;
    id++;
    first_name = NULL;
    second_name = NULL;
    balance = 0;
}

account::account(char* name_1, char* name_2, int money)
{
    ID = id;
    id++;
    first_name = name_1;
    second_name = name_2;
    balance = money;
}

double account::get_balance()
{
    return balance;
}

void account::set_balance(double result)
{
    balance = result;
}

char* account::get_first_name()
{
    return first_name;
}

char* account::get_second_name()
{
    return second_name;
}

void account::add_balance(int sum)
{
    balance += sum;
}

void account::negative_add_balance(int sum)
{
    if(sum <= balance){
        balance -= sum;
    }
    else{
        std::cout << "It is type of account don't can !!!" << std::endl;
    }
}

int account::get_ID()
{
    return ID;
}

int account::get()                //static
{
    return id;
}

/*std::ostream& account::operator<<(std::ostream& os)
{
    os << "ID : " << ID << std::endl;
    os << "First name : " << first_name << std::endl;
    os << "Second name : " << second_name << std::endl;
    os << "Balance : " << balance << std::endl;

    return os;
}*/

std::ostream& operator<<(std::ostream& os, account& acc)
{
    os << "ID : " << acc.ID << std::endl;
    os << "First name : " << acc.first_name << std::endl;
    os << "Second name : " << acc.second_name << std::endl;
    os << "Balance : " << acc.balance << std::endl;

    return os;
}










Extra_account::Extra_account() : account()
{
    percent = 0;
}

Extra_account::Extra_account(char* name_1, char* name_2, int money, int per) : account(name_1, name_2, money)
{
    percent = per;
}

/*std::ostream& Extra_account::operator<<(std::ostream& os)
{
    os << "ID : " << get_ID() << std::endl;
    os << "Balance : " << get_balance() << std::endl;

    return os;
}*/

std::iostream& operator<<(std::iostream& os, Extra_account& Ex)
{
    os << "ID : " << Ex.get_ID() << std::endl;
    os << "First name : " << Ex.get_first_name() << std::endl;
    os << "Second name : " << Ex.get_second_name() << std::endl;
    os << "Balance : " << Ex.get_balance() << std::endl;

    return os;
}

void Extra_account::negative_add_balance(int sum)
{
    double result;

    if( (get_balance() - (sum + sum *(percent/100) ) ) < MAX){
        std::cout << "Limit exceeded !!!" << std::endl;
        return;
    }

    if(get_balance() >= sum){
        result = get_balance() - sum;
        set_balance(result);
        return;
    }

    if(get_balance() > 0){
        result = (get_balance() - sum)*(percent/100) + (get_balance() - sum);
        set_balance(result);
    }
    else{
        if(get_balance() <= 0){
            result = -sum * (percent/100) + (get_balance() - sum);
            set_balance(result);
        }
    }
    
}