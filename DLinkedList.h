#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <iostream>
#include <cassert>

namespace std{

template <typename T>
struct DLLNode{
	T			data;
	DLLNode<T>	*next, *prev;
};

template <typename T>
class DLinkedList{
protected:
	DLLNode<T>	*head, *tail;
	int 		count;
public:
	DLinkedList();
	virtual ~DLinkedList();
	DLinkedList(const DLinkedList &other);
	DLinkedList& operator=(const DLinkedList &other);
	
	bool isEmpty() const;
	int length() const;
	
	void insertFirst(const T &val);
	void insertLast(const T &val);
	void insertAt(const int idx, const T &val);
	
	DLLNode<T>* search(const T &val);
	void insertAfter(const T &sVal, const T &val);
	void insertBefore(const T &sVal, const T &val);
	
	void deleteFirst();
	void deleteLast();
	void clearList();
	void deleteNode(const T& item);
	
	T front() const;
	T back() const;
	
	template <typename S>
	friend ostream& operator<<(ostream& out, const DLinkedList<S> &list);
	
	void reversePrint();
	
protected:
	void recursiveReversePrint(DLLNode<T> *p);
};

template <typename T>
DLinkedList<T>::DLinkedList(){
	head = tail = NULL;
	count = 0;
}

template <typename T>
DLinkedList<T>::~DLinkedList(){
	clearList();
}

template <typename T>
DLinkedList<T>::DLinkedList(const DLinkedList &other){
	head = tail = NULL;
	DLLNode<T>	*p = other.head;
	
	while(p != NULL){
		insertLast(p->data);
		p = p->next;
	}
	count = other.count;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList &other){
	clearList();
	if(other.count == 0)
		return *this;
	
	DLLNode<T>	*p = other.head;
	while(p != NULL){
		insertLast(p->data);
		p = p->next;
	}
	return *this;
}

template <typename T>
bool DLinkedList<T>::isEmpty() const{
	return (count == 0);
}

template <typename T>
int DLinkedList<T>::length() const{
	return count;
}

template <typename T>
void DLinkedList<T>::insertFirst(const T &val){
	DLLNode<T>	*newNode = new DLLNode<T>;
	newNode->data = val;
	newNode->prev = NULL;
	newNode->next = head;
	
	if(tail != NULL){
		head->prev = newNode;
		head = newNode;
	}else{
		head = tail = newNode;
	}
	count++;
}

template <typename T>
void DLinkedList<T>::insertLast(const T &val){
	DLLNode<T>	*newNode = new DLLNode<T>;
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = tail;
	
	if(head != NULL){
		tail->next = newNode;
		tail = newNode;
	}else{
		head = tail = newNode;
	}
	count++;
}

template <typename T>
void DLinkedList<T>::insertAt(const int idx, const T &val){
	if(idx > count){
		insertLast(val);
	}else if(idx <= 1){
		insertFirst(val);
	}else{
		DLLNode<T>	*newNode = new DLLNode<T>;
		DLLNode<T>	*p = head;
		
		for(int i = 2; i < idx; i++){
			p = p->next;
		}
		newNode->data = val;
		newNode->next = p->next;
		newNode->prev = p;
		p->next = newNode;
		p = newNode->next;
		p->prev = newNode;
		count++;
	}
}

template <typename T>
DLLNode<T>* DLinkedList<T>::search(const T &val){
	DLLNode<T>	*p = head;
	bool found = false;
	while(!found && (p != NULL)){
		if(p->data == val)
			found = true;
		else
		p = p->next;
	}
	return p;
}

template <typename T>
void DLinkedList<T>::insertAfter(const T &sVal, const T &val){
	DLLNode<T>	*sNode = search(sVal);
	
	if(sNode == NULL){
		cout << "The value " << sVal << " is not found in the list, so nothing will be inserted." << endl;
	}else if(sNode == tail){
		insertLast(val);
	}else{
		DLLNode<T>	*newNode = new DLLNode<T>;
		newNode->data = val;
		newNode->next = sNode->next;
		newNode->prev = sNode;
		sNode->next = newNode;
		sNode = newNode->next;
		sNode->prev = newNode;
		count++;
	}
}

template <typename T>
void DLinkedList<T>::insertBefore(const T &sVal, const T &val){
	DLLNode<T>	*sNode = search(sVal);
	
	if(sNode == NULL){
		cout << "The value " << sVal << " is not found in the list, so nothing will be inserted." << endl;
	}else if(sNode == head){
		insertFirst(val);
	}else{
		DLLNode<T>	*newNode = new DLLNode<T>;
		newNode->data = val;
		newNode->prev = sNode->prev;
		newNode->next = sNode;
		sNode->prev = newNode;
		sNode = newNode->prev;
		sNode->next = newNode;
		count++;
	}
}

template <typename T>
void DLinkedList<T>::deleteFirst(){
	if(isEmpty()){
		cout << "Linked List is already empty." << endl;
	}else{
		DLLNode<T>	*p = head;
		head = head->next;
		if(head == NULL){
			tail = NULL;
		}else
			head->prev = NULL;
		delete p;
		count--;
	}
}

template <typename T>
void DLinkedList<T>::deleteLast(){
	if(isEmpty()){
		cout << "Linked List is already empty." << endl;
	}else{
		DLLNode<T>	*p = tail;
		tail = tail->prev;
		if(tail == NULL){
			head = NULL;
		}
		delete p;
		count--;
		tail->next = NULL;
	}
}

template <typename T>
void DLinkedList<T>::clearList(){
	DLLNode<T>	*p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	tail = NULL;
	count = 0;
}

template <typename T>
void DLinkedList<T>::deleteNode(const T& item){
	DLLNode<T>	*p, *q;
	if(isEmpty()){
		cout << "Cannot delete from empty list." << endl;
	}else{
		if(head->data == item){
			deleteFirst();
		}else if(tail->data == item){
			deleteLast();
		}else{
			p = search(item);
			if(p == NULL){
				cout << "Item to be deleted is not in the list." << endl;
			}else{
				q = p->prev;
				q->next = p->next;
				q = p->next;
				q->prev = p->prev;
				delete p;
				count--;
			}
		}
	}
}

template <typename T>
T DLinkedList<T>::front() const{
	assert(head !=  NULL&&"Linked List has no elements.");
	return head->data;
}

template <typename T>
T DLinkedList<T>::back() const{
	assert(tail != NULL);
	return tail->data;
}

template <typename T>
ostream& operator<<(ostream& out, const DLinkedList<T> &list){
	DLLNode<T>	*p = list.head;
	while(p != NULL){
		out << p->data << " ";
		p = p->next;
	}
	return out;
}

template <typename T>
void DLinkedList<T>::reversePrint(){
	recursiveReversePrint(head);
	cout << endl;
}

template <typename T>
void DLinkedList<T>::recursiveReversePrint(DLLNode<T> *p){
	if(p != NULL){
		recursiveReversePrint(p->next);
		cout << p->data << " ";
	}
}

}

#endif
