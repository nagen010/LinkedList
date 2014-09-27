#include "SingleList.h"
#include "SingleNode.h"
#include <iostream>

ISingleNode* SingleList::getHead(){
	return Head;
}

void SingleList::setHead(ISingleNode * head){
	Head = head;
}

void SingleList::addHead(int value){

	ISingleNode* newSingleNode = new SingleNode();
	newSingleNode->setValue(value);
	newSingleNode->setNext(Head);
	Head = newSingleNode;

}

void SingleList::orderSort2(){

	ISingleNode * first = Head, * second = Head->getNext();

	if (first == NULL || first->getNext() == NULL){
		return;
	}

	Head = second;
	while (true){
		ISingleNode * temp;
		temp = second->getNext();
		second->setNext(first);

		if (temp == NULL || temp->getNext() == NULL){
			first->setNext(temp);
			break;
		}

		first->setNext(temp->getNext());
		first = temp;
		second = first->getNext();
	}
}

void SingleList::orderSort3(){

	ISingleNode * first = Head, * second = Head->getNext(), * third = Head->getNext()->getNext();

	if (Head == NULL || Head->getNext() == NULL || Head->getNext()->getNext() == NULL){
		return;
	}

	Head = third;
	while (true){
		ISingleNode * temp;
		temp = third->getNext();
		second->setNext(first);
		third->setNext(second);
		if (temp == NULL || temp->getNext() == NULL){
			first->setNext(temp);
			break;
		}
		if (temp == NULL || temp->getNext() == NULL || temp->getNext()->getNext() == NULL){
			first->setNext(temp->getNext());
			first->getNext()->setNext(temp);
			break;
		}

		first->setNext(temp->getNext()->getNext());
		first = temp;
		second = first->getNext();
		third = second->getNext();
	}
}

//void SingleList::print(){
//	ISingleNode * temp2 = Head;
//	std::cout << "\n printing forward ";
//	while (temp2 != NULL){
//		std::cout << temp2->getValue() << "\t";
//		temp2 = temp2->getNext();
//	}
//}

void SingleList::sequenceOrderSort(){

	ISingleNode * first = Head, * second = first->getNext();
	int count = 0;

	first->setNext(second->getNext());
	second->setNext(first);
	Head = second;
	count = 3;

	ISingleNode * curr = first, * next = first->getNext();
	second = next;
	//print();
	while (next != NULL)
	{
		for (int i = 1; i < count && second->getNext() != NULL; i++){
			second = second->getNext();
		}

		ISingleNode  * temp = NULL, * temp1 = NULL;
		first = next;
		temp = first;
		next = first->getNext();
		temp1 = next->getNext();
		first->setNext(second->getNext());

		while (first != second){
			next->setNext(first);
			first = next;
			next = temp1;
			if (next)
				temp1 = next->getNext();
		}
		curr->setNext(first);
		curr = temp;
		second = temp->getNext();
		count++;
	}
	//print();
}

void SingleList::reverse(){

	if (Head == NULL || Head->getNext() == NULL){
		return;
	}
	ISingleNode * first = NULL, * second = Head, * temp;

	while (second != NULL){
		temp = second->getNext();
		second->setNext(first);
		first = second;
		second = temp;
		
	}
	Head = first;
}