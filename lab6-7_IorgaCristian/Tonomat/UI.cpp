#include <iostream>
#include <string.h>
#include <conio.h>
#include <string.h>
#include "Service.h"
#include "Repo.h"
#include "Product.h"
#include "UI.h"
using namespace std;

UI::UI() {}
UI::UI(const Service& s, const ServiceCoins& sm)
{
	this->service = s;
	this->serviceCoins = sm;
}

void UI::showMenu()
{
	cout << "0. Exit app" << endl;
	cout << "1. Buy item" << endl;
	cout << "2. Vending machine menu" << endl;
}

void UI::showMenuVendor()
{
	cout << "0. Exit to main menu" << endl;
	cout << "1. Add product" << endl;
	cout << "2. Delete product" << endl;
	cout << "3. Update product name" << endl;
	cout << "4. Update product price" << endl;
	cout << "5. Update product (name and price)" << endl;
	cout << "4. Show vending machine items" << endl;
	cout << "5. Show vending machine coin storage" << endl;
}

void UI::addItem()
{
	int id;
	double price;
	char* name = new char[20];
	cout << "Input product id: ";
	cin >> id;
	cout << "Input product  price: ";
	cin >> price;
	cout << "Input product  name: ";
	cin >> name;
	this->service.addProduct(id, price, name);
	delete[] name;
}

void UI::deleteItem()
{
	int id;
	cout << "Input the id of the to-be-deleted product: ";
	cin >> id;
	this->service.delProduct(id);
}

void UI::updateName()
{
	int id;
	char* name = new char[20];
	cout << "Input id of to-be-updated product ";
	cin >> id;
	cout << "Input new name for product: ";
	cin >> name;
	this->service.updateProduct(id, 0, name);
	delete[] name;
}

void UI::updatePrice()
{
	int id;
	double price;
	cout << "Input id of to-be-updated product: ";
	cin >> id;
	cout << "Input new price for product: ";
	cin >> price;
	this->service.updateProduct(id, price, NULL);
}

void UI::updateNamePrice()
{
	int id;
	double price;
	char* name = new char[20];
	cout << "Input id of to-be-updated product";
	cin >> id;
	cout << "Input new name: ";
	cin >> name;
	cout << "Input new price: ";
	cin >> price;
	this->service.updateProduct(id, price, name);
	delete[] name;
}

void UI::showProducte()
{
	Product list[100];
	int lungime = this->service.getSize();
	this->service.getAll(list);
	for (int i = 0; i < lungime; i++)
		cout << list[i].getId() << " " << list[i].getPrice() << " " << list[i].getName() << endl;
}

void UI::buyProduct()
{
	Coin list[100];
	Product p;
	int id;
	double sumProd, x;
	serviceCoins.getAll(list);
	cout << "Id product: ";
	cin >> id;
	p = service.getProduct(id);
	sumProd = p.getPrice();
	while (sumProd > 0)
	{
		cout << "Introduceti valoare monezii: ";
		cin >> x;
		sumProd -= x;
		for(int i=0; i< serviceCoins.getSize(); i++)
			if (list[i].getValue() == x)
			{
				int am = list[i].getAmount();
				list[i].setAmount(am + 1);
				break;
			}
				
	}
	if (sumProd != 0)
	{
		if (this->serviceCoins.Rest(list, this->serviceCoins.getSize(), -sumProd))
		{
			for (int i = 0; i < this->serviceCoins.getSize(); i++)
				this->serviceCoins.updateCoin(list[i].getValue(), list[i].getAmount());
			cout << "Succesfull purchase and return of change" << endl;
				
		}
		else
			cout << "Inssuficient vending machine funds for change"  << endl;
	}
	else
	{
		cout << "Succesfull purchase, no need for change" << endl;
		for (int i = 0; i < this->serviceCoins.getSize(); i++)
			this->serviceCoins.updateCoin(list[i].getValue(), list[i].getAmount());
	}
}

void UI::showCoins()
{
	Coin list[100];
	this->serviceCoins.getAll(list);
	for (int i = 0; i < this->serviceCoins.getSize(); i++)
		cout << list[i] << endl;
}

void UI::run()
{
	char op[10];
	while (true)
	{
		this->showMenu();
		cout << "Input product  optiunea: ";
		cin >> op;
		if (!strcmp(op, "1"))
		{
			this->showProducte();
			this->buyProduct();
		}
		else if (!strcmp(op, "2"))
		{
			while (true)
			{
				this->showMenuVendor();
				cout << "Choose vendor option: ";
				cin >> op;
				if (!strcmp(op, "1")) this->addItem();
				else if (!strcmp(op, "2")) this->deleteItem();
				else if (!strcmp(op, "3")) this->updateName();
				else if (!strcmp(op, "3b")) this->updatePrice();
				else if (!strcmp(op, "3c")) this->updateNamePrice();
				else if (!strcmp(op, "4")) this->showProducte();
				else if (!strcmp(op, "5")) this->showCoins();
				else if (!strcmp(op, "0")) break;
				else cout << "Incorrect input. Please try again." << endl;
			}
		}
		else if (!strcmp(op, "0")) break;
		else cout << "Incorrect input.Please try again." << endl;
		
	}
}