#ifndef WITHDRAW_TRANSACTION_H
#define WITHDRAW_TRANSACTION_H
#include "../Transaction/Transaction.h"
#include <fstream>
class Withdraw: public Transaction
{
    private:
    public:
        Withdraw();
        Withdraw(const string&, Card, const long&, const float&, const string&, const Date&);
        Withdraw(const string&, Card, const long&);
        Withdraw(const Withdraw&);

        ~Withdraw();

        string getType();
        void show();
        int calFee();
        bool makeTransaction(const string&);

        const Withdraw& operator=(const Withdraw&);
        bool operator==(const Withdraw&);
        friend ifstream& operator>>(ifstream&, Withdraw&);
        friend ofstream& operator<<(ofstream&, const Withdraw&);
};
#endif