#include "../Card/Card.h"

bool compareHolderID(Card C, const string &holderID){
    return (C.getHolder().getID() == holderID);
}
