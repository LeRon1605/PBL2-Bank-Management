#ifndef REPO_H
#define REPO_H
#include <string>
#include <string.h>
#include <fstream>
#include "../CTDL/LinkedList.h"
using namespace std;
template <class T>
class Repository 
{
    private:
    public:
        static T getByID(const string&, const string&);
        static bool contains(const string&, const string&);
        static bool findAndUpdate(T, const string&);
        static bool findAndRemove(const string&, const string&);
        static bool findAndRemove(bool (*compare)(const T, const string&), const string&, const string&);
        static int countDoc(bool (*compare)(const T, const string&), const string&, const string&);
};

template <class T>
T Repository<T>::getByID(const string &ID, const string &fileName){
    ifstream in;
    in.open("../Data/" + fileName);
    int n, totalDoc;
    in >> n;
    in >> totalDoc;
    T temp;
    for (int i = 0; i < n;i++){
        in >> temp;
        if (temp.getID() == ID) return temp;
    }
    return T();
}

template <class T>
bool Repository<T>::contains(const string &ID, const string &fileName){
    ifstream in;
    in.open("../Data/" + fileName);
    int n, totalDoc;
    in >> n;
    in >> totalDoc;
    T temp;
    for (int i = 0; i < n;i++){
        in >> temp;
        if (temp.getID() == ID) return true;
    }
    return false;
}

template <class T>
bool Repository<T>::findAndUpdate(T value, const string &fileName){
    ofstream temp;
    temp.open("../Data/temp.txt", ios::out);
    ifstream in;
    in.open("../Data/" + fileName, ios::in);
    int n, totalDoc;
    in >> n;
    temp << n << endl;
    in >> totalDoc;
    temp << totalDoc << endl;
    T tempElement;
    bool success = false;
    for (int i = 0; i < n;i++){
        in >> tempElement;
        if (tempElement.getID() == value.getID()) {
            tempElement.update(value);
            success = true;
        }
        temp << tempElement;
    }
    in.close();
    temp.close();
    remove(("../Data/" + fileName).c_str());
    rename("../Data/temp.txt", ("../Data/" + fileName).c_str());
    return success;
}

template <class T>
bool Repository<T>::findAndRemove(const string &ID, const string &fileName){
    if (!Repository<T>::contains(ID, fileName)) return false;
    ofstream temp;
    temp.open("../Data/temp.txt");
    ifstream in;
    in.open("../Data/" + fileName);
    int n, totalDoc;
    in >> n;
    temp << n - 1 << endl;
    in >> totalDoc;
    temp << totalDoc << endl;
    T tempElement;
    for (int i = 0; i < n;i++){
        in >> tempElement;
        if (tempElement.getID() != ID) temp << tempElement;
    }
    temp.close();
    in.close();
    remove(("../Data/" + fileName).c_str());
    rename("../Data/temp.txt", ("../Data/" + fileName).c_str());
    return true;
}

template <class T>
bool Repository<T>::findAndRemove(bool (*compare)(const T, const string&), const string &str, const string &fileName){
    ofstream temp;
    temp.open("../Data/temp.txt");
    ifstream in;
    in.open("../Data/" + fileName);
    int n, totalDoc;
    in >> n;
    int num = Repository<T>::countDoc(compare, str, fileName);
    if (num == 0) return false;
    temp << n - num << endl;
    in >> totalDoc;
    temp << totalDoc << endl;
    T tempElement;
    for (int i = 0; i < n;i++){
        in >> tempElement;
        if (compare(tempElement, str) != true) temp << tempElement;
    }
    temp.close();
    in.close();
    remove(("../Data/" + fileName).c_str());
    rename("../Data/temp.txt", ("../Data/" + fileName).c_str());
    return true;
}

template <class T>
int Repository<T>::countDoc(bool (*compare)(const T, const string&), const string &str, const string &fileName){
    ifstream in;
    in.open("../Data/" + fileName);
    int n, totalDoc;
    in >> n;
    in >> totalDoc;
    T tempElement;
    int count = 0;
    for (int i = 0; i < n;i++){
        in >> tempElement;
        if (compare(tempElement, str)) count++;
    }
    in.close();
    return count;
}
#endif