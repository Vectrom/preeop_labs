#include <iostream>
#include "Node.h"
#include "List.h"

	List::List() : _head(nullptr), _tail(nullptr) {}

	List::List(const List &listToCopy) : _head(nullptr), _tail(nullptr) {
		for(Node * p = listToCopy._head; p!=nullptr; p=p->getNextNode()) {
			insert(p->data());
		}
	}

	List::~List() {
		Node * actual = _head;
		Node * next = actual->getNextNode();

		while(next != nullptr) {
			actual = next;
			next = actual->getNextNode();
			delete actual;
		}
		delete _head;
	}

	void List::print() const {
		std::cout << "[";
		for(Node * p = _head; p!=nullptr; p=p->getNextNode())
			std::cout << " " << p->data();
		std::cout << "]" << std::endl;
	}

	List &List::insert(const int data, const placeToInsert p) {
		Node *nodeToInsert = new Node(data);

		if(_tail == nullptr) {
			_head = _tail = nodeToInsert;
		}
		else if(p == End) {
				_tail->setNextNode(nodeToInsert);
				_tail = nodeToInsert;
			}
		else {
				nodeToInsert->setNextNode(_head);
				_head = nodeToInsert;
			}

		return *this;
	}

	const Node *List::find(const int value) const {
		for(Node * p = _head; p!=nullptr; p=p->getNextNode()) {
			if(p->data() == value)
				return p;
		}
		return nullptr;
	}