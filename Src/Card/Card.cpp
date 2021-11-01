#include "Card.h"
//Constructor
Card::Card(){

}
Card::Card(const Card &card){
    this->ID = card.ID;
    this->IdHolder = card.IdHolder;
    this->pin = card.pin;
    this->balance = card.balance;
    this->createdAt = Date::getCurrentDate();
    this->updatedAt = Date();
}
Card::Card(const string &ID, const string &IdHolder, const string &pin, const long &balance)
{
    this->ID = (Card::isValidID(ID)) ? ID : "";
    this->IdHolder = (Card::isValidIdHolder(IdHolder)) ? IdHolder : "";
    this->pin =(Card::isValidPin(pin)) ? pin : "";
    this->balance = balance;
    this->createdAt = Date::getCurrentDate();
    this->updatedAt = Date();
}
//Getter
string Card::getID()
{
    return this->ID;
}
string Card::getIdHolder()
{
    return this->IdHolder;
}
string Card::getPin()
{
    return this->pin;
}
long Card::getBalance()
{
    return this->balance;
}
Date Card::getCreatedAt()
{
    return this->createdAt;
}
Date Card::getUpdatedAt()
{
    return this->updatedAt;
}
//Setter
void Card::setID(const string &ID){
    this->ID = ID;
}
void Card::setIdHolder(const string &IdHolder){
    this->IdHolder = IdHolder;
}
void Card::setPin(const string &pin){
    this->pin = pin;
}
void Card::setBalance(const long &balance){
    this->balance = balance;
}
void Card::setCreatedAt(const Date &createdAt){
    this -> createdAt = createdAt;
}
void Card::setUpdatedAt(const Date &updatedAt){
    this -> updatedAt = updatedAt;
}

const Card& Card::operator=(const Card &card){
    this->ID = card.ID;
    this->IdHolder = card.IdHolder;
    this->pin = card.pin;
    this->balance = card.balance;
    this->createdAt = card.createdAt;
    this->updatedAt = card.updatedAt;
    return (*this);
}
//input
istream& operator>>(istream &in, Card &card){
    cout << "Type Card's ID: ";
    in >> card.ID;
    while (!card.isValidID(card.ID)){
        cout << "Invalid ID, type again: ";
        in >> card.ID;
    }
    cout << "Type Card's IdHolder: ";
    in >> card.IdHolder;
    while (!card.isValidIdHolder(card.IdHolder)){
        cout << "Invalid IdHolder, type again: ";
        in >> card.IdHolder;
    }
    cout << "Type Card's Pin: ";
    in >> card.pin;
    while (!card.isValidPin(card.pin)){
        cout << "Invalid pin, type again: ";
        in >> card.pin;
    }
    cout << "Type Card's Balance: ";
    in >> card.balance;
    card.createdAt = Date::getCurrentDate();
    card.updatedAt = Date();
    return in;
}
//output
ostream& operator<<(ostream &out, const Card &card){
    out << "ID: " << card.ID << endl;
    out << "IdHolder: " << card.IdHolder << endl;
    out << "Pin: " << card.pin << endl;
    out << "Balance: " << Card(card).getBalance() << endl;
    out << "Created At: " << card.createdAt;
    if (Card(card).updatedAt.isValidDate())
        out << "Updated At: " << card.updatedAt;
    return out;
}
bool Card::isValidID(const string &str){
    if (str.size() != 12) return false; // ID có độ dài là 8 số
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}
bool Card::isValidIdHolder(const string &str){
    if (str.size() != 8) return false; // ID có độ dài là 8 số
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}
bool Card::isValidPin(const string &str){
    if (str.size() != 6) return false; // ID có độ dài là 8 số
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

void Card::show(){
    cout << "ID: " << this->ID << endl;
    cout << "IdHolder: " << this->IdHolder << endl;
    cout << "Pin: " << this->pin << endl;
    cout << "Created At: " << this->createdAt << endl;
    cout << "Update At: " << this->updatedAt << endl;
    if (this -> updatedAt.isValidDate())
        cout << "Updated At: " << this -> updatedAt;
}
void Card::showBalance(){
    cout << "Balance: " << this->balance << endl;
}
