#ifndef CARD_MANAGER_H
#define CARD_MANAGER_H
#include "../Manager.h"
#include "../../CTDL/LinkedList.h"
#include "../../Card/Card.h"
class CardManager: public Manager<Card> 
{
    private:
        LinkedList<Card> list;
    public:
        CardManager();
        ~CardManager();

        string generateID();
        void show();
        void showByID(const string&);
        Card findByID(const string&);
        int indexOf(const Card);
        int indexOf(const string&); 
        bool add(const Card);
        bool remove(const Card);
        bool removeByID(const string&);
        void listByDate(const Date&);
        bool updateByID(const Card, const string&);
};
#endif