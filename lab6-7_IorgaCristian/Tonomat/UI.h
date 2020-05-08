#pragma once
#include <iostream>
#include "Service.h"
#include "RepoFile.h"
#include "Product.h"
#include "ServiceCoins.h"

using namespace std;

class UI
{
private:
	Service service;
	ServiceCoins serviceCoins;
public:
	UI();
	UI(const Service& s, const ServiceCoins& sm);
	void showMenu();
	void showMenuVendor();
	void addItem();
	void deleteItem();
	void updateName();
	void updatePrice();
	void updateNamePrice();
	void showProducte();
	void buyProduct();
	void showCoins();
	void run();
};