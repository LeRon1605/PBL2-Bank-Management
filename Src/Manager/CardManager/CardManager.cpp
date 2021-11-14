#include "CardManager.h"
#include "../../Helper/Helper.h"
#include <iomanip>
int CardManager::totalCardCreated = 0;
CardManager::CardManager(){
    ifstream in;
    in.open("../Data/Card.txt", ios::in);
    int numberOfCard;
    in >> numberOfCard;
    in >> CardManager::totalCardCreated;
    for (int i = 0; i < numberOfCard;i++){
        Card temp;
        in >> temp;
        this -> list.addTail(temp);
    }
    in.close();
}

CardManager::~CardManager(){
    ofstream out;
    out.open("../Data/Card.txt", ios::out);
    out << this -> list.getLength() << endl;
    out << CardManager::totalCardCreated << endl;
    for (int i = 0; i < this -> list.getLength();i++){
        out << this -> list[i];
    }
    out.close();
}

void CardManager::show(){
    Node<Card> *ptr = this -> list.getHead();
    cout << left << setw(15) << "ID" << left << setw(15) << "ID Holder";
    cout << left << setw(10) << "Pin" << left << setw(15) << "Balance";
    cout << left << setw(30) << "Created At" << left << setw(30) << "Updated At" << left << setw(30) << "Pin Updated At" << endl;
    while (ptr != nullptr){
        ptr -> getData().show();
        cout << endl;
        ptr = ptr -> getNext();
    }
}

void CardManager::showByID(const string &ID){
    Node<Card> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr-> getData().getID() == ID) {
            ptr -> getData().show();
            return;
        }
        ptr = ptr -> getNext();
    }
}

string CardManager::generateID(){
    return to_string(100000000000 + CardManager::totalCardCreated);
}

Card CardManager::findByID(const string &ID){
    Node<Card> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr-> getData().getID() == ID) return ptr -> getData();
        ptr = ptr -> getNext();
    }
    return Card();
}

int CardManager::indexOf(const Card C){
    return this -> list.indexOf(C);
}

int CardManager::indexOf(const string &ID){
    return this -> list.indexOf(compareID, ID);
}

bool CardManager::add(Card C){
    if ((this -> countClientCard(C.getHolder().getID())) >= 3) return false;
    C.setID(this -> generateID()); 
    CardManager::totalCardCreated++;
    return this -> list.addTail(C);
}

bool CardManager::remove(const Card C){
    return this -> list.remove(C);
}

bool CardManager::removeByID(const string &ID){
    return this -> list.remove(compareID, ID);
}

void CardManager::listByDate(const Date &D){
    Node<Card> *ptr = this -> list.getHead();
    cout << left << setw(15) << "ID" << left << setw(15) << "ID Holder";
    cout << left << setw(10) << "Pin" << left << setw(15) << "Balance";
    cout << left << setw(30) << "Created At" << left << setw(30) << "Updated At" << left << setw(30) << "Pin Updated At" << endl;
    while (ptr != nullptr){
        if (Date::compareDate(ptr -> getData().getCreatedAt(), D)) ptr -> getData().show();
        ptr = ptr -> getNext();
    }
}

bool CardManager::updateByID(Card C, const string &ID){
    int index = this -> indexOf(ID);
    if (index == -1) return false;
    this -> list[index].update(C);
    return true;
}

void CardManager::removeAll(const string &ClientID){
    Node<Card> *ptr = this -> list.getHead();
    int index = 0;
    while (ptr != nullptr && this -> list.getLength() > 0){
        if (ptr -> getData().getHolder().getID() == ClientID) {
            ptr = ptr -> getNext();
            this -> list.removeAt(index);
            index--;
        }else{
            ptr = ptr -> getNext();
        }
        index++;
    }
}

void CardManager::showInf(const string &ID){
    Node<Card> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData().getID() == ID){
            ptr -> getData().getHolder().show();
        }
        ptr = ptr -> getNext();
    }
}

bool CardManager::changePin(const string &ID, const string &currentPin, const string &newPin){
    Node<Card> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData().getID() == ID){
            try{
                ptr -> getRefData().updatePin(currentPin, newPin);
            }catch(string err){
                cout << err << endl;
                return false;
            }catch(...){
                return false;
            }
            return true;
        }
        ptr = ptr -> getNext();
    }
    return true;
}

int CardManager::countClientCard(const string &ClientID){
    Node<Card> *ptr = this -> list.getHead();
    int count = 0;
    while (ptr != nullptr){
        if (ptr -> getData().getHolder().getID() == ClientID) count++;
        ptr = ptr -> getNext();
    }
    return count;
}

void CardManager::listAllClientCard(const string &ClientID){
    Node<Card> *ptr = this -> list.getHead();
    while (ptr != nullptr){
        if (ptr -> getData().getHolder().getID() == ClientID) ptr -> getData().getHolder().show();
        ptr = ptr -> getNext();
    }
}