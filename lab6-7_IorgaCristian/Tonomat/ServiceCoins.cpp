#include "ServiceCoins.h"
#include <algorithm>

using namespace std;

ServiceCoins::ServiceCoins()
{
	this->repo = RepoFile <Coin>();
}

ServiceCoins::~ServiceCoins() {}

ServiceCoins::ServiceCoins(const RepoFile<Coin>& r)
{
	this->repo = r;
}

int ServiceCoins::getSize()
{
	return this->repo.getSize();
}

void ServiceCoins::getAll(Coin rez[])
{
	this->repo.getAll(rez);
}

void ServiceCoins::delCoin(double val)
{
	Coin list[100];
	this->repo.getAll(list);
	for(int i=0; i<this->getSize(); i++)
		if(list[i].getValue() == val)
			this->repo.delElem(list[i]);
}

void ServiceCoins::updateCoin(double val, int am)
{
	Coin list[100];
	this->getAll(list);
	for (int i = 0; i < this->getSize(); i++)
	{
		if (val == list[i].getValue())
		{
			Coin m(val, am);
			this->repo.updateElem(list[i], m);
			break;
		}
			
	}
}

void ServiceCoins::Sort()
{
	int size;
	Coin list[50], copy[50];
	this->getAll(list);
	this->getAll(copy);
	size = this->getSize();
	sort(list, list + size, Comp); 
	for (int i = 0; i < size; i++)
		this->repo.updateElem(copy[i], list[i]);
}

bool ServiceCoins::Rest(Coin list[], int size, double rest)
{
	int am;
	for (int i = size - 1; i >= 0; i--)
	{
		while (rest >= list[i].getValue() && list[i].getAmount() > 0)
		{
			rest -= list[i].getValue();
			am = list[i].getAmount();
			list[i].setAmount(am - 1);
		}
		if (rest == 0)
			return true;
	}
	return false;
}

bool Comp(Coin m1, Coin m2)
{
	return m1.getValue() < m2.getValue();
}
