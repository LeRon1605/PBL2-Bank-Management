#ifndef HELPER_H
#define HELPER_H
#include "../Card/Card.h"

bool compareHolderID(Card C, const string &holderID);
void background();
void mainMenu();
void clientManagerMenu();
void cardManagerMenu();
void transactionManagerMenu();
void print(const string&, const int&);

template <class T>
bool sortAscByCreatedAt(T A, T B){
    if (A.getCreatedAt() > B.getCreatedAt()) return true;
    return false;
}

template <class T>
bool sortDescByCreatedAt(T A, T B){
    if (A.getCreatedAt() < B.getCreatedAt()) return true;
    return false;
}

template <class T>
bool compareID(T A, const string &ID){
    return (A.getID() == ID);
}

#endif