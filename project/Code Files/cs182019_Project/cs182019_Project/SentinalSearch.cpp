#include "StdAfx.h"
#include "SentinalSearch.h"
#include <iostream>
#include <string>

using namespace std;

int SentinalSearch::search(string *Array , int size , string target)
{
	size = size-1;				 //original array size.
	string temp = Array[size];  // last element of array.
	Array[size] = target;	  // element to be searched.
	int i=0;
	while(Array[i] != target)
		i++;
	// putting back the last element.
	Array[size] = temp;
	if((i < size) || (target == Array[size]))
	{
		return i;
	}
	else
	{
		return -1;	
	}
}
