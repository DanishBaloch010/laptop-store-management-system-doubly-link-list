#include "StdAfx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "DoublyLinkList_doubleEnded.h"

using namespace std;

//default constructor used for initialing.
 DoublyLinkList_doubleEnded:: DoublyLinkList_doubleEnded()
{
		head = NULL;
		tail = NULL;
		temp = NULL;
		current = NULL;
}

// insert at last
void DoublyLinkList_doubleEnded::addLaptop(string addDataLast, int code)
{
	nodeptr n = new node;
	n->data = addDataLast;
	n->key = code;
	n->next = NULL;
//	n->prev = tail;
	temp = n;
	if(head != NULL)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	else
	{
		head = temp;
		tail = temp;
	}	
}

// deleting with value 
void DoublyLinkList_doubleEnded::deleteLaptop(int code)
{
	if (head == NULL)
	{ cout <<"\nThe Inventory is empty."; }
	else if(code == head->key)
	{
		if(head==tail)
		{  head = NULL;
		   tail = NULL; } 
		else
		{   head = head->next;
			head->prev = NULL; }
		cout <<"\nThe product with Code : "<<code<<" is removed from inventory.";
	}
	current = head->next;
	while(current != NULL  && code !=current->key)
	{ current = current->next; }
	if(current == tail)
	{   tail = tail->prev;
		tail->next = NULL;
		cout <<"\nThe product with Code : "<<code<<" is removed from inventory."; }
	else
	{
		if(current != NULL)
		{ current->prev->next =current->next;
			current->next->prev =current->prev;
			cout <<"\nThe product with Code : "<<code<<" is removed from inventory."; }
		else
		{ cout <<"\nThe product with Code : "<<code<<" (Unavailable) cant be removed from inventory."; }	
	}
}

// selling laptop
void DoublyLinkList_doubleEnded::sell(int code)
{
	if (head == NULL)
	{
		cout <<"\nThe Inventory is empty.";
	}
	else if(code == head->key)
	{
		if(head==tail)
		{
			head = NULL;
			tail = NULL;
		} 
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		cout <<"\nThe product with Code : "<<code<<" is SOLD.";
	}
	current = head->next;
	while(current != NULL /*&& value != current->data*/ && code !=current->key)
	{
		current = current->next;
	}
	if(current == tail)
	{
		tail = tail->prev;
		tail->next = NULL;
		cout <<"\nThe product with Code : "<<code<<" is SOLD.";
	}
	else
	{
		if(current != NULL)
		{
			current->prev->next =current->next;
			current->next->prev =current->prev;
			cout <<"\nThe product with Code : "<<code<<" is SOLD";	
		}
		else{cout <<"\nThe product with Code : "<<code<<" IS UNAVAILABLE.";}	
	}
}

//reverse traverse
void DoublyLinkList_doubleEnded::reverseTraverse()
{
	current = head;
	while(current != NULL)
	{
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}
	temp = head;
	head = tail;
	tail = temp;
}

// printing
void DoublyLinkList_doubleEnded::printList()

{
	temp = head;
	while(temp != NULL)
	{
		cout <<temp->key<<"   "<<temp->data  << "\n";
		temp = temp->next;	 
	}
}

int DoublyLinkList_doubleEnded::size()
{
	temp=head;
	int counter =0;
	while(temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}
void DoublyLinkList_doubleEnded::sort(int size)
{
		int i,j;
		for( i=0; i<size ; i++)
		{
			current=head;
			for(j=0; j<size-1-i; j++)
			{
				if(current->key > current->next->key)
				{
					nextOne = current->next;
					current->next= nextOne->next;
					nextOne->next = current;
					if(current == head)
					{
						head = nextOne;
						current = nextOne;
					}
					else
					{
						current = nextOne;
						temp->next = nextOne;
					}		
				}
				temp = current;
				current = current->next;
			}
		}
}

bool DoublyLinkList_doubleEnded::checkEmpty()
{
	temp = head;
	if(temp==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int DoublyLinkList_doubleEnded::LinearSearch(int target)
{
	temp = head;
	int index =0;
	while (temp!=NULL)
	{
		if(temp->key== target)
		{
			return index;
		}
		index ++;
		temp = temp ->next;
	}
}
