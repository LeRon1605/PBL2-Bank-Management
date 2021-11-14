#include "WithdrawTransaction/WithdrawTransaction.h"
#include "DepositTransaction/DepositTransaction.h"
#include "TransferTransaction/TransferTransaction.h"
#include "Manager/ClientManager/ClientManager.h"
#include "Manager/CardManager/CardManager.h"
#include "Manager/TransactionManager/TransactionManager.h"
#include "Repo/Repo.h"
// #include "CTDL/Node.h"
// #include "CTDL/LinkedList.cpp"
using namespace std;
int main(){
	// // Code
	Client Ron("10220014", "Le Quoc Ron", "male", "30001234", "16/07/2002");
	Client RonA("10220015", "Le Quoc Ron", "male", "30001234", "16/07/2002");
	Card D("102200000003", Ron, "160502", 50000);
	// Withdraw W("10000000", C, 50000);
	// Transaction *ptr = new Withdraw(W);
	// ptr -> makeTransaction(C.getPin());
	// ptr -> show();
	// Deposit H("10000001", &C, 50000);
	// Transfer E("10000000", &C, &D, 50000);
	// // W.makeTransaction(C.getPin());
	// // W.show();
	// // H.makeTransaction(C.getPin());

	// LinkedList<Card> listCard;
	// listCard.add(C);
	// listCard.add(C);
	// listCard.add(C);
	// listCard.insertAt(D, 0);
	// listCard[1] = D;
	// listCard.remove(C);
	// cout << listCard.getLength();
	// listCard.show();
	// cout << listCard.indexOf("102200000003") << endl;
	// ClientManager A;
	// ofstream a;
	// a.open("../Data/M.txt");
	// a << 3; 
	// cout << Repository<Client>::findAndUpdate(RonA, "Client.txt");
	// cout << Repository<Client>::findAndRemove("10220013", "Client.txt");
	//Client A = Repository<Client>::getByID("10220014", "Client.txt"); // copy constructor <-
	// A.show();
	// LinkedList<Transaction*> list;
	// Transaction *ptr = new Withdraw("10000000", C, 50000);
	// list.add(ptr);
	// list.show();

	// LinkedList<Client> listB;
	// listB.addHead(Ron);
	// RonB.setCreatedAt("3/6/2021");
	// listB.addHead(RonB);
	// listB.addHead(RonA);
	// listB.insertAt(RonA, 1);
	// listB.sort(sortDescByCreatedAt);
	// listB.show();
	// cout << listB.remove(test);
	// listB.show();
	// ifstream in;
	// Card A;
	// in.open("../Data/Card.txt");
	// int n;
	// in >> n;
	// for (int i = 0; i < n;i++){
	// 	in >> A; 
	// 	A.show();
	// }
	// A.getHolder().show();
	//CardManager A;
	// // A.changePin("102200000000", "133333", "133333");
	//Card C(A.generateID(), Ron, "160502", 70000);
	// A.add(C);
	// // A.listByDate("10/11/2021");
	// A.removeByID("100000000000");
	// // Date A = "16/05/2002";
	// cout << (A == "16/05/2002") << endl;
	//A.add(C);
	// cout << A.add(C) << endl;
	// A.show();
	//CardManager A;
	//cout << A.updateByID( D,"100000000000");
	// A.changePin("100000000003", "150503", "150503");
	//cout << Repository<Card>::findAndRemove(compareHolderID, "10220013", "Card.txt");
	// ClientManager A;
	// A.show();
	//A.add(Ron);
	// CardManager A;
	// A.add();
	// A.listAllClientCard("10220013");
	// ifstream test;
	// test.open("../Data/Transaction.txt");
	// int n, m;
	// test >> n >> m;
	// // Deposit temp;
	// string a;
	// // for (int i = 0; i < n; i++){
	// // 	test >> a;
	// // 	test >> temp;
	// // 	temp.getSrcAccount().show();
	// // 	temp.show();
	// // }
	// // test.close();
	// for (int i = 0; i < n;i++){
	// 	test >> a;
	// 	Deposit temp;
	// 	test >> temp;
	// 	Transaction *ptr = new Deposit(temp);
	// 	ptr -> show();
	// }
	// Transaction *ptr = new Withdraw;
	// TransactionManager b;
	// b.showAllClientTransaction("10000001");
	// ClientManager b;
	// // Client A;
	// // A.input();
	// // b.add(A);
	// b.show();
	TransactionManager A;
	Transaction *ptr = A.findByID("10000000");
	ptr -> show();
	return 0;
}