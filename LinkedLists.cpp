#include <iostream>
#include <stdlib.h>
#include <string>
#include <cassert>
#include "DLinkedList.h"

using namespace std;

int main(){
	DLinkedList<string>	List;
	int choose, idx;
	string val, sVal;
	
	while(1){
		cout << endl << endl;
		cout << "Choose the function: "	<< endl;
		cout << "1-)	insertFirst"	<< endl;
		cout << "2-)	insertLast"		<< endl;
		cout << "3-)	insertAt"		<< endl;
		cout << "4-)	insertAfter"	<< endl;
		cout << "5-)	insertBefore"	<< endl;
		cout << "6-)	deleteFirst"	<< endl;
		cout << "7-)	deleteLast"		<< endl;
		cout << "8-)	deleteNode"		<< endl;
		cout << "9-)	clearList"		<< endl;
		cout << "10-)	length"			<< endl;
		cout << "11-)	isEmpty"		<< endl;
		cout << "12-)	reversePrint"	<< endl;
		cout << "13-)	Print the list"	<< endl;
		cout << "14-)	quit"			<< endl;
		cout << endl;
		
		do{
			cin >> choose;
		}while((0 > choose) || (14 < choose));
		
		cout << endl;
		
		switch(choose){
			case 1:
				cout << "Enter the value(string): ";	cin >> val;
				List.insertFirst(val);
				break;
			case 2:
				cout << "Enter the value(string): ";	cin >> val;
				List.insertLast(val);
				break;
			case 3:
				cout << "Enter the idx(int) and value(string): ";	cin >> idx >> val;
				List.insertAt(idx, val);
				break;
			case 4:
				cout << "Enter the node's value(string) and value(string): ";	cin >> sVal; cin >> val;
				List.insertAfter(sVal, val);
				break;
			case 5:
				cout << "Enter the node's value(string) and value(string): ";	cin >> sVal; cin >> val;
				List.insertBefore(sVal, val);
				break;
			case 6:
				List.deleteFirst();
				cout << "First element has deleted.";
				break;
			case 7:
				List.deleteLast();
				cout << "Last element has deleted.";
				break;
			case 8:
				cout << "Enter the value: ";	cin >> val;
				List.deleteNode(val);
				break;
			case 9:
				List.clearList();
				cout << "All the elements on the list has deleted.";
				break;
			case 10:
				cout << "The length of the list: " << List.length() << endl;
				break;
			case 11:
				if(List.isEmpty()){
					cout << "The list is empty." << endl;
				}else{
					cout << "The list is not empty." << endl;
				}
				break;
			case 12:
				List.reversePrint();
				break;
			case 13:
				cout << List << endl;
				break;
			case 14:
				return 0;
		}
	}
}



























/*
int main(){
	DLinkedList<int>	list;
	
	cout << list << endl;
	
	list.insertLast(1);
	cout << list << endl;
	
	list.insertFirst(2);
	cout << list << endl;
	
	list.insertAt(2, 3);
	cout << list << endl;
	
	list.insertAt(-2, 4);
	cout << list << endl;
	
	list.insertLast(5);
	cout << list << endl;
	
	list.insertAt(99, 6);
	cout << list << endl;
	
	list.insertAfter(4, 7);
	cout << list << endl;
	
	list.insertAfter(8, 8);
	cout << list << endl;
	
	list.insertBefore(7, 9);
	cout << list << endl;
	
	list.deleteFirst();
	cout << list << endl;
	
	list.deleteLast();
	cout << list << endl;
	
	list.deleteNode(10);
	cout << list << endl;
	
	list.deleteNode(9);
	cout << list << endl;
	
	list.deleteNode(5);
	cout << list << endl;
	
	list.reversePrint();
	
	list.clearList();
	cout << list << endl;
	
	//cout << list.back() << endl;
	//cout << list.front() << endl;
	
	cout << list.length() << endl;
	
	system("PAUSE");
	return 0;
}
*/
