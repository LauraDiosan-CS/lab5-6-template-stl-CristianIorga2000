#pragma once
#include <iostream>
using namespace std;

class Product
{
private:
	int id;
	double price;
	char* name;
public:
	Product();
	~Product();
	Product(int c, double p, char* n);
	Product(const Product& p);
	int getId();
	double getPrice();
	char* getName();
	void setId(int c);
	void setPrice(double pr);
	void setName(char* n);
	Product& operator=(const Product& p);
	bool operator==(const Product& p);
	bool operator!();
	friend ostream& operator<<(ostream& os, const Product& p);
	friend istream& operator>>(istream& is, Product& p);
};
