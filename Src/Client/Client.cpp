#include "Client.h"

Client::Client(){

}

Client::Client(const string &ID, const string &name, const int &gender, const string &CCCD, const Date &birth){
    this -> ID = ID;
    this -> name = name;
    this -> gender = gender;
    this -> CCCD = CCCD;
    this -> birth = birth;
    this -> createdAt = Date::getCurrentDate();
    this -> updatedAt = Date();
}

string Client::getID(){
    return this -> ID;
}

string Client::getName(){
    return this -> name;
}

string Client::getGender(){
    if (this -> gender == 0) return "Nam";
    else if (this -> gender == 1) return "Nu";
    return "Khac";
}

string Client::getCCCD(){
    return this -> CCCD;
}

Date Client::getBirth(){
    return this -> birth;
}

Date Client::getCreatedAt(){
    return this -> createdAt;
}

Date Client::getUpdatedAt(){
    return this -> updatedAt;
}

void Client::setID(const string &ID){
    this -> ID = ID;
}

void Client::setName(const string &name){
    this -> name = name;
}

void Client::setGender(const int &gender){
    this -> gender = gender;
}

void Client::setCCCD(const string &CCCD){
    this -> CCCD = CCCD;
}

void Client::setBirth(const Date &birth){
    this -> birth = birth;
}

void Client::setCreatedAt(const Date &createdAt){
    this -> createdAt = createdAt;
}

void Client::setUpdatedAt(const Date &updatedAt){
    this -> updatedAt = updatedAt;
}

bool Client::isValidID(){
    if (this -> ID.size() < 8) return false; // ID có độ dài là 8 số
    for (int i = 0; i < this -> ID.size();i++){
        if (this -> ID[i] < '0' || this -> ID[i] > '9') return false;
    }
    return true;
}

bool Client::isValidName(){
    if (this -> name.size() < 3) return false; // Tên có ít nhất 3 kí tự
    for (int i = 0;i < this -> name.size();i++){
        if (this -> name[i] == ' ') continue;
        if ((this -> name[i] < 'a' || this -> name[i] > 'z') && (this -> name[i] < 'A' || this -> name[i] > 'Z')) return false;
    }
    return true;
}

void Client::show(){
    cout << "ID: " << this -> ID << endl;
    cout << "Name: " << this -> name << endl;
    cout << "Birth: " << this -> birth << endl;
    cout << "Created At: " << this -> createdAt << endl;
}

void Client::update(const string &name, const int &gender, const string &CCCD, const Date &birth){
    this -> name = name;
    this -> gender = gender;
    this -> CCCD = CCCD;
    this -> birth = birth;
    this -> updatedAt = Date::getCurrentDate();
}

const Client& Client::operator=(const Client &C){
    this -> ID = C.ID;
    this -> name = C.name;
    this -> gender = C.gender;
    this -> CCCD = CCCD;
    this -> birth = birth;
    this -> createdAt = C.updatedAt;
    this -> updatedAt = C.updatedAt;
    return (*this);
}

istream& operator>>(istream &in, Client &D){
    cout << "Type Clients's ID: ";
    in >> D.ID;
    while (!D.isValidID()){
        cout << "Invalid ID, type again: ";
        in >> D.ID;
    }
    cout << "Type Clients's name: ";
    fflush(stdin);
    getline(in, D.name);
    while (!D.isValidName()){
        cout << "Invalid Name, type again: ";
        fflush(stdin);
        getline(in, D.name);
    }
    cout << "Type Client's gender(number): ";
    in >> D.gender;
    cout << "Type Client's CCCD: ";
    in >> D.CCCD;
    cout << "Type Client's birth(dd-mm-yyyy): ";
    fflush(stdin);
    cin >> D.birth;
    D.createdAt = Date::getCurrentDate();
    D.updatedAt = Date();
    return in;
}

ostream& operator<<(ostream &out, const Client &C){
    out << "ID: " << C.ID << endl;
    out << "Name: " << C.name << endl;
    out << "Gender: " << Client(C).getGender() << endl;
    out << "Birth: " << C.birth;
    out << "CCCD: " << C.CCCD << endl;
    out << "Created At: " << C.createdAt;
    if (Client(C).updatedAt.isValidDate())
        out << "Updated At: " << C.updatedAt;
    return out;
}