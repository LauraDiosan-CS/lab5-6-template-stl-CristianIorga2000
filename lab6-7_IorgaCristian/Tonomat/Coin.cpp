#include "Coin.h"
#include <fstream>
#include <ostream>
#include <istream>

using namespace std;

Coin::Coin()
{
	this->value = 0;
	this->amount = 0;
}

Coin::~Coin() {}

Coin::Coin(double v, int am)
{
	this->value = v;
	this->amount = am;
}

Coin::Coin(const Coin& c)
{
	this->value = c.value;
	this->amount = c.amount;
}

double Coin::getValue()
{
	return this->value;
}

int Coin::getAmount()
{
	return this->amount;
}

void Coin::setValue(double val)
{
	this->value = val;
}

void Coin::setAmount(int am)
{
	this->amount = am;
}

Coin& Coin::operator=(const Coin& c)
{
	this->value = c.value;
	this->amount = c.amount;
	return* this;
}

bool Coin::operator==(const Coin& c)
{
	return (this->value == c.value && this->amount == c.amount);
}

bool Coin::operator!()
{
	if (this->value == 0 or this->amount == 0)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Coin& c)
{
	os << c.value << " " << c.amount;
	return os;
}

istream& operator>>(istream& is, Coin& c)
{
	int am = 0;
	double val = 0;
	if (&is == &cin)
		cout << "Input value: ";
	is >> val;
	if (&is == &cin)
		cout << "Input coin amount: ";
	is >> am;
	c.setValue(val);
	c.setAmount(am);
	return is;
}
