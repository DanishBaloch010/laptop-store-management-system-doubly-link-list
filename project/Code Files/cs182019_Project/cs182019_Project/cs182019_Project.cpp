#include "StdAfx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <fstream>
#include "DoublyLinkList_doubleEnded.h"
#include "SentinalSearch.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	DoublyLinkList_doubleEnded list; // object of doubly link list
	SentinalSearch S_search;
	list.addLaptop("Lenovo T460 - Lenovo - 99,000",  10); // Adding laptops
	list.addLaptop("Lenovo T560 - Lenovo - 45,000",  30);
	list.addLaptop("Lenovo T550 - Lenovo - 46,000",  90);
	list.addLaptop("Lenovo T460 - Lenovo - 89,000",  20);
	list.addLaptop("DELL  XPS13 - DELL   - 120,000", 60);
	list.addLaptop("DELL  XPS13 - DELL   - 120,000", 70);
	
	cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-";
	cout << "\n----------Laptop Store Management System--------------";
	cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
	
	consoleControlInstructions:
	cout << "\nx-----Please enter particular key for prefered task.-------x\n";
	cout << "\n**********************************************************************";
	cout << "\n** ->    Press 1 for adding a laptop in inventory.	<- ******";
	cout << "\n** ->    Press 2 for showing collection to customer.	<- ******";
	cout << "\n** ->    Press 3 for selling a laptop.			<- ******";
	cout << "\n** ->    Press 4 for deleting laptop from inventory.	<- ******";
	cout << "\n** ->    Press 5 to sort the products with code.	<- ******";
	cout << "\n** ->    Press 6 for number of products in inventory.	<- ******";
	cout << "\n** ->    Press 7 to search for a laptop.		<- ******";
	cout << "\n** ->    Press 8 to search for a user data.		<- ******";
	cout << "\n\n** ->    Press -1 to exit the program.			<- ******";
	cout << "\n**********************************************************************";
	
	cout <<"\n\nEnter code :";
	int enteredCode = 0;  
	cin >> enteredCode;					// getting user entered key 
	char continueAddChoice = 'Y';
	if (enteredCode == 1)				// checking user entered key
	{
		while(continueAddChoice=='Y' || continueAddChoice== 'y')
		{
		cout <<"\nEnter Laptop Data in (Model Name- Company- Price) Format :";
		string laptopData = "";
		getline(cin >>ws,laptopData);
		cout <<"Enter the code for this product :";
		int code =0;
		cin >> code;
		list.addLaptop(laptopData, code);
		cout <<"SUCCESS : Laptop is successfully added to the Inventory.";
		cout <<"\n\nWant to Add more Laptops? press (Y) for YES press (N) for NO.  :";
		cin >> continueAddChoice;
		}
	}
	
	else if(enteredCode == 2)
	{
		//system ("CLS");
		cout <<"\n\nShowing all the Laptops in Inventory.\n\n";
		list.printList();
	}
			
	else if(enteredCode == 3)
	{ 
		cout <<"\nx----------  Selling a Laptop Process ---------x";
		cout <<"\n----- Below Are The Available Laptops ------\n\n";
		bool emptyCheck = list.checkEmpty();
		if(emptyCheck==true)
		{
			cout <<"There are no Laptops in inventory. Please add Some.\n";
		}
		else
		{
		list.printList();
		cout <<"\nEnter respective code of the selling product :";
		int code = 0;
		cin  >> code;
		string buyerName;
		cout << "\nEnter buyer Name :";
		getline(cin >>ws , buyerName);
		cout << "\nEnter buyer Phone Number :";
		string buyerPhoneNum;
		getline(cin >> ws , buyerPhoneNum);
		cout << "\nBuyer Details :";
		cout << "\nBuyer Name : " << buyerName << " || Buyer Phone Number : "<<buyerPhoneNum<<endl;
		list.sell(code);
		ofstream writerFile;
		writerFile.open("buyerData.txt",writerFile.app);
		writerFile <<endl<<buyerName<<endl<<buyerPhoneNum;
		writerFile.close();
		
		}
		cout <<"\nx--------  Selling a Laptop Process END ---------x\n";

	}
	 
	else if(enteredCode == 4)
	{
		cout <<"\nRemoving laptop from Inventory.";
		cout <<"\nEnter code for the Laptop Product :";
		int productCode = 0;
		cin >> productCode;
		list.deleteLaptop(productCode);
	}		
	else if(enteredCode == 5)
	{
		cout <<"\n---------- Showing sorted products Codes ---------\n";
		bool check =list.checkEmpty();
		if(check == true)
		{
			cout <<"There are no Laptops in inventory. Please add Some.\n";
		}
		else
		{
			int size =list.size();
			list.sort(size);
			list.printList();
		}
		cout <<"\n------- Showing sorted products Codes END --------\n";
		
	}

	else if(enteredCode == 6)
	{
		cout <<"\n---------- Showing Number of products in inventory ------------\n";

		int numOfLaptops =list.size();
		cout <<"\nYou have ( "<<numOfLaptops<<" ) Number of Laptops in your inventory.\n";

		cout <<"\n---------- Showing Number of products in inventory END ---------\n";


	}
	else if(enteredCode==7)
	{
		cout <<"\n---------- Searching of products in inventory     ------------\n\n";
		list.printList();
		bool check = list.checkEmpty();
		if(check == true)
			cout <<"There are no Laptops to search. Please add Some.\n";

		else
		{
			cout <<"\nPlease enter the product code for searching :";
			int code=0;
			cin >> code;
			int index = list.LinearSearch(code);
			cout << "\nThe product is found at index  : ( "<< index<<" )" ;
		}

		cout <<"\n\n---------- Searching of products in inventory END ------------\n";
	}
	else if(enteredCode == 8)
	{
		cout <<"\n---------- Searching of Buyer Data. --------------\n\n";

		ifstream fileForCountLines("buyerData.txt");
		int numberOfLine=0;
		string fileText;

		while(getline(fileForCountLines, fileText , '\n'))
		{
			//cout <<fileText << endl; // checking file. fine.
			numberOfLine++;
		}
		fileForCountLines.clear();
		fileForCountLines.close();
		cout << endl;
		//cout << numberOfLine; /*checking no. of lines. fine*/

		string *buyerDataArray;
		buyerDataArray = new string [numberOfLine];
		ifstream fileForArrayInput;
		fileForArrayInput.open("buyerData.txt");
		int i =0;
		while(!fileForArrayInput.eof())
		{
			getline(fileForArrayInput, fileText , '\n');
			buyerDataArray[i] = fileText;
			/*cout <<buyerDataArray[i] <<endl;*/
			i++;
		}
		fileForArrayInput.clear();
		fileForArrayInput.close();

		cout <<"Enter buyer Name to Find it's location : ";
		string buyerName;
		getline(cin >>ws , buyerName);
		int index = S_search.search(buyerDataArray , numberOfLine, buyerName);
		if(index == -1)
		{
			cout<<"\nThe entered name is not found in data.";
		}
		else
		{
			cout << "\nThe user Data is found at index : " << index;
			cout << "\nThe Data is : ";
			cout <<endl<<"Name : "<<buyerDataArray[index];
			cout <<endl<<"Phone Number :" <<buyerDataArray[index+1];
		}

		delete [] buyerDataArray; // DELETING THE ARRAY FROM MEMORY
		buyerDataArray=NULL;

		//array is ready
		//cout <<endl; // checking and printing array. . fine.
		//for(int i=0 ; i<numberOfLine ; i++)
		//{
		//	cout <<buyerDataArray[i] <<endl;
		//}

		cout <<"\n\n---------- Searching of Buyer Data. END ------------\n";

	}
	else if(enteredCode == -1)
	{
		goto exit;		
	}
	
	else
	{		
		cout <<"\nInvalid Code Entry.";
	}
	  
	
	goto  consoleControlInstructions;
	
	exit:
	cout << "\n\n\n\n\nProgram is ended. press any key to exit.....";
	
	_getch();
	
		
}

	