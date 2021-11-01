#ifndef CARD_H
#define CARD_H
#include "../Datetime/Datetime.h"
class Card{
    private:
        string ID;
        string IdHolder;
        string pin;
        long balance;
        Date createdAt;
        Date updatedAt;
    public:
        Card();
        Card(const string&, const string&, const string&, const long&);
        
        // Getter
        string getID();
        string getIdHolder();
        string getPin();
        long getBalance();
        Date getCreatedAt();
        Date getUpdatedAt();
        
        // Setter
        void setID(const string&);
        void setIdHolder(const string&);
        void setPin(const string&);
        void setBalance(const long&);
        void setCreatedAt(const Date&);
        void setUpdatedAt(const Date&);
        
        bool isValidID(const string&);
        bool isValidIdHolder(const string&);
        bool isValidPin(const string&);
        void show();
        void showBalance();
        void update( const string&,const long& ); // update pin , balance

        const Card& operator=(const Card&);
        friend ostream& operator<<(ostream&, const Card&);
        friend istream& operator>>(istream&, Card&);
};
#endif