#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include "Repo.h"
using namespace std;

template < class T>
class RepoFile : public Repo <T>
{
private:
	char* inputfile;
	char* outputfile;
public:
	RepoFile()
	{
		this->inputfile = NULL;
		this->outputfile = NULL;
	}

	~RepoFile()
	{
		delete[] this->inputfile;
		delete[] this->outputfile;
		inputfile = NULL;
		outputfile = NULL;
	}

	RepoFile(const char* fin, const char* fout)
	{
		this->inputfile = new char[strlen(fin) + 1];
		this->outputfile = new char[strlen(fout) + 1];
		strcpy_s(this->inputfile, strlen(fin) + 1, fin);
		strcpy_s(this->outputfile, strlen(fout) + 1, fout);
		this->loadFromFile();
	}

	RepoFile(const RepoFile& r)
	{
		inputfile = new char[strlen(r.inputfile) + 1];
		outputfile = new char[strlen(r.outputfile) + 1];
		strcpy_s(inputfile, strlen(r.inputfile) + 1, r.inputfile);
		strcpy_s(outputfile, strlen(r.outputfile) + 1, r.outputfile);
		loadFromFile();
	}

	RepoFile& operator=(const RepoFile& r)
	{
		setNameFileIn(r.inputfile);
		setNameFileOut(r.outputfile);
		loadFromFile();
		return *this;
	}
	
	void setNameFileIn(const char* fin)
	{
		if (this->inputfile != NULL)
			delete[] this->inputfile;
		if (fin == NULL)
			inputfile = NULL;
		else
		{
			this->inputfile = new char[strlen(fin) + 1];
			strcpy_s(this->inputfile, strlen(fin) + 1, fin);
		}
	}

	void setNameFileOut(const char* fout)
	{
		if (this->outputfile != NULL)
			delete[] this->outputfile;
		if (fout == NULL)
			outputfile = NULL;
		else
		{
			this->outputfile = new char[strlen(fout) + 1];
			strcpy_s(this->outputfile, strlen(fout) + 1, fout);
		}
	}

	void saveToFile()
	{
		if (this->outputfile != NULL)
		{
			T list[100];
			Repo<T>::getAll(list);
			ofstream out(this->outputfile);
			for (int i = 0; i < this->getSize(); i++)
				out << list[i] << endl;
			out.close();
		}
	}

	void loadFromFile()
	{
		if (this->inputfile != NULL)
		{
			T e;

			ifstream f(this->inputfile);
			while (!f.eof())
			{
				f >> e;
				if(!!e)
					this->addElem(e);
			}
			f.close();
		}
	}

	int getSize()
	{
		return Repo<T>::getSize();
	}

	void getAll(T rez[])
	{
		Repo<T>::getAll(rez);
	}

	void addElem(T& e)
	{
		Repo<T>::addElem(e);
		saveToFile();
	}

	void delElem(T e)
	{
		Repo<T>::delElem(e);
		saveToFile();
	}

	void updateElem(T& e1, T& e2)
	{
		Repo<T>::updateElem(e1, e2);
		saveToFile();
	}

	T getElem(int id)
	{
		return Repo<T>::getElem(id);
	}
};


