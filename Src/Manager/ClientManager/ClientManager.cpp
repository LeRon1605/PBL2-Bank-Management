#include "ClientManager.h"
#include "../../Repo/Repo.h"
#include "../../Helper/Helper.h"
#include "../../Card/Card.h"
#include <iomanip>
int ClientManager::totalClientCreated = 0;
ClientManager::ClientManager(){
    ifstream in;
    in.open("../Data/Client.txt", ios::in);
    int numberOfClient;
    in >> numberOfClient;
    in >> ClientManager::totalClientCreated;
    for (int i = 0; i < numberOfClient;i++){
        Client temp;
        in >> temp;
        this -> list.addTail(temp);
    }
    in.close();
}

ClientManager::~ClientManager(){
    ofstream out;
    out.open("../Data/Client.txt", ios::out);
    out << this -> list.getLength() << endl;
    out << ClientManager::totalClientCreated << endl;
    for (int i = 0; i < this -> list.getLength();i++){
        out << this -> list[i];
    }
    out.close();
}

void ClientManager::show(){
    Node<Client> *ptr = this->list.getHead();
    cout << left << setw(15) << "ID" << left << setw(20) << "Name" << left << setw(10) << "Gender";
    cout << left << setw(15) << "CCCD" << left << setw(10) << "Age" << left << setw(15) << "Birth";
    cout << left << setw(30) << "Created At" << left << setw(30) << "Updated At" << endl;
    while (ptr != nullptr){
        ptr->getData().show();
        cout << endl;
        ptr = ptr->getNext();
    }
}

void ClientManager::showByID(const string &ID){
    Node<Client> *ptr = this->list.getHead();
    while (ptr != nullptr){
        if (ptr->getData().getID() == ID) {
            ptr->getData().show();
            return;
        }
        ptr = ptr->getNext();
    }
}

string ClientManager::generateID(){
    return to_string(10000000 + ClientManager::totalClientCreated);
}

Client ClientManager::findByID(const string &ID){
    Node<Client> *ptr = this->list.getHead();
    while (ptr != nullptr)
    {
        if(ptr -> getData().getID() == ID){
            return ptr->getData();
        }
        ptr = ptr->getNext();
    }
    return Client();
}

int ClientManager::indexOf(const Client C){
    return this->indexOf(C);
}

int ClientManager::indexOf(const string &ID){
    Node<Client> *ptr = this->list.getHead();
    long index = 0;
    while (ptr != nullptr)
    {
        if(ptr->getData().getID() == ID){ 
            return index;
        }
        index++;
        ptr = ptr->getNext();
    }
    return -1;
}

bool ClientManager::add(const Client C){
    ClientManager::totalClientCreated++;
    return this -> list.addTail(C);
}

bool ClientManager::remove(const Client C){
    if (this -> list.contains(C)) {
        Repository<Card>::findAndRemove(compareHolderID, Client(C).getID(), "Card.txt");
    }
    return this -> list.remove(C);
}

bool ClientManager::removeByID(const string &ID){
    int index = this -> indexOf(ID);
    if (index == -1) return false;
    else {
        Repository<Card>::findAndRemove(compareHolderID, ID, "Card.txt");
        return this -> list.removeAt(index);
    }
}

void ClientManager::listByDate(const Date &D){
    Node<Client> *ptr = this -> list.getHead();
    cout << left << setw(15) << "ID" << left << setw(20) << "Name" << left << setw(10) << "Gender";
    cout << left << setw(15) << "CCCD" << left << setw(10) << "Age" << left << setw(15) << "Birth";
    cout << left << setw(30) << "Created At" << left << setw(30) << "Updated At" << endl;
    while (ptr != nullptr){
        if (Date::compareDate(ptr -> getData().getCreatedAt(), D)) {
            ptr -> getData().show();
            cout << endl;
        }
        ptr = ptr -> getNext();
    }
}

bool ClientManager::updateByID(Client C, const string &ID){
    int index = this -> indexOf(ID);
    if (index == -1) return false;
    this -> list[index].update(C);
    return true;

}
