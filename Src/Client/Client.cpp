#include "Client.h"
#include <string>
#include <algorithm>
Client::Client(){

}

Client::Client(const Client &D){
    this -> ID = D.ID;
    this -> name = D.name;
    this -> gender = D.gender;
    this -> CCCD = D.CCCD;
    this -> birth = D.birth;
    this -> age = D.age;
    this -> createdAt = D.createdAt;
    this -> updatedAt = D.updatedAt;
}

Client::Client(const string &ID, const string &name, const string &gender, const string &CCCD, const Date &birth){
    this -> ID = (Client::isValidID(ID)) ? ID : "";
    this -> name = (Client::isValidName(name)) ? name : "";
    this -> gender = (Client::isValidGender(gender)) ? Client::formatGender(gender) : "Other";
    this -> CCCD = CCCD;
    this -> birth = (Date(birth).isValidDate()) ? birth : Date();
    this -> age = this -> getAge();
    this -> createdAt = Date::getCurrentDate();
    this -> updatedAt = Date();
}

Client::Client(const string &ID, const string &name, const string &gender, const string &CCCD, const Date &birth, const Date &createdAt, const Date &updatedAt){
    this -> ID = (Client::isValidID(ID)) ? ID : "";
    this -> name = (Client::isValidName(name)) ? name : "";
    this -> gender = (Client::isValidGender(gender)) ? Client::formatGender(gender) : "Other";
    this -> CCCD = CCCD;
    this -> birth = (Date(birth).isValidDate()) ? birth : Date();
    this -> age = this -> getAge();
    this -> createdAt = (Date(createdAt).isValidDate()) ? createdAt : Date();
    this -> updatedAt = (Date(updatedAt).isValidDate()) ? updatedAt : Date();
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

int Client::getAge(){
    Date temp = Date(this -> birth.getDay(), this -> birth.getMonth(), Date::getCurrentDate().getYear());
    if (temp < Date::getCurrentDate()) return Date::getCurrentDate().getYear() - this -> birth.getYear();
    return Date::getCurrentDate().getYear() - this -> birth.getYear() - 1;
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
    this -> ID = (Client::isValidID(ID)) ? ID : "";
}

void Client::setName(const string &name){
    this -> name = (Client::isValidName(name)) ? name : "";
}

void Client::setGender(const string &gender){
    this -> gender = (Client::isValidGender(gender)) ? Client::formatGender(gender) : "Other";
}

void Client::setCCCD(const string &CCCD){
    this -> CCCD = CCCD;
}

void Client::setBirth(const Date &birth){
    this -> birth = (Date(birth).isValidDate()) ? birth : Date();;
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

bool Client::isValidID(const string &str){
    if (str.size() != 8) return false; // ID có độ dài là 8 số
    for (int i = 0; i < str.size();i++){
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

bool Client::isValidName(const string &str){
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
    cout << "Gender: " << this -> gender << endl;
    cout << "Age: " << this -> age << endl;
    cout << "Birth: " << this -> birth;
    cout << "CCCD: " << this -> CCCD << endl;
    cout << "Created At: " << this -> createdAt;
    if (this -> updatedAt.isValidDate())
        cout << "Updated At: " << this -> updatedAt;
}

void Client::update(const string &name, const string &gender, const string &CCCD, const Date &birth){
    this -> name = (Client::isValidName(name)) ? name : "";
    this -> gender = (Client::isValidGender(gender)) ? Client::formatGender(gender) : "Other";
    this -> CCCD = CCCD;
    this -> birth = (Date(birth).isValidDate()) ? birth : Date();
    this -> age = this -> getAge();
    this -> updatedAt = Date::getCurrentDate();
}

void Client::update(const Client &C){
    this -> name = C.name;
    this -> gender = C.gender;
    this -> CCCD = C.CCCD;
    this -> birth = C.birth;
    this -> age = C.age;
    this -> updatedAt = Date::getCurrentDate();
}

const Client& Client::operator=(const Client &C){
    this -> ID = C.ID;
    this -> name = C.name;
    this -> gender = C.gender;
    this -> CCCD = C.CCCD;
    this -> birth = C.birth;
    this -> age = C.age;
    this -> createdAt = C.createdAt;
    this -> updatedAt = C.updatedAt;
    return (*this);
}

void Client::input(){
    cout << "Type Clients's name: ";
    fflush(stdin);
    getline(cin, this -> name);
    while (!Client::isValidName(this -> name)){
        cout << "Invalid Name, type again: ";
        fflush(stdin);
        getline(cin, this -> name);
    }
    cout << "Type Client's gender(Male/Female/Other): ";
    fflush(stdin);
    cin >> this -> gender;
    while (!Client::isValidGender(this -> gender)){
        cout << "Invalid gender, type again: ";
        fflush(stdin);
        cin >> this -> gender;
    }
    this -> gender = Client::formatGender(this -> gender);
    cout << "Type Client's CCCD: ";
    cin >> this -> CCCD;
    cout << "Type Client's birth(dd-mm-yyyy): ";
    cin >> this -> birth;
    this -> age = this -> getAge();
    this -> createdAt = Date::getCurrentDate();
    this -> updatedAt = Date();
}
// istream& operator>>(istream &in, Client &D){
//     cout << "Type Clients's name: ";
//     fflush(stdin);
//     getline(in, D.name);
//     while (!Client::isValidName(D.name)){
//         cout << "Invalid Name, type again: ";
//         fflush(stdin);
//         getline(in, D.name);
//     }
//     cout << "Type Client's gender(Male/Female/Other): ";
//     fflush(stdin);
//     cin >> D.gender;
//     while (!Client::isValidGender(D.gender)){
//         cout << "Invalid gender, type again: ";
//         fflush(stdin);
//         cin >> D.gender;
//     }
//     D.gender = Client::formatGender(D.gender);
//     cout << "Type Client's CCCD: ";
//     in >> D.CCCD;
//     cout << "Type Client's birth(dd-mm-yyyy): ";
//     cin >> D.birth;
//     D.age = D.getAge();
//     D.createdAt = Date::getCurrentDate();
//     D.updatedAt = Date();
//     return in;
// }

ofstream& operator<<(ofstream &out, const Client &C){
    out << C.ID << endl;
    out << C.name << endl;
    out << C.gender << endl;
    out << C.CCCD << endl;
    out << Date(C.birth).toString() << endl;
    out << Date(C.createdAt).toString() << endl;
    out << Date(C.updatedAt).toString() << endl;
    return out;
}

bool Client::operator==(const Client &newClient){
    if(this->ID == newClient.ID && this->name == newClient.name && this->gender == newClient.gender && this->age == newClient.age && this->birth == newClient.birth && this->CCCD == newClient.CCCD && this->createdAt == newClient.createdAt && this->updatedAt == newClient.updatedAt){
        return true;
    }
    return false;
}
ifstream& operator>>(ifstream &in, Client &C){
    string date;
    in >> C.ID;
    in.ignore(2000,'\n');
    getline(in, C.name);
    in >> C.gender;
    in >> C.CCCD;
    in.ignore(2000,'\n');
    getline(in, date);
    C.birth = Date(date.c_str());
    getline(in, date);
    C.createdAt = Date(date.c_str());
    getline(in, date);
    C.updatedAt = Date(date.c_str());
    C.age = C.getAge();
    return in;
}
