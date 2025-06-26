#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

#ifndef TRANSPOSE_H
#define TRANSPOSE_H

template <typename E>
class transpose : public SelfOrderedListADT<E> {
public:

	//Default transpose constructor
	//Postcondition: the transpose list object is created with compares initialized to 0
	transpose() {
		
		totalCompares = 0;
	}


	//finds a value within the list
	//Postcondition, returns true if the value exists, otherwise, returns false and calls the insert() method
	bool find(const E& it) {

		bool isFound = false;

		//Move to start to search most likely position
		list.moveToStart();
		for (int i = 0; i < list.length(); i++)
		{
			//Increment compares for each value searched
			totalCompares++;

			//If the value is found, the search ends
			if (list.getValue() == it)
			{

				isFound = true;
				break;
			}

			list.next();

		}

		//if the value is found, the reorder function is called after adjustment to the accesses
		if (isFound == true)
		{

			int temp = list.getTimesAccessed();

			list.setTimesAccessed(temp + 1);
			reorder();
			return true;
		}

		else
		{
			list.moveToEnd();
			list.insert(it);
			list.setTimesAccessed(1);
			reorder();
			return true;
		}

		return false;
	}

	//adds a value to the back of the list
	//Postcondition: a new value is inserted into the back of the list
	void add(const E& it) {
		list.append(it);
	}

	//prints the entire list
	//Postcondition: the entire list is printed along with the number of accesses for each entry, as well as compares
	void printlist() const {
		cout << "\nTranspose Heuristic: " << "\tSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print(); //Call the list print function

	}

	//Same as above, but instead of the entire list, a number 'n' of values are printed.
	void printlist(int n) const {
		cout << "\nTranspose Heuristic: " << "\tSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print(n);
	}

	



	//gets the current number of compares
	//Postcondition: the number of compares are returned
	int getCompares() const {
		return totalCompares;
	}

	//gets the size of the list
	//Postcondition: the list size is returned
	int size() const {
		return list.length();
	}

	//sorts the items from most accesses to least within the list.
	//Postcondition: the list is organized based upon the transpose Heuristic
	void reorder() {

		E frontVal = list.frontValue();
		E endValue = list.tailValue();

		if (list.getValue() == frontVal)
		{
			return;
		}

		if (list.getValue() == endValue)
		{
			int endValue = list.getTimesAccessed();

			//this is where the transpose heuristic takes place
			list.prev();

			int prevValue = list.getTimesAccessed();
			E temp = list.remove();
			list.setTimesAccessed(prevValue);
			list.moveToEnd();

			//first element inserted where old element was
			list.insert(temp);
			list.setTimesAccessed(prevValue);

			//prepare to finish swap
			list.prev();
			list.setTimesAccessed(endValue);
			return;
		}

		int toSwap = list.getTimesAccessed();

		list.prev();
		int prev = list.getTimesAccessed();

		//Go back to start swap
		list.next();
		int curr = list.getTimesAccessed();
		list.next();
		int next = list.getTimesAccessed();
		list.prev();

		//Remove the item to open that list position
		E temp = list.remove();
		list.setTimesAccessed(next);
		list.prev();
		prev = list.getTimesAccessed();

		//Transpose completed
		list.insert(temp);
		list.setTimesAccessed(toSwap);
		list.next();
		list.setTimesAccessed(prev);

	}

	//Default transpose destructor
	~transpose() {

	}

private:
	LList<E> list;
	int totalCompares;
};

#endif
