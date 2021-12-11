#include "Manager/ClientManager/ClientManager.h"
#include "Manager/CardManager/CardManager.h"
#include "Manager/TransactionManager/TransactionManager.h"
#include "Menu/Menu.h"
#include "Helper/Helper.h"
#include "Repo/Repo.h"
#include <conio.h>
#include <iomanip>
using namespace std;
int main(){
	Menu application;
	ClientManager *CManager;
	CardManager *cardManager;
	TransactionManager *TManager;
	do{
		system("cls");
		application.printMenu(background);
		application.printMenu(mainMenu);
		application.inputChoice(1, 4);
		switch (application.getChoice()){
			case 1:
				CManager = new ClientManager();
				do{
					system("cls");
					application.printMenu(background);
					application.printMenu(clientManagerMenu);
					application.inputChoice(1, 7);
					switch (application.getChoice()){
						case 1:
							{
								Client newClient;
								newClient.input();
								if (CManager -> add(newClient)) cout << "=> Them khach hang thanh cong" << endl;
								else cout << "=> Them khach hang that bai" << endl;
								getch();
							}
							break;
						case 2:
							{
								string ClientID;
								cout << "Nhap ID khach hang muon xoa: ";
								cin >> ClientID;
								if (CManager -> removeByID(ClientID)) cout << "Xoa thanh cong khach hang co ID: " << ClientID << endl;
								else cout << "Khach hang co ID: " << ClientID << " khong ton tai" << endl;
								getch();
							}
							break;
						case 3:
							{
								string ClientID, newName, newGender, newAddress, newBirth;
								cout << "Nhap ID khach hang muon cap nhat: ";
								cin >> ClientID;
								Client temp = CManager -> findByID(ClientID);
								if (temp.isNull()) cout << "Khach hang khong ton tai" << endl;
								else 
								{
									clientPanel();
									temp.show();
									cout << endl;
									cout << "Nhap thong tin cap nhat, nhan (No) neu khong co thay doi" << endl;
									do{
										cout << "Nhap ten khach hang: ";
										getline(cin >> ws, newName);
										if (newName == "No") break;
									}while (!Client::isValidName(newName));
									do{
										cout << "Nhap gioi tinh khach hang(Male/Female/Other): ";
										cin >> newGender;
										if (newGender == "No") break;
									}while (!Client::isValidGender(newGender));
									do{
										cout << "Nhap dia chi khach hang: ";
										getline(cin >> ws, newAddress);
										if (newAddress == "No"){
											newAddress = "";
											break;
										}
									}while (newAddress.size() < 3);
									do{
										cout << "Nhap ngay sinh khach hang(dd/mm/yyyy): ";
										getline(cin >> ws, newBirth);
										if (newBirth == "No") break;
									}while (!Date(newBirth.c_str()).isValidDate());
									if (CManager -> updateByID(Client(newName, newGender, newAddress, Date(newBirth.c_str())), ClientID)) cout << "Cap nhat thanh cong" << endl;
								}
								getch();
							}
							break;
						case 4:
							{
								string ClientID;
								cout << "Nhap ID khach hang can tim kiem: ";
								cin >> ClientID;
								CManager -> showByID(ClientID);
								getch();
							}
							break;
						case 5:
							system("cls");
							CManager -> show();
							cout << "=> Nhan phim bat ki de quay tro ve.";
							getch();
							break;
						case 6:
							{
								Date temp;
								cout << "Nhap ngay can thong ke(dd/mm/yyyy): ";
								cin >> temp;
								CManager -> listByDate(temp);
								getch();
								break;
							}
							break;
						case 7:
							delete CManager;
					}
				}while (application.getChoice() != 7);
				break;
			case 2:
				cardManager = new CardManager();
				do{
					system("cls");
					application.printMenu(background);
					application.printMenu(cardManagerMenu);
					application.inputChoice(1, 9);
					switch(application.getChoice()){
						case 1:
							{
								Card newCard;
								newCard.input();
								if(cardManager -> add(newCard)) cout << "=> The ngan hang duoc tao thanh cong" << endl;
								else cout << "=> The ngan hang duoc tao that bai" << endl;
								getch();
							}
							getch();
							break;
						case 2:
							{
								string CardID;
								cout << "=> Nhap ID the ngan hang muon xoa: ";
								cin >> CardID;
								if(cardManager -> removeByID(CardID)) cout << "=> Xoa thanh cong the ngan hang co ID: " << CardID << endl;
								else cout << "=> The ngan hang co ID: " << CardID << "khong ton tai" << endl;
							}
							getch();
							break;
						case 3 :
							{
								string CardID, newPin , currentPin;
								cout << "=> Nhap ID the ngan hang muon doi ma pin: ";
								cin >> CardID;
								Card temp = cardManager -> findByID(CardID);
								if(temp.isNull()) cout << "=> The ngan hang khong ton tai" << endl;
								else
								{
									cout << "=> Nhap ma pin cu: ";
									cin >> currentPin;
									cout << "=> Nhap ma pin moi: ";
									cin >> newPin;
									if (currentPin == newPin) {
										cout << "=> Ma PIN moi khong the giong PIN cu" << endl;
										cout << "=> Doi ma pin khong thanh cong" << endl;
									}else
										if(cardManager -> changePin(CardID, currentPin, newPin)) cout << "=> Doi ma pin thanh cong" << endl;
										else cout << "=> Doi ma pin khong thanh cong";
								}
							}
							getch();
							break;
						case 4 :
							{
								string CardID;
								cout << "=> Nhap ID the ngan hang muon hien thi thong tin: ";
								cin >> CardID;
								Card temp = cardManager -> findByID(CardID);
								if(temp.isNull()) cout << "=> The ngan hang khong ton tai" << endl;
								else
								{
									cardManager -> showByID(CardID);
								}
								getch();
							}
							break;
						case 5 :
							system("cls");
							cardManager ->show();
							cout << "=> Nhan phim bat ki de quay tro ve.";
							getch();
							break;
						case 6 :
							{
								string ClientID;
								cout << "=> Nhap ID khach hang muon hien thi danh sach the ngan hang: ";
								cin >> ClientID;
								Client temp = Repository<Client>::getByID(ClientID, "Client.txt");
								if(temp.isNull()) cout << "=> Khach hang khong ton tai" << endl;
								else
								{
									cardManager -> listAllClientCard(ClientID);
								}
								getch();
							}
							getch();
							break;
						case 7:
							{
								string ClientID;
								cout << "=> Nhap ID khach hang muon xoa tat ca cac the ngan hang: ";
								cin >> ClientID;
								Client temp = Repository<Client>::getByID(ClientID, "Client.txt");
								if(temp.isNull()) cout << "=> Khach hang khong ton tai" << endl;
								else
								{
									cardManager -> removeAll(ClientID);
									cout << "=> Xoa the ngan hang thanh cong.";
								}
							}
							getch();
							break;
						case 8 :
							{
								Date temp;
								cout << "=> Nhap ngay can thong ke(dd/mm/yyyy): ";
								cin >> temp;
								cardManager -> listByDate(temp);
								getch();
							}
							break;
						case 9 :
						 	delete cardManager;
					}
				}while (application.getChoice() != 9);
				break;
			case 3:
				TManager = new TransactionManager();
				do{
					system("cls");
					application.printMenu(background);
					application.printMenu(transactionManagerMenu);
					application.inputChoice(1, 12);
					switch (application.getChoice()){
						case 1:
							{
								string CardID, PIN;
								long cash; 
								cout << "=> Nhap ID tai khoan muon rut tien: ";
								cin >> CardID;
								if (Repository<Card>::getByID(CardID, "Card.txt").isNull()){
									cout << "=> Tai khoan khong ton tai";
									getch();
									break;
								}
								cout << "=> Nhap so tien muon rut: ";
								cin >> cash;
								cout << "=> Nhap ma PIN cua tai khoan: ";
								cin >> PIN;
								if (TManager -> makeWithdraw(CardID, cash, PIN)) cout << "=> Rut tien thanh cong" << endl;
								else cout << "=> Rut tien that bai";
								getch();
							}
							break;
						case 2:
							{
								string CardID, PIN;
								long cash; 
								cout << "=> Nhap ID tai khoan muon nap tien: ";
								cin >> CardID;
								if (Repository<Card>::getByID(CardID, "Card.txt").isNull()){
									cout << "=> Tai khoan khong ton tai";
									getch();
									break;
								}
								cout << "=> Nhap so tien muon nap: ";
								cin >> cash;
								cout << "=> Nhap ma PIN cua tai khoan: ";
								cin >> PIN;
								if (TManager -> makeDeposit(CardID, cash, PIN)) cout << "=> Nap tien thanh cong" << endl;
								else cout << "=> Nap tien that bai";
								getch();
							}
							break;
						case 3:
							{
								string srcAccount, destAccount, PIN;
								long cash; 
								cout << "=> Nhap ID tai khoan thuc hien chuyen tien: ";
								cin >> srcAccount;
								if (Repository<Card>::getByID(srcAccount, "Card.txt").isNull()){
									cout << "=> Tai khoan khong ton tai";
									getch();
									break;
								}
								cout << "=> Nhap ID tai khoan nhan tien: ";
								cin >> destAccount;
								if (Repository<Card>::getByID(srcAccount, "Card.txt").isNull()){
									cout << "=> Tai khoan khong ton tai";
									getch();
									break;
								}
								cout << "=> Nhap so tien muon chuyen: ";
								cin >> cash;
								cout << "=> Nhap ma PIN cua tai khoan: ";
								cin >> PIN;
								if (TManager -> makeTransfer(srcAccount, destAccount, cash, PIN)) cout << "=> Chuyen tien thanh cong" << endl;
								else cout << "=> Chuyen tien that bai" << endl; 
								getch();
							}
							break;
						case 4:
							system("cls");
							TManager -> showWithdraw();
							cout << "=> Nhan phim bat ki de quay tro ve.";
							getch();
							break;
						case 5:
							system("cls");
							TManager -> showDeposit();
							cout << "=> Nhan phim bat ki de quay tro ve.";
							getch();
							break;
						case 6:
							system("cls");
							TManager -> showTransfer();
							cout << "=> Nhan phim bat ki de quay tro ve.";
							getch();
							break;
						case 7:
							system("cls");
							TManager -> show();
							cout << "=> Nhan phim bat ki de quay tro ve.";
							getch();
							break;
						case 8:
							{
								string TransactionID;
								cout << "=> Nhap ID giao dich can tim kiem: ";
								cin >> TransactionID;
								Transaction *ptr = TManager -> findByID(TransactionID);
								if (ptr == nullptr) cout << "=> Giao dich khong ton tai" << endl;
								else{
									transactionPanel();
									ptr -> show();
								}
							}
							getch();
							break;
						case 9:
							{
								string clientID;
								cout << "=> Nhap ID khach hang: ";
								cin >> clientID;
								system("cls");
								TManager -> showAllClientTransaction(clientID);
								cout << "=> Nhan phim bat ki de quay tro ve.";
							}
							getch();
							break;
						case 10:
							{
								string cardID;
								cout << "=> Nhap ID the ngan hang: ";
								cin >> cardID;
								if (Repository<Card>::getByID(cardID, "Card.txt").isNull()) cout << "=> The khong ton tai" << endl;
								else{
									system("cls");
									TManager -> showAllCardTransaction(cardID);
									cout << "=> Nhan phim bat ki de quay tro ve.";
								}
							}
							getch();
							break;
						case 11:
							{
								Date time;
								cout << "=> Nhap ngay can thong ke(dd/mm/yyyy): ";
								cin >> time;
								system("cls");
								TManager -> listByDate(time);
							}
							cout << "=> Nhan phim bat ki de quay tro ve.";
							getch();
							break;
						case 12:
							delete TManager;
					}
				}while (application.getChoice() != 12);
				break;
			case 4:
				cout << "Ket thuc chuong trinh" << endl;
				break;
		}
	}while (application.getChoice() != 4);
	return 0;
}