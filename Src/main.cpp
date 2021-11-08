#include "WithdrawTransaction/WithdrawTransaction.h"
#include "DepositTransaction/DepositTransaction.h"
#include "TransferTransaction/TransferTransaction.h"
#include "Manager/ClientManager/ClientManager.h"
#include "Repo/Repo.h"
// #include "CTDL/Node.h"
// #include "CTDL/LinkedList.cpp"
using namespace std;
int main(){
	// // Code
	Client Ron("10220013", "Ron Le", "Male", "30001234", "16/05/2002");
	Client RonA("10220013", "Ron Le", "Female", "30001234", "16/06/2002");
	// Card C("102200000000", Ron, "160502", 70000);
	// Card D("102200000003", Ron, "160502", 70000);
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
	Repository<Client>::findAndRemove("10220013", "Client.txt");
	return 0;
}