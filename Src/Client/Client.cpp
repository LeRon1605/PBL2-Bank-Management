#include "Client.h"
#include <algorithm>
Client::Client(){

}

Client::Client(const string &ID, const string &name, const string &gender, const string &CCCD, const Date &birth){
    this -> ID = (Client::isValidID(ID)) ? ID : "";
    this -> name = (Client::isValidName(name)) ? name : "";
    this -> gender = (Client::isValidGender(gender)) ? Client::formatGender(gender) : "Other";
    this -> CCCD = CCCD;
    this -> birth = (Date(birth).isValidDate()) ? birth : Date();
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
    return this -> gender;
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

string Client::formatGender(string str){
    for_each(str.begin(), str.end(), [](char & c) {
        c = ::tolower(c);
    });
    str[0] = (str[0] >= 'A' && str[0] <= 'Z') ? str[0] : str[0] - 32;
    return str;
}

bool Client::isValidGender(string str){
    for_each(str.begin(), str.end(), [](char & c) {
        c = ::tolower(c);
    });
    if (str != "male" && str != "female" && str != "other") return false;
    return true;
}

bool Client::isValidID(string str){
    if (str.size() != 8) return false; // ID có độ dài là 8 số
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

bool Client::isValidName(string str){
    if (str.size() < 3) return false; // Tên có ít nhất 3 kí tự
    for (int i = 0;i < str.size();i++){
        if (str[i] == ' ') continue;
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) return false;
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
    this -> createdAt = C.createdAt;
    this -> updatedAt = C.updatedAt;
    return (*this);
}

istream& operator>>(istream &in, Client &D){
    cout << "Type Clients's name: ";
    fflush(stdin);
    getline(in, D.name);
    while (!Client::isValidName(D.name)){
        cout << "Invalid Name, type again: ";
        fflush(stdin);
        getline(in, D.name);
    }
    cout << "Type Client's gender(Male/Female/Other): ";
    fflush(stdin);
    cin >> D.gender;
    while (!Client::isValidGender(D.gender)){
        cout << "Invalid gender, type again: ";
        fflush(stdin);
        cin >> D.gender;
    }
    D.gender = Client::formatGender(D.gender);
    cout << "Type Client's CCCD: ";
    in >> D.CCCD;
    cout << "Type Client's birth(dd-mm-yyyy): ";
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