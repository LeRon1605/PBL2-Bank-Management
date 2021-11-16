#ifndef CLIENT_H
#define CLIENT_H
#include "../Datetime/Datetime.h"
#include <fstream>
class Client{
    private:
        string ID;
        string name;
        string gender;
        string address;
        int age;
        Date birth;
        Date createdAt;
        Date updatedAt;
    public:
        Client();
        Client(const Client&);
        Client(const string&, const string &gender, const string&, const Date&);
        Client(const string&, const string&, const string &gender, const string&, const Date&, const Date&, const Date& = "");

        // Getter
        string getID();
        string getName();
        string getGender();
        string getAddress();
        int getAge();
        Date getBirth();
        Date getCreatedAt();
        Date getUpdatedAt();
        
        // Setter
        void setID(const string&);
        void setName(const string&);
        void setGender(const string&);
        void setAddress(const string&);
        void setBirth(const Date&);
        void setCreatedAt(const Date&);
        void setUpdatedAt(const Date&);

        static string formatGender(string);
        static bool isValidGender(string);
        static bool isValidID(const string&);
        static bool isValidName(const string&);
        bool isNull();
        void show();
        void input();
        void update(const string&, const string&, const string&, const Date&); // Name, gender, address, birth
        void update(const Client&);

        const Client& operator=(const Client&);
        bool operator==(const Client&);
        friend ifstream& operator>>(ifstream&, Client&);
        friend ofstream& operator<<(ofstream&, const Client&);
};
#endif