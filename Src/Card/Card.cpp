#include "Card.h"
#include <string>
//Constructor
Card::Card()
{

}

Card::Card(const Card &card)
{
    this -> ID = card.ID;
    this -> holder = card.holder;
    this -> pin = card.pin;
    this -> balance = card.balance;
    this -> createdAt = Date::getCurrentDate();
    this -> updatedAt = Date();
}

Card::Card(const string &ID, const Client &holder, const string &pin, const long &balance)
{
    this -> ID = (Card::isValidID(ID)) ? ID : "";
    this -> holder = holder;
    this -> pin = (Card::isValidPin(pin)) ? pin : "";
    this -> balance = (balance > 0) ? balance : 0;
    this -> createdAt = Date::getCurrentDate();
    this -> updatedAt = Date();
    this -> pinUpdatedAt = Date();
}

Card::Card(const string &ID, const Client &holder, const string &pin, const long &balance, const Date &createdAt, const Date &updatedAt, const Date &pinUpdatedAt)
{
    this -> ID = (Card::isValidID(ID)) ? ID : "";
    this -> holder = holder;
    this -> pin = (Card::isValidPin(pin)) ? pin : "";
    this -> balance = (balance > 0) ? balance : 0;
    this -> createdAt = (Date(createdAt).isValidDate()) ? createdAt : Date();
    this -> updatedAt = (Date(updatedAt).isValidDate()) ? updatedAt : Date();
    this -> pinUpdatedAt = (Date(pinUpdatedAt).isValidDate()) ? pinUpdatedAt : Date();
}

// Destructor
Card::~Card(){

}

//Getter
string Card::getID()
{
    return this -> ID;
}

Client Card::getHolder()
{
    return this -> holder;
}

string Card::getPin()
{
    return this -> pin;
}

long Card::getBalance()
{
    return this -> balance;
}

Date Card::getCreatedAt()
{
    return this -> createdAt;
}

Date Card::getUpdatedAt()
{
    return this -> updatedAt;
}

Date Card::getPinUpdatedAt(){
    return this -> pinUpdatedAt;
}
//Setter
void Card::setID(const string &ID){
    this -> ID = (Card::isValidID(ID)) ? ID : ""; 
}

void Card::setHolder(const Client &holder){
    this -> holder = holder;
}

void Card::setPin(const string &pin){
    this -> pin = pin;
}

void Card::setBalance(const long &balance){
    this -> balance = (balance > 0) ? balance : this -> balance;
}

void Card::setCreatedAt(const Date &createdAt){
    this -> createdAt = createdAt;
}
void Card::setUpdatedAt(const Date &updatedAt){
    this -> updatedAt = updatedAt;
}

const Card& Card::operator=(const Card &card){
    this -> ID = card.ID;
    this -> holder = card.holder;
    this -> pin = card.pin;
    this -> balance = card.balance;
    this -> createdAt = card.createdAt;
    this -> updatedAt = card.updatedAt;
    this -> pinUpdatedAt = card.pinUpdatedAt;
    return (*this);
}
//input
// istream& operator>>(istream &in, Card &card){
//     cout << "Type Card's Pin: ";
//     in >> card.pin;
//     while (!card.isValidPin(card.pin)){
//         cout << "Invalid pin, type again: ";
//         in >> card.pin;
//     }
//     cout << "Type Card's Balance: ";
//     in >> card.balance;

//     card.holder = Client();
//     card.createdAt = Date::getCurrentDate();
//     card.updatedAt = Date();
//     card.pinUpdatedAt = Date();
//     return in;
// }
//output
// ostream& operator<<(ostream &out, const Card &card){
//     out << "ID: " << card.ID << endl;
//     out << "IDholder: " << Client(card.holder).getID() << endl;
//     out << "Pin: " << card.pin << endl;
//     out << "Balance: " << Card(card).getBalance() << " VND" << endl;
//     out << "Created At: " << card.createdAt;
//     if (Date(card.updatedAt).isValidDate())
//         out << "Updated At: " << card.updatedAt;
//     if (Date(card.pinUpdatedAt).isValidDate())
//         out << "Pin Updated At: " << card.pinUpdatedAt << endl;
//     return out;
// }
//check
bool Card::isValidID(const string &str){
    if (str.size() != 12) return false; // ID có độ dài là 12 số
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

bool Card::isValidPin(const string &str){
    if (str.size() != 6) return false; // ID có độ dài là 6 số
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

void Card::show(){
    cout << "ID: " << this -> ID << endl;
    cout << "IDholder: " << this -> holder.getID() << endl;
    cout << "Pin: " << this -> pin << endl;
    cout << "Balance: " << this -> balance << " VND" <<  endl;
    cout << "Created At: " << this -> createdAt << endl;
    if (this -> updatedAt.isValidDate())
        cout << "Updated At: " << this -> updatedAt;
    if (this -> pinUpdatedAt.isValidDate())
        cout << "Pin Updated At: " << this -> pinUpdatedAt << endl;
}

void Card::showBalance(){
    cout << "Balance: " << this -> balance << endl;
}

int Card::withdraw(const long &money){
    if (money > this -> balance || money < 0) return -1;
    this -> balance -= money;
    this -> updatedAt = Date::getCurrentDate();
    return money;
}

void Card::deposit(const long &money){
    if (money > 0) 
        this -> balance += money;
        this -> updatedAt = Date::getCurrentDate();
}

void Card::updatePin(const string &currentPin, const string &newPin){
    if (this -> pin == currentPin)
        if (Card::isValidPin(pin)){
            if (Date::DATEDIFF(this -> pinUpdatedAt, Date::getCurrentDate()) >= 2 && Date::getCurrentDate() > this -> pinUpdatedAt){
                this -> pin = pin;
                this -> pinUpdatedAt = Date::getCurrentDate();
                this -> updatedAt = Date::getCurrentDate();
            }else cout << "You have to wait " << 2 - Date::DATEDIFF(this -> pinUpdatedAt, Date::getCurrentDate()) << " day left to change your PIN account" << endl;
        }else cout << "Invalid PIN" << endl;
    else cout << "Inccorect PIN" << endl;
}

bool Card::operator==(const Card &newCard){
    if(this->ID == newCard.ID && this->holder == newCard.holder && this->balance == newCard.balance && this->pin == newCard.pin && this->createdAt == newCard.createdAt && this->updatedAt == newCard.updatedAt){
        return true;
    }
    return false;
}

void Card::input(){

    cout << "Type Card's Pin: ";
    cin >> this -> pin;
    while (!Card::isValidPin(this -> pin)){
        cout << "Invalid pin, type again: ";
        cin >> this -> pin;
    }
    cout << "Type Card's Balance: ";
    cin >> this -> balance;
    this -> holder = Client();
    this -> createdAt = Date::getCurrentDate();
    this -> updatedAt = Date();
    this -> pinUpdatedAt = Date();
}

ofstream& operator<<(ofstream &out, const Card &card){
    out << card.ID << endl;
    out << card.holder << endl;
    out << card.pin << endl;
    out << card.balance << endl;
    out << Date(card.createdAt).toString() << endl;
    out << Date(card.updatedAt).toString() << endl;
    out << Date(card.pinUpdatedAt).toString() << endl;
    return out;
}
ifstream& operator>>(ifstream &in, Card &card){
    string date;
    in >> card.ID;
    // Client : holder
    in >> card.pin;
    card.balance = card.getBalance();
    getline(in, date);
    card.createdAt = Date(date.c_str());
    in.ignore();
    getline(in, date);
    card.updatedAt = Date(date.c_str());
    getline(in, date);
    card.pinUpdatedAt = Date(date.c_str());
    return in;
}   