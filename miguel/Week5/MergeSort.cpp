// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

template <class TYPE>
void mergeSort(vector<TYPE>& arr);

template <class TYPE>
void mergeSort(vector<TYPE>& arr, vector<TYPE>& tmp, int start, int end);

template <class TYPE>
void merge(vector<TYPE>& arr, vector<TYPE>& tmp, int start, int start2, int end);

int main()
{
//	const int ENTRIES = 1000000;
	const int ENTRIES = 8;
	ofstream outfile1, outfile2;
	outfile1.open("unsorted.dat");
	outfile2.open("sorted.dat");

	vector<int> intList;
	for (int i = 0; i < ENTRIES; ++i) {
//		int val = i * 13 % 128;
		int val = i * 13 % 9;
		intList.push_back(val);
	}
	outfile1 << "Before the Sort" << endl;
	for (int i = 0; i < ENTRIES; ++i) {
		outfile1 << i << ". " << intList.at(i) << endl;
	}
	outfile1.close();

	double startTime, endTime, totalTime;
	startTime = GetTickCount();//milliseconds
	mergeSort(intList);
	endTime = GetTickCount();
	totalTime = endTime - startTime;
	cout << "The sort of " << ENTRIES << " entries took " << totalTime << " milliseconds." << endl;

	outfile2 << "After the Sort" << endl;
	for (int i = 0; i < ENTRIES; ++i) {
		outfile2 << i << ". " << intList.at(i) << endl;
	}
	outfile2.close();

	return 0;
}

template <class TYPE>
void mergeSort(vector<TYPE>& arr) {
	vector<TYPE> tmp(arr.size());
	//call mergeSort with the array, the temporary
	//and the starting and ending indices of the array
	mergeSort(arr, tmp, 0, arr.size() - 1);
}

//this function sorts arr from index start to end
template <class TYPE>
void mergeSort(vector<TYPE>& arr, vector<TYPE>& tmp,
	                             int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		cout << "mergeSort(start:" << start << ", mid:" << mid << ");" << endl;
		mergeSort(arr, tmp, start, mid);
		cout << "mergeSort(mid+1:" << mid+1 << ", end:" << end << ");" << endl;
		mergeSort(arr, tmp, mid + 1, end);
	    cout << "merge(start:" << start << ", mid+1:" << mid+1 << ", end:" << end << ");" << endl;
		merge(arr, tmp, start, mid + 1, end);
	}
}

template <class TYPE>
void merge(vector<TYPE>& arr, vector<TYPE>& tmp, int start,
	int start2, int end) {
	int lptr = start;
	int rptr = start2;
	int i = start;
	while (lptr < start2 && rptr <= end) {
		if (arr[lptr] < arr[rptr])
			tmp[i++] = arr[lptr++];
		else
			tmp[i++] = arr[rptr++];
	}
	while (lptr < start2) {
		tmp[i++] = arr[lptr++];
	}
	while (rptr <= end) {
		tmp[i++] = arr[rptr++];
	}
	for (i = start; i <= end; i++) {
		arr[i] = tmp[i];
	}
}