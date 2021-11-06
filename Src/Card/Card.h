#ifndef CARD_H
#define CARD_H
#include "../Client/Client.h"
class Card{
    private:
        string ID;
        Client holder;
        string pin;
        long balance;
        Date createdAt;
        Date updatedAt;
        Date pinUpdatedAt;
    public:
        //  Constructor
        Card();
        Card(const Card&);
        Card(const string&, const Client&, const string&, const long&);
        Card(const string&, const Client&, const string&, const long&, const Date&, const Date& = "", const Date& = "");
        ~Card();

        // Getter
        string getID();
        Client getHolder();
        string getPin();
        long getBalance();
        Date getCreatedAt();
        Date getUpdatedAt();
        Date getPinUpdatedAt();

        // Setter
        void setID(const string&);
        void setHolder(const Client&);
        void setPin(const string&);
        void setBalance(const long&);
        void setCreatedAt(const Date&);
        void setUpdatedAt(const Date&);
        
        static bool isValidID(const string&);
        static bool isValidPin(const string&);
        void show();
        void showBalance();
        int withdraw(const long&);
        void deposit(const long&);
        void updatePin(const string&, const string&);

        const Card& operator=(const Card&);
        friend ostream& operator<<(ostream&, const Card&);
        friend istream& operator>>(istream&, Card&);

};
#endif