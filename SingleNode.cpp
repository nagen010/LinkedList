#include "SingleNode.h"

void SingleNode::setValue(int value){
	Value = value;
}

int SingleNode::getValue(){
	return Value;
}

void SingleNode::setNext(ISingleNode * next){
	Next = next;
}

ISingleNode * SingleNode::getNext(){
	return Next;
}