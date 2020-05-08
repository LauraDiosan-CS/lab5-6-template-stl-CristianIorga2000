#pragma once
#include <iostream>
#include "RepoFile.h"
#include "Coin.h"
#include "Product.h"
using namespace std;

bool Comp(Coin m1, Coin m2);

class ServiceCoins
{
private:
	RepoFile <Coin> repo;
public:
	ServiceCoins();
	~ServiceCoins();
	ServiceCoins(const RepoFile <Coin>& r);
	int getSize();
	void getAll(Coin rez[]);
	void delCoin(double val);
	void updateCoin(double val, int am);
	void Sort();
	bool Rest(Coin list[], int size, double rest);
};
