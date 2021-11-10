#ifndef HELPER_H
#define HELPER_H
#include "../Card/Card.h"
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

bool compareHolderID(Card C, const string &holderID){
    return (C.getHolder().getID() == holderID);
}
#endif