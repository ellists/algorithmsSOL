#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

#ifndef COUNT_H
#define COUNT_H

template <typename E>
class Count : public SelfOrderedListADT<E> {
public:

	//Default Count constructor
	//Postcondition: the Count list object is created with compares initialized to 0
	Count() { 

		totalCompares = 0;
	}


	//finds a value within the list.
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

		//If the value is found, the reorder function is called after adjustments to the accesses
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

			//this->add(it) was putting the items into the list, but the reorder was giving incorrect results
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

		cout << "Count Heuristic: " << "\tSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print();
		cout << endl;

	}

	//Same as above, but instead of the entire list, a number 'n' of values are printed.
	void printlist(int n) const {

		cout << "\nCount Heuristic: " << "\tSize of List: " << size();
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
	//Postcondition: the list is organized based upon the Count Heuristic
	void reorder() {

		int currPos = list.getTimesAccessed();
		list.prev();
		int prevPos = list.getTimesAccessed();

		//Loop that compares two elements and swaps them if needed, this makes the method rather concise
		while (currPos > prevPos)
		{
			list.next();
			E temp = list.remove();
			list.setTimesAccessed(prevPos);
			list.prev();
			list.insert(temp);

			list.setTimesAccessed(currPos);
			list.next();
			list.setTimesAccessed(prevPos);

			list.prev();
			list.prev();
			prevPos = list.getTimesAccessed();
		}

	}

	//Default Count destructor
	~Count() {

	}

private:
	LList<E> list;
	int totalCompares;
};

#endif
