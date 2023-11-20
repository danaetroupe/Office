#pragma once
class Account
{
public:
	Account() {
		this->balance = 500;
	}
	Account(float balance) {
		this->balance = balance;
	}

	float getBalance() { return balance; }
private:
	float balance;
};

