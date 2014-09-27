#pragma once

#include "Interfaces01.h"

class SingleNode : public ISingleNode{
	//friend class SingleList;
private:
	int Value;
	ISingleNode * Next = NULL;
public:
	SingleNode() {}
	~SingleNode() {}
	void setValue(int value);
	int getValue();
	ISingleNode * getNext();
	void setNext(ISingleNode * next);
};