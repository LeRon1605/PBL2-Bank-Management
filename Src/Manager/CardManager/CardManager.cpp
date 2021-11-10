#include "CardManager.h"
CardManager::CardManager(){
    ifstream in;
    in.open("../Data/Client.txt", ios::in);
    int numberOfClient;
    in >> numberOfClient;
    for (int i = 0; i < numberOfClient;i++){
        Card temp;
        in >> temp;
        this -> list.addTail(temp);
    }
    in.close();
}

CardManager::~CardManager(){
    ofstream out;
    out.open("../Data/Client.txt", ios::out);
    out << this -> list.getLength() << endl;
    for (int i = 0; i < this -> list.getLength();i++){
        out << this -> list[i];
    }
    out.close();
}

void CardManager::show(){

}

void CardManager::showByID(const string &ID){

}

string CardManager::generateID(){

}

Card CardManager::findByID(const string &ID){

}

int CardManager::indexOf(const Card){

}

int CardManager::indexOf(const string &ID){

}

bool CardManager::add(const Card C){

}

bool CardManager::remove(const Card C){

}

bool CardManager::removeByID(const string &ID){

}

void CardManager::listByDate(const Date &D){

}

bool CardManager::updateByID(Card C, const string &ID){

}
