#include <iostream>
#include "Service.h"
#include "Repo.h"

Service::Service()
{
	
}

Service::Service(const RepoFile<Product>& rep)
{
	this->repo = rep;
}

Service::~Service() {}

void Service::addProduct(int c, double pr, char* n)
{
	Product p(c, pr, n);
	this->repo.addElem(p);
}

void Service::delProduct(int id)
{
	Product list[100];
	this->repo.getAll(list);
	for(int i=0; i<this->getSize(); i++)
		if(list[i].getId() == id)
			this->repo.delElem(list[i]);
}

void Service::updateProduct(int c, double pr, char* n)
{
	Product prod = this->repo.getElem(c);
	if (pr && n)
	{
		Product p(c, pr, n);
		this->repo.updateElem(prod, p);
	}
	else
		if (pr)
		{
			Product p(c, pr, prod.getName());
			this->repo.updateElem(prod, p);
		}
		else
		{
			Product p(c, prod.getPrice(), n);
			this->repo.updateElem(prod, p);
		}
}

void Service::getAll(Product rez[])
{
	this->repo.getAll(rez);
}

Product Service::getProduct(int id)
{
	return this->repo.getElem(id);
}

int Service::getSize()
{
	return this->repo.getSize();
}