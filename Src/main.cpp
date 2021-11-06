#include "WithdrawTransaction/WithdrawTransaction.h"
#include "DepositTransaction/DepositTransaction.h"
#include "TransferTransaction/TransferTransaction.h"
using namespace std;
int main(){
	// Code
	Client Ron("10220019", "Ron Le", "Male", "30001234", "16-05-2002");
	Card C("102200000000", Ron, "160502", 70000);
	Card D("102200000003", Ron, "160502", 70000);
	Withdraw W("10000000", &C, 50000);
	Deposit H("10000001", &C, 50000);
	Transfer E("10000000", &C, &D, 50000);
	// W.makeTransaction(C.getPin());
	// W.show();
	// H.makeTransaction(C.getPin());
	E.makeTransaction(C.getPin());
	E.show();
	D.show();
	C.show();
	return 0;
}