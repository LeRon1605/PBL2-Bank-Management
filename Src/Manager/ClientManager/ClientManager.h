#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H
#include "../Manager.h"
#include "../../CTDL/LinkedList.h"
#include "../../Client/Client.h"
class ClientManager: public Manager<Client> 
{
    private:
        LinkedList<Client> list;
    public:
        ClientManager();
        ~ClientManager();

        string generateID();
        void show();
        void showByID(const string&);
        Client findByID(const string&);
        int indexOf(const Client);
        int indexOf(const string&); 
        bool add(const Client);
        bool remove(const Client);
        bool removeByID(const string&);
        void listByDate(const Date&);
        bool updateByID(const Client, const string&);
};
#endif