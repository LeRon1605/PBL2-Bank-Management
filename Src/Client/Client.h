#include "../Datetime/Datetime.h"
class Client{
    private:
        string ID;
        string name;
        int gender;
        string CCCD;
        Date birth;
        Date createdAt;
        Date updatedAt;
    public:
        Client();
        Client(const string&, const string&, const int&, const string&, const Date&);
        
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
        void setGender(const int&);
        void setCCCD(const string&);
        void setBirth(const Date&);
        void setCreatedAt(const Date&);
        void setUpdatedAt(const Date&);

        void show();
        void update(const string&, const int&, const string&, const Date&); // Name, gender, CCCD, birth

        const Client& operator=(const Client&);
        friend ostream& operator<<(ostream&, const Client&);
        friend istream& operator>>(istream&, Client&);

};