#pragma once

class account
{
private:
    static int id;                                                    // для всех объектов этого класса, поле id будет общим. Нужно заранее инициализировать такую переменную
    int ID;                                     
    char* first_name;
    char* second_name;
    int balance;
public:
    account();
    account(char* name_1, char* name_2, int money);
    double get_balance();
    void set_balance(double result);
    char* get_first_name();
    char* get_second_name();
    void add_balance(int sum);
    virtual void negative_add_balance(int sum);
    int get_ID();
    static int get();                                                // данный статический метод может получить доступ к статическому полю. Но почему нельзя через обычный метод? МОЖНО, но тогда необходимо создать объект класса и через его метод получать доступ. Крч, через static метод удобнее
    //std::ostream& operator<<(std::ostream& os);
    friend std::ostream& operator<<(std::ostream& os, account& acc);
};

class Extra_account : public account
{
private:
    const int MAX = -5000;                                           // лимит по кредиту
    double percent;
public:
    Extra_account();
    Extra_account(char* name_1, char* name_2, int money, int per);
    //std::ostream& operator<<(std::ostream& os);
    friend std::iostream& operator<<(std::iostream& os, Extra_account& Ex);
    virtual void negative_add_balance(int sum);                                        // здесь можно без virtual

};