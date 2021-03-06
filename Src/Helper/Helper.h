#ifndef HELPER_H
#define HELPER_H
#include "../Card/Card.h"

bool compareHolderID(Card C, const string &holderID);
void SetColor(int backgound_color, int text_color);
void background();
void mainMenu();
void clientManagerMenu();
void cardManagerMenu();
void transactionManagerMenu();
void print(const string&, const int&);
void transactionPanel();
void clientPanel();
void cardPanel();
void statusTable();
string moneyFormat(long);

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