#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <exception>
#include <vector>
using namespace std;

/*
 * heap.h
 *
 *  Created on: Feb 22, 2015
 *      Author: Thurston, ALex
 */
// do nothing default constructor
template <class T>
Heap<T>::Heap() {
	structuredheapsize=0;
	// TODO Auto-generated constructor stub
}

// inputs and initializes data to a maximum root heap
template <class T>
Heap<T>::Heap(vector<T> input) {
	initializeMaxHeap(input);
	buildMaxHeap();
	return;
}

// builds a maximum root heap from an unstructured array
/* in the future, this should just call 'buildHeap' */
template <class T>
void Heap<T>::buildMaxHeap() // turns a heap structure into a valid heap
{
	/*
	 - initialize heap structure size to full array of data
	 - move from last index with children to first index creating valid heaps
	 */
	structuredheapsize= data.size();
	if (!data.size()) {
		return;
	} // empty heap base case
	for (int i = (data.size()-1)/2; i >= 0; i--) {
		maxHeapify(i);
	}
	return;
}

// creates a maximum root heap of root i
/* in the future, this should just call 'heapify' */
template <class T>
void Heap<T>::maxHeapify(int i) // makes a heap with root i valid
{
	if (i < 0) {
		throw invalid_argument("In 'maxHeapify': invalid index\n");
	}
	int l = left(i), r = right(i); // left, right index: valid if >= 0
	string big = data[i];
	int ibig = i; // largest value and coresponding index: defaults to root

	if ((r >= 0) && (data[r] > big)) {
		big = data[r];
		ibig = r;
	} // check if index is valid first
	if ((l >= 0) && (data[l] > big)) {
		big = data[l];
		ibig = l;
	} // then find largest node/node-index

	// if the root isn't the largest, swap values, validate the swapped subheap
	if (ibig != i) {
		dataSwap(i, ibig);
		maxHeapify(ibig);
	}
	return;
}

/* in the future, this should call 'heapSort' */
template <class T>
void Heap<T>::maxHeapSort() {
	/*
	 - initialize heap structure size to full array of data & ensure we start with a fully valid heap
	 - then, move through the array from back to front creating a list from the back of the heap
	 - for each iteration: move top item to the back of the list and decrement the size of the array that is
	 considered part of the heap structure: this affects the 'left', 'right' functions
	 - then, recreate a valid heap
	 */
	structuredheapsize = data.size()-1;
	buildMaxHeap();
	for (int i = data.size()-1; i > 1; i--)
	{
		dataSwap(0, i);
		structuredheapsize -= 1;
		maxHeapify(0);
	}
	return;
}
/**
 * minHeapSort() sorts the heap vector from smallest to largest
 *
 */
template <class T>
void Heap<T>::minHeapSort()
{
	structuredheapsize = data.size()-1;
	buildMinHeap();
	for (int i = data.size()-1; i > 1; i--)
	{
		dataSwap(0, i);
		structuredheapsize -= 1;
		minHeapify(0);
	}
	return;
}
/**
 * minHeapfiy verifies and creates the heap structure
 * In this case it makes it a minHeap so that the node is smaller then
 * its children. This will be called recursively to fix broken heap structures
 * @param int i-the current node that is going to be fixed
 */
template <class T>
void Heap<T>::minHeapify(int i)
{
	if (i < 0) {
		throw invalid_argument("In 'maxHeapify': invalid index\n");
	}
	int l = left(i), r = right(i); // left, right index: valid if >= 0
	string small = data[i];
	int iSmall = i; // largest value and coresponding index: defaults to root

	if ((r >= 0) && (data[r] < small)) {
		small = data[r];
		iSmall = r;
	} // check if index is valid first
	if ((l >= 0) && (data[l] < small)) {
		small = data[l];
		iSmall = l;
	} // then find largest node/node-index

	// if the root isn't the largest, swap values, validate the swapped subheap
	if (iSmall != i) {
		dataSwap(i, iSmall);
		minHeapify(iSmall);
	}
	return;
}
/**
 * buildMinHeap takes a random vector of type T and turns
 * it into a minHeap structure
 */
template <class T>
void Heap<T>::buildMinHeap()
{
	/*
	 - initialize heap structure size to full array of data
	 - move from last index with children to first index creating valid heaps
	 */
	structuredheapsize= data.size()-1;
	if (!data.size()) {
		return;
	} // empty heap base case
	for (int i = (data.size()-1)/2; i >= 0; i--) {
		minHeapify(i);
	}
	return;
}

// swap values of data
template <class T>
void Heap<T>::dataSwap(int i, int j) {
	if (i >= data.size() || j >= data.size() || i < 0 || j < 0) // check indexing boundaries
			{
		throw out_of_range("In 'dataSwap': index out of bounds");
	}
	string temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return;
}

template <class T>
Heap<T>::~Heap() {
	// TODO Auto-generated destructor stub
}
