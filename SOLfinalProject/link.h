#ifndef LINK_H
#define LINK_H

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E> class Link {
public:
	E element;
	Link *next;
	int timesAccessed;

	// Constructors
	Link(const E& elemval, Link* nextval = NULL)
	{
		element = elemval; next = nextval;
	}
	Link(Link* nextval = NULL) { next = nextval; }

	//Function to set the number of accesses
	void setAccessed(int n)
	{
		timesAccessed = n;
	}

	//Function to return the number of accesses
	int getAccessed()
	{
		return timesAccessed;
	}
};

#endif
