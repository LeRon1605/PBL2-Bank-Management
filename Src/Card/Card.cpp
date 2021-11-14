#include "Card.h"
#include "../Repo/Repo.h"
#include <string>
#include <iomanip>
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
    this -> createdAt = card.createdAt;
    this -> updatedAt = card.updatedAt;
    this -> pinUpdatedAt = card.pinUpdatedAt;
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
    // cout << "ID: " << this -> ID << endl;
    // cout << "IDholder: " << this -> holder.getID() << endl;
    // cout << "Pin: " << this -> pin << endl;
    // cout << "Balance: " << this -> balance << " VND" <<  endl;
    // cout << "Created At: " << this -> createdAt;
    // if (this -> updatedAt.isValidDate())
    //     cout << "Updated At: " << this -> updatedAt;
    // if (this -> pinUpdatedAt.isValidDate())
    //     cout << "Pin Updated At: " << this -> pinUpdatedAt;
    cout << left << setw(15) << this -> ID;
    cout << left << setw(15) << this -> holder.getID();
    cout << left << setw(10) << this -> pin;
    cout << left << setw(15) << to_string(this -> balance) + " VND" ;
    cout << left << setw(30) << this -> createdAt << setw(11) << ' ';
    cout << left << setw(30) << this -> updatedAt << setw(11) << ' ';;
    cout << left << setw(30) << this -> pinUpdatedAt;
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
                this -> pin = newPin;
                this -> pinUpdatedAt = Date::getCurrentDate();
                this -> updatedAt = Date::getCurrentDate();
            }else throw string("You have to wait " + to_string(2 - Date::DATEDIFF(this -> pinUpdatedAt, Date::getCurrentDate())) + " day left to change your PIN account");
        }else throw string("Invalid PIN");
    else throw string("Inccorect PIN");
}

void Card::update(const Card &C){
    this -> balance = C.balance;
    this -> updatedAt = Date::getCurrentDate();
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
    out << Client(card.holder).getID() << endl;
    out << card.pin << endl;
    out << card.balance << endl;
    out << Date(card.createdAt).toString() << endl;
    out << Date(card.updatedAt).toString() << endl;
    out << Date(card.pinUpdatedAt).toString() << endl;
    return out;
}

ifstream& operator>>(ifstream &in, Card &card){
    string data;
    in >> card.ID;
    in >> data;
    card.holder = Repository<Client>::getByID(data, "Client.txt");
    in >> card.pin;
    in >> card.balance;
    in.ignore();
    getline(in, data);
    card.createdAt = Date(data.c_str());
    getline(in, data);
    card.updatedAt = Date(data.c_str());
    getline(in, data);
    card.pinUpdatedAt = Date(data.c_str());
    return in;
}   