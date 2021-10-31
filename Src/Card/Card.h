#ifndef CARD_H
#define CARD_H
#include "../Datetime/Datetime.h"
class Card{
    private:
        string IdAccount;
        string IdHolder;
        string pin;
        int balance;
        Date createdAt;
        Date updatedAt;
    public:
        Card();
        Card(const string&, const string&, const string&, const int&);
        
        // Getter
        string getIdAccount();
        string getIdHolder();
        string getpin();
        int getBalance();
        Date getCreatedAt();
        Date getUpdatedAt();
        
        // Setter
        void setIdAccount(const string&);
        void setIdHolder(const string&);
        void setpin(const string&);
        void setBalance(const int&);
        void setCreatedAt(const Date&);
        void setUpdatedAt(const Date&);
        
        bool isValidIdAccount();
        bool isValidIdHolder();
        bool isValidPin();
        void show();
        void update( const string&,const int& ); // update pin , balance

        const Date& operator=(const Date&);
        friend ostream& operator<<(ostream&, const Card&);
        friend istream& operator>>(istream&, Card&);

};
#endif