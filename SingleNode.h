#pragma once

#include "Interfaces01.h"

class SingleNode : public ISingleNode{
private:
	int Value;
	ISingleNode * Next;
public:
	SingleNode() { Next = NULL; }
	~SingleNode() {}
	void setValue(int value);
	int getValue();
	ISingleNode * getNext();
	void setNext(ISingleNode * next);
};