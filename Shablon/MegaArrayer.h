#pragma once
#include<iostream>

#include "Random.h"

template <class T>
class MegaArrayer
{
private:
	T* _array;
	int _arraySize;

public:
	T operator[](int index);
	MegaArrayer(int arraySize);
	void Generate();
	void Sort();
	void Print();
	T ApproximateSearch(T toSearch, int, int);

};


template<class T>
inline T MegaArrayer<T>::operator[](int index) {
	return _array[index];
}


template<class T>
inline MegaArrayer<T>::MegaArrayer(int arraySize)
{
	this->_arraySize = arraySize;
	this->_array = new T[_arraySize];

}


template<class T>
inline void MegaArrayer<T>::Generate()
{
	random_device RAND;
	for (int i = 0; i < _arraySize; i++) {
		_array[i] = RAND() % 100;
	}
}


template<class T>
inline void MegaArrayer<T>::Sort()
{
	for (int iterationCounter = 0; iterationCounter < _arraySize / 2; iterationCounter++) {
		int startIndex = iterationCounter;
		int stopIndex = _arraySize - 1 - iterationCounter;
		T maximumValue = _array[startIndex];
		T minimumValue = _array[stopIndex];
		int maximumValueIndex = startIndex;
		int minimumValueIndex = stopIndex;

		for (int counter = startIndex; counter <= stopIndex; counter++) {
			if (_array[counter] > maximumValue) {
				maximumValue = _array[counter];
				maximumValueIndex = counter;
			}
			if (_array[counter] < minimumValue) {
				minimumValue = _array[counter];
				minimumValueIndex = counter;
			}


		}
		swap(_array[startIndex], _array[minimumValueIndex]);
		if (maximumValueIndex == startIndex) {
			maximumValueIndex = minimumValueIndex;
		}
		if (!(stopIndex == minimumValueIndex && startIndex == maximumValueIndex)) {
			swap(_array[stopIndex], _array[maximumValueIndex]);
		}
	}
}


template<class T>
inline void MegaArrayer<T>::Print()
{
	for (int i = 0; i < _arraySize; i++) {
		cout << this->_array[i] << " ";
	}
}


template<class T>
inline T MegaArrayer<T>::ApproximateSearch(T toSearch, int startIndex, int stopIndex) {

	int checkIndex = ((stopIndex - startIndex) / 2) + startIndex;

	if (stopIndex - startIndex == 0) {
		return stopIndex;
	}
	else if (stopIndex - startIndex == 1) {
		if (_array[startIndex] == toSearch) {
			return startIndex;
		}
		if (_array[stopIndex] == toSearch) {
			return stopIndex;
		}
		if (_array[stopIndex] - toSearch < toSearch - _array[startIndex]) {
			return stopIndex;
		}
		else {
			return startIndex;
		}
	}
	else {
		if (_array[checkIndex] > toSearch) {
			return ApproximateSearch(toSearch, startIndex, checkIndex);
		}
		else {
			return ApproximateSearch(toSearch, checkIndex, stopIndex);
		}
	}
}

