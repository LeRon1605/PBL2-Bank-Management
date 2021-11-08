#ifndef TRANSFER_TRANSACTION_H
#define TRANSFER_TRANSACTION_H
#include "../Transaction/Transaction.h"
class Transfer: public Transaction
{
    private:
        Card desAccount; // Tài khoản đích
    public:
        Transfer();
        Transfer(const string&, Card, Card, const long&, const float&, const bool&, const Date&);
        Transfer(const string&, Card, Card, const long&);
        Transfer(const Transfer&);

        ~Transfer();

        void setDesAccount(Card);
        Card getDesAccount();

        void show();
        int calFee();
        void makeTransaction(const string&);
};
#endif