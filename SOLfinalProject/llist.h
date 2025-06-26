#ifndef LLIST_H
#define LLIST_H


#include "list.h"
#include "link.h"
#include "book.h"
using namespace std;


template <typename E> class LList : public List<E> {
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;
	int cnt;

	void init() {
		curr = tail = head = new Link<E>;
		cnt = 0;
	}

	void removeall() {
		while (head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	LList() { init(); }
	~LList() { removeall(); }
	void clear() { removeall(); init(); }

	// Insert "it" at current position
	void insert(const E& it) {
		curr->next = new Link<E>(it, curr->next);
		if (tail == curr) tail = curr->next; // New tail
		//cout << endl << it << " has been inserted.";
		cnt++;
	}

	void append(const E& it) { // Append "it" to list
		tail = tail->next = new Link<E>(it, NULL);
		tail->setAccessed(0);
		head->setAccessed(0);
		cnt++;
	}

	// Remove and return current element
	E remove() {
		//Assert(curr->next != NULL, "No element");
		E it = curr->next->element;
		Link<E>* ltemp = curr->next;
		if (tail == curr->next) tail = curr;
		curr->next = curr->next->next;
		delete ltemp;
		cnt--;
		//cout << endl << it << " has been removed.";
		return it;
	}

	void moveToStart()
	{
		curr = head;
	}

	void moveToEnd()
	{
		curr = tail;
	}

	// Move curr one step left; no change if already at front
	void prev() {
		if (curr == head) return;
		Link<E>* temp = head;
		// March down list until we find the previous element
		while (temp->next != curr) temp = temp->next;
		curr = temp;
	}

	// Move curr one step right; no change if already at end
	void next()
	{
		if (curr != tail) curr = curr->next;
	}

	int length() const { return cnt; } //Return length

	// Return the position of the current element
	int currPos() const {
		Link<E>* temp = head;
		int i;
		for (i = 0; curr != temp; i++)
			temp = temp->next;
		return i;
	}

	// Move down list to "pos" position
	void moveToPos(int pos) {
		Assert((pos >= 0) && (pos <= cnt), "Position out of range");
		curr = head;
		for (int i = 0; i < pos; i++) curr = curr->next;
	}

	const E& getValue() const {
		Assert(curr->next != NULL, "No value");
		return curr->next->element;
	}

	//Function to set the accesses for a link
	void setTimesAccessed(int n) {
		curr->setAccessed(n);
	}

	//Returns number of accesses
	int getTimesAccessed() const {
		return curr->getAccessed();
	}

	//Return the tail value from the list
	E tailValue() {
		return tail->element;
	}

	//Return the front value from the list
	E frontValue() {
		return head->next->element;
	}

	//Function to print the list
	void print() const {
		Link<E>* temp = head->next;
		Link<E>* temp2 = head;
		cout << endl;

		//prints each item in list based on temp link pointers above
		for (int i = 0; i < cnt; i++)
		{
			//Display the element and the number of accesses
			cout << " " << temp->element << "-" << temp2->getAccessed();
			temp = temp->next;
			temp2 = temp2->next;
		}
	}

	//Same as above, but with n list items
	void print(int n) const {
		Link<E>* temp = head->next;
		Link<E>* temp2 = head;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << " " << temp->element << "-" << temp2->getAccessed();
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
};

#endif

