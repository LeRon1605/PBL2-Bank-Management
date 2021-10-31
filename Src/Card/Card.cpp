#include "Card.h"
//Constructor
Card::Card(){

}
Card::Card(const string &IdAccount, const string &IdHolder, const string &pin, const int &balance)
{
    this->IdAccount = IdAccount;
    this->IdHolder = IdHolder;
    this->pin = pin;
    this->balance = balance;
    this->createdAt = Date::getCurrentDate();
    this->updatedAt = Date();
}
//Getter
string Card::getIdAccount()
{
    return this->IdAccount;
}
string Card::getIdHolder()
{
    return this->IdHolder;
}
string Card::getpin()
{
    return this->pin;
}
int Card::getBalance()
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
void Card::setIdAccount(const string &IdAccount){
    this->IdAccount = IdAccount;
}
void Card::setIdHolder(const string &IdHolder){
    this->IdHolder = IdHolder;
}
void Card::setpin(const string &pin){
    this->pin = pin;
}
void Card::setBalance(const int &balance){
    this->balance = balance;
}
void Card::setCreatedAt(const Date &createdAt){
    this -> createdAt = createdAt;
}
void Card::setUpdatedAt(const Date &updatedAt){
    this -> updatedAt = updatedAt;
}
//input
istream& operator>>(istream &in, Card &card){
    cout << "Type Card's IdAccount: ";
    in >> card.IdAccount;
    while (!card.isValidIdAccount()){
        cout << "Invalid ID, type again: ";
        in >> card.IdAccount;
    }
    cout << "Type Card's IdHolder: ";
    in >> card.IdHolder;
    while (!card.isValidIdHolder()){
        cout << "Invalid ID, type again: ";
        in >> card.IdHolder;
    }
    cout << "Type Card's Pin(number): ";
    in >> card.pin;
    while (!card.isValidPin()){
        cout << "Invalid ID, type again: ";
        in >> card.pin;
    }
    cout << "Type Card's Balance: ";
    in >> card.balance;
    D.createdAt = Date::getCurrentDate();
    D.updatedAt = Date();
    return in;
}
//output
ostream& operator<<(ostream &out, const Card &C){
    out << "IdAccount: " << C.IdAccount << endl;
    out << "IdHolder: " << C.IdHolder << endl;
    out << "Pin: " << C.pin << endl;
    out << "Balance: " << Card(C).getBalance() << endl;
    out << "Created At: " << C.createdAt;
    if (Card(C).updatedAt.isValidDate())
        out << "Updated At: " << C.updatedAt;
    return out;
}
bool Card::isValidIdAccount(){
    if (this->IdAccount.size() < 16) return false; // IdAccount có độ dài là 16 số
    for (int i = 0; i < this->IdAccount.size();i++){
        if (this->IdAccount[i] < '0' || this->IdAccount[i] > '9') return false;
    }
    return true;
}
bool Card::isValidIdHolder(){
    if (this->IdHolder.size() < 10) return false; // IdHolder có độ dài là 10 số
    for (int i = 0; i < this->IdHolder.size();i++){
        if (this->IdHolder[i] < '0' || this->IdHolder[i] > '9') return false;
    }
    return true;
}
bool Card::isValidPin(){
    if (this->pin.size() < 6) return false; // IdHolder có độ dài là 6 số
    for (int i = 0; i < this->pin.size();i++){
        if (this->pin[i] < '0' || this->pin[i] > '9') return false;
    }
    return true;
}