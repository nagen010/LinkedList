#include "DoubleNode.h"

void DoubleNode::setValue(int value){
	Value = value;
}

int DoubleNode::getValue(){
	return Value;
}

void DoubleNode::setNext(IDoubleNode * next){
	Next = next;
}

IDoubleNode * DoubleNode::getNext(){
	return Next;
}

void DoubleNode::setPrev(IDoubleNode * prev){
	Prev = prev;
}

IDoubleNode * DoubleNode::getPrev(){
	return Prev;
}