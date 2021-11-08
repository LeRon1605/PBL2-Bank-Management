#ifndef WITHDRAW_TRANSACTION_H
#define WITHDRAW_TRANSACTION_H
#include "../Transaction/Transaction.h"
class Withdraw: public Transaction
{
    private:
    public:
        Withdraw();
        Withdraw(const string&, Card*, const long&, const float&, const bool&, const Date&);
        Withdraw(const string&, Card*, const long&);
        Withdraw(const Withdraw&);

        ~Withdraw();

        void show();
        int calFee();
        void makeTransaction(const string&);

        const Withdraw& operator=(const Withdraw&);
        bool operator==(const Withdraw&);
};
#endif