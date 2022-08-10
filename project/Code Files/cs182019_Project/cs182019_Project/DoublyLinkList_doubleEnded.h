#ifndef DOUBLYLINKLIST_DOUBLEENDED_H
#define DOUBLYLINKLIST_DOUBLEENDED_H
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;
class DoublyLinkList_doubleEnded
{
	private:
		typedef struct node
		{
			string data;
			int key;
			node* next;
			node* prev;
			
		}* nodeptr; 
		
		nodeptr head;
		nodeptr tail;
		nodeptr temp;
		nodeptr current;
		nodeptr nextOne;
	
	public: // public functions
	DoublyLinkList_doubleEnded(); // default constructor (used for intializing the global variables)
	void addLaptop(string addDataLast , int code);
	void deleteLaptop(int code);
	void sell(int code);
	void reverseTraverse();
	void printList();
	bool checkEmpty();
	int size();
	void sort( int size);
	int LinearSearch(int target);
			
};
#endif