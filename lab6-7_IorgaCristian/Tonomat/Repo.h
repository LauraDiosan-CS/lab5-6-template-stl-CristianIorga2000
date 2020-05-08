#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

template <class T>
class Repo
{
private:
	vector <T> elements;
public:
	Repo() {}

	~Repo() 
	{
		this->elements.clear();
	}

	void addElem(T& e)
	{
		int found = 0;
		for (int i = 0; i < this->getSize(); i++)
			if (e == this->elements[i])
				found = 1;
		if (!found)
			elements.push_back(e);	
	}

	void getAll(T rez[])
	{
		for (int i = 0; i < this->getSize(); i++)
			rez[i] = elements[i];
	}

	T getElem(int c)
	{
		for (int i = 0; i < this->getSize(); i++)
			if (c == elements[i].getId())
				return elements[i];
	}

	void delElem(T e)
	{
		for (int i = 0; i < this->getSize(); i++)
			if (e == this->elements[i])
				elements.erase(elements.begin() + i);
	}

	void updateElem(T& e1, T& e2)
	{
		for (int i = 0; i < this->getSize(); i++)
			if (e1 == elements[i])
				elements[i] = e2;
				
	}

	int getSize()
	{
		return this->elements.size();
	}
};