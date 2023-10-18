#pragma once
class Account
{
public:
	Account(int* id);
	Account(int* id, float balance);
	~Account();

	float getBalance();
private:
	int id;
	float balance;
};

