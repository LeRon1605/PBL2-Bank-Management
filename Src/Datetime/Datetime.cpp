#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <iomanip>
#include "Datetime.h"

Date::Date(const int &day, const int &month, const int &year, const int &hour, const int &minute, const int &second){
    this -> day = day;
    this -> month = month;
    this -> year = year;
    this -> hour = hour;
    this -> minute = minute;
    this -> second = second;
}

Date::Date(const Date &other){
    this -> day = other.day;
    this -> month = other.month;
    this -> year = other.year;
    this -> hour = other.hour;
    this -> minute = other.minute;
    this -> second = other.second;
}

Date::Date(const char *time){
    this -> day = this -> month = this -> year = -1;
    this -> hour = this -> minute = this -> second = -1;

    char temp[20];
    strcpy(temp, time);
    this -> toDate(temp);
}

void Date::toDate(const char *time){
    char *str = strtok((char*)time, " ");  
    char *dateStr = NULL, *hourStr = NULL;
    bool dateSplit = true;
    int col = 1;
    // Split dd-mm-yyyy hh:mm:ss to two strings dd/mm/yyyy and hh/mm/ss
    while(str != NULL) 
    {
        if (dateSplit == true){
            dateStr = str;
            dateSplit = false;
        }else{
            hourStr = str;	
        }
        str = strtok(NULL, " ");
    }

    // Split string dd-mm-yyyy and save data to day, month, year
    if (dateStr){
        str = strtok(dateStr, "-");
        while (str != NULL){
            if (col == 1) this -> day = atoi(str);
            else if (col == 2) this -> month = atoi(str);
            else if (col == 3) this -> year = atoi(str);
            col++;
            str = strtok(NULL, "-");   		
        }
    }

    // Split string hh:mm:ss and save data to hour, minute, second
    if (hourStr){
        col = 1;
        str = strtok(hourStr, ":");
        while (str != NULL){
            if (col == 1) this -> hour = atoi(str);
            else if (col == 2) this -> minute = atoi(str);
            else if (col == 3) this -> second = atoi(str);
            col++;
            str = strtok(NULL, ":");
        }
    }
}

int Date::getDay(){
    return this -> day;
}

int Date::getMonth(){
    return this -> month;
}

int Date::getYear(){
    return this -> year;
}

int Date::getHour(){
    return this -> hour;
}

int Date::getMinute(){
    return this -> minute;
}

int Date::getSecond(){
    return this -> second;
}

bool Date::isLeapYear(){
    if (this -> year % 400 == 0 || (this -> year % 4 == 0 && this -> year % 100 != 0)){
        return true;
    }
    return false;
}

bool Date::isValidDate(){
    if (this -> day <= 0 || this -> month <= 0 || this -> year <= 0) return false;
    switch (this -> month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (this -> day > 0 && this -> day <= 31) return true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (this -> day > 0 && this -> day <= 30) return true;
            break;
        case 2:
            if ((this -> isLeapYear() && this -> day > 0 && this -> day <= 29) || (!this -> isLeapYear() && this -> day > 0 && this -> day <= 28)) return true;
    }
    return false;
}

bool Date::isValidHour(){
    if (this -> hour > 23 || this -> hour < 0 || this -> minute < 0 || this -> minute > 59 || this -> second > 59 || this -> second < 0) return false;
    return true;
}

Date Date::getCurrentDate(){
    time_t now = time(0);
    static char currentDate[20];
    tm *timeinfo = localtime(&now);
    strftime (currentDate, 20, "%d-%m-%Y %H:%M:%S", timeinfo);
    return Date(currentDate);
}

ostream& operator<<(ostream &out, const Date &D){
    out << setfill('0');
    if (Date(D).isValidHour())
        out << setw(2) << D.hour << ":" << setw(2) << D.minute << ":" << setw(2) << D.second << " ";
    if (Date(D).isValidDate())
        out << setw(2) << D.day << "-" << setw(2) << D.month << "-" << setw(4) << D.year;
    out << endl;
    out << setfill(' ');
    return out;
}

istream& operator>>(istream &in, Date &D){
    char str[20];
    gets(str);
    D.toDate(str);
    while (D.isValidDate() == false){
        cout << "Invalid date, type again: ";
        gets(str);
        D.toDate(str);
    }
    return in;
}

const Date& Date::operator=(const Date &other){
    if (this != &other){
        this -> day = other.day;
        this -> month = other.month;
        this -> year = other.year;
        this -> hour = other.hour;
        this -> minute = other.minute;
        this -> second = other.second;
    }
    return (*this);
}

bool operator>(const Date &A, const Date &B){
    return ((A.year*365 + A.month*30 + A.day) > (B.year*365 + B.month*30 + B.day));
    return ((A.hour*3600 + A.minute*60 + A.second) > (B.hour*3600 + B.minute*60 + B.second));
}

bool operator<(const Date &A, const Date &B){
    return ((A.year*365 + A.month*30 + A.day) < (B.year*365 + B.month*30 + B.day));
    return ((A.hour*3600 + A.minute*60 + A.second) < (B.hour*3600 + B.minute*60 + B.second));
}

bool operator>=(const Date &A, const Date &B){
    return ((A.year*365 + A.month*30 + A.day) >= (B.year*365 + B.month*30 + B.day));
    return ((A.hour*3600 + A.minute*60 + A.second) >= (B.hour*3600 + B.minute*60 + B.second));
}

bool operator<=(const Date &A, const Date &B){
    return ((A.year*365 + A.month*30 + A.day) <= (B.year*365 + B.month*30 + B.day));
    return ((A.hour*3600 + A.minute*60 + A.second) <= (B.hour*3600 + B.minute*60 + B.second));
}