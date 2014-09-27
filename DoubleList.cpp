#include "DoubleNode.h"
#include "DoubleList.h"
#include <iostream>

IDoubleNode* DoubleList::getHead(){
	return Head;
}

void DoubleList::setHead(IDoubleNode * head){
	Head = head;
}

IDoubleNode* DoubleList::getTail(){
	return Tail;
}

void DoubleList::setTail(IDoubleNode * tail){
	Tail = tail;
}

//void DoubleList::print(){
//	IDoubleNode *temp1 = Tail;
//	IDoubleNode *temp2 = Head;
//	std::cout << "\n\n\n\n\n printing forward ";
//	while (temp2 != NULL){
//		std::cout << temp2->getValue() << "\t";
//		temp2 = temp2->getNext();
//	}
//	std::cout << "\n printing  backward ";
//	while (temp1 != NULL){
//		std::cout << temp1->getValue() << "\t";
//		temp1 = temp1->getPrev();
//	}
//}

void DoubleList::addSorted(int value){

	IDoubleNode * newDoubleNode = new DoubleNode();
	newDoubleNode->setValue(value);
	newDoubleNode->setNext(NULL);
	newDoubleNode->setPrev(NULL);

	if (Head == NULL && Tail == NULL){
		Head = newDoubleNode;
		Tail = newDoubleNode;
		newDoubleNode->setPrev(NULL);
		newDoubleNode->setNext(NULL);
		return;
	}

	IDoubleNode * temp = Head;
	bool isAdded = false;

	while (temp != NULL){
		if (newDoubleNode->getValue() <= temp->getValue()){
			if (temp->getPrev() == NULL){
				Head = newDoubleNode;
			}
			if (temp->getPrev())
				temp->getPrev()->setNext(newDoubleNode);
			newDoubleNode->setNext(temp);

			newDoubleNode->setPrev(temp->getPrev());
			temp->setPrev(newDoubleNode);
			isAdded = true;
			return;
		}
		temp = temp->getNext();
	}
	if (!isAdded){
		newDoubleNode->setPrev(Tail);
		Tail->setNext(newDoubleNode);
		Tail = newDoubleNode;
	}
}

void DoubleList::orderSort2(){

	IDoubleNode * first = NULL, *second = NULL, *temp = NULL;
	int count;

	temp = Head;

	while (temp != NULL){
		if (temp != NULL){
			first = temp;
		}

		if (first->getNext() != NULL){
			second = first->getNext();
			temp = temp->getNext();
		}

		if (first->getPrev() == NULL){
			Head = second;
			Head->setPrev(NULL);
		}

		if (first->getNext() == NULL){
			Tail = first;
			Tail->setNext(NULL);
		}

		IDoubleNode * temp1 = NULL;
		temp1 = second->getNext();
		if (temp1 == NULL){
			Tail = first;
			first->setNext(NULL);
		}

		if (first->getPrev()){
			first->getPrev()->setNext(second);
		}

		first->setNext(temp1);
		if (temp1){
			temp1->setPrev(first);
		}

		second->setPrev(first->getPrev());
		if (second->getNext()){
			second->getNext()->setPrev(first);
		}

		first->setPrev(second);
		second->setNext(first);

		temp = first->getNext();
		//print();
	}
}

void DoubleList::orderSort3(){

	IDoubleNode * first = NULL, *second = NULL, *temp = NULL;

	temp = Head;

	while (temp != NULL)
	{
		if (temp != NULL){			
			first = temp;
		}

		if (first->getNext() != NULL){
			second = first->getNext();
			temp = temp->getNext();
		}

		if (first->getPrev() == NULL){
			Head = second;
			Head->setPrev(NULL);
		}

		if (first->getNext() == NULL){
			Tail = first;
			Tail->setNext(NULL);
		}

		IDoubleNode * temp1 = NULL;
		temp1 = second->getNext();
		if (temp1 == NULL){
			Tail = first;
			first->setNext(NULL);
		}

		if (first->getPrev()){
			first->getPrev()->setNext(second);
		}

		first->setNext(temp1);
		if (temp1){
			temp1->setPrev(first);
		}

		second->setPrev(first->getPrev());
		if (second->getNext()){
			second->getNext()->setPrev(first);
		}

		first->setPrev(second);
		second->setNext(first);
	
		IDoubleNode * third;
		third = first->getNext();
		temp = first->getNext();
		if (third != NULL){
			first->setNext(third->getNext());
			third->setPrev(second->getPrev());
			if (third->getNext()){
				third->getNext()->setPrev(first);
			}
			if (second->getPrev() == NULL){
				Head = third;
				Head->setPrev(NULL);
			}
			else{
				second->getPrev()->setNext(third);
			}
			if (third->getNext() == NULL){
				Tail = first;
				Tail->setNext(NULL);
			}
			second->setPrev(third);
			third->setNext(second);
		}
		temp = first->getNext();
		////print();
	}
	////print();
}

bool sequence(IDoubleNode*& start, IDoubleNode *& tail, int count){

	if (start == NULL){
		return true;
	}
	IDoubleNode * prev = start->getPrev(), * first = start, *last_prev = NULL;
	bool flag = false;
	while (count && start != NULL){
		count--;
		IDoubleNode * temp = start->getPrev();
		start->setPrev(start->getNext());
		start->setNext(temp);
		last_prev = start;
		start = start->getPrev();
	}
	////print();
	if (count > 0){
		flag = true;
	}

	IDoubleNode * Last = last_prev;
	IDoubleNode * LastNext = start;

	//IDoubleNode * temp_next = Last->getNext(), * temp_prev = Last->getPrev();

	prev->setNext(Last);
	Last->setPrev(prev);

	first->setNext(LastNext);
	if (LastNext){
		LastNext->setPrev(first);
	}

	if (LastNext == NULL){
		tail = first;
		tail->setNext(NULL);
	}

	start = LastNext;
	//print();
	return flag;
}

void DoubleList::sequenceOrderSort(){
	IDoubleNode * first = NULL, * second = NULL, * third = NULL;
	//print();
	first = Head;
	second = first->getNext();
	third = second->getNext();
	// Set the head
	Head = second;
	second->setPrev(NULL);

	// Change first and second
	second->setNext(first);
	first->setNext(third);
	first->setPrev(second);

	third->setPrev(first);

	//print();

	for (int i = 3;; i++){
		bool isDone = sequence(third, Tail, i);
		//print();
		if (isDone == true)
			break;
	}
	//print();
}

void DoubleList::reverse(){

	if (Head == NULL || Head->getNext() == NULL){
		return;
	}
	IDoubleNode * first = NULL, *second = Head;
	////print();
	while (second != NULL){
		first = second->getPrev();
		second->setPrev(second->getNext());
		second->setNext(first);
		second = second->getPrev();
	}

	if (first != NULL){
		Tail = Head;
		Head = first->getPrev();
	}
	////print();
}