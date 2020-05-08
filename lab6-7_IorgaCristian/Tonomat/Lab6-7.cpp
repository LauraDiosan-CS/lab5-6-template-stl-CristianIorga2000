#include <iostream>
#include "Product.h"
#include "Repo.h"
#include "Tests.h"
#include "UI.h"

int main()
{
	cout << "Starting tests.\n";
	 
	TestProduct();
	TestRepoFile();
	TestServiceCRUD();
	TestCoin();
	TestServiceCoins();
	TestRest();

	cout << "Testing succesfull. Initiating build protocol. \n";

	char* f1 = new char[20];
	char* f2 = new char[20];
	char* f3 = new char[20];
	char* f4 = new char[20];
	strcpy_s(f1, 16, "ProductsIn.txt");
	strcpy_s(f2, 16, "ProductsOut.txt");
	strcpy_s(f3, 13, "CoinsIn.txt");
	strcpy_s(f4, 13, "CoinsOut.txt");

	cout << "Build protocol stage I finished: storage files updated.\n";
	
	RepoFile<Product> repo(f1, f2);
	RepoFile<Coin> repoC(f3, f4);

	cout << "Build protocol stage II finished: repositories initialised.\n";

	Service s(repo);
	ServiceCoins sc(repoC);

	cout << "Build protocol stage III finished: services initialised.\n";

	UI ui(s, sc);

	cout << "Build protocol stage IV finished: UI initialised.\n";

	cout << "Preparing for launch\n" << endl;
	ui.run();
	delete[] f1;
	delete[] f2;
	delete[] f3;
	delete[] f4;

	return 0;
}