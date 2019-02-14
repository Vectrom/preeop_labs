#pragma once
#include "Node.h"

class List {

public:
	enum placeToInsert {Begin, End};

	List();

	List(const List &listToCopy);

	~List();

	void print() const;

	List &insert(const int data, const placeToInsert p = End);

	const Node *find(const int value) const;

private:
	Node *_head;
	Node *_tail;
};