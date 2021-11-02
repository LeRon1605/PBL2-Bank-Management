#include "Client.h"
#include <iostream>
using namespace std;
int main(){
    Client A("10000", "Ron", "Male", "3000", "16-05-2002", Date::getCurrentDate());
    cout << A;
}