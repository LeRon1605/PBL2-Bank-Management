#include "ClientManager.h"
ClientManager::ClientManager(){
    ifstream in;
    in.open("../Data/Client.txt", ios::in);
    int numberOfClient;
    in >> numberOfClient;
    for (int i = 0; i < numberOfClient;i++){
        Client temp;
        in >> temp;
        this -> list.add(temp);
    }
    in.close();
}

ClientManager::~ClientManager(){
    ofstream out;
    out.open("../Data/Client.txt", ios::out);
    out << this -> list.getLength() << endl;
    for (int i = 0; i < this -> list.getLength();i++){
        out << this -> list[i];
    }
    out.close();
}

void ClientManager::show(){

}

void ClientManager::showByID(const string &ID){

}

string ClientManager::generateID(){

}

Client ClientManager::findByID(const string &ID){

}

int ClientManager::indexOf(const Client){

}

int ClientManager::indexOf(const string &ID){

}

bool ClientManager::add(const Client C){

}

bool ClientManager::remove(const Client C){

}

bool ClientManager::removeByID(const string &ID){

}

void ClientManager::listByDate(const Date &D){

}

bool ClientManager::updateByID(Client C, const string &ID){

}
