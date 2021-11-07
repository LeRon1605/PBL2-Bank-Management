#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "../Card/Card.h"
class Transaction{
    protected:
        string ID; 
        Card *srcAccount; // Tài khoản thực hiện giao dịch 
        long cash; 
        int fee;
        bool status; // true: Thành công, false: Thất bại
        Date date;
    public:
        Transaction();
        Transaction(const string&, Card*, const long&, const float&, const bool&, const Date&);
        Transaction(const string&, Card*, const long&); // Create a new one transaction.
        Transaction(const Transaction&);

        ~Transaction();

        string getID();
        Card getSrcAccount();
        long getCash();
        int getFee();
        int getStatus();
        string getStrStatus();
        Date getDate();

        void setID(const string&);
        void setSrcAccount(Card*);
        void setCash(const long&);
        void setFee(const int&);
        void setStatus(const bool&);
        void setDate(const Date&);

        static bool isValidID(const string&);
        virtual void show();
        virtual int calFee();
        virtual void makeTransaction(const string&);


        virtual const Transaction& operator=(const Transaction&);
};
#endif