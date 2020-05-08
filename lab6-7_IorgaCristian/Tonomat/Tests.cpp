#include <iostream>
#include "Product.h"
#include "Coin.h"
#include "RepoFile.h"
#include "Service.h"
#include "ServiceCoins.h"
#include <assert.h>
#include <string.h>
#include <vector>

void TestProduct()
{
	char* bere = new char[10];
	char* soparla = new char[10];
	strcpy_s(bere, 5, "bere");
	strcpy_s(soparla, 8, "soparla");
	Product p1(1, 1.5, soparla);
	Product p2(2, 2.5, bere);
	Product p3(2, 2.5, bere);

	assert(p1.getId() == 1);
	assert(p2.getPrice() == 2.5);
	assert(strcmp(p2.getName(), bere) == 0);
	assert(p2 == p3);

	delete[] bere;
	delete[] soparla;
}

void TestRepoFile()
{
	char* testin = new char[20];
	char* testout = new char[20];
	strcpy_s(testin, 11, "TestIn.txt");
	strcpy_s(testout, 12, "TestOut.txt");
	RepoFile <Product> repo(testin, testout);
	char* bere = new char[10];
	char* apa = new char[10];
	char* soparla = new char[10];
	strcpy_s(bere, 5, "bere");
	strcpy_s(soparla, 8, "soparla");
	strcpy_s(apa, 4, "apa");
	
	Product p1(1, 1.5, soparla);
	Product p2(2, 3.5, bere);
	Product p3(1, 2.5, apa);
	repo.addElem(p1);
	repo.addElem(p2);
	
	assert(repo.getSize() == 4);
	assert(repo.getElem(2) == p2);

	repo.updateElem(p1, p3);
	repo.delElem(p2);

	assert(repo.getSize() == 3);
	assert(repo.getElem(1) == p3);

	delete[] bere;
	delete[] soparla;
	delete[] apa;
	delete[] testin;
	delete[] testout;
}

void TestServiceCRUD()
{
	Service service;
	Product p1, p2;
	char* bere = new char[10];
	char* soparla = new char[10];
	char* apa = new char[10];
	strcpy_s(bere, 5, "bere");
	strcpy_s(soparla, 8, "soparla");
	strcpy_s(apa, 4, "apa");
	service.addProduct(1, 2.5, apa);
	service.addProduct(2, 3.5, bere);
	service.addProduct(3, 1.5, soparla);
	service.delProduct(1);
	p1 = service.getProduct(2);
	p2 = service.getProduct(3);

	assert(service.getSize() == 2);
	assert(p1.getPrice() == 3.5);
	assert(p2.getPrice() == 1.5);

	delete[] bere;
	delete[] soparla;
	delete[] apa;
}

void TestCoin()
{
	Coin m1(0.5, 4);
	Coin m2(1, 5);
	assert(m1.getAmount() == 4);
	assert(m1.getValue() == 0.5);
	assert(m2.getAmount() == 5);
	assert(m2.getValue() == 1);
}

void TestServiceCoins()
{
	char* testin = new char[30];
	char* testout = new char[20];
	strcpy_s(testin, 21, "TestServiceCoins.txt");
	strcpy_s(testout, 12, "TestOut.txt");
	RepoFile <Coin> repo(testin, testout);
	ServiceCoins sm(repo);
	assert(sm.getSize() == 3);
	
	sm.delCoin(5);
	assert(sm.getSize() == 2);

	delete[] testin;
	delete[] testout;
}

void TestRest()
{
	double rest = 2.5;
	bool ok;
	ServiceCoins s;
	Coin list[7];
	for (int i = 0; i < 7; i++)
	{
		list[i].setValue(0);
		list[i].setAmount(0);
	}
	Coin m1(0.5, 10);
	Coin m2(1, 10);
	Coin m3(5, 10);
	list[0] = m1;
	list[1] = m2;
	list[2] = m3;
	ok = s.Rest(list, 3, rest);
	assert(ok == true);
	assert(list[0].getAmount() == 9);
	assert(list[1].getAmount() == 8);
	assert(list[2].getAmount() == 10);
}
