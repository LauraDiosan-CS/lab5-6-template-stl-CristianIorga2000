#pragma once
#include <iostream>
#include "Product.h"
#include "RepoFile.h"
using namespace std;

class Service
{
private:
	RepoFile <Product> repo;
public:
	Service();
	Service(const RepoFile<Product>& rep);
	~Service();
	void addProduct(int c, double pr, char* n);
	void delProduct(int id);
	void updateProduct(int c, double pr, char* n);
	void getAll(Product rez[]);
	Product getProduct(int id);
	int getSize();
};
