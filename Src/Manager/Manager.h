#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "../Datetime/Datetime.h"
template <class T>
class Manager{
    private:
    public:
        virtual string generateID() = 0;
        virtual void show() = 0;
        virtual void showByID(const string&) = 0;
        virtual T findByID(const string&) = 0;
        virtual int indexOf(const T) = 0;
        virtual int indexOf(const string&) = 0; 
        virtual void add(const T) = 0;
        virtual void remove(const T) = 0;
        virtual void removeByID(const string&) = 0;
        virtual void listByDate(const Date&) = 0;
};
#endif