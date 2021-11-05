#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "../Card/Card.h"
class Transaction{
    private:
        string ID; 
        Card srcAccount; // Tài khoản thực hiện giao dịch 
        long cash; 
        int fee;
        bool status; // true: Thành công, false: Thất bại
        Date date;
    public:
        Transaction();
        Transaction(const string&, const Card&, const long&, const float&, const bool&, const Date&);
        Transaction(const string&, const Card&, const long&); // Create a new one transaction.
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
        void setSrcAccount(const Card&);
        void setCash(const long&);
        void setFee(const int&);
        void setStatus(const bool&);
        void setDate(const Date&);

        static bool isValidID(const string&);
        virtual void show();
        virtual int calFee();
        
        const Transaction& operator=(const Transaction&);
        friend ostream& operator<<(ostream&, const Transaction&);
        friend istream& operator>>(ostream&, const Transaction&);
};
#endif