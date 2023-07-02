// Shablon.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "MegaArrayer.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива" << endl;
	int arraySize;
	cin >> arraySize;

	MegaArrayer<int>* megaArrayer = new MegaArrayer<int>[1] {arraySize};
	megaArrayer->Generate();
	megaArrayer->Print();
	cout << endl;
	megaArrayer->Sort();
	megaArrayer->Print();
	cout << endl;

	int search;
	cout << ("Введите элемент для поиска: "); 
	cin >> search;
	int positionSearch = megaArrayer->ApproximateSearch(search, 0, arraySize - 1);
	cout << "Искомый элемент равен " << (*megaArrayer)[positionSearch] << " ";
	cout << " и находится на позиции " << positionSearch;
}


