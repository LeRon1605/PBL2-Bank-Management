#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "../Card/Card.h"
class Transaction{
    protected:
        string ID; 
        Card srcAccount; // Tài khoản thực hiện giao dịch 
        long cash; 
        int fee;
        Date date;
        string statusCode;
    public:
        Transaction();
        Transaction(const string&, Card, const long&, const float&, const string&, const Date&);
        Transaction(const string&, Card, const long&); // Create a new one transaction.
        Transaction(const Transaction&);

        ~Transaction();

        string getID();
        Card getSrcAccount();
        long getCash();
        int getFee();
        string getStatus();
        string getStrStatus();
        Date getDate();

        void setID(const string&);
        void setSrcAccount(Card);
        void setCash(const long&);
        void setFee(const int&);
        void setStatus(const string&);
        void setDate(const Date&);

        static bool isValidID(const string&);

        virtual string getType() = 0;
        virtual void show() = 0;
        virtual int calFee() = 0;
        virtual bool makeTransaction(const string&) = 0;
        virtual void exportToCSV(ofstream&);
};
#endif