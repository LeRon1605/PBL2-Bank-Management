#ifndef TRANSFER_TRANSACTION_H
#define TRANSFER_TRANSACTION_H
#include "../Transaction/Transaction.h"
#include <fstream>
class Transfer: public Transaction
{
    private:
        Card destAccount; // Tài khoản đích
    public:
        Transfer();
        Transfer(const string&, Card, Card, const long&, const float&, const bool&, const string&, const Date&);
        Transfer(const string&, Card, Card, const long&);
        Transfer(const Transfer&);

        ~Transfer();

        void setDestAccount(Card);
        Card getDestAccount();

        string getType();
        void show();
        int calFee();
        bool makeTransaction(const string&);
        bool operator==(const Transfer&);

        friend ifstream& operator>>(ifstream&, Transfer&);
        friend ofstream& operator<<(ofstream&, const Transfer&);
};
#endif