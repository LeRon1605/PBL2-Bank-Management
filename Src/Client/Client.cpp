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

void Client::show(){
    cout << "ID: " << this -> ID << endl;
    cout << "Name: " << this -> name << endl;
    cout << "Birth: " << this -> birth << endl;
    cout << "Created At: " << this -> createdAt << endl;
}