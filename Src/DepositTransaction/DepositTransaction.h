#ifndef DEPOSIT_TRANSACTION_H
#define DEPOSIT_TRANSACTION_H
#include "../Transaction/Transaction.h"
class Deposit: public Transaction
{
    private:
    public:
        Deposit();
        Deposit(const string&, Card, const long&, const float&, const bool&, const Date&);
        Deposit(const string&, Card, const long&);
        Deposit(const Deposit&);

        ~Deposit();

        void show();
        int calFee();
        void makeTransaction(const string&);
        
        const Deposit& operator=(const Deposit&);
        bool operator==(const Deposit&);
};
#endif