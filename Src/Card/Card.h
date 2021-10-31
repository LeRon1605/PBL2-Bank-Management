#ifndef CARD_H
#define CARD_H
#include "../Datetime/Datetime.h"
class Card{
    private:
        string idAccount;
        string idHolder;
        Date createdAt;
        Date updatedAt;
        string pin;
        int balance;
    public:
};
#endif