#include "SingleList.h"
#include "SingleNode.h"

ISingleNode* SingleList::getHead(){
	return Head;
}

void SingleList::setHead(ISingleNode * head){
	Head = head;
}

void SingleList::addHead(int value){
	SingleNode* newSingleNode = new SingleNode();
	newSingleNode->setValue(value);
	newSingleNode->setNext(NULL);
}

void SingleList::orderSort2(){


}

void SingleList::orderSort3(){

}

void SingleList::sequenceOrderSort(){

}

void SingleList::reverse(){

}