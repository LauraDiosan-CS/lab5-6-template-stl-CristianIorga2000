#include <iostream>
#include "Product.h"
#include <string.h>
#include <ostream>
#include <istream>
using namespace std;

Product::Product()
{
	this->id = 0;
	this->price = 0;
	this->name = NULL;
}

Product::Product(int c, double p, char* n)
{
	this->id = c;
	this->price = p;
	if (n == NULL)
		this->name = NULL;
	else
	{
		this->name = new char[strlen(n) + 1];
		strcpy_s(this->name, strlen(n) + 1, n);
	}
}

Product::Product(const Product& p)
{
	this->id = p.id;
	this->price = p.price;

	if (p.name == NULL)
		this->name = NULL;
	else {

		this->name = new char[strlen(p.name) + 1];
		strcpy_s(this->name, strlen(p.name) + 1, p.name);
	}
}

Product::~Product()
{
	delete[] this->name;
	this->name = NULL;
}

int Product::getId()
{
	return this->id;
}

double Product::getPrice()
{
	return this->price;
}

char* Product::getName()
{
	return this->name;  
}

void Product::setId(int c)
{
	this->id = c;
}

void Product::setPrice(double pr)
{
	this->price = pr;
}

void Product::setName(char* n)
{
	if (this->name != NULL)
		delete[] this->name;
	if (n == NULL)
		this->name = NULL;
	else
	{
		this->name = new char[strlen(n) + 1];
		strcpy_s(this->name, strlen(n) + 1, n);
	}
}

Product& Product::operator=(const Product& p)
{
	this->id = p.id;
	this->price = p.price;
	this->setName(p.name);
	return* this;
}

bool Product::operator==(const Product& p)
{
	if (this->name == NULL && p.name == NULL)
		return (this->id == p.id && this->price == p.price);
	if (this->name == NULL or p.name == NULL)
		return false;
	return (this->id == p.id && this->price == p.price && (strcmp(this->name, p.name) == 0));
}

bool Product::operator!()
{
	if (this->id == 0 or this->price == 0 or strlen(this->name) == 0)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Product& p)
{
	os << p.id << " " << p.price << " " << p.name;
	return os;
}

istream& operator>>(istream& is, Product& p)
{
	int id;
	double price;
	char* name = new char[50];
	if (&is == &cin)
		cout << "Input id: ";
	is >> id;
	if (&is == &cin)
		cout << "Input price: ";
	is >> price;
	if (&is == &cin)
		cout << "Input name: ";
	is >> name;
	p.setId(id);
	p.setPrice(price);
	p.setName(name);
	delete[] name;
	return is;
}