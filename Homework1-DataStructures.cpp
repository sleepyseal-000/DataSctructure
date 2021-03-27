// Homework1-DataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // include cout  
#include <vector> //Include Vector
#include <cstdlib> // Include rand
#include <ctime> //include time 
#include <string> //Include strings 
#include "LinkedList.h" //include my Linked List header
#include <algorithm> // include generate

using namespace std; 
vector<int>::iterator pos;
vector<string>::iterator pos_2;
LinkedList<int>::iterator it;
LinkedList<string>::iterator it_2;

// Insert vector (insert value - int)
void insertValueVector(vector<int> &v, int value) {
	
	int n = 0;

	//Ask user which position (index) wants to be?
	cout << "Which position you want to be? (index) " << endl; 
	cin >> n; 
	pos = v.begin() + n;
	pos = v.insert(pos, value);// Insert element with value at n Position
	
}
// Delete vector (Delete value - int)
void deleteValueVector(vector<int> &v) {
	
	int n = 0;
	//Ask user which position (index) wants to be?
	cout << "Which position you want to delete? (index) " << endl;
	cin >> n;
	pos = v.begin() + n;
	pos = v.erase(pos);
}
// Search vector (Find value - int)
void searchVector(vector<int> &v, int value) {

	pos = find(v.begin(), v.end(), value);

	
	if (pos != v.end()) {

		cout << "element found" << endl;
		// get index of element from iterator
		int index = distance(v.begin(), pos);
		cout << "Index of element in vector : " << index << std::endl;

	}
	else {
			
		cout << "Element not found" << endl;
	}

}
//Print vector (int)
void printVector(vector<int> v) {
	cout << endl;
	for (pos = v.begin(); pos!= v.end(); pos++) {

		 cout << *pos << endl;

	}
}
//Print LinkedList (int)
void printLinkedList(LinkedList<int>  &l) {
	for (it = l.begin(); it != l.end(); it++)
	{
		cout << "Iterator: " << *it << " ";
	}

}
void printLinkedList(LinkedList<string>& l) {
	for (it_2 = l.begin(); it_2 != l.end(); it_2++)
	{
		cout << "Iterator: " << *it_2 << " ";
	}


}



int main()
{
	srand((unsigned int) time(NULL)); //the timing changes the sequence of random numbers. 
	const int SIZE = 4;
	vector<int> myVector (SIZE);
	vector<string>myVector_2 ;
	vector<string>myVector_3;
	LinkedList<int> list;
	LinkedList<string> list_2;
	LinkedList<string> list_3;

	// Random Vector numbers 
	//generate(myVector.begin(), myVector.end(), rand);
	//insertValueVector(myVector, 10); //insert value 
	//deleteValueVector(myVector); // delete value 
//	printVector(myVector); //print vector 
	//searchVector(myVector, 10); // Will give back 0-false 1-true
	

	/*
	// Random strings vector (ascii)
	
			//cout << endl;
			const int  MAX = 71;
			const char alphanum[MAX] =
				"0123456789"
				"!@#$%^&*"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";

			string random = "";
			for (int i = 0; i < 4; i++) {
				random = alphanum[rand() % (sizeof(alphanum) - 1)];
				myVector_2.push_back(random);

			}

		
	
	
		//Inserction 
		pos_2 = myVector_2.begin() + 0;
		myVector_2.insert(pos_2, "M");
		//Deletion
		pos_2 = myVector_2.begin() + 0;
		myVector_2.erase(pos_2);
		//Searching
		pos_2 = find(myVector_2.begin(), myVector_2.end(), "M"); // Find m in Vector
			if (pos_2 != myVector_2.end()) {

				cout << "Element Found" << std::endl;
				// Get index of element from iterator
				int index = distance(myVector_2.begin(), pos_2);
				cout << "Index of element in vector : " << index << endl;

			}
			else {

				cout << "Element not found" << endl;
			}
	
		// Printing
			for (pos_2 = myVector_2.begin(); pos_2 != myVector_2.end(); pos_2++) {

				cout << *pos_2 << endl;

			}
	

		
		cout << endl;
		//Move semantics when filling with random strings
		myVector_3 = move(myVector_2);// Using move semantics on containers , I "steal" the value without copying it
			//printing
			for (pos_2 = myVector_3.begin(); pos_2 != myVector_3.end(); pos_2++) {

				cout << *pos_2 << endl;

			}
		
	
	*/
/*
	//Random LinkedListNumbers
	list.insert(list.end(),rand());
	list.insert(list.end(), rand() );
	list.insert(list.end(), rand());

	//insertion
	it = list.begin();
	it++;// It will go to next postion
	it = list.insert(it, 99);

	//Delection
	it = list.begin();
	it++; // It will go to next postion
	it = list.erase(it); // Delete node
	
	//Searching (0-false 1-true)
	cout << list.search(99);
	cout << endl;
	//Printing
		printLinkedList(list);
	
*/


	//Random string in the Linked List 
	// Filling them with random strings
	cout << endl;
	const int  MAX = 71;
	const char alphanum[MAX] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

		string random = "";
		for (int i = 0; i < 4; i++) {
			random = alphanum[rand() % (sizeof(alphanum)- 1)];
			list_2.insert(list_2.end(), random);

		}

		//Insertion
		it_2 = list_2.begin();
		it_2++;// It will go to next postion
		it_2 = list_2.insert(it_2, "A");
	
		//Delection
		it_2 = list_2.begin();
		it_2++; // It will go to next postion
		it_2 = list_2.erase(it_2); // Delete node
		
		// Printing 
		printLinkedList(list_2);
	
		//Move semantics when filling with random strings
		list_3.copyList(list_2);
		cout << endl << endl;
	
		printLinkedList(list_3);
		//	cout << endl << endl;
		//Search
		//	cout << list_3.search("w"); // 0 false 1 true 
		
	


	/*
	
	1. Create your own vector and linked list. They should each have all the necessary
	operations such as insertion, deletion, search, etc. You should create an iterator for
	them as well. Test the following to see which is faster:
		 
		 a. Filling them with random numbers
		 b. Filling them with random strings (use ascii)
		 c. Doing the above with move semantics when filling with random strings

	*/

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
