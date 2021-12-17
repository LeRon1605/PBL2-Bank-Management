#ifndef CARD_MANAGER_H
#define CARD_MANAGER_H
#include "../Manager.h"
#include "../../CTDL/LinkedList.h"
#include "../../Card/Card.h"
class CardManager: public Manager<Card> 
{
    private:
        LinkedList<Card> list;
        static int totalCardCreated;
    public:
        CardManager();
        ~CardManager();

        string generateID();
        void show();
        void showByID(const string&);
        Card findByID(const string&);
        int indexOf(const Card);
        int indexOf(const string&); 
        bool add(Card);
        bool remove(const Card);
        bool removeByID(const string&);
        void listByDate(const Date&);
        bool updateByID(const Card, const string&);
        void exportToCSV(const string&);

        int countClientCard(const string&); // Đếm số lượng thẻ của client
        bool removeAll(const string&); //  Xóa tất cả thẻ của khách hàng
        void showInf(const string&); // Hiển thị thông tin chủ thẻ
        bool changePin(const string&, const string&, const string&);
        void listAllClientCard(const string&); // Hiển thị các thẻ của Client
};
#endif