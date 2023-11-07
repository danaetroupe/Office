#pragma once
class Account
{
public:
	Account(int id) {
		this->id = id;
		this->balance = 0;
	}
	Account(int id, float balance) {
		this->id = id;
		this->balance = balance;
	}

	float getBalance() { return balance; }
private:
	int id;
	float balance;
};

