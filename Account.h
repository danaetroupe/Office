#pragma once
class Account
{
public:
	Account() {
		this->balance = 500;
	}
	Account(double balance) {
		this->balance = balance;
	}

	double getBalance() { return balance; }
	void makeTransaction(double value) { balance += value; }
private:
	double balance;
};

