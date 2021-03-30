// Homework1-11DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

/*
Give it the necessary structure, variables, and
functions, and create a pure virtual function called menu.
*/
class Restaurant {

	
public:
	struct Order {
			//Italian
			string pizza = "pizza";
			string pasta = "pasta";
			string ravioli = "ravioli";
			//Greek
			string horiatiki = "horiatiki";
			string pastitsio = "pastitsio";
			string garides = "garides";

			//Chinese 
			string pekin_duck = "pekin duck";
			string dumplings = "dumplings";
			string noddles = "noddles";

			//General Drinks 
			string coke = "coke";
			string water = "water";
			string tea = "tea";

			string name;

		} myOrder;
	//Empty void name function
	Restaurant(void) {

		myOrder.name = "";
	}
	//pure virtual function
	virtual void menu() = 0;

};

class Italian_Restaurant : public Restaurant {

	// Here is the italian menu
	
	public:
	Italian_Restaurant(void) {
		
		myOrder.name = "------------Italian Restaurant--------------\n";

	}
	string ShowFood() {

		return "There is " + myOrder.pizza + ", " + myOrder.pasta + ", or " + myOrder.ravioli;
	}
	string ShowDrink() {

		return "There is " + myOrder.coke + ", or " + myOrder.water;

	}
	
	void menu() {
	
	}
	
	

};
class Greek_Restaurant : public Restaurant {

	//  Here is the greek menu 

public:
	Greek_Restaurant(void) {

		myOrder.name = "------------Greek Restaurant--------------\n";

	}

	string ShowFood() {

		return "There is " + myOrder.horiatiki + ", " + myOrder.pastitsio + ", or " + myOrder.garides;
	}
	string ShowDrink() {
	
		return "There is " + myOrder.coke + ", or " + myOrder.water;

	}

	void menu() { }

};
class Chinese_Restaurant : public Restaurant {

	// Here is the chinese menu 
public:
	Chinese_Restaurant(void) {

		myOrder.name = "------------Chinese Restaurant--------------\n";

	}
	string  ShowFood() {

		return "There is " + myOrder.pekin_duck + ", " + myOrder.dumplings + ", or " + myOrder.noddles;
	}
	string ShowDrink() {

		return "There is " + myOrder.coke + ", " + myOrder.tea +", or "+ myOrder.water;
	}
	


};
//Create a polymorphic template 
template <typename T> 
class Reader_Robot : public T {

	public:

		void menu() {

			cout << "Here is the Food Menu:\n" << T::ShowFood() << endl;
			cout << "Here is the Drinks Menu\n" << T::ShowDrink() << endl;
			cout << endl;
		}

};

int main()
{
	//Object template of the italian restaurant
	Reader_Robot<Italian_Restaurant> italia;	
	cout << italia.myOrder.name;
	italia.menu();
	
	//Object template of the greek restaurant
	Reader_Robot<Greek_Restaurant> greek;
	cout << greek.myOrder.name;
	greek.menu();

	//Object template of the chinese restaurant
	Reader_Robot<Chinese_Restaurant > chinese;
	cout << chinese.myOrder.name;
	chinese.menu();

	
	cout << endl;
	cout << "I want to order " + italia.myOrder.pizza + " and " + italia.myOrder.water + " please!";
	cout << endl;

}

/*
	Create a class called Restaurant. Give it the necessary structure, variables, and
	functions, and create a pure virtual function called menu. Create a class called
	Italian_Restaurant, Greek_Restaurant, and Chinese_Restaurant as derived classes.
	Use the parent classes constructor as well as any other variables that need to be
	created. Create a templated class called Reader_Robot. It should take in any kind of
	restaurant and use polymorphism to read the menu (that you overrode). Show how this
	works in main
	
*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
