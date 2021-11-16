#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(){

}
Menu::~Menu(){
    
}

void Menu::printMenu(void (*Menu)()){
    Menu();
}

void Menu::inputChoice(const int &min, const int &max){
    cout << "Nhap lua chon: ";
    cin >> this -> choice;
    while (!this -> isValidChoice(min, max)){
        cout << "Lua chon khong hop le, vui long nhap lai: ";
        cin >> this -> choice;
    }
}

int Menu::getChoice(){
    return this -> choice;
}

bool Menu::isValidChoice(const int &min, const int &max){
    return (this -> choice >= min && this -> choice <= max);
}