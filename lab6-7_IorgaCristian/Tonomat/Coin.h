#pragma once
#include <iostream>
using namespace std;

class Coin
{
private:
	double value;
	int amount;
public:
	Coin();
	~Coin();
	Coin(double v, int am);
	Coin(const Coin& c);
	double getValue();
	int getAmount();
	void setValue(double val);
	void setAmount(int am);
	Coin& operator=(const Coin& c);
	bool operator==(const Coin& c);
	bool operator!();
	friend ostream& operator<<(ostream& os, const Coin& c);
	friend istream& operator>>(istream& is, Coin& c);
};
