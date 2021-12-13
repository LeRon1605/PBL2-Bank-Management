#ifndef MENU_H
#define MENU_H
class Menu
{
    private:
        int choice;
    public:
        Menu();
        ~Menu();

        void printMenu(void (*Menu)());
        void inputChoice(const int&, const int&);
        int getChoice();
        bool isValidChoice(const int&, const int&);
};
#endif