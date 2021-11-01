#ifndef CLIENT_H
#define CLIENT_H
#include "../Datetime/Datetime.h"
class Client{
    private:
        string ID;
        string name;
        string gender;
        string CCCD;
        Date birth;
        Date createdAt;
        Date updatedAt;
    public:
        Client();
        Client(const Client&);
        Client(const string&, const string&, const string &gender, const string&, const Date&);
        
        // Getter
        string getID();
        string getName();
        string getGender();
        string getCCCD();
        Date getBirth();
        Date getCreatedAt();
        Date getUpdatedAt();
        
        // Setter
        void setID(const string&);
        void setName(const string&);
        void setGender(const string&);
        void setCCCD(const string&);
        void setBirth(const Date&);
        void setCreatedAt(const Date&);
        void setUpdatedAt(const Date&);

        static string formatGender(string);
        static bool isValidGender(string);
        static bool isValidID(const string&);
        static bool isValidName(const string&);
        void show();
        void update(const string&, const string&, const string&, const Date&); // Name, gender, CCCD, birth

        const Client& operator=(const Client&);
        friend ostream& operator<<(ostream&, const Client&);
        friend istream& operator>>(istream&, Client&);

};
#endif