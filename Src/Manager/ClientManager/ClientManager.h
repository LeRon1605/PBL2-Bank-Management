#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H
#include "../CTDL/LinkedList.h"
#include "../Manager.h"
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
        void add(const Client);
        void remove(const Client);
        void removeByID(const string&);
        void listByDate(const Date&);
        void update(const Client&);
};
#endif