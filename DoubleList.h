#pragma once

#include "Interfaces01.h"

class DoubleList : public IDoubleList{
private:
	IDoubleNode * Head;
	IDoubleNode * Tail;
public:
	DoubleList() { Head = NULL; Tail = NULL; }
	~DoubleList() {}
	IDoubleNode * getHead();
	IDoubleNode * getTail();
	void setHead(IDoubleNode * head);
	void setTail(IDoubleNode * tail);
	void addSorted(int value);
	void orderSort2();
	void orderSort3();
	void sequenceOrderSort();
	void reverse();
	//void print();
	//bool sequence(IDoubleNode*&, IDoubleNode*&, int);
};