#pragma once

#include "Interfaces01.h"

class DoubleNode : public IDoubleNode{
private:
	int Value;
	IDoubleNode * Next;
	IDoubleNode * Prev;
public:
	DoubleNode() { Next = NULL; Prev = NULL; }
	~DoubleNode() {}
	void setValue(int value);
	int getValue();
	IDoubleNode* getPrev();
	IDoubleNode* getNext();
	void setPrev(IDoubleNode * prev);
	void setNext(IDoubleNode * next);
};